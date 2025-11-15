#include "glow.h"
#include "util.h"

#include "sdk/sdk.h"

#include "vars.h"

#include <vector>

#define P( Property ) unity::shader::property_to_id( Property )

enum shader_property_type {
	color
};

struct shader_property {
	int32_t id;
	shader_property_type type;
};

struct configured_shader_property {
	shader_property property;

	union {
		uint32_t* color;
	};

	union {
		uint32_t previous_color;
	};
};

enum materials_index {
	players,
	scientists,
	held_item,
	hands
};

class material_collection {
public:
	class instance {
	public:
		instance() = default;
		instance( uint64_t hash, unity::material* material ) :
			id_( hash ), material_( material ), material_instance_id( material->get_instance_id() ) {};

		uint64_t get_id() const { return id_; }
		int32_t get_instance_id() const { return material_instance_id; }
		unity::material* get_material() const { return material_; }

		template <typename T>
		void bind_property( const shader_property& property, T* value ) {
			configured_properties_.add( configured_shader_property( property, value ) );
		}

		void update() {
			for ( auto& configured_property : configured_properties_ ) {
				if ( configured_property.property.type == shader_property_type::color ) {
					// Only update if value has changed
					if ( *configured_property.color != configured_property.previous_color ) {
						material_->set_color( configured_property.property.id, unity::color( *configured_property.color ) );
						configured_property.previous_color = *configured_property.color;
					}
				}
			}
		}

	private:
		// Hash for identifying instance
		uint64_t id_;
		unity::material* material_;
		// Used to set renderer materials with a single write
		int32_t material_instance_id;
		util::array<configured_shader_property, 8> configured_properties_;
	};

	material_collection() = default;
	material_collection( unity::shader * shader ) : shader_( shader ) {};

	instance* create_instance( uint64_t hash ) {
		// Sanity check
		if ( !shader_ )
			return nullptr;

		unity::material* material = unity::material::ctor( shader_ );
		if ( !is_valid_ptr( material ) )
			return nullptr;

		return instances_.add( instance( hash, material ) );
	}

	int32_t get_material_id( uint64_t hash ) {
		for ( const auto& instance : instances_ ) {
			if ( instance.get_id() == hash ) {
				return instance.get_instance_id();
			}
		}

		return -1;
	}

	int32_t get_material_id_at_index( int32_t index ) {
		return instances_[ index ].get_instance_id();
	}

	unity::material* get_material_at_index( int32_t index ) {
		return instances_[ index ].get_material();
	}

	void update() {
		for ( auto& instance : instances_ ) {
			instance.update();
		}
	}

private:
	unity::shader* shader_;
	util::array<instance, 8> instances_;
};

unity::shader* stencil_shader;
unity::shader* composite_shader;
unity::shader* blur_shader;

unity::material* composite_material;
unity::material* blur_material;

unity::command_buffer* command_buffer;

unity::render_texture* stencil_texture;
unity::render_texture* blur_texture;
unity::render_texture* ping_pong_texture;

int _MainTex;
int _BlurTex;
int _StencilTex;

material_collection glow_materials;

unity::shader* unlit_shader;

material_collection unlit_materials;

util::lazy_initializer<std::vector<std::pair<bool, rust::skinned_multi_mesh*>>> multi_mesh_cache;

bool glow_manager::init( unity::asset_bundle* asset_bundle ) {
	DESTROY_BEGIN

	stencil_shader = asset_bundle->load_asset<unity::shader>( S( L"Color.shader" ) );
	if ( !stencil_shader )
		return false;

	il2cpp_gchandle_new( stencil_shader, true );

	composite_shader = asset_bundle->load_asset<unity::shader>( S( L"Composite.shader" ) );
	if ( !composite_shader )
		return false;

	il2cpp_gchandle_new( composite_shader, true );

	blur_shader = asset_bundle->load_asset<unity::shader>( S( L"Blur.shader" ) );
	if ( !blur_shader )
		return false;

	il2cpp_gchandle_new( blur_shader, true );

	unlit_shader = asset_bundle->load_asset<unity::shader>( S( L"UnlitShader.shader" ) );
	if ( !unlit_shader )
		return false;

	il2cpp_gchandle_new( unlit_shader, true );

	composite_material = unity::material::ctor( composite_shader );
	if ( !composite_material )
		return false;

	blur_material = unity::material::ctor( blur_shader );
	if ( !blur_material )
		return false;

	command_buffer = unity::command_buffer::ctor();
	if ( !command_buffer )
		return false;

	il2cpp_gchandle_new( command_buffer, true );

	_MainTex = unity::shader::property_to_id( S( L"_MainTex" ) );
	_StencilTex = unity::shader::property_to_id( S( L"_StencilTex" ) );
	_BlurTex = unity::shader::property_to_id( S( L"_BlurTex" ) );

	shader_property color = shader_property( P( S( L"_Color" ) ), shader_property_type::color );
	shader_property visible_color = shader_property( P( S( L"_VisibleColor" ) ), shader_property_type::color );
	shader_property occluded_color = shader_property( P( S( L"_OccludedColor" ) ), shader_property_type::color );

	glow_materials = material_collection( stencil_shader );

	auto players_glow = glow_materials.create_instance( H( "players" ) );

	players_glow->bind_property( color, &player_visuals.glow_color );

	auto scientists_glow = glow_materials.create_instance( H( "scientists" ) );

	scientists_glow->bind_property( color, &scientist_visuals.glow_color );

	unlit_materials = material_collection( unlit_shader );

	auto players_unlit = unlit_materials.create_instance( H( "players" ) );

	players_unlit->bind_property( visible_color, &player_visuals.chams_visible_color );
	players_unlit->bind_property( occluded_color, &player_visuals.chams_occluded_color );

	auto scientists_unlit = unlit_materials.create_instance( H( "scientists" ) );

	scientists_unlit->bind_property( visible_color, &scientist_visuals.chams_visible_color );
	scientists_unlit->bind_property( occluded_color, &scientist_visuals.chams_occluded_color );

	auto held_item_unlit = unlit_materials.create_instance( H( "held_item" ) );

	held_item_unlit->bind_property( visible_color, &local_chams.held_item_visible_color );
	held_item_unlit->bind_property( occluded_color, &local_chams.held_item_occluded_color );

	auto hands_unlit = unlit_materials.create_instance( H( "hands" ) );

	hands_unlit->bind_property( visible_color, &local_chams.hands_visible_color );
	hands_unlit->bind_property( occluded_color, &local_chams.hands_occluded_color );

	multi_mesh_cache.construct();

	DESTROY_END

	return true;
}

void glow_manager::destroy() {
	multi_mesh_cache.destruct();
}

void glow_manager::add_player( rust::base_player* player ) {
	rust::player_model* player_model = player->player_model;
	if ( !is_valid_ptr( player_model ) )
		return;

	rust::skinned_multi_mesh* multi_mesh = player_model->multi_mesh;
	if ( !is_valid_ptr( multi_mesh ) )
		return;

	multi_mesh_cache.get().push_back( { player->is<rust::base_player>(), multi_mesh } );
}

void glow_manager::remove_player( rust::base_player* player ) {
	rust::player_model* player_model = player->player_model;
	if ( !is_valid_ptr( player_model ) )
		return;

	rust::skinned_multi_mesh* multi_mesh = player_model->multi_mesh;
	if ( !is_valid_ptr( multi_mesh ) )
		return;

	std::vector<std::pair<bool, rust::skinned_multi_mesh*>>& multi_meshes = multi_mesh_cache.get();

	auto it = std::find_if( multi_meshes.begin(), multi_meshes.end(), [&]( const auto& pair ) { return pair.second == multi_mesh; } );
	if ( it == multi_meshes.end() )
		return;

	multi_meshes.erase( it );
}

void glow_manager::invalidate_cache() {
	multi_mesh_cache.get().clear();
}

void glow_manager::on_render_image( unity::render_texture* src, unity::render_texture* dest ) {
	// Update material properties
	glow_materials.update();
	unlit_materials.update();

	bool run_glow = player_visuals.glow || scientist_visuals.glow;

	if ( run_glow ) {
		stencil_texture = unity::render_texture::get_temporary( screen_width, screen_height, 0 );

		const vector2i half_resolution = vector2i( screen_width / 2, screen_height / 2 );

		blur_texture = unity::render_texture::get_temporary( half_resolution.x, half_resolution.y, 0 );
		ping_pong_texture = unity::render_texture::get_temporary( half_resolution.x, half_resolution.y, 0 );

		command_buffer->set_render_target( unity::render_target_identifier::ctor( stencil_texture ) );
		command_buffer->clear_render_target( true, true, unity::color() );
	}

	bool run_chams = player_visuals.chams || scientist_visuals.chams;

	if ( run_glow || run_chams ) {
		for ( auto& [ is_player, multi_mesh ] : multi_mesh_cache.get() ) {
			sys::list<unity::renderer*>* renderers_list = multi_mesh->renderers;
			if ( !is_valid_ptr( renderers_list ) || !is_valid_ptr( renderers_list->items ) )
				continue;

			sys::array<unity::renderer*>* renderers = renderers_list->items;
			if ( !is_valid_ptr( renderers ) )
				continue;

			for ( size_t i = 0; i < renderers->size; i++ ) {
				unity::renderer* renderer = renderers->buffer[ i ];
				if ( !is_valid_ptr( renderer ) )
					continue;

				unity::internals::renderer* native_renderer = renderer->get_native_renderer();
				if ( !is_valid_ptr( native_renderer ) )
					continue;

				if ( ( is_player && player_visuals.chams ) || ( !is_player && scientist_visuals.chams ) ) {
					auto materials = native_renderer->materials;

					if ( is_valid_ptr( materials.buffer ) ) {
						int32_t material_id = is_player ?
							unlit_materials.get_material_id_at_index( materials_index::players ) : unlit_materials.get_material_id_at_index( materials_index::scientists );

						for ( size_t i = 0; i < materials.size; i++ ) {
							materials.buffer[ i ].instance_id = material_id;
						}
					}
				}

				if ( !native_renderer->is_visible_in_scene() )
					continue;

				if ( ( is_player && player_visuals.glow ) || ( !is_player && scientist_visuals.glow ) ) {
					unity::material* material = is_player ?
						glow_materials.get_material_at_index( materials_index::players ) : glow_materials.get_material_at_index( materials_index::scientists );

					command_buffer->draw_renderer( renderer, material );
				}
			}
		}
	}

	if ( local_chams.held_item || local_chams.hands ) {
		rust::base_view_model* active_model = rust::base_view_model::get_active_model();

		if ( is_valid_ptr( active_model ) ) {
			// This must be disabled for viewmodel chams to work
			active_model->use_view_model_camera = false;

			unity::game_object* game_object = active_model->get_game_object();

			if ( is_valid_ptr( game_object ) ) {
				sys::array<unity::renderer*>* renderers = game_object->get_components_in_children<unity::renderer>();

				if ( is_valid_ptr( renderers ) ) {
					for ( int32_t i = 0; i < renderers->size; i++ ) {
						unity::renderer* renderer = renderers->buffer[ i ];
						if ( !is_valid_ptr( renderer ) )
							continue;

						sys::string* name = renderer->get_name();
						if ( !is_valid_ptr( name ) )
							continue;

						bool hands = util::hash_w( name->buffer ) == H( "hand_mesh" );

						if ( ( hands && !local_chams.hands ) || ( !hands && !local_chams.held_item ) )
							continue;

						unity::internals::renderer* native_renderer = renderer->get_native_renderer();
						if ( !is_valid_ptr( native_renderer ) )
							continue;

						auto materials = native_renderer->materials;
						if ( !is_valid_ptr( materials.buffer ) )
							continue;

						int32_t instance_id = unlit_materials.get_material_id_at_index( hands ? materials_index::hands : materials_index::held_item );

						for ( size_t i = 0; i < materials.size; i++ ) {
							materials.buffer[ i ].instance_id = instance_id;
						}

						command_buffer->draw_renderer( renderer, glow_materials.get_material_at_index( materials_index::players ) );
					}
				}
			}
		}
	}

	if ( run_glow ) {
		unity::graphics::execute_command_buffer( command_buffer );

		unity::graphics::blit( stencil_texture, blur_texture, blur_material );

		for ( int32_t i = 0; i < 3; i++ ) {
			unity::graphics::blit( blur_texture, ping_pong_texture, blur_material );
			unity::graphics::blit( ping_pong_texture, blur_texture, blur_material );
		}

		composite_material->set_texture( _MainTex, src );
		composite_material->set_texture( _StencilTex, stencil_texture );
		composite_material->set_texture( _BlurTex, blur_texture );

		unity::graphics::blit( src, dest, composite_material );

		unity::render_texture::release_temporary( stencil_texture );
		unity::render_texture::release_temporary( blur_texture );
		unity::render_texture::release_temporary( ping_pong_texture );

		command_buffer->clear();
	}
}
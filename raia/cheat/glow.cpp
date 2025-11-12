#include "glow.h"
#include "util.h"

#include "sdk/sdk.h"

#include "vars.h"

#include <vector>

unity::shader* stencil_shader;
unity::shader* composite_shader;
unity::shader* blur_shader;

unity::material* stencil_material;
unity::material* composite_material;
unity::material* blur_material;

unity::command_buffer* command_buffer;

unity::render_texture* stencil_texture;
unity::render_texture* blur_texture;

int _BlurScale;
int _MainTex;
int _StencilTex;
int _BlurTex;
int _OutlineScale;
int _OutlineColor;

int _VisibleColor;
int _OccludedColor;

enum material_index {
	players,
	scientists,
	held_item,
	hands,
	max
};

struct configured_material {
	unity::material* material;
	int32_t material_id;
	uint32_t* colors[ 2 ];
};

using configured_materials = std::array<configured_material, material_index::max>;

configured_materials create_material_collection_from_shader( unity::shader* shader ) {
	configured_materials collection;

	for ( int32_t i = 0; i < material_index::max; i++ ) {
		collection[ i ].material = unity::material::ctor( shader );
		if ( !is_valid_ptr( collection[ i ].material ) )
			continue;

		collection[ i ].material_id = collection[ i ].material->get_instance_id();
	}

	return collection;
}

unity::shader* unlit_shader;

configured_materials unlit_materials;

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

	stencil_material = unity::material::ctor( stencil_shader );
	if ( !stencil_material )
		return false;

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

	_BlurScale = unity::shader::property_to_id( S( L"_BlurScale" ) );
	_MainTex = unity::shader::property_to_id( S( L"_MainTex" ) );
	_StencilTex = unity::shader::property_to_id( S( L"_StencilTex" ) );
	_BlurTex = unity::shader::property_to_id( S( L"_BlurTex" ) );
	_OutlineScale = unity::shader::property_to_id( S( L"_OutlineScale" ) );
	_OutlineColor = unity::shader::property_to_id( S( L"_OutlineColor" ) );

	unlit_shader = asset_bundle->load_asset<unity::shader>( S( L"UnlitShader.shader" ) );
	if ( !unlit_shader )
		return false;

	il2cpp_gchandle_new( unlit_shader, true );

	unlit_materials = create_material_collection_from_shader( unlit_shader );

	unlit_materials[ material_index::players ].colors[ 0 ] = &player_visuals.chams_visible_color.value;
	unlit_materials[ material_index::players ].colors[ 1 ] = &player_visuals.chams_occluded_color.value;
	unlit_materials[ material_index::scientists ].colors[ 0 ] = &scientist_visuals.chams_visible_color.value;
	unlit_materials[ material_index::scientists ].colors[ 1 ] = &scientist_visuals.chams_occluded_color.value;
	unlit_materials[ material_index::held_item ].colors[ 0 ] = &local_chams.held_item_visible_color.value;
	unlit_materials[ material_index::held_item ].colors[ 1 ] = &local_chams.held_item_occluded_color.value;
	unlit_materials[ material_index::hands ].colors[ 0 ] = &local_chams.hands_visible_color.value;
	unlit_materials[ material_index::hands ].colors[ 1 ] = &local_chams.hands_occluded_color.value;

	_VisibleColor = unity::shader::property_to_id( S( L"_VisibleColor" ) );
	_OccludedColor = unity::shader::property_to_id( S( L"_OccludedColor" ) );

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

void update_chams() {
	for ( const auto& material : unlit_materials ) {
		material.material->set_color( _VisibleColor, unity::color( *material.colors[ 0 ] ) );
		material.material->set_color( _OccludedColor, unity::color( *material.colors[ 1 ] ) );
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

						for ( size_t i = 0; i < materials.size; i++ ) {
							materials.buffer[ i ].instance_id = hands ?
								unlit_materials[ material_index::hands ].material_id : unlit_materials[ material_index::held_item ].material_id;
						}
					}
				}
			}
		}
	}

	for ( auto& [ is_player, multi_mesh ] : multi_mesh_cache.get() ) {
		if ( ( is_player && !player_visuals.chams ) || ( !is_player && !scientist_visuals.chams ) )
			continue;

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

			auto materials = native_renderer->materials;
			if ( !is_valid_ptr( materials.buffer ) )
				continue;

			const configured_material& configured_material = is_player ? unlit_materials[ material_index::players ] : unlit_materials[ material_index::scientists ];

			for ( size_t i = 0; i < materials.size; i++ ) {
				materials.buffer[ i ].instance_id = configured_material.material_id;
			}
		}
	}
}

void glow_manager::update() {
	update_chams();
}

void glow_manager::invalidate_cache() {
	multi_mesh_cache.get().clear();
}

void render_stencil() {
	stencil_texture = unity::render_texture::get_temporary( screen_width, screen_height, 0 );

	command_buffer->set_render_target( unity::render_target_identifier::ctor( stencil_texture ) );
	command_buffer->clear_render_target( true, true, unity::color() );

	for ( auto& [ _, multi_mesh ] : multi_mesh_cache.get() ) {
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

			// We only need to check if the renderer is visible
			if ( !native_renderer->is_visible_in_scene() )
				continue;

			command_buffer->draw_renderer( renderer, stencil_material );
		}
	}
	
	unity::graphics::execute_command_buffer( command_buffer );
}

void render_blur() {
	vector2i blur_tex_dims = vector2i( screen_width / 2, screen_height / 2 );

	blur_texture = unity::render_texture::get_temporary( blur_tex_dims.x, blur_tex_dims.y, 0 );
	unity::render_texture* temp = unity::render_texture::get_temporary( blur_tex_dims.x, blur_tex_dims.y, 0 );
	blur_material->set_float( _BlurScale, 0.75f );

	unity::graphics::blit( stencil_texture, blur_texture, blur_material );

	for ( int32_t i = 0; i < 3; i++ ) {
		unity::graphics::blit( blur_texture, temp, blur_material );
		unity::graphics::blit( temp, blur_texture, blur_material );
	}

	unity::render_texture::release_temporary( temp );
}

void render_composite( unity::render_texture* src, unity::render_texture* dest ) {
	composite_material->set_texture( _MainTex, src );
	composite_material->set_texture( _StencilTex, stencil_texture );
	composite_material->set_texture( _BlurTex, blur_texture );
	composite_material->set_float( _OutlineScale, 0.5f );
	composite_material->set_color( _OutlineColor, unity::color( glow_outline_color ) );

	unity::graphics::blit( src, dest, composite_material );

	unity::render_texture::release_temporary( stencil_texture );
	unity::render_texture::release_temporary( blur_texture );

	stencil_texture = nullptr;
	blur_texture = nullptr;
}

void glow_manager::on_render_image_hook( unity::render_texture* src, unity::render_texture* dest ) {
	if ( glow && multi_mesh_cache.get().size() > 0 ) {
		render_stencil();
		render_blur();
		render_composite( src, dest );

		command_buffer->clear();
	}
}
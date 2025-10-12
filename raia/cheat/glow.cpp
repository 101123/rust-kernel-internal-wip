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

unity::shader* gui_text_shader;

unity::material* gui_text_material;

int gui_text_material_instance_id;

int _Color;

util::lazy_initializer<std::vector<rust::skinned_multi_mesh*>> multi_mesh_cache;

bool glow_manager::init( unity::asset_bundle* asset_bundle ) {
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

	gui_text_shader = unity::shader::find( S( L"GUI/Text Shader" ) );
	if ( !gui_text_shader )
		return false;

	gui_text_material = unity::material::ctor( gui_text_shader );
	if ( !gui_text_material )
		return false;

	gui_text_material_instance_id = gui_text_material->get_instance_id();

	_Color = unity::shader::property_to_id( S( L"_Color" ) );

	multi_mesh_cache.construct();

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

	multi_mesh_cache.get().push_back( multi_mesh );
}

void glow_manager::remove_player( rust::base_player* player ) {
	rust::player_model* player_model = player->player_model;
	if ( !is_valid_ptr( player_model ) )
		return;

	rust::skinned_multi_mesh* multi_mesh = player_model->multi_mesh;
	if ( !is_valid_ptr( multi_mesh ) )
		return;

	std::vector<rust::skinned_multi_mesh*>& multi_meshes = multi_mesh_cache.get();

	auto it = std::find( multi_meshes.begin(), multi_meshes.end(), multi_mesh );
	if ( it == multi_meshes.end() )
		return;

	multi_meshes.erase( it );
}

// TODO: update_chams and render_stencil run the same code for the most part so it can probably be made into a function
void update_chams() {
	gui_text_material->set_color( _Color, unity::color( chams_color ) );

	for ( rust::skinned_multi_mesh* multi_mesh : multi_mesh_cache.get() ) {
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

			for ( size_t i = 0; i < materials.size; i++ ) {
				materials.buffer[ i ].instance_id = gui_text_material_instance_id;
			}
		}
	}
}

void glow_manager::update() {
	if ( chams ) {
		update_chams();
	}
}

void glow_manager::invalidate_cache() {
	multi_mesh_cache.get().clear();
}

void render_stencil() {
	stencil_texture = unity::render_texture::get_temporary( screen_width, screen_height, 0 );

	command_buffer->set_render_target( unity::render_target_identifier::ctor( stencil_texture ) );
	command_buffer->clear_render_target( true, true, unity::color( 0.f, 0.f, 0.f, 0.f ) );

	for ( rust::skinned_multi_mesh* multi_mesh : multi_mesh_cache.get() ) {
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
	blur_texture = unity::render_texture::get_temporary( screen_width, screen_height, 0 );
	unity::render_texture* temp = unity::render_texture::get_temporary( screen_width, screen_height, 0 );
	blur_material->set_float( _BlurScale, glow_blur_scale );

	unity::graphics::blit( stencil_texture, blur_texture, blur_material );
	unity::graphics::blit( blur_texture, temp, blur_material );
	unity::graphics::blit( temp, blur_texture, blur_material );

	unity::render_texture::release_temporary( temp );
}

void render_composite( unity::render_texture* src, unity::render_texture* dest ) {
	composite_material->set_texture( _MainTex, src );
	composite_material->set_texture( _StencilTex, stencil_texture );
	composite_material->set_texture( _BlurTex, blur_texture );
	composite_material->set_float( _OutlineScale, glow_outline_scale );
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
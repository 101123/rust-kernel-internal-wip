#include "render.h"

#include "cheat/sdk/sdk.h"
#include "cheat/entities.h"

#include "renderer.h"
#include "gui.h"

Matrix4x4 view_matrix;
Vector3 camera_position;

struct w2s_result {
	bool success;
	Vector2 screen;
};

bool w2s( const Vector3& world, Vector2& screen ) {
	float w = Vector3::dot( Vector3( view_matrix[ 3 ], view_matrix[ 7 ], view_matrix[ 11 ] ), world ) + view_matrix[ 15 ];
	if ( w < 0.098f )
		return false;

	screen = Vector2(
		( 2560.f * 0.5f ) * ( 1.f + ( Vector3::dot( Vector3( view_matrix[ 0 ], view_matrix[ 4 ], view_matrix[ 8 ] ), world ) + view_matrix[ 12 ] ) / w ),
		( 1440.f * 0.5f ) * ( 1.f - ( Vector3::dot( Vector3( view_matrix[ 1 ], view_matrix[ 5 ], view_matrix[ 9 ] ), world ) + view_matrix[ 13 ] ) / w )
	) + Vector2( 0.f, 0.f );

	return true;
}

struct Bounds {
	float left = FLT_MAX;
	float right = FLT_MIN;
	float top = FLT_MAX;
	float bottom = FLT_MIN;
};

bool get_player_bounds( Bounds& bounds, const w2s_result* w2s, size_t count, float distance ) {
	for ( size_t i = 0; i < count; i++ ) {
		if ( !w2s[ i ].success )
			continue;

		const Vector2& position = w2s[ i ].screen;

		if ( position.x < bounds.left )
			bounds.left = position.x;

		if ( position.x > bounds.right )
			bounds.right = position.x;

		if ( position.y < bounds.top )
			bounds.top = position.y;

		if ( position.y > bounds.bottom )
			bounds.bottom = position.y;
	}

	if ( bounds.left == FLT_MAX )
		return false;

	if ( bounds.right == FLT_MIN )
		return false;

	if ( bounds.top == FLT_MAX )
		return false;

	if ( bounds.bottom == FLT_MIN )
		return false;

	float padding = ( 1.f / distance ) * 75.f;

	bounds.left = floorf( bounds.left - max( padding, 2.f ) );
	bounds.right = floorf( bounds.right + max( padding, 4.f ) );
	bounds.top = floorf( bounds.top - max( padding, 2.f ) );
	bounds.bottom = floorf( bounds.bottom + max( padding, 4.f ) );

	if ( bounds.top < 0.f && ( bounds.bottom <= max( padding, 4.f ) || bounds.bottom > 1440.f ) )
		return false;

	if ( bounds.left < 0.f && bounds.right <= max( padding, 4.f ) )
		return false;

	return true;
}

int bone_connections[][ 2 ] = {
	{ 1, 0 }, { 0, 3 }, { 3, 2 },
	{ 3, 4 }, { 4, 6 }, { 6, 8 },
	{ 8, 10 }, { 2, 12 }, { 12, 14 },
	{ 14, 16 }, { 3, 5 }, { 5, 7 },
	{ 7, 9 }, { 9, 11 }, { 2, 13 },
	{ 13, 15 }, { 15, 17 }
};

// Actually draws both players and scientists
void draw_players( const entity_vector<rust::base_player*, cached_player>& players ) {
	for ( const auto& [ player, cached_player ] : players ) {
		const cvar_player_visuals& visuals = 
			cached_player.scientist ? scientist_visuals : player_visuals;

		if ( !visuals.enabled )
			continue;

		const cached_bone_data& bone_data = cached_player.bone_data;

		float distance = Vector3::distance( camera_position, bone_data.positions[ 17 ] );
		if ( distance > visuals.maximum_distance )
			continue;

		w2s_result w2s_results[ _countof( bone_data.positions ) ];

		for ( size_t i = 0; i < _countof( bone_data.positions ); i++ ) {
			w2s_results[ i ].success = w2s( bone_data.positions[ i ], w2s_results[ i ].screen );
		}

		// Preserve actual head result
		w2s_result head_w2s = w2s_results[ 1 ];

		// Get the head result for bounds, where we add a vertical offset so that the bounds are above the players head
		w2s_results[ 1 ].success = w2s( bone_data.positions[ 1 ] + Vector3( 0.f, 0.105f, 0.f ), w2s_results[ 1 ].screen );

		// Implicit ctor called on bounds
		Bounds bounds;
		if ( !get_player_bounds( bounds, w2s_results, _countof( bone_data.positions ), distance ) )
			continue;
		
		// Restore actual head result
		w2s_results[ 1 ] = head_w2s;

		float half = ( bounds.right - bounds.left ) / 2.f;

		if ( visuals.box ) {
			renderer::draw_rect( bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, 3.f, COL32( 0, 0, 0, 130 ) );
			renderer::draw_rect( bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, 1.f, visuals.box_color );
		}

		if ( visuals.skeleton ) {
			for ( size_t j = 0; j < _countof( bone_connections ); j++ ) {
				const w2s_result& a_w2s = w2s_results[ bone_connections[ j ][ 0 ] ];
				const w2s_result& b_w2s = w2s_results[ bone_connections[ j ][ 1 ] ];
				if ( !a_w2s.success || !b_w2s.success )
					continue;

				const Vector2& a_pos = a_w2s.screen;
				const Vector2& b_pos = b_w2s.screen;

				renderer::draw_line( a_pos.x, a_pos.y, b_pos.x, b_pos.y, 1.f, visuals.skeleton_color );
			}
		}

		if ( visuals.name ) {
			renderer::draw_text( bounds.left + half, bounds.top - 14.f, fonts::verdana, text_flags::centered | text_flags::drop_shadow, visuals.name_color, "Fredrechster");
		}

		float offset = 0.f;

		if ( visuals.held_item ) {
			if ( cached_player.active_item != -1 ) {
				renderer::draw_text( bounds.left + half, bounds.bottom + 1.f, fonts::small_fonts, text_flags::centered, visuals.held_item_color, cached_player.belt_items[ cached_player.active_item ].name );
				offset += 8.f + 1.f;
			}
		}

		if ( visuals.distance ) {
			char buffer[ 16 ] = {};
			snprintf( buffer, sizeof( buffer ), "%dm", ( int )distance );
			renderer::draw_text( bounds.left + half, bounds.bottom + 1.f + offset, fonts::small_fonts, text_flags::centered, visuals.distance_color, buffer );
		}
	}
}

void draw_esp() {
	auto static_fields = rust::main_camera::s_static_fields;
	if ( !is_valid_ptr( static_fields ) )
		return;

	unity::camera* main_camera = static_fields->main_camera;
	if ( !is_valid_ptr( main_camera ) )
		return;

	unity::internals::camera* native_camera = main_camera->get_native_camera();
	if ( !is_valid_ptr( native_camera ) )
		return;

	view_matrix = native_camera->culling_matrix;
	camera_position = native_camera->last_position;

	util::scoped_spinlock lock( &entity_manager::cache_lock );

	entity_collection entities = entity_manager::get_entities();

	for ( const auto& [ entity, cached_entity ] : entities.resources ) {
		Vector2 screen;
		if ( !w2s( cached_entity.m_position, screen ) )
			continue;

		float distance = Vector3::distance( camera_position, cached_entity.m_position );

		char buffer[ 16 ] = {};
		snprintf( buffer, sizeof( buffer ), "%dM\n", static_cast< int >( distance ) );

		renderer::draw_text( screen.x, screen.y, fonts::small_fonts, text_flags::centered, cached_entity.m_visual->color, cached_entity.m_visual->display_name );
		renderer::draw_text( screen.x, screen.y + 8.f, fonts::small_fonts, text_flags::centered, COL32_WHITE, buffer );
	}

	if ( player_visuals.enabled || scientist_visuals.enabled ) {
		draw_players( entities.players );
	}
}

bool renderer_init;

void on_render( IDXGISwapChain* swap_chain ) {
	if ( !renderer_init ) {
		if ( !( renderer_init = renderer::init( swap_chain ) ) ) {
			return;
		}
	}

	renderer::begin_frame();

	renderer::draw_text( 8.f, 5.f, fonts::small_fonts, text_flags::none, COL32( 110, 183, 212, 255 ), "sentian" );
	renderer::draw_text( 38.f, 5.f, fonts::small_fonts, text_flags::none, COL32( 255, 255, 255, 255 ), ".gg" );

	draw_esp();

	if ( gui::open ) {
		gui::run();
	}

	renderer::end_frame();
}
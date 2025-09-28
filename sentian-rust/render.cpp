#include "render.h"

#include "cheat/sdk/sdk.h"
#include "cheat/entities.h"

#include "renderer.h"
#include "gui.h"

#include <cstdarg>

uint8_t format_buffer[ 1024 ];

const char* format_string( const char* format, ... ) {
	char* buffer = ( char* )format_buffer;

	va_list args;
	va_start( args, format );
	vsprintf( buffer, format, args );
	va_end( args );

	return buffer;
}

const wchar_t* format_string_w( const wchar_t* format, ... ) {
	wchar_t* buffer = ( wchar_t* )format_buffer;
	size_t count = sizeof( format_buffer ) / sizeof( wchar_t );

	va_list args;
	va_start( args, format );
	vswprintf( buffer, format, args );
	va_end( args );

	return buffer;
}

class visual_builder {
public:
	visual_builder() = delete;
	visual_builder( vector2 position ) : position_( position ), vertical_offset_( 0.f ) {};

	visual_builder& set_font( fonts font ) {
		font_ = font;
		return *this;
	}

	visual_builder& set_vertical_spacing( float vertical_spacing ) {
		vertical_spacing_ = vertical_spacing;
		return *this;
	}

	visual_builder& set_flags( uint32_t flags ) {
		flags_ = flags;
		return *this;
	}

	visual_builder& draw_text( const char* text, uint32_t color ) {
		renderer::draw_text( position_.x, position_.y + vertical_offset_, font_, flags_, color, text );
		vertical_offset_ += vertical_spacing_;
		return *this;
	}

	visual_builder& draw_text( const wchar_t* text, uint32_t color ) {
		renderer::draw_text( position_.x, position_.y + vertical_offset_, font_, flags_, color, text );
		vertical_offset_ += vertical_spacing_;
		return *this;
	}

private:
	vector2 position_;
	float vertical_spacing_;
	float vertical_offset_;
	fonts font_;
	uint32_t flags_;
};

matrix4x4 view_matrix;
vector3 camera_position;

struct w2s_result {
	bool success;
	vector2 screen;
};

bool w2s( const vector3& world, vector2& screen ) {
	float w = vector3::dot( vector3( view_matrix[ 3 ], view_matrix[ 7 ], view_matrix[ 11 ] ), world ) + view_matrix[ 15 ];
	if ( w < 0.098f )
		return false;

	screen = vector2(
		( ( float )screen_width * 0.5f ) * ( 1.f + ( vector3::dot( vector3( view_matrix[ 0 ], view_matrix[ 4 ], view_matrix[ 8 ] ), world ) + view_matrix[ 12 ] ) / w ),
		( ( float )screen_height * 0.5f ) * ( 1.f - ( vector3::dot( vector3( view_matrix[ 1 ], view_matrix[ 5 ], view_matrix[ 9 ] ), world ) + view_matrix[ 13 ] ) / w )
	) + vector2( 0.f, 0.f );

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

		const vector2& position = w2s[ i ].screen;

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

struct visual_item_info {
	int item_id;
	char codepoint;
};

visual_item_info visual_items[] = {
	{ 1545779598, 'a' }, // rifle.ak
	{ -1335497659, 'a' }, // rifle.ak.ice
	{ 472505338, 'a' }, // rifle.ak.med
	{ -139037392, 'a' }, // rifle.ak.diver
	{ 2054929933, 'a' }, // rifle.ak.jungle
	{ -880412831, 'b' }, // blunderbuss
	{ 1588298435, 'c' }, // rifle.bolt
	{ 884424049, 'd' }, // bow.compound
	{ 1965232394, 'e' }, // crossbow
	{ -765183617, 'f' }, // shotgun.double
	{ -75944661, 'g' }, // pistol.eoka
	{ 1914691295, 'h' }, // pistol.prototype17
	{ -1123473824, 'i' }, // multiplegrenadelauncher
	{ -92315244, 'j' }, // revolver.hc
	{ -1214542497, 'k' }, // hmlmg
	{ -218009552, 'l' }, // homingmissile.launcher
	{ 2040726127, 'm' }, // knife.combat
	{ -778367295, 'n' }, // rifle.l96
	{ -1812555177, 'o' }, // rifle.lr300
	{ 678698219, 'p' }, // shotgun.m4
	{ 1673224590, 'q' }, // pistol.semiauto.a.m15
	{ 28201841, 'r' }, // rifle.m39
	{ -852563019, 's' }, // pistol.m92
	{ -2069578888, 't' }, // lmg.m249
	{ 935606207, 'u' }, // minigun
	{ 1318558775, 'v' }, // smg.mp5
	{ 1953903201, 'w' }, // pistol.nailgun
	{ -1367281941, 'x' }, // shotgun.waterpipe
	{ 1373971859, 'y' }, // pistol.python
	{ 649912614, 'z' }, // pistol.revolver
	{ 442886268, 'A' }, // rocket.launcher,
	{ 795371088, 'B' }, // shotgun.pump,
	{ 818877484, 'C' }, // pistol.semiauto,
	{ -904863145, 'D' }, // rifle.semiauto
	{ -348232115, 'E' }, // rifle.sks
	{ 1796682209, 'F' }, // smg.2
	{ -41440462, 'G' }, // shotgun.spas12
	{ 2083256995, 'H' }, // t1_smg
};

void draw_players( const entity_vector<rust::base_player*, cached_player>& players ) {
	for ( const auto& [ player, cached_player ] : players ) {
		const cvar_player_visuals& visuals = 
			cached_player.scientist ? scientist_visuals : player_visuals;

		if ( !visuals.enabled )
			continue;

		const cached_bone_data& bone_data = cached_player.bone_data;

		float distance = vector3::distance( camera_position, bone_data.positions[ 17 ] );
		if ( distance > visuals.maximum_distance )
			continue;

		w2s_result w2s_results[ _countof( bone_data.positions ) ];

		for ( size_t i = 0; i < _countof( bone_data.positions ); i++ ) {
			w2s_results[ i ].success = w2s( bone_data.positions[ i ], w2s_results[ i ].screen );
		}

		// Preserve actual head result
		w2s_result head_w2s = w2s_results[ 1 ];

		// Get the head result for bounds, where we add a vertical offset so that the bounds are above the players head
		w2s_results[ 1 ].success = w2s( bone_data.positions[ 1 ] + vector3( 0.f, 0.105f, 0.f ), w2s_results[ 1 ].screen );

		// Implicit ctor called on bounds
		Bounds bounds;
		if ( !get_player_bounds( bounds, w2s_results, _countof( bone_data.positions ), distance ) )
			continue;
		
		// Restore actual head result
		w2s_results[ 1 ] = head_w2s;

		float half = ( bounds.right - bounds.left ) / 2.f;

		if ( visuals.bounding_box ) {
			renderer::draw_rect( bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, 3.f, COL32( 0, 0, 0, 130 ) );
			renderer::draw_rect( bounds.left, bounds.top, bounds.right - bounds.left, bounds.bottom - bounds.top, 1.f, visuals.bounding_box_color );
		}

		if ( visuals.skeleton ) {
			for ( size_t j = 0; j < _countof( bone_connections ); j++ ) {
				const w2s_result& a_w2s = w2s_results[ bone_connections[ j ][ 0 ] ];
				const w2s_result& b_w2s = w2s_results[ bone_connections[ j ][ 1 ] ];
				if ( !a_w2s.success || !b_w2s.success )
					continue;

				const vector2& a_pos = a_w2s.screen;
				const vector2& b_pos = b_w2s.screen;

				renderer::draw_line( a_pos.x, a_pos.y, b_pos.x, b_pos.y, 1.f, visuals.skeleton_color );
			}
		}

		if ( visuals.name ) {
			renderer::draw_text( bounds.left + half, bounds.top - 11.f, fonts::verdana, text_flags::centered | text_flags::drop_shadow, visuals.name_color, cached_player.name );
		}

		float offset = 0.f;

		if ( visuals.held_item && cached_player.active_item_idx != -1 ) {
			if ( visuals.held_item_text ) {
				renderer::draw_text( bounds.left + half, bounds.bottom + offset + 1.f, fonts::small_fonts, text_flags::centered, visuals.held_item_color, cached_player.belt_items[ cached_player.active_item_idx ].name );
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

void draw_entities( const entity_vector<rust::base_entity*, cached_entity>& entities ) {
	for ( const auto& [ entity, cached_entity ] : entities ) {
		cvar_visual* visuals = cached_entity.visual;
		if ( !visuals->enabled )
			continue;

		float distance = vector3::distance( camera_position, cached_entity.position );
		if ( distance > visuals->maximum_distance )
			continue;

		vector2 screen;
		if ( !w2s( cached_entity.position, screen ) )
			continue;

		visual_builder( screen )
			.set_font( fonts::small_fonts )
			.set_vertical_spacing( 8.f )
			.set_flags( text_flags::centered )
			.draw_text( visuals->display_name, visuals->color )
			.draw_text( format_string( "%dm", ( int )distance ), COL32_WHITE );
	}
}

void draw_combat_entities( const entity_vector<rust::base_combat_entity*, cached_combat_entity>& combat_entities ) {
	for ( const auto& [ combat_entity, cached_combat_entity ] : combat_entities ) {
		if ( cached_combat_entity.lifestate != rust::lifestate::alive )
			continue;

		cvar_visual* visuals = cached_combat_entity.visual;
		if ( !visuals->enabled )
			continue;

		float distance = vector3::distance( camera_position, cached_combat_entity.position );
		if ( distance > visuals->maximum_distance )
			continue;

		vector2 screen;
		if ( !w2s( cached_combat_entity.position, screen ) )
			continue;

		float x = TRUNC( screen.x );
		float y = TRUNC( screen.y );

		float width = renderer::calc_text_size( fonts::small_fonts, visuals->display_name ).x + 1.f;
		float half = ceilf( width / 2.f );

		renderer::draw_text( x - half, y, fonts::small_fonts, text_flags::none, visuals->color, visuals->display_name );

		float health_width = ( cached_combat_entity.health / cached_combat_entity.max_health ) * ( width - 2.f );

		renderer::draw_filled_rect( x - half, y + 10.f, width, 4.f, COL32_BLACK );
		renderer::draw_filled_rect( x - half + 1.f, y + 11.f, health_width, 2.f, COL32( 120, 225, 80, 255 ) );


		//float x = ( float )( int )( screen.x );
		//float y = 

		//float width = renderer::calc_text_size( fonts::small_fonts, visuals->display_name ).x;
		//float half = ceilf( width / 2.f );

		//float rx = ( float )( int )( screen.x );
		//float ry = ( float )( int )( screen.y );

		//renderer::draw_text( rx - half, ry, fonts::small_fonts, text_flags::none, visuals->color, visuals->display_name );

		//ry += 10.f;

		//renderer::draw_filled_rect( rx - half, ry, width, 4.f, COL32( 120, 225, 80, 255 ) );

		//ry += 10f.;

		////float nig = ( cached_combat_entity.health / cached_combat_entity.max_health ) * width;

		////renderer::draw_filled_rect( rx + 1.f, ry + 1.f, nig, 2.f, COL32( 120, 225, 80, 255 ) );

		//char buffer[ 64 ] = {};
		//snprintf( buffer, sizeof( buffer ), "%.2f %.2f %.2f %.2f\n", rx, ry, width, half );

		//renderer::draw_text( screen.x, screen.y + 3.f, fonts::small_fonts, text_flags::centered, COL32_WHITE, buffer );
	}
}

cvar_visual* dropped_item_visuals[] = {
	&dropped_weapon, &dropped_construction, &dropped_items,
	&dropped_resources, &dropped_attire, &dropped_tool,
	&dropped_medical, &dropped_food, &dropped_ammunition,
	&dropped_traps, &dropped_misc, nullptr /* All */,
	nullptr /* Common */, &dropped_component, nullptr /* Search */,
	nullptr /* Favourite */, &dropped_electrical, &dropped_fun
};

void draw_dropped_items( const entity_vector<rust::world_item*, cached_dropped_item>& dropped_items ) {
	for ( const auto& [ dropped_item, cached_dropped_item ] : dropped_items ) {
		if ( cached_dropped_item.category < 0 || cached_dropped_item.category >= _countof( dropped_item_visuals ) )
			continue;

		cvar_visual* visuals = dropped_item_visuals[ cached_dropped_item.category ];
		if ( !visuals )
			continue;

		if ( !visuals->enabled )
			continue;

		float distance = vector3::distance( camera_position, cached_dropped_item.position );
		if ( distance > visuals->maximum_distance )
			continue;

		vector2 screen;
		if ( !w2s( cached_dropped_item.position, screen ) )
			continue;

		visual_builder( screen )
			.set_font( fonts::small_fonts )
			.set_vertical_spacing( 8.f )
			.set_flags( text_flags::centered )
			.draw_text( cached_dropped_item.amount > 1 ?
				format_string_w( L"%ws (%dx)", cached_dropped_item.name, cached_dropped_item.amount ) :
				format_string_w( L"%ws", cached_dropped_item.name ), 
				visuals->color )
			.draw_text( format_string( "%dm", ( int )distance ), COL32_WHITE );
	}
}

void draw_esp() {
	auto static_fields = rust::main_camera::static_fields_;
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

	entity_collection entity_collection = entity_manager::get_entities();

	visual_builder( vector2( 100.f, 100.f ) )
		.set_font( fonts::verdana )
		.set_vertical_spacing( 12.f )
		.set_flags( text_flags::none )
		.draw_text( format_string( "Velocity: %.2f, Drag: %.2f, Gravity Modifier: %.2f, Initial Distance: %.2f, Projectile Velocity Scale: %.2f, Aim Sway Scale: %.2f, Recoil Scale: %.2f, Sight Aim Cone Scale: %.2f, Hip Aim Cone Scale: %.2f, Hash: %u",
			held_weapon.velocity,
			held_weapon.drag,
			held_weapon.gravity_modifier,
			held_weapon.initial_distance,
			held_weapon.mods.projectile_velocity_scale, 
			held_weapon.mods.aim_sway_scale,
			held_weapon.mods.recoil_scale,
			held_weapon.mods.sight_aim_cone_scale,
			held_weapon.mods.hip_aim_cone_scale,
			held_weapon.mods.hash ),
			COL32_WHITE )

		.draw_text( format_string( "%d entities", entity_collection.entities.size() ), COL32_WHITE )
		.draw_text( format_string( "%d combat entities", entity_collection.combat_entities.size() ), COL32_WHITE )
		.draw_text( format_string( "%d dropped items", entity_collection.dropped_items.size() ), COL32_WHITE )
		.draw_text( format_string( "%d players", entity_collection.players.size() ), COL32_WHITE );

	draw_entities( entity_collection.entities );
	draw_combat_entities( entity_collection.combat_entities );
	draw_dropped_items( entity_collection.dropped_items );

	if ( player_visuals.enabled || scientist_visuals.enabled ) {
		draw_players( entity_collection.players );
	}
}

bool renderer_init;

void on_render( IDXGISwapChain* swapchain ) {
	if ( !renderer_init ) {
		if ( !( renderer_init = renderer::init( swapchain ) ) ) {
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
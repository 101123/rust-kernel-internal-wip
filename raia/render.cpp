#include "render.h"

#include "cheat/sdk/sdk.h"
#include "cheat/entities.h"

#include "renderer.h"
#include "gui.h"

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

struct w2s_result {
	bool success;
	vector2 screen;
};

bool w2s( const vector3& world, vector2& screen ) {
	float w = vector3::dot( vector3( camera.view_matrix[ 3 ], camera.view_matrix[ 7 ], camera.view_matrix[ 11 ] ), world ) + camera.view_matrix[ 15 ];
	if ( w < 0.098f )
		return false;

	screen = vector2(
		( ( float )screen_width * 0.5f ) * ( 1.f + ( vector3::dot( vector3( camera.view_matrix[ 0 ], camera.view_matrix[ 4 ], camera.view_matrix[ 8 ] ), world ) + camera.view_matrix[ 12 ] ) / w ),
		( ( float )screen_height * 0.5f ) * ( 1.f - ( vector3::dot( vector3( camera.view_matrix[ 1 ], camera.view_matrix[ 5 ], camera.view_matrix[ 9 ] ), world ) + camera.view_matrix[ 13 ] ) / w )
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
	const char* shorter_name;
	char codepoint;
};

visual_item_info visual_items[] = {
	{ 1545779598, "AK", 'a' }, // rifle.ak
	{ -1335497659, "AK", 'a' }, // rifle.ak.ice
	{ 472505338, "AK", 'a' }, // rifle.ak.med
	{ -139037392, "AK", 'a' }, // rifle.ak.diver
	{ 2054929933, "AK", 'a' }, // rifle.ak.jungle
	{ -880412831, nullptr, 'b' }, // blunderbuss
	{ 1588298435, "Bolty", 'c'}, // rifle.bolt
	{ 884424049, nullptr, 'd'}, // bow.compound
	{ 1965232394, nullptr, 'e' }, // crossbow
	{ -765183617, "DB", 'f' }, // shotgun.double
	{ -75944661, nullptr, 'g' }, // pistol.eoka
	{ 1914691295, "Glock", 'h' }, // pistol.prototype17
	{ -1123473824, nullptr, 'i' }, // multiplegrenadelauncher
	{ -92315244, nullptr, 'j'}, // revolver.hc
	{ -1214542497, nullptr, 'k' }, // hmlmg
	{ -218009552, nullptr, 'l' }, // homingmissile.launcher
	{ 2040726127, nullptr, 'm' }, // knife.combat
	{ -778367295, "L96", 'n' }, // rifle.l96
	{ -1812555177, "LR300", 'o' }, // rifle.lr300
	{ 678698219, "M4", 'p' }, // shotgun.m4
	{ 1673224590, "M15", 'q' }, // pistol.semiauto.a.m15
	{ 28201841, "M39", 'r' }, // rifle.m39
	{ -852563019, "M92", 's' }, // pistol.m92
	{ -2069578888, "M2", 't' }, // lmg.m249
	{ 935606207, nullptr, 'u' }, // minigun
	{ 1318558775, nullptr, 'v' }, // smg.mp5
	{ 1953903201, nullptr, 'w' }, // pistol.nailgun
	{ -1367281941, "Pipey", 'x' }, // shotgun.waterpipe
	{ 1373971859, "Python", 'y' }, // pistol.python
	{ 649912614, nullptr, 'z' }, // pistol.revolver
	{ 442886268, nullptr, 'A' }, // rocket.launcher,
	{ 795371088, "Pumpy", 'B' }, // shotgun.pump,
	{ 818877484, "P2", 'C' }, // pistol.semiauto,
	{ -904863145, "SAR", 'D' }, // rifle.semiauto
	{ -348232115, nullptr, 'E' }, // rifle.sks
	{ 1796682209, "Custom", 'F' }, // smg.2
	{ -41440462, "SPAS", 'G' }, // shotgun.spas12
	{ 2083256995, nullptr, 'H' }, // t1_smg
};

void draw_players( const entity_vector<rust::base_player*, cached_player>& players ) {
	for ( const auto& [ player, cached_player ] : players ) {
		if ( player == local_player.entity || !cached_player.init )
			continue;

		const cvar_player_visuals& visuals = 
			cached_player.scientist ? scientist_visuals : player_visuals;

		if ( !visuals.enabled )
			continue;

		const cached_bone_data& bone_data = cached_player.bone_data;

		float distance = vector3::distance( camera.position, bone_data.positions[ 17 ] );
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

		bool draw_avatar = !cached_player.scientist && cached_player.avatar_srv && player_avatar;

		if ( visuals.name || draw_avatar ) {
			float avatar_width = draw_avatar ? 13.f : 0.f;
			float name_width = visuals.name ? renderer::calc_text_size( fonts::verdana, cached_player.name ).x : 0.f;
			float spacing = ( draw_avatar && visuals.name ) ? 3.f : 0.f;
			float total_width = avatar_width + spacing + name_width;
			float cursor = bounds.left + half - ( total_width / 2.f );

			if ( draw_avatar ) {
				renderer::draw_unity_image( cached_player.avatar_srv, cursor, bounds.top - 14.f, avatar_width, avatar_width, 2.f );
				cursor += avatar_width + spacing;
			}

			if ( visuals.name ) {
				renderer::draw_text( cursor, bounds.top - 11.f, fonts::verdana, text_flags::drop_shadow, cached_player.visible ? COL32_RED : ( UINT32 )visuals.name_color, cached_player.name );
			}
		}

		bool draw_team_id = !cached_player.scientist && ( cached_player.team_id > 0 && cached_player.team_id < 100'000 ) && player_team_id;

		if ( draw_team_id ) {
			renderer::draw_text( bounds.right + 2.f, bounds.top - 3.f, fonts::small_fonts, text_flags::none, COL32_WHITE, util::format_string( S( "%llu" ), cached_player.team_id ) );
		}

		float offset = 0.f;

		if ( visuals.held_item && cached_player.active_item_idx != -1 ) {
			if ( visuals.held_item_text ) {
				renderer::draw_text( bounds.left + half, bounds.bottom + offset + 1.f, fonts::small_fonts, text_flags::centered, visuals.held_item_color, cached_player.belt_items[ cached_player.active_item_idx ].name );
				offset += 8.f + 1.f;
			}
		}

		if ( visuals.distance ) {
			renderer::draw_text( bounds.left + half, bounds.bottom + 1.f + offset, fonts::small_fonts, text_flags::centered, visuals.distance_color, util::format_string( S( "%dm" ), ( int )distance ) );
		}
	}
}

void draw_entities( const entity_vector<rust::base_entity*, cached_entity>& entities ) {
	for ( const auto& [ entity, cached_entity ] : entities ) {
		cvar_visual* visuals = cached_entity.visual;
		if ( !visuals->enabled )
			continue;

		float distance = vector3::distance( camera.position, cached_entity.position );
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
			.draw_text( util::format_string( "%dm", ( int )distance ), COL32_MERGE_ALPHA( COL32_WHITE, visuals->color ) );
	}
}

void draw_combat_entities( const entity_vector<rust::base_combat_entity*, cached_combat_entity>& combat_entities ) {
	for ( const auto& [ combat_entity, cached_combat_entity ] : combat_entities ) {
		if ( cached_combat_entity.lifestate != rust::lifestate::alive )
			continue;

		cvar_visual* visuals = cached_combat_entity.visual;
		if ( !visuals->enabled )
			continue;

		float distance = vector3::distance( camera.position, cached_combat_entity.position );
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

		renderer::draw_filled_rect( x - half, y + 10.f, width, 4.f, COL32_MERGE_ALPHA( COL32_BLACK, visuals->color ) );
		renderer::draw_filled_rect( x - half + 1.f, y + 11.f, health_width, 2.f, COL32_MERGE_ALPHA( COL32( 120, 225, 80, 255 ), visuals->color ) );
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

		float distance = vector3::distance( camera.position, cached_dropped_item.position );
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
				util::format_string_w( S( L"%ws (%dx)" ), cached_dropped_item.name, cached_dropped_item.amount ) :
				util::format_string_w( S( L"%ws" ), cached_dropped_item.name ),
				visuals->color )
			.draw_text( util::format_string( S( "%dm" ), ( int )distance ), COL32_MERGE_ALPHA( COL32_WHITE, visuals->color ) );
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

	camera.view_matrix = native_camera->culling_matrix;
	camera.position = native_camera->last_position;

	util::scoped_spinlock lock( &entity_manager::cache_lock );

	entity_collection entity_collection = entity_manager::get_entities();

	visual_builder( vector2( 100.f, 100.f ) )
		.set_font( fonts::verdana )
		.set_vertical_spacing( 12.f )
		.set_flags( text_flags::none )
		.draw_text( util::format_string( "Velocity: %.2f [%.2f], Drag: %.2f, Gravity Modifier: %.2f, Initial Distance: %.2f, Projectile Velocity Scale: %.2f, Aim Sway Scale: %.2f, Recoil Scale: %.2f, Sight Aim Cone Scale: %.2f, Hip Aim Cone Scale: %.2f, Hash: %u",
			held_weapon.velocity,
			held_weapon.max_velocity,
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

		.draw_text( util::format_string( "%d entities", entity_collection.entities.size() ), COL32_WHITE )
		.draw_text( util::format_string( "%d combat entities", entity_collection.combat_entities.size() ), COL32_WHITE )
		.draw_text( util::format_string( "%d dropped items", entity_collection.dropped_items.size() ), COL32_WHITE )
		.draw_text( util::format_string( "%d players", entity_collection.players.size() ), COL32_WHITE );

	draw_entities( entity_collection.entities );
	draw_combat_entities( entity_collection.combat_entities );
	draw_dropped_items( entity_collection.dropped_items );

	if ( player_visuals.enabled || scientist_visuals.enabled ) {
		draw_players( entity_collection.players );
	}
}

void draw_raids() {
	if ( !raid_visuals.enabled )
		return;

	uint32_t time = util::get_seconds();

	for ( auto& raid : raids ) {
		if ( !raid.active_time )
			continue;

		uint32_t seconds_since_active = time - raid.active_time;

		// If the raid has timed out, we can just reset the active time to allow the slot to be reused
		if ( seconds_since_active > raid_visuals.maximum_time ) {
			raid.active_time = 0u;
			continue;
		}

		float distance = vector3::distance( camera.position, raid.position );
		if ( distance > raid_visuals.maximum_distance )
			continue;

		vector2 screen;
		if ( !w2s( raid.position, screen ) )
			continue;

		auto visual = visual_builder( screen )
			.set_font( fonts::small_fonts )
			.set_vertical_spacing( 9.f )
			.set_flags( text_flags::none )
			.draw_text( util::format_string( S( "Raid [%s] [%dm]" ), raid.grid, ( int )distance ), raid_visuals.color );

		static const char* effect_names[] = { S( "Rocket" ), S( "High Velocity Rocket" ), S( "Incendiary Rocket" ),
			S( "Explosive Ammo" ), S( "C4" ), S( "Satchel Charge" ), S( "HE Grenade" ), S( "MLRS Rocket" ) };

		for ( size_t i = 0; i < _countof( raid.effects ); i++ ) {
			if ( raid.effects[ i ] ) {
				visual.draw_text( util::format_string( S( "%s (%ux)" ), effect_names[ i ], raid.effects[ i ] ), raid_visuals.color );
			}
		}

		visual.draw_text( util::format_string( S( "%us" ), seconds_since_active ), raid_visuals.color );
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

	renderer::draw_text( 8.f, 5.f, fonts::small_fonts, text_flags::none, COL32( 110, 183, 212, 255 ), S( "sentian" ) );
	renderer::draw_text( 38.f, 5.f, fonts::small_fonts, text_flags::none, COL32( 255, 255, 255, 255 ), S( ".gg" ) );

	renderer::draw_circle( ( float )screen_width / 2.f, ( float )screen_height / 2.f, ( float )aimbot.fov, 1.f, COL32_WHITE );

	draw_esp();

	{
		
	}

	if ( render_input.get_async_key_state( VK_END ) & 0x1 ) {
		gui::open = !gui::open;
	}

	if ( gui::open ) {
		gui::run();
	}

	renderer::end_frame();
}
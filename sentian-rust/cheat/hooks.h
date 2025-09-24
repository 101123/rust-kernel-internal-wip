#pragma once

struct _CONTEXT;

namespace hook_handlers {
	void network_client_create_networkable( _CONTEXT* );
	void network_client_destroy_networkable( _CONTEXT* );
	void outline_manager_on_render_image( _CONTEXT* );
	void player_walk_movement_do_fixed_update( _CONTEXT* );
	void protobuf_player_tick_write_to_stream_delta( _CONTEXT* );
	void protobuf_projectile_shoot_write_to_stream( _CONTEXT* );
	void protobuf_player_projectile_update_write_to_stream( _CONTEXT* );
	void protobuf_player_projectile_attack_write_to_stream( _CONTEXT* );
	void item_icon_try_to_move( _CONTEXT* );
	void client_on_client_disconnected( _CONTEXT* );
}
#pragma once

struct _CONTEXT;

namespace hook_handlers {
	void network_client_create_networkable( _CONTEXT*, void* );
	void network_client_destroy_networkable( _CONTEXT*, void* );
	void post_outline_manager_on_render_image( _CONTEXT*, void* );
	bool pre_player_walk_movement_client_input( _CONTEXT*, void* );
	void post_player_walk_movement_client_input( _CONTEXT*, void* );
	bool pre_protobuf_player_tick_write_to_stream_delta( _CONTEXT*, void* );
	bool pre_protobuf_projectile_shoot_write_to_stream( _CONTEXT*, void* );
	bool pre_protobuf_player_projectile_update_write_to_stream( _CONTEXT*, void* );
	bool pre_protobuf_player_projectile_attack_write_to_stream( _CONTEXT*, void* );
	void post_item_icon_try_to_move( _CONTEXT*, void* );
	bool pre_client_on_client_disconnected( _CONTEXT*, void* );
	bool pre_base_player_client_input( _CONTEXT*, void* );
	bool pre_console_system_command_set( _CONTEXT*, void* );
	bool pre_console_system_command_call( _CONTEXT*, void* );
	void effect_library_setup_effect( _CONTEXT*, void* );
}
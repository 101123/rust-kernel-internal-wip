#pragma once

struct _CONTEXT;

void create_networkable_hook_handler( _CONTEXT* context );
void destroy_networkable_hook_handler( _CONTEXT* context );
void on_render_image_hook_handler( _CONTEXT* context );
void movement_hook_handler( _CONTEXT* context );

void projectile_shoot_write_to_stream_hook_handler( _CONTEXT* context );
void player_projectile_update_write_to_stream_hook_handler( _CONTEXT* context );
void player_projectile_attack_write_to_stream_hook_handler( _CONTEXT* context );

void item_icon_try_to_move_hook_handler( _CONTEXT* context );
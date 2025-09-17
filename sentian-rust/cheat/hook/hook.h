#pragma once

struct _CONTEXT;

void create_networkable_hook_handler( _CONTEXT* context );
void destroy_networkable_hook_handler( _CONTEXT* context );
void on_render_image_hook_handler( _CONTEXT* context );
void movement_hook_handler( _CONTEXT* context );
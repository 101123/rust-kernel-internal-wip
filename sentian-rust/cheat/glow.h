#pragma once

namespace unity {
	class render_texture;
	class asset_bundle;
}

namespace rust {
	class base_player;
}

namespace glow_manager {
	bool init( unity::asset_bundle* asset_bundle );
	void destroy();

	// These should only be called from a game thread
	void add_player( rust::base_player* player );
	void remove_player( rust::base_player* player );

	void on_render_image_hook( unity::render_texture* src, unity::render_texture* dest );
}
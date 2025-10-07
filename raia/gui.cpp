#include "gui.h"

#include "util.h"

#include "renderer.h"

#include "math/vec2.h"
#include "math/vec4.h"

#include "vars.h"
#include "um.h"

#include "cheat/sdk/sdk.h"

#include <imgui/imgui_internal.h>

#include <vector>
#include <algorithm>

struct rect {
	float x, y, w, h;
};

enum draw_commands {
	filled_rect,
	filled_rect_multi_color,
	text,
	push_clip_rect,
	pop_clip_rect,
	push_floating,
	pop_floating
};

struct draw_command {
	draw_commands type;
    rect bounds;
    int z_index;

	union {
		struct {
			uint32_t color;
            float rounding;
		} filled_rect;

		struct {
			uint32_t colors[ 4 ];
		} filled_rect_multi_color;

		struct {
			char buffer[ 64 ];
            uint32_t font;
            uint32_t flags;
            uint32_t color;
		} text;
	};
};

class ordered_draw_list {
public:
	void add_command( draw_command& command ) {
		floating_ ? floating_commands_.push_back( command ) : commands_.push_back( command );
	}

    void add_filled_rect( float x, float y, float width, float height, uint32_t color, float rounding = 0.f ) {
        draw_command command;
        command.type = draw_commands::filled_rect;
        command.bounds = rect( x, y, width, height );
        command.z_index = current_z_index_;

        command.filled_rect.color = color;
        command.filled_rect.rounding = rounding;

        add_command( command );
    }

    void add_filled_rect_multi_color( float x, float y, float width, float height, uint32_t colors[ 4 ] ) {
        draw_command command;
        command.type = draw_commands::filled_rect_multi_color;
        command.bounds = rect( x, y, width, height );
        command.z_index = current_z_index_;

        memcpy( command.filled_rect_multi_color.colors, colors, sizeof( command.filled_rect_multi_color.colors ) );

        add_command( command );
    }

    void add_text( float x, float y, uint32_t font, uint32_t flags, uint32_t color, const char* text ) {
        draw_command command;
        command.type = draw_commands::text;
        command.bounds = rect( x, y, 0.f, 0.f );
        command.z_index = current_z_index_;

        int length = min( strlen( text ), sizeof( command.text.buffer ) - 1 );
        memcpy( command.text.buffer, text, length );
        command.text.buffer[ length ] = '\0';
        command.text.font = font;
        command.text.flags = flags;
        command.text.color = color;

        add_command( command );
    }

    void push_clip_rect( float x, float y, float width, float height ) {
        draw_command command;
        command.type = draw_commands::push_clip_rect;
        command.bounds = rect( x, y, width, height );

        add_command( command );
    }

    void pop_clip_rect() {
        draw_command command;
        command.type = draw_commands::pop_clip_rect;

        add_command( command );
    }

    void push_z_index( int z_index ) {
        previous_z_index_ = current_z_index_;
        current_z_index_ = z_index;
    }

    void pop_z_index() {
        current_z_index_ = previous_z_index_;
    }

    void set_floating( bool floating ) {
        floating_ = floating;
    }

    void render() {
        sort_commands();

        render_commands( commands_ );
        render_commands( floating_commands_ );
    }

    void clear() {
        commands_.resize( 0 );
        floating_commands_.resize( 0 );
    }

private:
    void sort_commands() {
        uint16_t clip_rect_indices[ 64 ][ 2 ];
        uint16_t clip_rect_count = 0;

        for ( size_t i = 0; i < commands_.size(); i++ ) {
            switch ( commands_[ i ].type ) {
                case draw_commands::push_clip_rect:
                    clip_rect_indices[ clip_rect_count ][ 0 ] = i;
                    break;
                case draw_commands::pop_clip_rect:
                    clip_rect_indices[ clip_rect_count++ ][ 1 ] = i;
                    break;
            }
        }

        for ( size_t i = 0; i < clip_rect_count; i++ ) {
            auto begin = commands_.begin() + clip_rect_indices[ i ][ 0 ] + 1;
            auto end = commands_.begin() + clip_rect_indices[ i ][ 1 ];

            std::stable_sort( begin, end, []( const draw_command& a, const draw_command& b ) {
                return a.z_index < b.z_index;
            } );
        }
    }

    void render_commands( std::vector<draw_command>& commands ) {
        for ( auto& command : commands ) {
            switch ( command.type ) {
                case draw_commands::filled_rect:
                    renderer::draw_filled_rect( command.bounds.x, command.bounds.y, command.bounds.w, command.bounds.h, command.filled_rect.color, command.filled_rect.rounding );
                    break;
                case draw_commands::filled_rect_multi_color:
                    renderer::draw_filled_rect_multi_color( command.bounds.x, command.bounds.y, command.bounds.w, command.bounds.h, command.filled_rect_multi_color.colors );
                    break;
                case draw_commands::text:
                    renderer::draw_text( command.bounds.x, command.bounds.y, command.text.font, command.text.flags, command.text.color, command.text.buffer );
                    break;
                case draw_commands::push_clip_rect:
                    renderer::push_clip_rect( command.bounds.x, command.bounds.y, command.bounds.w, command.bounds.h );
                    break;
                case draw_commands::pop_clip_rect:
                    renderer::pop_clip_rect();
                    break;
            }
        }
    }

	std::vector<draw_command> commands_;
	std::vector<draw_command> floating_commands_;
	int current_z_index_;
	int previous_z_index_;
	bool floating_;
};

template <typename T>
struct state_history2 {
    T previous;
    T current;
};

util::lazy_initializer<ordered_draw_list> gui_draw_list;

state_history2<bool> left_mouse_state;
state_history2<vector2> mouse_position;
state_history2<uint64_t> active_hash;

rect menu_bounds = rect( 400.f, 400.f, 548.f, 480.f );

bool left_mouse_clicked;
bool left_mouse_held;

vector4 color_picker_hsv;

uint32_t gradient_on[ 4 ] = {
    COL32( 110, 183, 212, 255 ),
    COL32( 110, 183, 212, 255 ),
    COL32( 82, 135, 156, 255 ),
    COL32( 82, 135, 156, 255 )
};

uint32_t gradient_off[ 4 ] = {
    COL32( 54, 54, 54, 255 ),
    COL32( 54, 54, 54, 255 ),
    COL32( 54, 54, 54, 255 ),
    COL32( 54, 54, 54, 255 )
};

void update_input() {
    left_mouse_state = {
        .previous = left_mouse_state.current,
        .current = unity::input::get_mouse_button( 0 )
    };

    left_mouse_clicked = left_mouse_state.current && !left_mouse_state.previous;
    left_mouse_held = left_mouse_state.previous && left_mouse_state.current;

    vector2 mouse_pos = unity::input::get_mouse_position();
    mouse_pos.y = ( float )screen_height - mouse_pos.y;

    mouse_position = {
        .previous = mouse_position.current,
        .current = mouse_pos
    };
}

bool mouse_in_rect( const rect& bounds ) {
    const vector2& position = mouse_position.current;

    return
        position.x >= bounds.x && position.x <= bounds.x + bounds.w &&
        position.y >= bounds.y && position.y <= bounds.y + bounds.h;
}

namespace elements {
    enum : int {
        none,
        toggle,
        slider,
        combo_box
    };
}

class group_box {
public:
    group_box() = delete;
    group_box( rect bounds, const char* label = nullptr )
        : bounds_( bounds ), cursor_( 12.f, 12.f ), previous_id_( elements::none ) {};

    void begin() {
        auto& draw_list = gui_draw_list.get();

        draw_list.add_filled_rect( bounds_.x, bounds_.y, bounds_.w, bounds_.h, COL32( 61, 61, 61, 255 ) );
        draw_list.add_filled_rect( bounds_.x + 1.f, bounds_.y + 1.f, bounds_.w - 2.f, bounds_.h - 2.f, COL32( 38, 38, 38, 255 ) );
        draw_list.add_filled_rect( bounds_.x + 2.f, bounds_.y + 2.f, bounds_.w - 4.f, bounds_.h - 4.f, COL32( 50, 50, 50, 255 ) );

        draw_list.push_clip_rect( bounds_.x + 2.f, bounds_.y + 2.f, bounds_.w - 4.f, bounds_.h - 4.f );

        draw_list.pop_z_index();
    }

    void end() {
        gui_draw_list.get().pop_clip_rect();
    }

    static inline vector2 toggle_movement[] = {
        { 0.f, 0.f }, /* None */
        { 0.f, 18.f }, /* Toggle -> Toggle */
        { 0.f, 36.f }, /* Slider -> Toggle */
        { 0.f, 50.f } /* Combobox -> Toggle */
    };

    bool toggle( const char* label, bool* value ) {
        auto& draw_list = gui_draw_list.get();

        cursor_ += toggle_movement[ ( int )previous_id_ ];

        draw_list.push_z_index( 2 );

        const vector2 position = vector2( bounds_.x + cursor_.x, bounds_.y + cursor_.y );
        const rect toggle_bounds = rect( position.x, position.y, 10.f, 10.f );

        const bool hovered = mouse_in_rect( toggle_bounds );
        const bool nothing_active = active_hash.previous == 0ull && active_hash.current == 0ull;

        if ( hovered && nothing_active && left_mouse_clicked ) {
            *value = !*value;
            active_hash.current = 0ull;
        }

        draw_list.add_filled_rect( toggle_bounds.x, toggle_bounds.y, toggle_bounds.w, toggle_bounds.h, COL32( 60, 60, 60, 255 ) );
        draw_list.add_filled_rect( toggle_bounds.x + 1.f, toggle_bounds.y + 1.f, toggle_bounds.w - 2.f, toggle_bounds.h - 2.f, COL32( 38, 38, 38, 255 ) );
        draw_list.add_filled_rect_multi_color( toggle_bounds.x + 2.f, toggle_bounds.y + 2.f, toggle_bounds.w - 4.f, toggle_bounds.h - 4.f, *value ? gradient_on : gradient_off );

        draw_list.add_text( position.x + 18.f, position.y + 2.f, fonts::verdana, text_flags::none, COL32( 160, 160, 160, 255 ), label );

        draw_list.pop_z_index();

        previous_id_ = elements::toggle;

        return *value;
    }

    void keybind( uint32_t* key ) {
        auto& draw_list = gui_draw_list.get();

        draw_list.push_z_index( 2 );

        const vector2 position = vector2( bounds_.x + cursor_.x, bounds_.y + cursor_.y );
        const rect bounds = rect( position.x + bounds_.w - 68.f, position.y - 1.f, 20.f, 10.f );

        const bool hovered = mouse_in_rect( bounds );
        const bool nothing_active = active_hash.previous == 0ull && active_hash.current == 0ull;

        const uint64_t hash = ( uint64_t )key;
        const bool active = active_hash.current == hash;

        if ( hovered && nothing_active && left_mouse_clicked ) {
            active_hash.current = hash;
        }

        if ( active ) {
            for ( uint8_t i = 0; i < 255; i++ ) {
                if ( render_input.get_async_key_state( i ) & 0x1 ) {
                    *key = i;
                    active_hash.current = 0ull;
                }
            }
        }

        draw_list.add_text( bounds.x, bounds.y, fonts::small_fonts, text_flags::none, active ? COL32_RED : COL32( 160, 160, 160, 255 ), util::format_string( S( "[%c]" ), *key ) );

        draw_list.pop_z_index();
    }

    void color_picker( uint32_t* value, bool alpha = true ) {
        auto& draw_list = gui_draw_list.get();

        draw_list.push_z_index( 2 );

        const vector2 position = vector2( bounds_.x + cursor_.x, bounds_.y + cursor_.y );
        const rect preview_bounds = rect( position.x + bounds_.w - 44.f, position.y, 20.f, 10.f );

        const float color_picker_padding = 6.f;
        const vector2 sv_percentage = vector2( 0.84f, alpha ? 0.84f : 0.935f );

        const rect color_picker_bounds = rect( preview_bounds.x + preview_bounds.w + 4.f, preview_bounds.y, 200.f, alpha ? 200.f : 180.f );
        const rect sv_square_bounds = rect( color_picker_bounds.x + color_picker_padding, color_picker_bounds.y + color_picker_padding, color_picker_bounds.w * sv_percentage.x, color_picker_bounds.h * sv_percentage.y );
        const rect hue_bar_bounds = rect( sv_square_bounds.x + sv_square_bounds.w + color_picker_padding - 2.f, sv_square_bounds.y, color_picker_bounds.w - sv_square_bounds.w - ( color_picker_padding * 3.f ) + 2.f, sv_square_bounds.h );
        const rect alpha_bar_bounds = rect( sv_square_bounds.x, sv_square_bounds.y + sv_square_bounds.h + color_picker_padding - 2.f, sv_square_bounds.w, color_picker_bounds.h - sv_square_bounds.h - ( color_picker_padding * 3.f ) + 2.f );

        const static uint32_t hue_colors[ 6 + 1 ] = {
            COL32( 255, 0, 0, 255 ),
            COL32( 255, 255, 0, 255 ),
            COL32( 0, 255, 0, 255 ),
            COL32( 0, 255, 255, 255 ),
            COL32( 0, 0, 255, 255 ),
            COL32( 255, 0, 255, 255 ),
            COL32( 255, 0, 0, 255 )
        };

        const bool preview_hovered = mouse_in_rect( preview_bounds );
        const bool color_picker_hovered = mouse_in_rect( color_picker_bounds );

        const uint64_t hash = ( uint64_t )value;
        const bool active = active_hash.current == hash;

        if ( preview_hovered && left_mouse_clicked ) {
            color_picker_hsv = rgb_to_hsv( *value );
            active_hash.current = hash;
        }

        if ( active && !color_picker_hovered && left_mouse_clicked ) {
            active_hash.current = 0ull;
        }

        else if ( active ) {
            draw_list.set_floating( true );

            draw_styled_rect( rect( color_picker_bounds.x, color_picker_bounds.y, color_picker_bounds.w, color_picker_bounds.h ) );

            // Account for 1px black border
            const rect sv_square_bounds_ = rect( sv_square_bounds.x + 1.f, sv_square_bounds.y + 1.f, sv_square_bounds.w - 2.f, sv_square_bounds.h - 2.f );
            const rect hue_bar_bounds_ = rect( hue_bar_bounds.x + 1.f, hue_bar_bounds.y + 1.f, hue_bar_bounds.w - 2.f, hue_bar_bounds.h - 2.f );
            const rect alpha_bar_bounds_ = rect( alpha_bar_bounds.x + 1.f, alpha_bar_bounds.y + 1.f, alpha_bar_bounds.w - 2.f, alpha_bar_bounds.h - 2.f );

            if ( mouse_in_rect( sv_square_bounds_ ) && left_mouse_held ) {
                color_picker_hsv.y = ImSaturate( ( mouse_position.current.x - sv_square_bounds_.x ) / ( sv_square_bounds_.w ) );
                color_picker_hsv.z = 1.f - ImSaturate( ( mouse_position.current.y - sv_square_bounds_.y ) / ( sv_square_bounds_.h ) );
            }

            else if ( mouse_in_rect( hue_bar_bounds_ ) && left_mouse_held ) {
                color_picker_hsv.x = ImSaturate( ( mouse_position.current.y - hue_bar_bounds_.y ) / ( hue_bar_bounds_.h ) );
            }

            else if ( alpha && mouse_in_rect( alpha_bar_bounds_ ) && left_mouse_held ) {
                ( ( uint8_t* )value )[ 3 ] = ( uint8_t )( ( ( mouse_position.current.x - alpha_bar_bounds_.x ) / alpha_bar_bounds_.w ) * 255.f );
            }

            uint32_t hue_color = hsv_to_rgb( color_picker_hsv.x, 1.f, 1.f );

            uint32_t first_pass[] = { COL32_WHITE, hue_color, hue_color, COL32_WHITE };
            uint32_t second_pass[] = { 0u, 0u, COL32_BLACK, COL32_BLACK };

            draw_list.add_filled_rect( sv_square_bounds.x, sv_square_bounds.y, sv_square_bounds.w, sv_square_bounds.h, COL32( 38, 38, 38, 255 ) );

            ImVec2 sv_cursor_pos;

            draw_list.add_filled_rect_multi_color( sv_square_bounds_.x, sv_square_bounds_.y, sv_square_bounds_.w, sv_square_bounds_.h, first_pass );
            draw_list.add_filled_rect_multi_color( sv_square_bounds_.x, sv_square_bounds_.y, sv_square_bounds_.w, sv_square_bounds_.h, second_pass );

            sv_cursor_pos.x = ImClamp( IM_ROUND( sv_square_bounds_.x + ImSaturate( color_picker_hsv.y ) * sv_square_bounds_.w ), sv_square_bounds_.x, sv_square_bounds_.x + sv_square_bounds_.w );
            sv_cursor_pos.y = ImClamp( IM_ROUND( sv_square_bounds_.y + ImSaturate( 1 - color_picker_hsv.z ) * sv_square_bounds_.h ), sv_square_bounds_.y, sv_square_bounds_.y + sv_square_bounds_.h );

            const rect sv_cursor_rect = rect( sv_cursor_pos.x - 2.f, sv_cursor_pos.y - 2.f, 4.f, 4.f );

            draw_list.add_filled_rect( sv_cursor_rect.x, sv_cursor_rect.y, sv_cursor_rect.w, sv_cursor_rect.h, COL32( 38, 38, 38, 255 ) );
            draw_list.add_filled_rect( sv_cursor_rect.x + 1.f, sv_cursor_rect.y + 1.f, sv_cursor_rect.w - 2.f, sv_cursor_rect.h - 2.f, COL32_WHITE );

            // Hue bar
            draw_list.add_filled_rect( hue_bar_bounds.x, hue_bar_bounds.y, hue_bar_bounds.w, hue_bar_bounds.h, COL32( 38, 38, 38, 255 ) );

            for ( size_t i = 0; i < 6; i++ ) {
                uint32_t colors[] = { hue_colors[ i ], hue_colors[ i ], hue_colors[ i + 1 ], hue_colors[ i + 1 ] };

                draw_list.add_filled_rect_multi_color(
                    hue_bar_bounds_.x,
                    hue_bar_bounds_.y + i * ( hue_bar_bounds_.h / 6.f ),
                    hue_bar_bounds_.w,
                    hue_bar_bounds_.h / 6.f,
                    colors
                );
            }

            float bar0_line_y = IM_ROUND( sv_square_bounds_.y + color_picker_hsv.x * hue_bar_bounds_.h );

            const rect hue_cursor_rect = rect( hue_bar_bounds_.x - 2.f, bar0_line_y - 2.f, hue_bar_bounds_.w + 4.f, 4.f );

            draw_list.add_filled_rect( hue_cursor_rect.x, hue_cursor_rect.y, hue_cursor_rect.w, hue_cursor_rect.h, COL32( 38, 38, 38, 255 ) );
            draw_list.add_filled_rect( hue_cursor_rect.x + 1.f, hue_cursor_rect.y + 1.f, hue_cursor_rect.w - 2.f, hue_cursor_rect.h - 2.f, COL32_WHITE );

            // Alpha bar
            if ( alpha ) {
                draw_list.add_filled_rect( alpha_bar_bounds.x, alpha_bar_bounds.y, alpha_bar_bounds.w, alpha_bar_bounds.h, COL32( 38, 38, 38, 255 ) );
                draw_checkerboard( rect( alpha_bar_bounds_.x, alpha_bar_bounds_.y, alpha_bar_bounds_.w, alpha_bar_bounds_.h ), alpha_bar_bounds_.w / 24.f );

                uint32_t colors[] = {
                    *value & ~0xFF000000,
                    *value | 0xFF000000,
                    *value | 0xFF000000,
                    *value & ~0xFF000000
                };

                draw_list.add_filled_rect_multi_color( alpha_bar_bounds_.x, alpha_bar_bounds_.y, alpha_bar_bounds_.w, alpha_bar_bounds_.h, colors );

                const vector2 alpha_cursor_pos = vector2( alpha_bar_bounds_.x + ( ( ( float )( ( uint8_t* )value )[ 3 ] / 255.f ) * alpha_bar_bounds_.w ), alpha_bar_bounds_.y );
                const rect alpha_cursor_rect = rect( alpha_cursor_pos.x - 2.f, alpha_cursor_pos.y - 2.f, 4.f, alpha_bar_bounds_.h + 4.f );

                draw_list.add_filled_rect( alpha_cursor_rect.x, alpha_cursor_rect.y, alpha_cursor_rect.w, alpha_cursor_rect.h, COL32( 38, 38, 38, 255 ) );
                draw_list.add_filled_rect( alpha_cursor_rect.x + 1.f, alpha_cursor_rect.y + 1.f, alpha_cursor_rect.w - 2.f, alpha_cursor_rect.h - 2.f, COL32_WHITE );
            }

            uint8_t backup = ( ( uint8_t* )value )[ 3 ];
            *value = hsv_to_rgb( color_picker_hsv.x, color_picker_hsv.y, color_picker_hsv.z );
            ( ( uint8_t* )value )[ 3 ] = backup;

            draw_list.set_floating( false );
        }

        uint32_t color_gradient[] = {
            *value,
            *value,
            *value - COL32( 0, 0, 0, 45 ),
            *value - COL32( 0, 0, 0, 45 ),
        };

        draw_styled_rect( rect( preview_bounds.x, preview_bounds.y, preview_bounds.w, preview_bounds.h ), color_gradient );

        draw_list.pop_z_index();
    }

    static inline vector2 slider_movement[] = {
        { 0.f, 0.f }, /* None */
        { 0.f, 18.f }, /* Toggle -> Slider */
        { 0.f, 29.f }, /* Slider -> Slider */
        { 0.f, 44.f } /* Combobox -> Slider */
    };

    template <typename T>
    void slider( const char* label, const char* fmt, T* value, const T& min, const T& max ) {
        auto& draw_list = gui_draw_list.get();

        static_assert( std::is_arithmetic_v<T> );

        cursor_ += slider_movement[ ( int )previous_id_ ];

        draw_list.push_z_index( 2 );

        const vector2 position = vector2( bounds_.x + cursor_.x, bounds_.y + cursor_.y );
        const rect slider_bounds = rect( position.x + 18.f, position.y + 16.f, bounds_.w - 60.f, 10.f );

        const bool hovered = mouse_in_rect( slider_bounds );
        const bool nothing_active = active_hash.previous == 0ull && active_hash.current == 0ull;

        const uint64_t hash = ( uint64_t )value;
        const bool active = active_hash.current == hash;

        if ( hovered && nothing_active && left_mouse_clicked ) {
            active_hash.current = hash;
        }

        else if ( active && left_mouse_held ) {
            *value = static_cast<T>( ( std::clamp( mouse_position.current.x - slider_bounds.x, 0.f, slider_bounds.w - 1 ) / ( slider_bounds.w - 1.f ) ) * ( max - min ) + min );
        }

        else if ( active && !left_mouse_held ) {
            active_hash.current = 0ull;
        }

        draw_list.add_text( slider_bounds.x, position.y + 4.f, fonts::verdana, text_flags::none, COL32( 160, 160, 160, 255 ), label );

        draw_styled_rect( slider_bounds );

        const rect draw_bounds = rect( slider_bounds.x + 3.f, slider_bounds.y + 3.f, slider_bounds.w - 6.f, slider_bounds.h - 6.f );
        float fill_width = draw_bounds.w * std::clamp( static_cast<float>( *value - min ) / static_cast<float>( max - min ), 0.f, 1.f );

        draw_list.add_filled_rect_multi_color( draw_bounds.x, draw_bounds.y, fill_width, draw_bounds.h, gradient_on );

        draw_list.add_text( draw_bounds.x + fill_width, draw_bounds.y, fonts::small_fonts, text_flags::centered, COL32( 160, 160, 160, 255 ), util::format_string( fmt, *value ) );

        draw_list.pop_z_index();

        previous_id_ = elements::slider;
    }

    static inline vector2 combo_box_movement[] = {
        { 0.f, 0.f }, /* None */
        { 0.f, 16.f }, /* Toggle -> Combobox */
        { 0.f, 29.f }, /* Slider -> Combobox */
        { 0.f, 50.f } /* Combobox -> Combobox */
    };

    template <typename T>
    void combo_box( const char* label, std::initializer_list<const char*> options, T* value ) {
        auto& draw_list = gui_draw_list.get();

        static_assert( std::is_integral_v<T> );

        cursor_ += combo_box_movement[ ( int )previous_id_ ];

        draw_list.push_z_index( 3 );

        const vector2 position = vector2( bounds_.x + cursor_.x, bounds_.y + cursor_.y );
        const rect combo_bounds = rect( position.x + 18.f, position.y + 16.f, bounds_.w - 60.f, 20.f );
        const rect options_bounds = rect( combo_bounds.x, combo_bounds.y + 21.f, combo_bounds.w, options.size() * 20.f );

        const bool hovered = mouse_in_rect( combo_bounds );
        const bool nothing_active = active_hash.previous == 0ull && active_hash.current == 0ull;

        const uint64_t hash = ( uint64_t )value;
        const bool active = active_hash.current == hash;

        if ( hovered && nothing_active && left_mouse_clicked ) {
            active_hash.current = hash;
        }

        else if ( active && left_mouse_clicked && !mouse_in_rect( options_bounds ) ) {
            active_hash.current = 0ull;
        }

        else if ( active ) {
            draw_styled_rect( options_bounds );

            for ( size_t i = 0; i < options.size(); i++ ) {
                const rect option_bounds = rect( options_bounds.x, options_bounds.y + ( i * 20.f ), options_bounds.w, 20.f );

                const bool hovered = mouse_in_rect( option_bounds );

                if ( hovered && left_mouse_clicked ) {
                    *value = static_cast<T>( i );
                    active_hash.current = 0ull;
                }

                draw_list.add_text( options_bounds.x + 6.f, options_bounds.y + 7.f + ( i * 20.f ), fonts::verdana, text_flags::none, hovered ? gradient_on[ 0 ] : COL32( 160, 160, 160, 255 ), options.begin()[ i ] );
            }
        }

        draw_list.add_text( position.x + 18.f, position.y + 4.f, fonts::verdana, text_flags::none, COL32( 160, 160, 160, 255 ), label );

        draw_styled_rect( combo_bounds );

        draw_list.add_text( position.x + 24.f, position.y + 23.f, fonts::verdana, text_flags::none, COL32( 160, 160, 160, 255 ), options.begin()[ *value ] );

        draw_list.pop_z_index();

        previous_id_ = elements::combo_box;
    }

    void multi_combo_box( const char* label, std::initializer_list<std::pair<const char*, bool*>> options) {
        auto& draw_list = gui_draw_list.get();

        cursor_ += combo_box_movement[ ( int )previous_id_ ];

        draw_list.push_z_index( 3 );

        const vector2 position = vector2( bounds_.x + cursor_.x, bounds_.y + cursor_.y );
        const rect combo_bounds = rect( position.x + 18.f, position.y + 16.f, bounds_.w - 60.f, 20.f );
        const rect options_bounds = rect( combo_bounds.x, combo_bounds.y + 21.f, combo_bounds.w, options.size() * 20.f );

        const bool hovered = mouse_in_rect( combo_bounds );
        const bool nothing_active = active_hash.previous == 0ull && active_hash.current == 0ull;

        const uint64_t hash = ( uint64_t )options.begin()[ 0 ].second;
        const bool active = active_hash.current == hash;

        if ( hovered && nothing_active && left_mouse_clicked ) {
            active_hash.current = hash;
        }

        else if ( active && left_mouse_clicked && !mouse_in_rect( options_bounds ) ) {
            active_hash.current = 0ull;
        }

        else if ( active ) {
            draw_styled_rect( options_bounds );

            for ( size_t i = 0; i < options.size(); i++ ) {
                const rect option_bounds = rect( options_bounds.x, options_bounds.y + ( i * 20.f ), options_bounds.w, 20.f );

                const char* option = options.begin()[ i ].first;
                bool* value = options.begin()[ i ].second;

                const bool hovered = mouse_in_rect( option_bounds );

                if ( hovered && left_mouse_clicked ) {
                    *value = !*value;
                }

                uint32_t color = COL32( 160, 160, 160, 255 );

                if ( *value ) {
                    color = COL32( 255, 0, 0, 255 );
                }

                draw_list.add_text( options_bounds.x + 6.f, options_bounds.y + 7.f + ( i * 20.f ), fonts::verdana, text_flags::none, color, option );
            }
        }

        draw_list.add_text( position.x + 18.f, position.y + 4.f, fonts::verdana, text_flags::none, COL32( 160, 160, 160, 255 ), label );

        draw_styled_rect( combo_bounds );

        // draw_list.add_text( position.x + 24.f, position.y + 23.f, fonts::verdana, text_flags::none, COL32( 160, 160, 160, 255 ), options.begin()[ *value ] );

        draw_list.pop_z_index();

        previous_id_ = elements::combo_box;
    }

private:
    void draw_styled_rect( const rect& bounds, uint32_t* background_colors = nullptr ) {
        auto& draw_list = gui_draw_list.get();

        draw_list.add_filled_rect( bounds.x, bounds.y, bounds.w, bounds.h, COL32( 60, 60, 60, 255 ) );
        draw_list.add_filled_rect( bounds.x + 1.f, bounds.y + 1.f, bounds.w - 2.f, bounds.h - 2.f, COL32( 38, 38, 38, 255 ) );

        background_colors ?
            draw_list.add_filled_rect_multi_color( bounds.x + 2.f, bounds.y + 2.f, bounds.w - 4.f, bounds.h - 4.f, background_colors ) :
            draw_list.add_filled_rect( bounds.x + 2.f, bounds.y + 2.f, bounds.w - 4.f, bounds.h - 4.f, COL32( 54, 54, 54, 255 ) );
    }

    void draw_checkerboard( const rect& bounds, float step ) {
        auto& draw_list = gui_draw_list.get();

        const uint32_t light = COL32( 204, 204, 204, 255 );
        const uint32_t dark = COL32( 128, 128, 128, 255 );

        draw_list.add_filled_rect( bounds.x, bounds.y, bounds.w, bounds.h, light );

        ImVec2 min = ImVec2( bounds.x, bounds.y );
        ImVec2 max = ImVec2( bounds.x + bounds.w, bounds.y + bounds.h );

        int yi = 0;

        for ( float y = min.y; y < max.y; y += step, yi++ ) {
            float y1 = ImClamp( y, min.y, max.y ), y2 = ImMin( y + step, max.y );
            if ( y2 <= y1 )
                continue;

            for ( float x = min.x + ( yi & 1 ) * step; x < max.x; x += step * 2.f ) {
                float x1 = ImClamp( x, min.x, max.x ), x2 = ImMin( x + step, max.x );
                if ( x2 <= x1 )
                    continue;

                draw_list.add_filled_rect( x1, y1, x2 - x1, y2 - y1, dark );
            }
        }
    }

    vector4 rgb_to_hsv( uint32_t rgb ) {
        ImVec4 color_as_float = ImGui::ColorConvertU32ToFloat4( rgb );
        ImVec4 hsv;
        ImGui::ColorConvertRGBtoHSV( color_as_float.x, color_as_float.y, color_as_float.z, hsv.x, hsv.y, hsv.z );
        return vector4( hsv.x, hsv.y, hsv.z, hsv.w );
    }

    uint32_t hsv_to_rgb( float h, float s, float v ) {
        ImVec4 rgb = ImVec4( 1.f, 1.f, 1.f, 1.f );
        ImGui::ColorConvertHSVtoRGB( h, s, v, rgb.x, rgb.y, rgb.z );
        return ImGui::ColorConvertFloat4ToU32( rgb );
    }

    rect bounds_;
    vector2 cursor_;
    int previous_id_;
};

void gui::init() {
    gui_draw_list.construct();
}

void gui::destroy() {
    gui_draw_list.destruct();
}

bool init_gui = false;

void draw_gui_background() {
    renderer::draw_filled_rect( menu_bounds.x, menu_bounds.y, menu_bounds.w, menu_bounds.h, COL32( 40, 40, 40, 255 ) );
    renderer::draw_filled_rect( menu_bounds.x + 1.f, menu_bounds.y + 1.f, menu_bounds.w - 2.f, menu_bounds.h - 2.f, COL32( 61, 61, 61, 255 ) );
    renderer::draw_filled_rect( menu_bounds.x + 2.f, menu_bounds.y + 2.f, menu_bounds.w - 4.f, menu_bounds.h - 4.f, COL32( 54, 54, 54, 255 ) );

    rect top_bar = rect( menu_bounds.x + 2.f, menu_bounds.y + 2.f, menu_bounds.w - 4.f, 20.f );

    renderer::draw_filled_rect( top_bar.x, top_bar.y, top_bar.w, top_bar.h, COL32( 50, 50, 50, 255 ) );
    renderer::draw_filled_rect( top_bar.x, top_bar.y + top_bar.h, top_bar.w, 1.f, COL32( 38, 38, 38, 255 ) );
    renderer::draw_filled_rect( top_bar.x, top_bar.y + top_bar.h + 1.f, top_bar.w, 1.f, COL32( 61, 61, 61, 255 ) );

    renderer::draw_text( top_bar.x + 6.f, top_bar.y + 6.f, 0, 0, gradient_on[ 0 ], "sentian" );
    renderer::draw_text( top_bar.x + 43.f, top_bar.y + 6.f, 0, 0, COL32( 160, 160, 160, 255 ), ".gg" );

    rect bottom_bar = rect( menu_bounds.x + 2.f, menu_bounds.y + ( menu_bounds.h - 18.f ) - 4.f, menu_bounds.w - 4.f, 18.f );

    renderer::draw_filled_rect( bottom_bar.x, bottom_bar.y, bottom_bar.w, 1.f, COL32( 61, 61, 61, 255 ) );
    renderer::draw_filled_rect( bottom_bar.x, bottom_bar.y + 1.f, bottom_bar.w, 1.f, COL32( 38, 38, 38, 255 ) );
    renderer::draw_filled_rect( bottom_bar.x, bottom_bar.y + 2.f, bottom_bar.w, 18.f, COL32( 50, 50, 50, 255 ) );
}

enum tabs {
    combat,
    visuals,
    misc,
    settings
};

namespace combat_subtabs {
    enum : uint32_t {
        aimbot
    };
}

namespace visual_subtabs {
    enum : uint32_t {
        players,
        scientists,
        world,
        resources,
        deployables,
        vehicles,
        animals,
        traps,
        loot
    };
};

enum misc_subtabs {
    quality_of_life,
    movement,
};

uint32_t current_tab;
uint32_t current_subtab[ 4 ];

void tab( const char* label, uint32_t value, uint32_t* tab, rect& cursor, float padding, bool subtab = false ) {
    float width = renderer::calc_text_size( fonts::verdana, label ).x + padding;

    cursor.x -= width;

    const bool selected = value == *tab;

    if ( mouse_in_rect( rect( cursor.x, cursor.y, width, cursor.h ) ) && left_mouse_clicked ) {
        active_hash.current = 0ull;
        *tab = value;
    }

    if ( selected && !subtab ) {
        renderer::draw_filled_rect_with_flags( cursor.x, cursor.y, width, cursor.h - 1.f, gradient_on[ 0 ], 3.f, draw_flags::round_corners_top );
        renderer::draw_filled_rect( cursor.x, cursor.y + 3.f, width, cursor.h - 4.f, COL32( 38, 38, 38, 255 ) );

        renderer::draw_filled_rect_with_flags( cursor.x + 1.f, cursor.y + 1.f, width - 2.f, cursor.h - 1.f, COL32( 61, 61, 61, 255 ), 3.f, draw_flags::round_corners_top );
        renderer::draw_filled_rect_with_flags( cursor.x + 2.f, cursor.y + 2.f, width - 4.f, cursor.h, COL32( 54, 54, 54, 255 ), 3.f, draw_flags::round_corners_top );
    }

    renderer::draw_text( cursor.x + width / 2.f, cursor.y + 6.f, 0, text_flags::centered, selected ? gradient_on[ 0 ] : COL32( 160, 160, 160, 255 ), label );
}

void visual_impl( group_box& group_box, cvar_visual& visual, const char* label = nullptr, uint32_t max_distance = 500u ) {
    bool toggled = group_box.toggle( label ? label : visual.display_name, &visual.enabled );
    group_box.color_picker( &visual.color );

    if ( toggled ) {
        group_box.slider( S( "Max distance" ), S( "%dm" ), &visual.maximum_distance, 0u, max_distance );
    }
}

void player_visuals_impl( group_box& left, group_box& right, cvar_player_visuals& visuals ) {
    bool is_player_visuals = &visuals == &player_visuals;

    left.begin();

    left.toggle( S( "Enabled" ), &visuals.enabled );
    left.toggle( S( "Visible check" ), &visuals.visible_check );

    left.toggle( S( "Bounding box" ), &visuals.bounding_box );
    left.color_picker( &visuals.bounding_box_color );

    left.toggle( S( "Skeleton" ), &visuals.skeleton );
    left.color_picker( &visuals.skeleton_color );

    left.toggle( S( "Name" ), &visuals.name );
    left.color_picker( &visuals.name_color );

    if ( is_player_visuals ) {
        left.toggle( S( "Avatar" ), &player_avatar );
        left.toggle( S( "Team ID" ), &player_team_id );
        left.color_picker( &player_team_id_color );
    }

    left.toggle( S( "Held item" ), &visuals.held_item );
    left.color_picker( &visuals.held_item_color );

    if ( visuals.held_item ) {
        left.multi_combo_box( S( "Held item type" ), { 
            { S( "Icon" ), &visuals.held_item_icon }, 
            { S( "Text" ), &visuals.held_item_text } 
        } );
    }

    left.toggle( S( "Distance" ), &visuals.distance );
    left.color_picker( &visuals.distance_color );

    left.end();

    right.begin();

    right.toggle( S( "Chams" ), &chams );
    right.color_picker( &chams_color );

    if ( chams ) {
        right.combo_box( S( "Chams type" ), { S( "Solid" ), S( "Material" ) }, &chams_type );
    }

    right.toggle( S( "Glow" ), &glow );
    right.color_picker( &glow_outline_color );

    if ( glow ) {
        right.slider( S( "Glow blur scale" ), S( "%.2f" ), &glow_blur_scale, 0.f, 10.f );
        right.slider( S( "Glow outline scale" ), S( "%.2f" ), &glow_outline_scale, 0.f, 10.f );
    }

    right.end();
}

void gui::run() {
    auto& draw_list = gui_draw_list.get();

    draw_list.clear();

    update_input();

    if ( mouse_in_rect( rect( menu_bounds.x, menu_bounds.y, menu_bounds.w, 30.f ) ) && left_mouse_held ) {
        menu_bounds.x += mouse_position.current.x - mouse_position.previous.x;
        menu_bounds.y += mouse_position.current.y - mouse_position.previous.y;
    }

    draw_gui_background();

    rect tabs_cursor = rect( menu_bounds.x + menu_bounds.w - 6.f, menu_bounds.y + 3.f, 0.f, 20.f );

    tab( S( "Settings" ), tabs::settings, &current_tab, tabs_cursor, 20.f );
    tab( S( "Miscellaneous" ), tabs::misc, &current_tab, tabs_cursor, 20.f );
    tab( S( "Visuals" ), tabs::visuals, &current_tab, tabs_cursor, 20.f );
    tab( S( "Combat" ), tabs::combat, &current_tab, tabs_cursor, 20.f );

    rect subtabs_cursor = rect( menu_bounds.x + menu_bounds.w - 5.f, menu_bounds.y + 28.f, 0.f, 20.f );

    switch ( current_tab ) {
        case tabs::combat:
            tab( S( "Aimbot" ), combat_subtabs::aimbot, &current_subtab[ tabs::combat ], subtabs_cursor, 19.f, true );
            break;
        case tabs::visuals:
            tab( S( "Loot" ), visual_subtabs::loot, &current_subtab[ tabs::visuals ], subtabs_cursor, 19.f, true );
            tab( S( "Traps" ), visual_subtabs::traps, &current_subtab[ tabs::visuals ], subtabs_cursor, 19.f, true );
            tab( S( "Animals" ), visual_subtabs::animals, &current_subtab[ tabs::visuals ], subtabs_cursor, 19.f, true );
            tab( S( "Vehicles" ), visual_subtabs::vehicles, &current_subtab[ tabs::visuals ], subtabs_cursor, 19.f, true );
            tab( S( "Deployables" ), visual_subtabs::deployables, &current_subtab[ tabs::visuals ], subtabs_cursor, 19.f, true );
            tab( S( "Resources" ), visual_subtabs::resources, &current_subtab[ tabs::visuals ], subtabs_cursor, 19.f, true );
            tab( S( "World" ), visual_subtabs::world, &current_subtab[ tabs::visuals ], subtabs_cursor, 19.f, true );
            tab( S( "Scientists" ), visual_subtabs::scientists, &current_subtab[ tabs::visuals ], subtabs_cursor, 19.f, true );
            tab( S( "Players" ), visual_subtabs::players, &current_subtab[ tabs::visuals ], subtabs_cursor, 19.f, true );
            break;
        case tabs::misc:
            tab( S( "Movement" ), misc_subtabs::movement, &current_subtab[ tabs::misc ], subtabs_cursor, 19.f, true );
            tab( S( "Quality of life" ), misc_subtabs::quality_of_life, &current_subtab[ tabs::misc ], subtabs_cursor, 19.f, true );
            break;
    }

    group_box left = group_box( rect( menu_bounds.x + 10.f, menu_bounds.y + 50.f, 260.f, 400.f ), "test" );
    group_box right = group_box( rect( menu_bounds.x + 10.f + 260.f + 8.f, menu_bounds.y + 50.f, 260.f, 400.f ) );

    switch ( current_tab ) {
        case tabs::combat: {
            switch ( current_subtab[ tabs::combat ] ) {
                case combat_subtabs::aimbot: {
                    left.begin();

                    left.toggle( S( "Aimbot" ), &aimbot.enabled );

                    if ( aimbot.enabled ) {
                        left.combo_box( S( "Aimbot type" ), { S( "Memory" ), S( "Silent" ), S( "Manipulation" ) }, &aimbot.type );
                    }

                    left.slider( S( "Field of view" ), S( "%dpx" ), &aimbot.fov, 0u, 800u );

                    left.end();

                    right.begin();

                    right.toggle( S( "Recoil modifier" ), &recoil_modifier.enabled );
                    if ( recoil_modifier.enabled ) {
                        right.slider( S( "Yaw scale" ), S( "%.2f" ), &recoil_modifier.yaw_scale, 0.f, 1.f );
                        right.slider( S( "Pitch scale" ), S( "%.2f" ), &recoil_modifier.pitch_scale, 0.f, 1.f );
                    }

                    right.toggle( S( "Spread modifier" ), &spread_modifier.enabled );
                    if ( spread_modifier.enabled ) {
                        right.slider( S( "Spread scale" ), S( "%.2f" ), &spread_modifier.scale, 0.f, 1.f );
                    }

                    right.toggle( S( "Sway modifier" ), &sway_modifier.enabled );
                    if ( sway_modifier.enabled ) {
                        right.slider( S( "Sway scale" ), S( "%.2f" ), &sway_modifier.scale, 0.f, 1.f );
                    }

                    right.toggle( S( "Force automatic" ), &force_automatic );

                    right.toggle( S( "Thicker projectiles" ), &thicker_projectiles.enabled );
                    if ( thicker_projectiles.enabled ) {
                        right.slider( S( "Thickness" ), S( "%.2fm" ), &thicker_projectiles.thickness, 0.05f, 1.f );
                    }

                    right.toggle( S( "Faster projectiles" ), &faster_projectiles );

                    right.toggle( S( "Instant eoka" ), &instant_eoka );
                    right.toggle( S( "Instant compound bow charge" ), &instant_compound_bow );

                    if ( right.toggle( S( "Player hit override" ), &player_hit_override.enabled ) ) {
                        right.combo_box( S( "Hit bone" ), { S( "Head" ), S( "Neck" ), S( "Chest" ), S( "Random" ) }, &player_hit_override.bone );
                    }
                   
                    if ( right.toggle( S( "Hit patrol helicopter weakspots" ), &hit_patrol_helicopter_weakspots.enabled ) ) {
                        right.slider( S( "Chance" ), S( "%d%" ), &hit_patrol_helicopter_weakspots.chance, 0u, 100u );
                    }

                    right.end();

                    break;
                }
            }

            break;
        }

        case tabs::visuals: {
            switch ( current_subtab[ tabs::visuals ] ) {
                case visual_subtabs::players: {
                    player_visuals_impl( left, right, player_visuals );
                    break;
                }

                case visual_subtabs::scientists: {
                    player_visuals_impl( left, right, scientist_visuals );
                    break;
                }

                case visual_subtabs::world: {
                    left.begin();

                    visual_impl( left, dropped_weapon, S( "Weapon" ) );
                    visual_impl( left, dropped_construction, S( "Construction" ) );
                    visual_impl( left, dropped_items, S( "Items" ) );
                    visual_impl( left, dropped_resources, S( "Resources" ) );
                    visual_impl( left, dropped_attire, S( "Attire" ) );
                    visual_impl( left, dropped_tool, S( "Tool" ) );
                    visual_impl( left, dropped_medical, S( "Medical" ) );
                    visual_impl( left, dropped_food, S( "Food" ) );
                    visual_impl( left, dropped_ammunition, S( "Ammunition" ) );
                    visual_impl( left, dropped_traps, S( "Traps" ) );
                    visual_impl( left, dropped_misc, S( "Misc" ) );
                    visual_impl( left, dropped_component, S( "Component" ) );
                    visual_impl( left, dropped_electrical, S( "Electrical" ) );
                    visual_impl( left, dropped_fun, S( "Fun" ) );

                    left.end();

                    right.begin();

                    right.toggle( "Raids", &raid_visuals.enabled );
                    right.color_picker( &raid_visuals.color );

                    if ( raid_visuals.enabled ) {
                        right.multi_combo_box( S( "Explosives" ), {
                                { S( "Rocket" ), &raid_visuals.rocket },
                                { S( "High velocity rocket" ), &raid_visuals.high_velocity_rocket },
                                { S( "Incendiary rocket" ), &raid_visuals.incendiary_rocket },
                                { S( "Explosive ammo" ), &raid_visuals.explosive_ammo },
                                { S( "C4" ), &raid_visuals.c4 },
                                { S( "Satchel charge" ), &raid_visuals.satchel_charge },
                                { S( "HE grenade" ), &raid_visuals.he_grenade },
                                { S( "MLRS rocket" ), &raid_visuals.mlrs_rocket },
                            } );

                        right.slider( S( "Maximum time" ), S( "%us" ), &raid_visuals.maximum_time, 0u, 600u );
                        right.slider( S( "Maximum distance" ), S( "%um" ), &raid_visuals.maximum_distance, 0u, 5000u );
                    }

                    right.end();

                    break;
                }

                case visual_subtabs::resources: {
                    left.begin();

                    visual_impl( left, stone_ore, S( "Stone ore" ) );
                    visual_impl( left, metal_ore, S( "Metal ore" ) );
                    visual_impl( left, sulfur_ore, S( "Sulfur ore" ) );

                    left.end();

                    right.begin();

                    visual_impl( right, hemp );
                    visual_impl( right, mushroom );
                    
                    visual_impl( right, pumpkin );
                    visual_impl( right, corn );
                    visual_impl( right, potato );
                    visual_impl( right, stone );
                    visual_impl( right, metal );
                    visual_impl( right, sulfur );
                    visual_impl( right, wood );

                    right.end();

                    break;
                }

                case visual_subtabs::deployables: {
                    left.begin();
                    left.end();

                    right.begin();
                    right.end();

                    break;
                }

                case visual_subtabs::vehicles: {
                    left.begin();

                    visual_impl( left, rowboat );
                    visual_impl( left, rhib );
                    visual_impl( left, minicopter );
                    visual_impl( left, scrap_helicopter, S( "Scrap helicopter" ) );
                    visual_impl( left, attack_helicopter, S( "Attack helicopter" ) );
                    visual_impl( left, tugboat );
                    visual_impl( left, submarine );
                    visual_impl( left, hot_air_balloon, S( "Hot air balloon" ) );
                    visual_impl( left, diver_propulsion_vehicle, S( "Diver propulsion vehicle" ) );

                    left.end();

                    right.begin();
                 
                    visual_impl( right, patrol_helicopter, S( "Patrol helicopter" ), 5000u );
                    visual_impl( right, bradley );

                    right.end();

                    break;
                }

                case visual_subtabs::animals: {
                    left.begin();

                    visual_impl( left, bear );
                    visual_impl( left, boar );
                    visual_impl( left, chicken );
                    visual_impl( left, horse );
                    visual_impl( left, stag );
                    visual_impl( left, wolf );
                    visual_impl( left, shark );
                    visual_impl( left, bee_swarm, S( "Bee swarm" ) );
                    visual_impl( left, tiger );
                    visual_impl( left, panther );
                    visual_impl( left, crocodile );
                    visual_impl( left, snake );

                    left.end();

                    right.begin();

                    right.end();

                    break;
                }

                case visual_subtabs::traps: {
                    left.begin();

                    visual_impl( left, shotgun_trap, S( "Shotgun trap" ) );
                    visual_impl( left, flame_turret, S( "Flame turret" ) );
                    visual_impl( left, land_mine, S( "Land mine" ) );
                    visual_impl( left, bear_trap, S( "Bear trap" ) );
                    visual_impl( left, sam_site, S( "SAM site" ) );

                    left.end();

                    right.begin();
                    right.end();

                    break;
                }

                case visual_subtabs::loot: {
                    left.begin();

                    visual_impl( left, red_barrel, S( "Red barrel" ) );
                    visual_impl( left, blue_barrel, S( "Blue barrel" ) );
                    visual_impl( left, oil_barrel, S( "Oil barrel" ) );
                    visual_impl( left, diesel_barrel, S( "Diesel barrel" ) );
                    visual_impl( left, minecart, S( "Minecart" ) );
                    visual_impl( left, vehicle_parts, S( "Vehicle parts" ) );
                    visual_impl( left, tech_parts, S( "Tech parts" ) );

                    left.end();

                    right.begin();

                    visual_impl( right, food_crate, S( "Food crate" ) );
                    visual_impl( right, medical_crate, S( "Medical crate" ) );
                    visual_impl( right, tool_crate, S( "Tool crate" ) );
                    visual_impl( right, ammo_crate, S( "Ammo crate" ) );
                    visual_impl( right, fuel_crate, S( "Fuel crate" ) );
                    visual_impl( right, basic_crate, S( "Basic crate" ) );
                    visual_impl( right, normal_crate, S( "Normal crate" ) );
                    visual_impl( right, underwater_crate, S( "Underwater crate" ) );
                    visual_impl( right, military_crate, S( "Military crate" ) );
                    visual_impl( right, elite_crate, S( "Elite crate" ) );
                    visual_impl( right, bradley_crate, S( "Bradley crate" ) );
                    visual_impl( right, heli_crate, S( "Heli crate" ) );

                    right.end();

                    break;
                }
            }

            break;
        }

        case tabs::misc: {
            switch ( current_subtab[ tabs::misc ] ) {
                case misc_subtabs::quality_of_life: {
                    left.begin();
                    left.toggle( S( "Instant loot" ), &instant_loot );
                    left.toggle( S( "Loot without untie" ), &loot_without_untie );

                    left.toggle( S( "Field of view modifier" ), &fov_modifier.enabled );
                    if ( fov_modifier.enabled ) {
                        left.slider( S( "Field of view" ), S( "%.0f" ), &fov_modifier.fov, 0.f, 140.f );
                    }

                    left.end();

                    right.begin();

                    right.toggle( S( "Override night" ), &override_night.enabled );
                    right.color_picker( &ambient_color, false );
                    right.keybind( &override_night.key );

                    if ( override_night.enabled ) {
                        right.slider( S( "Ambient multiplier" ), S( "%.2fx" ), &ambient_multiplier, 0.f, 3.f );
                        right.slider( S( "Ambient saturation" ), S( "%.2f" ), &ambient_saturation, 0.f, 0.5f );
                    }

                    right.end();

                    break;
                }

                case misc_subtabs::movement: {
                    left.begin();
                    left.toggle( S( "Spider-man" ), &spider_man );
                    left.toggle( S( "Infinite jump" ), &infinite_jump );
                    left.toggle( S( "Omnisprint" ), &omnisprint );
                    left.toggle( S( "No attack restrictions" ), &no_attack_restrictions.enabled );
                    left.toggle( S( "On ladder" ), &on_ladder );
                    left.end();

                    right.begin();

                    right.toggle( S( "Admin flags" ), &admin_flags );
                    right.toggle( S( "Block server commands" ), &block_server_commands );

                    right.end();

                    break;
                }
            }

            break;
        }
    }

    draw_list.render();
}
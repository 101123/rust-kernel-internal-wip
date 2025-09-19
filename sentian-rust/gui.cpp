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
state_history2<Vector2> mouse_position;
state_history2<uint64_t> active_hash;

rect menu_bounds = rect( 400.f, 400.f, 548.f, 480.f );

bool left_mouse_clicked;
bool left_mouse_held;

Vector4 color_picker_hsv;

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

    Vector2 mouse_pos = unity::input::get_mouse_position();
    mouse_pos.y = 1440.f - mouse_pos.y;

    mouse_position = {
        .previous = mouse_position.current,
        .current = mouse_pos
    };
}

bool mouse_in_rect( const rect& bounds ) {
    const Vector2& position = mouse_position.current;

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

    static inline Vector2 toggle_movement[] = {
        { 0.f, 0.f }, /* None */
        { 0.f, 18.f }, /* Toggle -> Toggle */
        { 0.f, 36.f }, /* Slider -> Toggle */
        { 0.f, 50.f } /* Combobox -> Toggle */
    };

    bool toggle( const char* label, bool* value ) {
        auto& draw_list = gui_draw_list.get();

        cursor_ += toggle_movement[ ( int )previous_id_ ];

        draw_list.push_z_index( 2 );

        const Vector2 position = Vector2( bounds_.x + cursor_.x, bounds_.y + cursor_.y );
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

        draw_list.add_text( position.x + 18.f, position.y - 1.f, fonts::verdana, text_flags::none, COL32( 160, 160, 160, 255 ), label );

        draw_list.pop_z_index();

        previous_id_ = elements::toggle;

        return *value;
    }

    void color_picker( uint32_t* value ) {
        auto& draw_list = gui_draw_list.get();

        draw_list.push_z_index( 2 );

        const Vector2 position = Vector2( bounds_.x + cursor_.x, bounds_.y + cursor_.y );
        const rect preview_bounds = rect( position.x + bounds_.w - 44.f, position.y, 20.f, 10.f );

        const float color_picker_padding = 6.f;
        const float sv_percentage = 0.83f;

        const rect color_picker_bounds = rect( preview_bounds.x + preview_bounds.w + 4.f, preview_bounds.y, 200.f, 200.f );
        const rect sv_square_bounds = rect( color_picker_bounds.x + color_picker_padding, color_picker_bounds.y + color_picker_padding, color_picker_bounds.w * sv_percentage, color_picker_bounds.h * sv_percentage );
        const rect hue_bar_bounds = rect( sv_square_bounds.x + sv_square_bounds.w + color_picker_padding - 2.f, sv_square_bounds.y, color_picker_bounds.w - sv_square_bounds.w - ( color_picker_padding * 3.f ) + 2.f, sv_square_bounds.h );

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

            if ( mouse_in_rect( sv_square_bounds_ ) && left_mouse_held ) {
                color_picker_hsv.y = ImSaturate( ( mouse_position.current.x - sv_square_bounds_.x ) / ( sv_square_bounds_.w ) );
                color_picker_hsv.z = 1.f - ImSaturate( ( mouse_position.current.y - sv_square_bounds_.y ) / ( sv_square_bounds_.h ) );
            }

            else if ( mouse_in_rect( hue_bar_bounds_ ) && left_mouse_held ) {
                color_picker_hsv.x = ImSaturate( ( mouse_position.current.y - hue_bar_bounds_.y ) / ( hue_bar_bounds_.h ) );
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
            draw_list.add_filled_rect( sv_cursor_rect.x + 1.f, sv_cursor_rect.y + 1.f, sv_cursor_rect.w - 2.f, sv_cursor_rect.h - 2.f, gradient_on[ 0 ] );

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
            draw_list.add_filled_rect( hue_cursor_rect.x + 1.f, hue_cursor_rect.y + 1.f, hue_cursor_rect.w - 2.f, hue_cursor_rect.h - 2.f, gradient_on[ 0 ] );

            *value = hsv_to_rgb( color_picker_hsv.x, color_picker_hsv.y, color_picker_hsv.z );

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

    static inline Vector2 slider_movement[] = {
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

        const Vector2 position = Vector2( bounds_.x + cursor_.x, bounds_.y + cursor_.y );
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

        draw_list.add_text( slider_bounds.x, position.y, fonts::verdana, text_flags::none, COL32( 160, 160, 160, 255 ), label );

        draw_styled_rect( slider_bounds );

        const rect draw_bounds = rect( slider_bounds.x + 3.f, slider_bounds.y + 3.f, slider_bounds.w - 6.f, slider_bounds.h - 6.f );
        float fill_width = draw_bounds.w * std::clamp( static_cast< float >( *value - min ) / static_cast< float >( max - min ), 0.f, 1.f );

        draw_list.add_filled_rect_multi_color( draw_bounds.x, draw_bounds.y, fill_width, draw_bounds.h, gradient_on );

        //renderer.draw_string_a( draw_bounds.x + fill_width, draw_bounds.y, Fonts::SmallFonts, TextFlags::Centered, COL32( 255, 255, 255, 255 ), FMT( fmt, value ) );

        draw_list.pop_z_index();

        previous_id_ = elements::slider;
    }

    static inline Vector2 combo_box_movement[] = {
        { 0.f, 0.f }, /* None */
        { 0.f, 18.f }, /* Toggle -> Combobox */
        { 0.f, 29.f }, /* Slider -> Combobox */
        { 0.f, 50.f } /* Combobox -> Combobox */
    };

    template <typename T>
    void combo_box( const char* label, std::initializer_list<const char*> options, T& value ) {
        auto& draw_list = gui_draw_list.get();

        static_assert( std::is_integral_v<T> );

        cursor_ += slider_movement[ ( int )previous_id_ ];

        draw_list.push_z_index( 3 );

        const Vector2 position = Vector2( bounds_.x + cursor_.x, bounds_.y + cursor_.y );
        const rect combo_bounds = rect( position.x + 18.f, position.y + 16.f, bounds_.w - 60.f, 20.f );
        const rect options_bounds = rect( combo_bounds.x, combo_bounds.y + 21.f, combo_bounds.w, options.size() * 20.f );

        const bool hovered = mouse_in_rect( combo_bounds );

        const uint64_t hash = ( uint64_t )&value;
        const bool active = active_hash.current == hash;

        if ( hovered && left_mouse_clicked ) {
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
                    value = static_cast< T >( i );
                    active_hash.current = 0ull;
                }

                draw_list.add_text( options_bounds.x + 6.f, options_bounds.y + 4.f + ( i * 20.f ), fonts::verdana, text_flags::none, hovered ? gradient_on[ 0 ] : COL32( 160, 160, 160, 255 ), options.begin()[ i ] );
            }
        }

        draw_list.add_text( position.x + 18.f, position.y, fonts::verdana, text_flags::none, COL32( 160, 160, 160, 255 ), label );

        draw_styled_rect( combo_bounds );

        draw_list.add_text( position.x + 24.f, position.y + 20.f, fonts::verdana, text_flags::none, COL32( 160, 160, 160, 255 ), options.begin()[ value ] );

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

    Vector4 rgb_to_hsv( uint32_t rgb ) {
        ImVec4 color_as_float = ImGui::ColorConvertU32ToFloat4( rgb );
        ImVec4 hsv;
        ImGui::ColorConvertRGBtoHSV( color_as_float.x, color_as_float.y, color_as_float.z, hsv.x, hsv.y, hsv.z );
        return Vector4( hsv.x, hsv.y, hsv.z, hsv.w );
    }

    uint32_t hsv_to_rgb( float h, float s, float v ) {
        ImVec4 rgb = ImVec4( 1.f, 1.f, 1.f, 1.f );
        ImGui::ColorConvertHSVtoRGB( h, s, v, rgb.x, rgb.y, rgb.z );
        return ImGui::ColorConvertFloat4ToU32( rgb );
    }

    rect bounds_;
    Vector2 cursor_;
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

    rect bottom_bar = rect( menu_bounds.x + 2.f, menu_bounds.y + ( menu_bounds.h - 18.f ) - 4.f, menu_bounds.w - 4.f, 18.f );

    renderer::draw_filled_rect( bottom_bar.x, bottom_bar.y, bottom_bar.w, 1.f, COL32( 61, 61, 61, 255 ) );
    renderer::draw_filled_rect( bottom_bar.x, bottom_bar.y + 1.f, bottom_bar.w, 1.f, COL32( 38, 38, 38, 255 ) );
    renderer::draw_filled_rect( bottom_bar.x, bottom_bar.y + 2.f, bottom_bar.w, 18.f, COL32( 50, 50, 50, 255 ) );
}

void gui::run() {
    auto& draw_list = gui_draw_list.get();

    draw_list.clear();

    update_input();

    char buffer[ 64 ];
    snprintf( buffer, sizeof( buffer ), "%.2f %.2f %d\n", mouse_position.current.x, mouse_position.current.y, left_mouse_held );
    renderer::draw_text( 100.f, 100.f, fonts::verdana, text_flags::none, COL32_RED, buffer );

    if ( mouse_in_rect( rect( menu_bounds.x, menu_bounds.y, menu_bounds.w, 30.f ) ) && left_mouse_held ) {
        menu_bounds.x += mouse_position.current.x - mouse_position.previous.x;
        menu_bounds.y += mouse_position.current.y - mouse_position.previous.y;
    }

    draw_gui_background();

    group_box test = group_box( rect( menu_bounds.x + 10.f, menu_bounds.y + 50.f, 260.f, 400.f ), "test" );

    test.begin();

    test.toggle( "Glow", &glow );
    test.color_picker( &glow_outline_color );

    if ( glow ) {
        test.slider( "Glow blur scale", "%.2f", &glow_blur_scale, 0.f, 10.f );
        test.slider( "Glow outline scale", "%.2f", &glow_outline_scale, 0.f, 10.f );
    }

    test.end();

    group_box test2 = group_box( rect( menu_bounds.x + 10.f + 260.f + 8.f, menu_bounds.y + 50.f, 260.f, 400.f ) );

    test2.begin();

    test2.end();

    draw_list.render();
}
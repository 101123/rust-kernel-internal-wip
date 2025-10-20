#include "notifications.h"
#include "util.h"
#include "renderer.h"
#include "animated_value.h"
#include "math/rect.h"

enum class notification_state {
	enter,
	exit,
	done
};

class notification {
public:
	notification() = default;
	notification( const char* message ) {
		strcpy_s( message_, sizeof( message_ ), message );
		init();
	}

	notification( const wchar_t* message ) {
		renderer::wstr_to_utf8( message, message_, sizeof( message_ ) );
		init();
	}

	void init() {
		// Cache text size
		size_ = renderer::calc_text_size( fonts::consolas_bold, message_ );
		
		// Start the enter animation
		state_ = notification_state::enter;
		value_.set( 0.f );
		value_.animate_to( 1.f, 0.5f, 3.f );
	}

	bool draw( float delta_time, int32_t& count ) {
		if ( state_ == notification_state::enter ) {
			bool finished = !value_.step( delta_time, ease_out_cubic );

			rect bounds( 8.f * value_.get(), 8.f + ( count++ * 22.f ), size_.x + 20.f, 18.f );

			draw_notification_rect( bounds.x, bounds.y, bounds.w, bounds.h, 0.9f, COL32( 0, 0, 0, 128 ) );
			renderer::draw_text( bounds.x + 10.f, bounds.y + 5.f, fonts::consolas_bold, text_flags::outline, COL32_WHITE, message_ );

			if ( finished ) {
				state_ = notification_state::exit;
				value_.set( 0.f );
				value_.animate_to( 1.f, 1.f, 1.f );
			}
		}

		else if ( state_ == notification_state::exit ) {
			bool finished = !value_.step( delta_time, ease_out_cubic );

			if ( finished ) {
				state_ = notification_state::done;
			}
		}

		return state_ != notification_state::done;
	}

private:
	static void draw_notification_rect( float x, float y, float width, float height, float percentage, uint32_t color ) {
		float center_width = width * percentage;
		float side_width = width * ( ( 1.f - percentage ) / 2.f );

		uint32_t colors_left[ 4 ] = {
			color & 0x00FFFFFF,
			color,
			color, 
			color & 0x00FFFFFF  
		};

		uint32_t colors_right[ 4 ] = {
			color,
			color & 0x00FFFFFF,
			color & 0x00FFFFFF,
			color
		};

		renderer::draw_filled_rect_multi_color( x, y, side_width, height, colors_left );
		renderer::draw_filled_rect( x + side_width, y, center_width, height, color );
		renderer::draw_filled_rect_multi_color( x + side_width + center_width, y, side_width, height, colors_right );
	}

	static float ease_out_cubic( float t ) {
		return 1.f - powf( 1.f - t, 3.f );
	}

	char message_[ 256 ];
	vector2 size_;
	notification_state state_;
	animated_value<float> value_;
};

util::fifo_queue<notification, 256> queue;
util::mutex lock;

void notifications::push( const char* message ) {
	util::scoped_spinlock guard( &lock );

	queue.emplace_push( message );
}

void notifications::push( const wchar_t* message ) {
	util::scoped_spinlock guard( &lock );

	queue.emplace_push( message );
}

void notifications::draw( float delta_time ) {
	util::scoped_spinlock guard( &lock );

	int32_t notification_count = 0, pop_count = 0;

	queue.for_each( [ & ]( notification& notification, size_t _ ) {
		if ( !notification.draw( delta_time, notification_count ) ) {
			pop_count++;
		}
	} );

	for ( int32_t i = 0; i < pop_count; i++ ) {
		queue.pop();
	}
 }
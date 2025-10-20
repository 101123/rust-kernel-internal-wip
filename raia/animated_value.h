#pragma once

#include <algorithm>

template <typename T>
class animated_value {
public:
	using easing_function = float( * )( float );

	void animate_to( T to, float animation_duration, float total_duration ) {
		from_ = current_;
		to_ = to;
		elapsed_ = 0.f;
		animation_duration_ = animation_duration;
		total_duration_ = total_duration;
		animating_ = true;
	}

	T get() {
		return current_;
	}

	void set( T value ) {
		current_ = value;
	}

	bool step( float delta_time, easing_function ease ) {
		if ( !animating_ )
			return false;

		if ( ( elapsed_ += delta_time ) > total_duration_ ) {
			elapsed_ = total_duration_;
			animating_ = false;
		}

		current_ = from_ + ( to_ - from_ ) * ease( std::clamp( elapsed_ / animation_duration_, 0.f, 1.f ) );
		return animating_;
	}

	bool animating() {
		return animating_;
	}

private:
	T from_, current_, to_;
	float elapsed_, animation_duration_, total_duration_;
	bool animating_;
};
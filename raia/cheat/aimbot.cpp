#include "aimbot.h"
#include "math/vec2.h"
#include "vars.h"
#include "sdk/sdk.h"

#include <algorithm>

class line {
public:
	vector3 point0, point1;

	vector3 closest_2d_point( vector3 pos ) {
		vector2 p0_xz( point0.x, point0.z );
		vector2 p1_xz( point1.x, point1.z );
		vector2 pos_xz( pos.x, pos.z );

		vector2 line = p1_xz - p0_xz;
		float len = vector2::magnitude( line );

		if ( len < 0.001f )
			return point0;

		vector2 dir = line / len;
		float proj = vector2::dot( pos_xz - p0_xz, dir );
		float t = std::clamp( proj / len, 0.f, 1.f );

		return point0 + ( point1 - point0 ) * t;
	}

	vector3 closest_point( vector3 pos ) {
		vector3 a = point1 - point0;
		float magnitude = vector3::magnitude( a );
		if ( magnitude < 0.001f ) {
			return point0;
		}

		vector3 vector = a / magnitude;
		return point0 + ( vector * std::clamp( vector3::dot( pos - point0, vector ), 0.f, magnitude ) );
	}
};

bool prediction_no_velocity( const vector3& origin, vector3& target, float& travel_time ) {
	vector2 target_2d = vector2( target.x, target.z );
	vector3 target_3d = target;

	for ( int32_t i = 0; i < 16; i++ ) {
		vector3 position = origin, previous_position = position;
		vector3 velocity = vector3::normalize( target - position ) * ( faster_projectiles ? held_weapon.max_velocity : held_weapon.velocity );

		for ( float t = 0.f, dt = 0.03125f; t < 8.f; t += dt ) {
			position += velocity * dt;
			velocity.y -= 9.81f * held_weapon.gravity_modifier * dt;
			velocity -= velocity * held_weapon.drag * dt;

			line line( previous_position, position );

			vector3 closest_2d_point = line.closest_2d_point( target_3d );

			if ( vector2::distance( closest_2d_point, target_2d ) < 0.001f ) {
				vector3 closest_3d_point = line.closest_point( target_3d );

				if ( vector3::distance( closest_3d_point, target_3d ) < 0.01f ) {
					travel_time = t - dt + ( dt * ( vector3::distance( previous_position, closest_3d_point ) / vector3::magnitude( velocity * dt ) ) );
					return true;
				}

				target.y += ( target_3d.y - closest_3d_point.y );
				break;
			}

			previous_position = position;
		}
	}

	return false;
}

bool prediction( const vector3& origin, vector3& target, const vector3& target_velocity ) {
	vector3 target_position = target;
	float travel_time = 0.f;

	if ( prediction_no_velocity( origin, target, travel_time ) ) {
		if ( target_velocity == vector3() )
			return true;

		// Extrapolate target position
		target = target_position + ( target_velocity * travel_time );

		return prediction_no_velocity( origin, target, travel_time );
	}

	return false;
}

vector3 get_player_velocity( const cached_player& cached_player ) {
	vector3 displacement;
	float time = 0.f;

	const cached_velocity_data& velocity_data = cached_player.velocity_data;

	for ( int32_t i = 0; i < velocity_data.index - 1; i++ ) {
		displacement += velocity_data.snapshots[ i + 1 ].position - velocity_data.snapshots[ i ].position;
		time += velocity_data.snapshots[ i + 1 ].time - velocity_data.snapshots[ i ].time;
	}

	if ( time == 0.f ) {
		return vector3();
	}

	return displacement / time;
}

bool calc_angle( const vector3& src, const vector3& dst, vector3& result ) {
	vector3 direction = dst - src;
	if ( vector3::sqr_magnitude( direction ) < 0.001f )
		return false;

	result = vector3(
		math::rad2deg( -asinf( direction.y / vector3::magnitude( direction ) ) ),
		math::rad2deg( atan2f( direction.x, direction.z ) ),
		0.f
	);

	return true;
}

inline void normalize( float& pitch, float& yaw ) {
	if ( pitch < -89.f ) pitch = -89.f;
	else if ( pitch > 89.f ) pitch = 89.f;
	if ( yaw < -180.f ) yaw += 360.f;
	else if ( yaw >= 180.f ) yaw -= 360.f;
}

inline vector2 angular_interpolate( const vector2& a, const vector2& b, float t ) {
	if ( t == 1.f )
		return b;

	float pitch = a.x + t * ( b.x - a.x ), yaw;

	if ( fabsf( b.y - a.y ) > 180.f ) {
		// Go around in the opposite direction
		yaw = a.y + t * ( b.y - a.y > 0.f ? -1.f : 1.f ) * ( 360.0f - fabsf( b.y - a.y ) );
	}
	else {
		yaw = a.y + t * ( b.y - a.y );
	}

	normalize( pitch, yaw );

	return vector2( pitch, yaw );
}

vector2 finalize_angles( const vector2& from, const vector2& to ) {
	if ( aimbot.smoothing == 0.f ) {
		vector2 angles = to;
		normalize( angles.x, angles.y );
		return angles;
	}

	return angular_interpolate( from, to, ( 1.f - aimbot.smoothing ) * ( unity::time::get_delta_time() * 30.f ) );
}

void memory_aimbot( rust::base_projectile* weapon, const std::pair<rust::base_player*, cached_player>* target ) {
	rust::player_input* input = local_player.entity->input;
	if ( !is_valid_ptr( input ) )
		return;

	vector3 target_position = target->second.bone_data.positions[ 1 ];
	float travel_time = 0.f;

	if ( !prediction( local_player.eyes_position, target_position, get_player_velocity( target->second ) ) )
		return;

	vector3 angle;
	if ( !calc_angle( local_player.eyes_position, target_position, angle ) )
		return;

	vector2 body_angles = input->body_angles;

	if ( aimbot.recoil > 0.f ) {
		sys::list<rust::held_entity::punch_entry*>* punches = weapon->punches;

		if ( is_valid_ptr( punches ) && is_valid_ptr( punches->items ) ) {
			float delta_time = unity::time::get_delta_time();

			for ( int32_t i = 0; i < punches->size; i++ ) {
				rust::held_entity::punch_entry* punch_entry = punches->at( i );
				if ( !is_valid_ptr( punch_entry ) )
					continue;

				vector3 amount = punch_entry->amount * ( delta_time / punch_entry->duration );

				if ( vector3::sqr_magnitude( amount ) >= vector3::sqr_magnitude( punch_entry->amount - punch_entry->amount_added ) ) {
					amount = punch_entry->amount - punch_entry->amount_added;
				}

				body_angles += amount * aimbot.recoil;
			}
		}
	}

	rust::base_entity* parent_entity = local_player.entity->parent_entity;

	if ( is_valid_ptr( parent_entity ) ) {
		unity::transform* transform = parent_entity->get_transform();

		if ( is_valid_ptr( transform ) ) {
			angle.y -= transform->get_euler_angles().y;
		}
	}

	input->body_angles = finalize_angles( body_angles, vector2( angle.x, angle.y ) );
}

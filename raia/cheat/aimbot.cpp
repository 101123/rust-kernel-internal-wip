#include "aimbot.h"

#include "math/vec2.h"
#include "vars.h"

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

bool prediction( const vector3& origin, vector3& target, float& travel_time ) {
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
					travel_time = t;
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
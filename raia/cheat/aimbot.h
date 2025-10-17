#pragma once

#include "math/vec3.h"
#include "cheat/entities.h"

bool prediction( const vector3& origin, vector3& target, float& travel_time );
void memory_aimbot( rust::base_projectile* weapon, const std::pair<rust::base_player*, cached_player>* target );
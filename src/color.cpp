#include "../include/ray.h"

vec3		color(const ray & r)
{
	vec3	unit_direction;
	float	t;
	
	unit_direction = unit_vector(r.direction());
	t = 0.5*(unit_direction.y() + 1.0);
	return ((1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.6, 0.7, 1.0));
}

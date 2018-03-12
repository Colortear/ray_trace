#include "../include/raytrace.h"
#include <float.h>

vec3		color(const ray &r, hitable *world)
{
	hit_record	rec;
	vec3		unit_direction;
	float		t;

	if (world->hit(r, 0.0, FLT_MAX, rec))
	{
		return (0.5 * vec3(rec.normal.x()+1,
						 rec.normal.y()+1,
						 rec.normal.z()+1));
	}
	else
	{
		unit_direction = unit_vector(r.direction());
		t = 0.5 * (unit_direction.y() * 1.0);
		return ((1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0));
	}
	return (vec3(0.0,0.0,0.0));
}

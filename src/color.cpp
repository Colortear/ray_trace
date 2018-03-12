#include "../include/raytrace.h"
#include <float.h>

vec3		color(const ray &r, hitable *world)
{
	hit_record	rec;
	vec3		unit_direction;
	vec3		target;
	float		t;

	if (world->hit(r, 0.001, FLT_MAX, rec))
	{
		target = rec.p + rec.normal + random_in_unit_sphere();
		return (0.5 * color(ray(rec.p, target - rec.p), world));
	}
	else
	{
		unit_direction = unit_vector(r.direction());
		t = 0.5 * (unit_direction.y() + 1.0);
		return ((1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0));
	}
	return (vec3(0.0,0.0,0.0));
}

#include "../include/raytrace.h"

bool	hit_sphere(const vec3 &center, float radius, const ray &r)
{
	vec3 	oc;
	float	a;
	float	b;
	float	c;
	float	discriminant;

	oc = r.origin() - center;
	a = dot(r.direction(), r.direction());
	b = 2.0 * dot(oc, r.direction());
	c = dot(oc, oc) - radius * radius;
	discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

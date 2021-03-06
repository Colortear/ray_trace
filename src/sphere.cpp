#include "../include/raytrace.h"
#include "../include/sphere.h"

bool	sphere::hit(const ray &r, float t_min, float t_max,
		hit_record &rec) const
{
	vec3 	oc;
	float	a;
	float	b;
	float	c;
	float	discriminant;
	float	temp;

	oc = r.origin() - center;
	a = dot(r.direction(), r.direction());
	b = dot(oc, r.direction());
	c = dot(oc, oc) - radius * radius;
	discriminant = b * b - a * c;
	if (discriminant > 0)
	{
		temp = (-b - sqrt(b*b-a*c))/a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return (true);
		}
		temp = (-b + sqrt(b*b-a*c))/a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = r.point_at_parameter(rec.t);
			rec.normal = (rec.p - center) / radius;
			return (true);
		}
	}
	return (false);
}

vec3	random_in_unit_sphere(void)
{
	vec3	p;
	do {
		p = 2.0*vec3(drand48(),drand48(),drand48()) - vec3(1,1,1);
	} while (p.squared_length() >= 1.0);
	return (p);
}

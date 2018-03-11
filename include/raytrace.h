#ifndef RAYTRACE_H
# define RAYTRACE_H

# include "ray.h"
# include "vec3.h"

vec3	color(const ray &r);
bool	hit_sphere(const vec3 &center, float radius, const ray &r);

#endif /* RAYTRACE_H */

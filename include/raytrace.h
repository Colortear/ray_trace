#ifndef RAYTRACE_H
# define RAYTRACE_H

# include "ray.h"
# include "vec3.h"
# include "sphere.h"
# include "hitable.h"
# include "hitable_list.h"

vec3	color(const ray &r, hitable *world);
float	hit_sphere(const vec3 &center, float radius, const ray &r);

#endif /* RAYTRACE_H */

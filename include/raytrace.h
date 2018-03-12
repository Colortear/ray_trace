#ifndef RAYTRACE_H
# define RAYTRACE_H

# include "ray.h"
# include "vec3.h"
# include "sphere.h"
# include "hitable.h"
# include "hitable_list.h"
# include "camera.h"

vec3	color(const ray &r, hitable *world);
vec3	random_in_unit_sphere(void);
float	hit_sphere(const vec3 &center, float radius, const ray &r);

#endif /* RAYTRACE_H */

#include <iostream>
#include "../include/raytrace.h"

int main(void)
{
	hitable	*list[2];
	hitable	*world;
	camera	cam;
	vec3	col;
//	vec3	p;
	ray		r;
	float	u;
	float	v;
	int		nx;
	int		ny;
	int		ns;
	int		ir;
	int		ig;
	int		ib;

	nx = 600;
	ny = 300;
	ns = 300;
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	list[0] = new sphere(vec3(0,0,-1), 0.5);
	list[1] = new sphere(vec3(0,-100.5,-1), 100);
	world = new hitable_list(list,2);
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			col = vec3(0, 0, 0);
			for (int s = 0; s < ns; s++)
			{
				u = float(i + drand48()) / float(nx);
				v = float(j + drand48()) / float(ny);
				r = cam.get_ray(u, v);
//				p = r.point_at_parameter(2.0);
				col += color(r, world);
			}
			col /= float(ns);
			ir = int(255.99*col[0]);
			ig = int(255.99*col[1]);
			ib = int(255.99*col[2]);
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
}

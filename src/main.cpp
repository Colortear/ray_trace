#include <iostream>
#include "../include/raytrace.h"

int main(void)
{
	vec3	col;
	vec3	lower_left_corner;
	vec3	horizontal;
	vec3	vertical;
	vec3	origin;
//	vec3	p;
	hitable	*list[2];
	hitable	*world;
	ray		r;
	float	u;
	float	v;
	int		nx;
	int		ny;
	int		ir;
	int		ig;
	int		ib;

	nx = 600;
	ny = 300;
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	lower_left_corner = vec3(-2.0, -1.0, -1.0);
	horizontal = vec3(4.0, 0.0, 0.0);
	vertical = vec3(0.0, 2.0, 0.0);
	origin = vec3(0.0, 0.0, 0.0);
	list[0] = new sphere(vec3(0,0,-1), 0.5);
	list[1] = new sphere(vec3(0,-100.5,-1), 100);
	world = new hitable_list(list, 2);
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			u = float(i) / float(nx);
			v = float(j) / float(ny);
			r = ray(origin, lower_left_corner + u*horizontal + v*vertical);
//			p = r.point_at_parameter(2.0);
//			if (p.e[0])
//				(vec3)p;
			col = color(r, world);
			ir = int(255.99*col[0]);
			ig = int(255.99*col[1]);
			ib = int(255.99*col[2]);
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	return (0);
}

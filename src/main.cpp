#include <iostream>
#include "../include/raytrace.h"

int main(void)
{
	vec3	col;
	vec3	lower_left_corner;
	vec3	horizontal;
	vec3	vertical;
	vec3	origin;
	ray		r;
	float	u;
	float	v;
	int		nx;
	int		ny;
	int		ir;
	int		ig;
	int		ib;

	nx = 200;
	ny = 100;
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	lower_left_corner = vec3(-2.0, -1.0, -1.0);
	horizontal = vec3(4.0, 0.0, 0.0);
	vertical = vec3(0.0, 2.0, 0.0);
	origin = vec3(0.0, 0.0, 0.0);
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			u = float(i) / float(nx);
			v = float(j) / float(ny);
			r = ray(origin, lower_left_corner + u*horizontal + v*vertical);
			col = color(r);
			ir = 255.99*col[0];
			ig = 255.99*col[1];
			ib = 255.99*col[2];
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	return (0);
}

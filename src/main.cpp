#include <iostream>
#include "../include/vec3.h"

int main(void)
{
	vec3	col;
	int		nx;
	int		ny;
	int		ir;
	int		ig;
	int		ib;

	nx = 200;
	ny = 100;
	std::cout << "P3\n" << nx << " " << ny << "\n255\n";
	for (int j = ny - 1; j >= 0; j--)
	{
		for (int i = 0; i < nx; i++)
		{
			col = vec3(float(i) / float(nx), float(j) / float(ny), 0.2);
			ir = 255.99*col[0];
			ig = 255.99*col[1];
			ib = 255.99*col[2];
			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	return (0);
}

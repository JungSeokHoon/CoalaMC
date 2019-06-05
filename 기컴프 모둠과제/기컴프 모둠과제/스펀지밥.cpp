#include<CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
#define M_PI 3.14

void orange_sphere(double x, double y, double z, double radius) {
	WoolID orange = createWool(COLOR_ORANGE);

	double radian = M_PI / 180.;

	for (int i = 0; i < 360; i++) {
		for (int j = 0; j < 360; j++) {
			double x_ = radius * sin(radian * i) * cos(radian * j);
			double z_ = radius * sin(radian * i) * sin(radian * j);
			double y_ = radius * cos(radian * i);

			locateBlock(orange, x + x_, y + y_, z + z_);
		}
	}
}

void y_line(BlockID block, int x, int y, int z, int floor)
{
	for (int i = 0; i <= floor; i++)
	{
		locateBlock(block, x, y + i, z);
	}
}

void x_Lstair(BlockID block, int x, int y, int z, int floor)
{
	for (int i = 1; i <= floor; i++)
	{
		y_line(block, x - i, y + i, z, 2);
	}

}

void x_Rstair(BlockID block, int x, int y, int z, int floor)
{
	for (int i = 1; i <= floor; i++)
	{
		y_line(block, x + i, y + i, z, 2);
	}

}


void F_body(int sx, int sy, int sz, int radius)
{

	for (int i = 0; i <= 10; i++)
	{
		orange_sphere(sx, sy + i, sz, radius);
	}

}

void F_hair(int x, int y, int z)
{
	WoolID green = createWool(COLOR_LIME);

	//ÁÙ±â
	for (int i = -1; i <= 1; i++)
	{
		y_line(green, x + i, y + 18, z, 11);
		y_line(green, x, y + 18, z + i, 12);
	}

	//ÀÙ
	x_Lstair(green, x - 1, y + 19, z, 5);
	x_Rstair(green, x + 1, y + 19, z, 5);

	for (int i = -1; i <= 1; i++)
	{
		x_Lstair(green, x, y + 19, z + i, 4);
		x_Rstair(green, x, y + 19, z + i, 4);
	}

}

void main()
{
	int sx, sy, sz, radius;
	scanf_s("%d %d %d", &sx, &sy, &sz);

	F_body(sx, sy, sz, 8);
	F_hair(sx, sy, sz);
}



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


void orange_circle(double x, double y, double z, double radius) {
	WoolID orange = createWool(COLOR_ORANGE);

	double radian = M_PI / 180.;

	for (int i = 0; i < 360; i++) {

			double x_ = radius * cos(radian * i);
			double z_ = radius * sin(radian * i);

			locateBlock(orange, x + x_, y, z + z_);
		
	}
}


void y_line(BlockID block, int x, int y, int z, int floor)
{
	for (int i = 0; i <= floor; i++)
	{
		locateBlock(block, x, y + i, z);
	}
}

void z_Lstair(BlockID block, int x, int y, int z, int floor)
{
	for (int i = 1; i <= floor; i++)
	{
		y_line(block, x, y + i, z - i, 2);
	}

}

void z_Rstair(BlockID block, int x, int y, int z, int floor)
{
	for (int i = 1; i <= floor; i++)
	{
		y_line(block, x, y + i, z + i, 2);
	}

}


void F_body(int sx, int sy, int sz, int radius)
{
	WoolID orange = createWool(COLOR_ORANGE);

	for (int i = 0; i <= 10; i++)
	{
		orange_circle(sx, sy + i, sz, radius);
	}
	orange_sphere(sx, sy + 10, sz, radius);
}

void F_hair(int x, int y, int z)
{
	WoolID green = createWool(COLOR_LIME);

	//ÁÙ±â
	for (int i = -1; i <= 1; i++)
	{
		y_line(green, x + i, y + 18, z, 12);
		y_line(green, x, y + 18, z + i, 11);
	}

	//ÀÙ
	z_Lstair(green, x, y + 19, z, 5);
	z_Rstair(green, x, y + 19, z, 5);

	for (int i = -1; i <= 1; i++)
	{
		z_Lstair(green, x + i, y + 19, z, 4);
		z_Rstair(green, x + i, y + 19, z, 4);
	}

}
void accessories(int sx, int sy, int sz)
{
	WoolID woolWh = createWool(COLOR_WHITE);
	WoolID woolBl = createWool(COLOR_LIGHT_BLUE);

	DoorID door = createDoor(DOOR_IRON, false, HINGE_RIGHT);

	// ÀÔ
	locateBlock(woolBl, sx + 8, sy, sz - 1);
	locateBlock(woolBl, sx + 8, sy, sz + 1);
	locateBlock(woolBl, sx + 8, sy + 1, sz - 1);
	locateBlock(woolBl, sx + 8, sy + 2, sz);
	locateBlock(woolBl, sx + 8, sy + 1, sz + 1);

	installDoor(door, sx + 8, sy, sz, FACING_WEST);

	//´«
	locateBlock(woolBl, sx + 8, sy + 11, sz + 3);
	locateBlock(woolWh, sx + 8, sy + 11, sz + 2);
	locateBlock(woolBl, sx + 8, sy + 11, sz + 1);
	locateBlock(woolBl, sx + 8, sy + 10, sz + 2);
	locateBlock(woolBl, sx + 8, sy + 12, sz + 2);

	locateBlock(woolBl, sx + 8, sy + 5, sz - 4);
	locateBlock(woolWh, sx + 8, sy + 5, sz - 3);
	locateBlock(woolBl, sx + 8, sy + 5, sz - 2);
	locateBlock(woolBl, sx + 8, sy + 4, sz - 3);
	locateBlock(woolBl, sx + 8, sy + 6, sz - 3);

	//±Í
	locateBlock(woolBl, sx, sy + 10, sz - 8);
	locateBlock(woolBl, sx + 1, sy + 10, sz - 8);
	locateBlock(woolBl, sx, sy + 10, sz - 9);
	locateBlock(woolBl, sx + 1, sy + 10, sz - 9);
	locateBlock(woolBl, sx, sy + 10, sz - 10);
	locateBlock(woolBl, sx + 1, sy + 10, sz - 10);

	y_line(woolBl, sx, sy + 10, sz - 11, 3);
	y_line(woolBl, sx + 1, sy + 10, sz - 11, 3);

}


void main()
{
	int sx, sy, sz, radius;
	sx = -18;
	sy = 4;
	sz = 13;



	F_body(sx, sy, sz, 8);
	F_hair(sx, sy, sz);
	accessories(sx, sy, sz);

	//orange_circle(sx, sy, sz, 8);
}

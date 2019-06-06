#define _CRT_SECURE_NO_WARNINGS
#include<CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")
#define M_PI 3.14


void circle(BlockID block, int radius, int x, int y, int z) {
	for (int i = -radius; i < radius; i++) {
		for (int j = -radius; j < radius; j++) {
			if (i*i + j * j < radius * radius) {
				locateBlock(block, x + i, y, z + j);
			}
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




// ±øÅëÁý
void main()
{
	int sx, sy, sz;

	char type1;
	char type2;

	WoolID sb1;
	WoolID sb2;

	BlockID air = createBlock(BLOCK_AIR);

	WoolID a = createWool(COLOR_ORANGE);
	WoolID b = createWool(COLOR_LIGHT_GRAY);
	WoolID c = createWool(COLOR_GRAY);
	WoolID d = createWool(COLOR_PINK);
	WoolID e = createWool(COLOR_BLACK);
	WoolID f = createWool(COLOR_LIGHT_BLUE);

	printf("a : ÁÖÈ²»ö\n");
	printf("b : ¹àÀº È¸»ö\n");
	printf("c : È¸»ö\n");
	printf("d : ÇÎÅ©\n");
	printf("e : °ËÁ¤\n");
	printf("f : ¹àÀºÆÄ¶û\n");


	printf("\n¸öÅë »ö±ò\n");
	scanf("%c", &type1);
	printf("¿£ÅÍ 1¹ø ~2¹ø\n");
	getchar();
	getchar();

	printf("¶Ñ²± »ö±ò\n");
	scanf("%c", &type2);

	printf("\nx, y, z\n");
	scanf("%d %d %d", &sx, &sy, &sz);

	if (type1 == 'a')
	{
		sb1 = a;
	}
	if (type1 == 'b')
	{
		sb1 = b;
	}
	if (type1 == 'c')
	{
		sb1 = c;
	}
	if (type1 == 'd')
	{
		sb1 = d;
	}
	if (type1 == 'e')
	{
		sb1 = e;
	}
	if (type1 == 'f')
	{
		sb1 = f;
	}


	if (type2 == 'a')
	{
		sb2 = a;
	}
	if (type2 == 'b')
	{
		sb2 = b;
	}
	if (type2 == 'c')
	{
		sb2 = c;
	}
	if (type2 == 'd')
	{
		sb2 = d;
	}
	if (type2 == 'e')
	{
		sb2 = e;
	}
	if (type2 == 'f')
	{
		sb2 = f;
	}


	//¸öÅë
	for (int i = 0; i <= 15; i++)
	{
		circle(sb1, 5, sx, sy + i, sz);
	}

	//¶Ñ²±
	for (int k = 0; k <= 1; k++)
	{
		for (int j = -4; j <= 4; j++)
		{
			for (int i = -4; i <= 4; i++)
			{
				locateBlock(sb2, sx + i, sy + 16 + k, sz + j);
			}
		}
	}

	for (int j = -1; j <= 1; j++)
	{
		for (int i = -1; i <= 1; i++)
		{
			locateBlock(sb2, sx + i, sy + 18, sz + j);
		}
	}

	y_line(air, sx - 4, sy + 16, sz + 4, 2);
	y_line(air, sx - 4, sy + 16, sz - 4, 2);
	y_line(air, sx + 4, sy + 16, sz + 4, 2);
	y_line(air, sx + 4, sy + 16, sz - 4, 2);

	y_line(sb2, sx, sy + 18, sz, 4);

	/*
	COLOR_WHITE
	COLOR_ORANGE
	COLOR_MAGENTA
	COLOR_LIGHT_BLUE
	COLOR_YELLOW
	COLOR_LIME
	COLOR_PINK
	COLOR_GRAY
	COLOR_LIGHT_GRAY
	COLOR_CYAN
	COLOR_PURPLE
	COLOR_BLUE
	COLOR_BROWN
	COLOR_GREEN
	COLOR_RED
	COLOR_BLACK
	*/

}
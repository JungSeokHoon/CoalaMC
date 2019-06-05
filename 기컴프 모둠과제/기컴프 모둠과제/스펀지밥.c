#include<CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")



void Bl_123(int sx, int sy, int sz)

{

	BlockID stone = createBlock(BLOCK_STONE);

	for (int i = 0; i <= 2; i++)

	{

		for (int j = 0; j <= 3 + i; j++)

		{

			locateBlock(stone, sx + j, sy, sz + i);

			locateBlock(stone, sx - j, sy, sz + i);

		}



	}



}



void Bl_321(int sx, int sy, int sz)

{

	BlockID stone = createBlock(BLOCK_STONE);

	for (int i = 0; i <= 2; i++)

	{

		for (int j = 0; j <= 5 - i; j++)

		{

			locateBlock(stone, sx + j, sy, sz + i);

			locateBlock(stone, sx - j, sy, sz + i);

		}



	}



}



void Bl_333(int sx, int sy, int sz)

{

	BlockID stone = createBlock(BLOCK_STONE);

	for (int i = 0; i <= 5; i++)

	{

		for (int j = 0; j <= 5; j++)

		{

			locateBlock(stone, sx + j, sy, sz + i);

			locateBlock(stone, sx - j, sy, sz + i);

		}



	}

}





int main()

{

	BlockID stone = createBlock(BLOCK_STONE);



	int sx, sy, sz;

	scanf_s("%d %d %d", &sx, &sy, &sz);



	for (int i = 0; i <= 9; i++)

	{

		Bl_123(sx, sy + i, sz);

		Bl_321(sx, sy + i, sz + 8);

		Bl_333(sx, sy + i, sz + 3);

	}



}
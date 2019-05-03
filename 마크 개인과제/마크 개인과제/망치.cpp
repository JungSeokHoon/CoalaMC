#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

int main()
{

	BlockID stone = createBlock(BLOCK_STONE);
	BlockID dirt = createBlock(BLOCK_DIRT);
	WoolID gray = createWool(COLOR_GRAY);


	int sx, sy, sz, ex, ey, ez;

	puts("sx, sy, sz를 입력하세요: ");
	scanf_s("%d %d %d", &sx, &sy, &sz);

	puts("ex, ey, ez를 입력하세요: ");
	scanf_s("%d %d %d", &ex, &ey, &ez);


	// 중간지점
	int Mx = (sx + ex) / 2;
	int My = (sy + ey) / 2;
	int Mz = (sz + ez) / 2;

	// 줄 길이
	int Lx = (ex - sx + 1);
	int Ly = (ey - sy + 1);
	int Lz = (ez - sz + 1);

	// 망치 머리
	for (int i = 0; i <= Lx / 4; i++)
	{
		for (int j = sz; j <= ez; j++)
		{
			for (int k = sy; k <= sy + Ly / 3; k++)
			{

					locateBlock(stone, Mx + i, k, j);
					locateBlock(stone, Mx - i, k, j);

			}
		}
	}

	//망치머리 1,2번 x축 코디
	for (int i = Mx - Lx / 4; i <= Mx + Lx / 4; i++)
	{
		locateBlock(gray, i, sy, ez);
		locateBlock(gray, i, sy, ez -1);
		locateBlock(gray, i, sy, sz);
		locateBlock(gray, i, sy, sz + 1);

		locateBlock(gray, i, sy + Ly / 3, ez);
		locateBlock(gray, i, sy + Ly / 3, ez - 1);
		locateBlock(gray, i, sy + Ly / 3, sz);
		locateBlock(gray, i, sy + Ly / 3, sz + 1);
	}

	//망치머리 1,2번 y축 코디
	for (int j = sy; j <= sy + Ly / 3; j++)
	{
		locateBlock(gray, Mx - Lx / 4, j, ez);
		locateBlock(gray, Mx - Lx / 4, j, ez - 1);
		locateBlock(gray, Mx - Lx / 4, j, sz);
		locateBlock(gray, Mx - Lx / 4, j, sz + 1);

		locateBlock(gray, Mx + Lx / 4, j, ez);
		locateBlock(gray, Mx + Lx / 4, j, ez - 1);
		locateBlock(gray, Mx + Lx / 4, j, sz);
		locateBlock(gray, Mx + Lx / 4, j, sz + 1);
	}



	// 망치 허리

	for (int i = 0; i <= Lx / 8; i++)
	{
		for (int j = Mz - Lx / 8; j <= Mz + Lx/8; j++)
		{
			for (int k = sy + Ly / 3; k <= ey; k++)
			{
				if (k % 3 == 0)
				{
					locateBlock(stone, Mx + i, k, j);
					locateBlock(stone, Mx - i, k, j);
				}
				else
				{
					locateBlock(dirt, Mx + i, k, j);
					locateBlock(dirt, Mx - i, k, j);
				}

			}
		}
	}

}
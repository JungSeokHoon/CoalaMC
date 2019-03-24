#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

int main()
{
	int px, py, pz;
	getPlayerLocation(&px, &py, &pz);				// 현재 플레이어의 위치를 획득한다.

	int x = px + 1, y, z = pz + 1;
	for (y = 1; getBlockType(x, y, z) != BLOCK_AIR; y++);

	BlockID stone = createBlock(BLOCK_STONE);		// STONE 블록을 생성한다.
	locateBlock(stone, x, y, z);
}

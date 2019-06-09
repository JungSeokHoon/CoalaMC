- 파인에플 집에 사용된 함수들

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

   for (int i = -1; i <= 1; i++)
   {
      y_line(green, x + i, y + 18, z, 12);
      y_line(green, x, y + 18, z + i, 11);
   }

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

   locateBlock(woolBl, sx + 8, sy, sz - 1);
   locateBlock(woolBl, sx + 8, sy, sz + 1);
   locateBlock(woolBl, sx + 8, sy + 1, sz - 1);
   locateBlock(woolBl, sx + 8, sy + 2, sz);
   locateBlock(woolBl, sx + 8, sy + 1, sz + 1);

   installDoor(door, sx + 8, sy, sz, FACING_WEST);

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

   locateBlock(woolBl, sx, sy + 10, sz - 8);
   locateBlock(woolBl, sx + 1, sy + 10, sz - 8);
   locateBlock(woolBl, sx, sy + 10, sz - 9);
   locateBlock(woolBl, sx + 1, sy + 10, sz - 9);
   locateBlock(woolBl, sx, sy + 10, sz - 10);
   locateBlock(woolBl, sx + 1, sy + 10, sz - 10);

   y_line(woolBl, sx, sy + 10, sz - 11, 3);
   y_line(woolBl, sx + 1, sy + 10, sz - 11, 3);

}


- 파인에플 집 설명
파인에플 집을 만들기 위해서 
함수를 크게

F_body (파인애플 몸통부분)
F_hair (파인에플 잎 부분)
accessories (창문, 문, 배출구)

로 나누었다.

파인에플의 몸통부분을 표현하기 위해서
F_body 함수를 만들 때
주황색 블럭으로 이루어진 구를 만드는 함수 orange_circle과
주황색 블럭으로 이루어진 원을 만드는 함수 orange_sphere를 사용했고

파인에플의 잎부분을 표현하기 위해서
F_hair 함수를 만들 떄
y축을 기준으로 블럭을 일자로 세우는 함수 y_line과
z축을 기준으로 오른쪽(+) 방향의 계단을 세우는 함수 z_Rstair와
z축을 기준으로 왼쪽(-) 방향으로 계단을 세우는 함수 z_Lstair를 사용했다.


창문, 문, 배출구는 accessories 함수로 묶어놨고, 
locateBlock installDoor y_line 함수들을 활용해서 만들었다. 

#include <stdio.h>
#include <Windows.h>

int map[20][20] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

//커서 이동
void SetPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct Obj
{
	int x;
	int y;
	const char* shape;

};

const float G = 9.81;
const float Vo = 12.0;

int main()
{
	Obj player;
	player.x = 10;
	player.y = 18;
	player.shape = "●";

	float time = 0.0;
	bool freeFall = false;

	float h = 0.0;
	float y = 0.0;

	while (true)
	{
		system("cls");


		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				switch (map[y][x])
				{
				case 1:
					SetPosition(x, y);
					printf("■");
					break;
				default:
					break;
				}
			}
		}


		if (GetAsyncKeyState(VK_LEFT))
		{
			player.x--;
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			player.x++;
		}

		if (GetAsyncKeyState(VK_SPACE))
		{
			freeFall = true;
			time = 0.0;
			h = player.y;
			y = 0.0;

		}

		if (freeFall)
		{
			time += 0.2;

			//y = -(Vo * t) + (0.5 * G * t * t);
			float v = Vo * time;
			float g = 0.5 * G * time * time;
			y =-(v) + (g);

			float beforeY = player.y;   // 이전 값
			float afterY = h + y;		// 지금값
		

			for (int i = beforeY; i <= afterY; i++)
			{

				if (map[i+1][player.x] == 1)
				{
					freeFall = false;
					afterY = i;
					break;
				}
			}

			player.y = afterY;

		}

		SetPosition(player.x, player.y);
		printf(player.shape);

		Sleep(30);
	}

	return 0;
}
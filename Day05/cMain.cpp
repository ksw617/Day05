#include <stdio.h>
#include <Windows.h>

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
	player.y = 25;
	player.shape = "●";

	float time = 0.0;
	bool freeFall = false;

	//점프 할때 player 높이
	float h = 0.0;
	//점프 하고 나서 부터 높이 변화량
	float y = 0.0;
	//y = Vo * t - 0.5 * G * t * t 
	//y = -(Vo * t) + (0.5 * G * t * t);

	while (true)
	{
		system("cls");

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
			// 구현
			player.y++;

			//y = -(Vo * t) + (0.5 * G * t * t);
			y =-(Vo * time) + (0.5 * G * time * time);
			player.y = h + y;

			time += 0.2;

			if (player.y > 25)
			{
				freeFall = false;
				player.y = h;
			}
		}

		SetPosition(player.x, player.y);
		printf(player.shape);

		Sleep(30);
	}

	return 0;
}
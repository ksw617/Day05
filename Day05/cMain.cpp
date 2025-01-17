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

enum Dir
{
	UP,
	DOWN,
};

struct Obj
{
	int x;
	int y;
	const char* shape;

};

int main()
{
	Obj player;
	player.x = 10;
	player.y = 20;
	player.shape = "●";

	bool jump = false;
	Dir upDown = UP;

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
			upDown = UP;
			jump = true;
		}

		if (jump)
		{
			if (player.y <= 15)
			{
				upDown = DOWN;
			}

			if (player.y > 20)
			{
				player.y = 20;
				jump = false;
			}

			//10
			//11
			if (upDown == DOWN)
			{
				//11
				player.y++;
			}
			else //upDown == DOWN
			{
				//11->10
				player.y--;
			}
		}

		SetPosition(player.x, player.y);
		printf(player.shape);

		Sleep(20);
	}

	return 0;
}
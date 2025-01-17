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

int main()
{
	Obj player;
	player.x = 10;
	player.y = 0;
	player.shape = "●";

	float time = 0.0;
	bool freeFall = false;

	float h = 0.0;
	//h = 0.5 * G * t * t;

	while (true)
	{
		system("cls");

		if (GetAsyncKeyState(VK_SPACE))
		{
			freeFall = true;
			time = 0.0;
			h = 0.0;
		}

		if (freeFall)
		{
			// 구현
			player.y++;

			h = 0.5 * G * time * time;
			player.y = h;

			time += 0.1;

			if (player.y >= 25)
			{
				freeFall = false;
			}
		}

		SetPosition(player.x, player.y);
		printf(player.shape);

		Sleep(50);
	}

	return 0;
}
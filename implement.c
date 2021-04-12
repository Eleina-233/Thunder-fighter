#include"标头.h"

void init()
{
	score = 0;
	right = 20; bottom = 20;
	x = bottom - 2, y = right / 2;
	bullet_x = x - 1; bullet_y = y;
	srand(time(0));
	target_x = rand() % (bottom / 4);
	target_y = rand() % y;
	target_v_x = 1; target_v_y = 1;
}

void show()
{
	gotoxy(0, 0);
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };//取消光标显示
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
	for (i = 0; i <= bottom; i++)
	{
		for (j = 0; j <= right; j++)
		{
			if (i == x && j == y)
				printf("*");
			else if (j == right)
				printf("|");
			else if (i == bottom)
				printf("-");
			else if (i == bullet_x && j == bullet_y)
				printf("^");
			else if (i == target_x && j == target_y)
				printf("@");
			else
				printf(" ");
		}
		printf("\n");
	}

	printf("您的得分：%d\n", score);
}

void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

void WithInput()
{
	if (_kbhit())
	{
		char ch = _getch();
		if (ch == 'a')
		{
			if (0 < y)
				y--;
		}
		else if(ch == 'w')
		{
			if (x > 0)
				x--;
		}
		else if (ch == 's')
		{
			if (x < bottom - 1)
				x++;
		}
		else if (ch == 'd')
		{
			if (y < right - 1)
				y++;
		}
		
	}
}

void WithOutInput()
{
	bullet_x--;

	if (bullet_x < 0) {
		bullet_x = x - 1;
		bullet_y = y;
	} 
	if (bullet_x == target_x && bullet_y == target_y)
	{
		score++;
		srand(time(0));
		target_x = rand() % (bottom / 4);
		target_y = rand() % right;
	}



	
	Sleep(20);
}

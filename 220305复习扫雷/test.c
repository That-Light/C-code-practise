#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("**********************\n");
	printf("*****   1.play   *****\n");
	printf("*****   0.exit   *****\n");
	printf("**********************\n");
}

void game()
{
	printf("开始游戏\n");

	//设置棋盘
	char showboard[ROWS][COLS] = { 0 };
	char mineboard[ROWS][COLS] = { 0 };

	//初始化棋盘
	InitializeBoard(showboard, '*');
	InitializeBoard(mineboard, '0');

	//展示棋盘
	DisplayBoard(showboard);
	printf("\n");
	//DisplayBoard(mineboard);
	//printf("\n");

	//设置雷区
	SetMine(mineboard);

	//展示棋盘
	//DisplayBoard(mineboard);
	//printf("\n");

	//开始游戏
	PlayGame(showboard,mineboard);

}

int main()
{
	int input = 0;

	srand((unsigned int) time(NULL));

	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入有误，请重新输入\n");
			break;
		}
	} while (input);

	return 0;
}
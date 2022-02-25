#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void game()
{
	printf("游戏开始\n");

	//设置棋盘及雷区的信息
	char mine[ROWS][COLS] = { 0 }; //生成雷区的棋盘
	char show[ROWS][COLS] = { 0 }; //生成展示的棋盘

	InitBoard(mine, '0'); //初始化雷区的棋盘
	InitBoard(show, '*'); //初始化展示的棋盘

	//DisplayBoard(mine); //打印雷区的棋盘(实际游戏不展示)
	DisplayBoard(show); //打印展示的棋盘

	SetMine(mine); //布置雷
	DisplayBoard(mine); //打印雷区的棋盘(实际游戏不展示)

	//扫雷游戏
	FindMine(mine, show);

}

void menu()
{
	printf("************************\n");
	printf("***      1.play      ***\n");
	printf("***      0.exit      ***\n");
	printf("************************\n");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL)); //置随机数种子

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
			printf("选择错误，请重新选择\n");
			break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}
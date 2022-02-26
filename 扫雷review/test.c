#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void game()
{
	system("cls"); //清空屏幕
	printf("开始游戏\n");

	//设置 雷区 和 展示 的棋盘
	char mine[ROWS][COLS] = { 0 }; //雷区棋盘
	char show[ROWS][COLS] = { 0 }; //展示棋盘

	InitBoard(mine, '0'); //初始化雷区棋盘
	InitBoard(show, '*'); //初始化展示棋盘

	//DisplayBoard(mine); //打印雷区棋盘（游戏时不显示）
	DisplayBoard(show); //打印展示棋盘

	SetMine(mine); //布置雷区
	//DisplayBoard(mine); //打印雷区棋盘（游戏时不显示）

	//扫雷
	FindMine(mine, show); //扫雷

}

void menu()
{
	printf("****************************\n");
	printf("*****      1.play      *****\n");
	printf("*****      0.exit      *****\n");
	printf("****************************\n");
}

void test()
{
	int input = 0;

	srand((unsigned int)time(NULL));  //置随机数种子

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
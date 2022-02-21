#define _CRT_SECURE_NO_WARNINGS

#include "三子棋game.h"

void game()
{
	char ret = 0;

	printf("开始游戏\n");

	char board[ROW][COL] = { 0 };

	//初始化棋盘
	InitBoard(board);
	//打印棋盘
	DisplayBoard(board);

	while (1)
	{
		//玩家下棋
		PlayerMove(board);
		DisplayBoard(board);
		//输赢
		ret = IsWin(board);
		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		ComputerMove(board);
		DisplayBoard(board);
		//输赢
		ret = IsWin(board);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}

void menu()
{
	printf("***************************\n");
	printf("***   1.play   0.exit   ***\n");
	printf("***************************\n");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请输入：");
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
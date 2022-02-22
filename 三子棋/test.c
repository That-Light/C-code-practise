#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void game()
{
	char ret; //接收 输赢判断 的 返回字符

	printf("开始游戏!\n");

	//生成棋盘
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
		//输赢判断
		ret = IsWin(board);
		if (ret != 'C') //除了 返回'C' 以外其他结果均表示本局游戏结束，跳出循环
		{
			break;
		}

		//电脑下棋
		ComputerMove(board);
		DisplayBoard(board);
		//输赢判断
		ret = IsWin(board);
		if (ret != 'C') //除了 返回'C' 以外其他结果均表示本局游戏结束，跳出循环
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
	printf("***********************************\n");
	printf("******   1.play     0.exit   ******\n");
	printf("***********************************\n");
}

void test()
{
	int input = 0; //接收玩家根据菜单的输入

	srand((unsigned int)time(NULL)); //置随机数种子，注意 (unsigned int) 要用()括住

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
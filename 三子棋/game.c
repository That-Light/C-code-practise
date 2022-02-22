#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++) //把 一行数字行 和 一行分隔行 看作一个整体进行打印
	{
		//打印 数字行
		//若用 printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]); ，存在局限性，当棋盘格局改变时不能按要求打印
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1) //最后一列不用打印 '|'
				printf("|");
		}

		printf("\n");

		//打印 分隔行
		//若用  if (i < row - 1)
		//      	printf("---|---|---\n"); ,存在局限性，当棋盘格局改变时不能按要求打印
		if (i < ROW - 1) //最后一行不用打印 分隔行
		{
			for (j = 0; j < COL; j++)
			{
				printf("---");
				if (j < COL - 1)//最后一列不用打印 '|'
					printf("|");
			}
		}

		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL])
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("请输入下棋的坐标：");
		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= 3 && y >= 1 && y <= 3) //用户输入 1~3 更直观，但 数组下标 从 0 开始，要记得 减1
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入\n");
			}
		}
		else
		{
			printf("坐标错误，请重新输入\n");
		}
	}
}

void ComputerMove(char board[ROW][COL])
{
	printf("电脑下棋：");
	while (1)
	{
		int x = rand() % ROW;
		int y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			printf("%d %d\n", x+1, y+1);
			break;
		}
	}

}

int IsFull(char board[ROW][COL])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
			{
				return 1;//未满
			}
		}
	}
	return 0;//已满
}

char IsWin(char board[ROW][COL])
{
	int i = 0;
	int ret = 0;
	
	//不继续的情况
	//横三行
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//竖三列
	for (i = 0; i < ROW; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//两个对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//平局
	ret = IsFull(board);
	if (ret == 0)
	{
		return 'Q';
	}

	//继续的情况
	return 'C';
}

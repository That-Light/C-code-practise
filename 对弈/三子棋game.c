#define _CRT_SECURE_NO_WARNINGS


#include "三子棋game.h"

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

	for (i = 0; i < ROW; i++)
	{
		//打印数字行
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
			{
				printf("|");
			}
		}

		printf("\n");

		//打印分隔行
		if (i < ROW - 1)
		{
			for (j = 0; j < COL; j++)
			{
				printf("---");
				if (j < COL - 1)
				{
					printf("|");
				}
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

		if (x >= 1 && x <= 3 && y >= 1 && y <= 3)
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
			printf("坐标输入有误，请重新输入\n");
		}
	}
}

void ComputerMove(char board[ROW][COL])
{
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % ROW;
		y = rand() % COL;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char IsWin(char board[ROW][COL])
{
	int i = 0;
	int j = 0;

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
	//两条对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//继续
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j]==' ')
			{
				return 'C';
			}
		}
	}

	//平局
	return 'Q';

}
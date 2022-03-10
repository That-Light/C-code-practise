#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitializeBoard(char board[ROWS][COLS], char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS])
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= ROW; i++)
	{
		if (i == 0)
		{
			for (j = 0; j <= COL; j++)
			{
				printf("%d ", j);
			}
			printf("\n");
			i++;
		}

		printf("%d ", i);

		for (j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

//void DisplayBoard(char board[ROWS][COLS])
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < ROWS; i++)
//	{
//		printf("%d ", i);
//	}
//	printf("\n");
//
//	for (i = 1; i <= ROW; i++)
//	{
//		printf("%d ", i);
//		for (j = 1; j <= COL; j++)
//		{
//			printf("%c ", board[i][j]);
//		}
//		printf("\n");
//	}
//}

void SetMine(char mineboard[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	int count = MineCount;

	x = rand() % ROW + 1;
	y = rand() % COL + 1;

	while (count)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;

		if (mineboard[x][y] == '0')
		{
			mineboard[x][y] = '1';
			count--;
		}

	}

}

int CountMine(char mineboard[ROWS][COLS], int x, int y)
{
	return mineboard[x - 1][y] +
		mineboard[x - 1][y - 1] +
		mineboard[x][y - 1] +
		mineboard[x + 1][y - 1] +
		mineboard[x + 1][y] +
		mineboard[x + 1][y + 1] +
		mineboard[x][y + 1] +
		mineboard[x - 1][y + 1] - 8 * '0';
}

void OpenBoard(char showboard[ROWS][COLS], char mineboard[ROWS][COLS], int x, int y)
{
	int ret = CountMine(mineboard, x, y);

	if (ret == 0)
	{
		showboard[x][y] = ' ';

		if (x - 1 > 0 && x - 1 < ROWS && y > 0 && y < COLS && showboard[x - 1][y] == '*')
		{
			OpenBoard(showboard, mineboard, x - 1, y);
		}
		if (x - 1 > 0 && x - 1 < ROWS && y - 1 > 0 && y - 1 < COLS && showboard[x - 1][y - 1] == '*')
		{
			OpenBoard(showboard, mineboard, x - 1, y - 1);
		}
		if (x > 0 && x < ROWS && y - 1 > 0 && y - 1 < COLS && showboard[x][y - 1] == '*')
		{
			OpenBoard(showboard, mineboard, x, y - 1);
		}
		if (x + 1 > 0 && x + 1 < ROWS && y - 1 > 0 && y - 1 < COLS && showboard[x + 1][y - 1] == '*')
		{
			OpenBoard(showboard, mineboard, x + 1, y - 1);
		}
		if (x + 1 > 0 && x + 1 < ROWS && y > 0 && y < COLS && showboard[x + 1][y] == '*')
		{
			OpenBoard(showboard, mineboard, x + 1, y);
		}
		if (x + 1 > 0 && x + 1 < ROWS && y + 1 > 0 && y + 1 < COLS && showboard[x + 1][y + 1] == '*')
		{
			OpenBoard(showboard, mineboard, x + 1, y + 1);
		}
		if (x > 0 && x < ROWS && y + 1 > 0 && y + 1 < COLS && showboard[x][y + 1] == '*')
		{
			OpenBoard(showboard, mineboard, x, y + 1);
		}
		if (x - 1 > 0 && x - 1 < ROWS && y + 1 > 0 && y + 1 < COLS && showboard[x - 1][y + 1] == '*')
		{
			OpenBoard(showboard, mineboard, x - 1, y + 1);
		}

	}
	else
	{
		showboard[x][y] = ret + '0';
	}
}

int CleanMine(char showboard[ROWS][COLS], char mineboard[ROWS][COLS], int x, int y)
{
	int count = 0;
	int i = 0;
	int j = 0;

	if (mineboard[x][y] == '1')
	{
		return 0;
	}
	else
	{
		OpenBoard(showboard, mineboard, x, y);

		for (i = 1; i <= COL; i++)
		{
			for (j = 1; j <= ROW; j++)
			{
				if (showboard[i][j] == '*')
				{
					count++;
				}
			}
		}
		if (count == MineCount)
		{
			DisplayBoard(showboard);
			return 2;
		}
		else
		{
			return 1;
		}

	}
}

void PlayGame(char showboard[ROWS][COLS], char mineboard[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	int reback = 0;

	while (1)
	{
		printf("请输入扫雷坐标:");
		scanf("%d%d", &x, &y);

		if (x > 0 && x < ROWS && y>0 && y < COLS)
		{
			if (showboard[x][y] != '*')
			{
				printf("该坐标已经被清除，请重新输入\n");
			}
			else
			{
				reback = CleanMine(showboard, mineboard, x, y);

				if (reback == 0)
				{
					printf("你被炸死了！\n");
					printf("雷区展示如下：\n");
					DisplayBoard(mineboard);
					printf("\n");
					break;
				}
				else if (reback == 1)
				{
					DisplayBoard(mineboard);
					printf("\n");
					DisplayBoard(showboard);
					printf("\n");
				}
				else
				{
					printf("扫雷完成，你赢了！\n");
					printf("雷区展示如下：\n");
					DisplayBoard(mineboard);
					printf("\n");
					break;
				}
			}
		}
		else
		{
			printf("坐标输入超出范围，请重新输入\n");
		}

	}

}
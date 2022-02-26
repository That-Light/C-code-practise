#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void InitBoard(char board[ROWS][COLS], char set)
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

	for (i = 0; i <= 9; i++) //打印 行 的 标号
	{
		printf("%d ", i);
	}

	printf("\n");

	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", i); //打印 列 的 标号
		for (j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS])
{
	int x = 0;
	int y = 0;

	int count = MINE_COUNT; //布置的雷数

	while (count)
	{
		x = rand() % ROW + 1; // rand() % ROW(9) 随机产生 0~8 的数字， +1 将产生 1~9 的数字
		y = rand() % COL + 1; // rand() % COL(9) 随机产生 0~8 的数字， +1 将产生 1~9 的数字

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int CountMine(char mine[ROWS][COLS], int x, int y)
{
	// 字符'1' - 字符 '0' = 数值 1
	// 字符'5' - 字符 '2' = 数值 3
	// 则
	// 字符'i' - 字符 'j' = 数值 i-j (其中i、j均为数字)
	// 
	// 同样地：
	// 数值 3  + 字符 '2' = 字符'5'
	// 则：
	// 数值 k  + 字符 '0' = 数值 k (其中k为数字)

	return mine[x - 1][y] + 
		mine[x - 1][y - 1] + 
		mine[x][y - 1] + 
		mine[x + 1][y - 1] +       //算式太长了，分段拆开 也是可以的
		mine[x + 1][y] + 
		mine[x + 1][y + 1] + 
		mine[x][y + 1] + 
		mine[x - 1][y + 1] 
		- 8 * '0';  //这里相当于 每个字符 减 字符'0'  
}

void SafeBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int ret = 0;

	ret = CountMine(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if (x - 1 >= 1 && x - 1 <= 9 && y >= 1 && y <= 9 && show[x - 1][y] == '*') //判定坐标合法性 且 判定 show棋盘 是否允许清扫
		{
			SafeBoard(mine, show, x - 1, y);
		}
		if (x - 1 >= 1 && x - 1 <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x - 1][y - 1] == '*') //判定坐标合法性 且 判定 show棋盘 是否允许清扫
		{
			SafeBoard(mine, show, x - 1, y - 1);
		}
		if (x >= 1 && x <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x][y - 1] == '*') //判定坐标合法性 且 判定 show棋盘 是否允许清扫
		{
			SafeBoard(mine, show, x, y - 1);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x + 1][y - 1] == '*') //判定坐标合法性 且 判定 show棋盘 是否允许清扫
		{
			SafeBoard(mine, show, x + 1, y - 1);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y >= 1 && y <= 9 && show[x + 1][y] == '*') //判定坐标合法性 且 判定 show棋盘 是否允许清扫
		{
			SafeBoard(mine, show, x + 1, y);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x + 1][y + 1] == '*') //判定坐标合法性 且 判定 show棋盘 是否允许清扫
		{
			SafeBoard(mine, show, x + 1, y + 1);
		}
		if (x >= 1 && x <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x][y + 1] == '*') //判定坐标合法性 且 判定 show棋盘 是否允许清扫
		{
			SafeBoard(mine, show, x, y + 1);
		}
		if (x - 1 >= 1 && x - 1 <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x - 1][y + 1] == '*') //判定坐标合法性 且 判定 show棋盘 是否允许清扫
		{
			SafeBoard(mine, show, x - 1, y + 1);
		}
	}
	else
	{
		// 字符'1' - 字符 '0' = 数值 1
		// 字符'5' - 字符 '2' = 数值 3
		// 则
		// 字符'i' - 字符 'j' = 数值 i-j (其中i、j均为数字)
		// 
		// 同样地：
		// 数值 3  + 字符 '2' = 字符'5'
		// 则：
		// 数值 k  + 字符 '0' = 数值 k (其中k为数字)

		show[x][y] = ret + '0';
	}
}

int OpenBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (mine[x][y] == '1')
	{
		printf("踩雷，你被炸死了！\n");
		printf("雷区展示如下：\n");
		DisplayBoard(mine);
		printf("重新返回主界面\n");
		return 0; //游戏结束
	}
	else
	{
		SafeBoard(mine, show, x, y);
		//DisplayBoard(mine); //打印雷区棋盘（游戏时不显示）
		//printf("\n");

		system("cls"); //清空屏幕

		DisplayBoard(show);

		return 1; //游戏继续
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int x = 0;
	int y = 0;

	int ret = 0; //接收 游戏是否继续 的 返回值

	int i = 0;
	int j = 0;
	int count = 0; //扫雷胜利判定的标志，统计 show棋盘 还剩多少个 *

	while (1)
	{
		printf("请输入需要清扫的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9) //判断坐标是否合法
		{
			if (show[x][y] == '*') //判断坐标是否已被清扫
			{
				ret = OpenBoard(mine, show, x, y); //自动开启一片雷区

				if (ret == 0) //踩雷，扫雷失败判定游戏结束
				{
					break;
				}

				//扫完雷，扫雷胜利判定游戏结束
				count = 0; //每次都要先把 count 置 0 ，不然会累加上一回合的数值
				for (i = 1; i <= ROW; i++)
				{
					for (j = 1; j <= COL; j++)
					{
						if (show[i][j]=='*')
						{
							count++;
						}
					}
				}
				if (count == MINE_COUNT)
				{
					printf("恭喜你，扫雷成功，游戏胜利！\n");
					printf("雷区展示如下：\n");
					DisplayBoard(mine);
					printf("重新返回主界面\n");
					break;
				}

			}
			else
			{
				printf("该坐标已清扫，请重新输入\n");
			}
		}
		else
		{
			printf("非法坐标，请重新输入\n");
		}
	}
}
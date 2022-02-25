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
	for (i = 0; i <= ROW; i++) //打印列的标号
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", i); //打印行的标号
		for (j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n"); //换行
	}
}

void SetMine(char board[ROWS][COLS])
{
	int count = easy_count; //雷的个数

	while (count)
	{
		int x = rand() % 9 + 1; // rand() % 9 随机产生 0~8 的数字， +1 将产生 1~9 的数字
		int y = rand() % 9 + 1; // rand() % 9 随机产生 0~8 的数字， +1 将产生 1~9 的数字

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
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
		mine[x + 1][y - 1] +     //算式太长了，分段拆开也是可以的
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1]
		- 8 * '0'; //这里相当于 每个字符 减 字符'0'  

}

// 递归链式反应（改进版才有）
void OpenBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int ret = 0;

	ret = get_mine_count(mine, x, y);

	if (ret == 0)
	{
		show[x][y] = ' ';
		if (x - 1 >= 1 && x - 1 <= 9 && y >= 1 && y <= 9 && show[x - 1][y] == '*')
		{
			SafeBoard(mine, show, x - 1, y);
		}
		if (x - 1 >= 1 && x - 1 <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x - 1][y - 1] == '*')
		{
			SafeBoard(mine, show, x - 1, y - 1);
		}
		if (x >= 1 && x <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x][y - 1] == '*')
		{
			SafeBoard(mine, show, x, y - 1);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x + 1][y - 1] == '*')
		{
			SafeBoard(mine, show, x + 1, y - 1);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y >= 1 && y <= 9 && show[x + 1][y] == '*')
		{
			SafeBoard(mine, show, x + 1, y);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x + 1][y + 1] == '*')
		{
			SafeBoard(mine, show, x + 1, y + 1);
		}
		if (x >= 1 && x <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x][y + 1] == '*')
		{
			SafeBoard(mine, show, x, y + 1);
		}
		if (x - 1 >= 1 && x - 1 <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x - 1][y + 1] == '*')
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

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int x = 0;
	int y = 0;


	while (1)
	{
		printf("请输入扫雷的坐标：");
		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= ROW && y >= 1 && y <= COL) //判断坐标是否合法
		{
			if (show[x][y] == '*') //判断坐标是否已经清扫
			{
				if (mine[x][y] == '1')
				{
					printf("你被炸死了\n");
					printf("雷区展示如下：\n");
					DisplayBoard(mine);
					printf("返回主菜单\n");
					break;
				}
				else
				{
					OpenBoard(mine, show, x, y);
				}

			}
			else
			{
				printf("该坐标雷区已清扫，请重新输入坐标\n");
			}

		}
		else
		{
			printf("坐标输入有误，请重新输入\n");
		}

	}
}
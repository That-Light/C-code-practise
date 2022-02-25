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
	for (i = 0; i <= ROW; i++) //��ӡ�еı��
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", i); //��ӡ�еı��
		for (j = 1; j <= COL; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n"); //����
	}
}

void SetMine(char board[ROWS][COLS])
{
	int count = easy_count; //�׵ĸ���

	while (count)
	{
		int x = rand() % 9 + 1; // rand() % 9 ������� 0~8 �����֣� +1 ������ 1~9 ������
		int y = rand() % 9 + 1; // rand() % 9 ������� 0~8 �����֣� +1 ������ 1~9 ������

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}

int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	// �ַ�'1' - �ַ� '0' = ��ֵ 1
	// �ַ�'5' - �ַ� '2' = ��ֵ 3
	// ��
	// �ַ�'i' - �ַ� 'j' = ��ֵ i-j (����i��j��Ϊ����)
	// 
	// ͬ���أ�
	// ��ֵ 3  + �ַ� '2' = �ַ�'5'
	// ��
	// ��ֵ k  + �ַ� '0' = ��ֵ k (����kΪ����)

	return mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +     //��ʽ̫���ˣ��ֶβ�Ҳ�ǿ��Ե�
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1]
		- 8 * '0'; //�����൱�� ÿ���ַ� �� �ַ�'0'  

}

// �ݹ���ʽ��Ӧ���Ľ�����У�
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
		// �ַ�'1' - �ַ� '0' = ��ֵ 1
	    // �ַ�'5' - �ַ� '2' = ��ֵ 3
	    // ��
	    // �ַ�'i' - �ַ� 'j' = ��ֵ i-j (����i��j��Ϊ����)
	    // 
	    // ͬ���أ�
	    // ��ֵ 3  + �ַ� '2' = �ַ�'5'
	    // ��
	    // ��ֵ k  + �ַ� '0' = ��ֵ k (����kΪ����)

		show[x][y] = ret + '0';
	}

}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int x = 0;
	int y = 0;


	while (1)
	{
		printf("������ɨ�׵����꣺");
		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= ROW && y >= 1 && y <= COL) //�ж������Ƿ�Ϸ�
		{
			if (show[x][y] == '*') //�ж������Ƿ��Ѿ���ɨ
			{
				if (mine[x][y] == '1')
				{
					printf("�㱻ը����\n");
					printf("����չʾ���£�\n");
					DisplayBoard(mine);
					printf("�������˵�\n");
					break;
				}
				else
				{
					OpenBoard(mine, show, x, y);
				}

			}
			else
			{
				printf("��������������ɨ����������������\n");
			}

		}
		else
		{
			printf("����������������������\n");
		}

	}
}
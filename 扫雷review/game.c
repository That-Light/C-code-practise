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

	for (i = 0; i <= 9; i++) //��ӡ �� �� ���
	{
		printf("%d ", i);
	}

	printf("\n");

	for (i = 1; i <= ROW; i++)
	{
		printf("%d ", i); //��ӡ �� �� ���
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

	int count = MINE_COUNT; //���õ�����

	while (count)
	{
		x = rand() % ROW + 1; // rand() % ROW(9) ������� 0~8 �����֣� +1 ������ 1~9 ������
		y = rand() % COL + 1; // rand() % COL(9) ������� 0~8 �����֣� +1 ������ 1~9 ������

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int CountMine(char mine[ROWS][COLS], int x, int y)
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
		mine[x + 1][y - 1] +       //��ʽ̫���ˣ��ֶβ� Ҳ�ǿ��Ե�
		mine[x + 1][y] + 
		mine[x + 1][y + 1] + 
		mine[x][y + 1] + 
		mine[x - 1][y + 1] 
		- 8 * '0';  //�����൱�� ÿ���ַ� �� �ַ�'0'  
}

void SafeBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int ret = 0;

	ret = CountMine(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if (x - 1 >= 1 && x - 1 <= 9 && y >= 1 && y <= 9 && show[x - 1][y] == '*') //�ж�����Ϸ��� �� �ж� show���� �Ƿ�������ɨ
		{
			SafeBoard(mine, show, x - 1, y);
		}
		if (x - 1 >= 1 && x - 1 <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x - 1][y - 1] == '*') //�ж�����Ϸ��� �� �ж� show���� �Ƿ�������ɨ
		{
			SafeBoard(mine, show, x - 1, y - 1);
		}
		if (x >= 1 && x <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x][y - 1] == '*') //�ж�����Ϸ��� �� �ж� show���� �Ƿ�������ɨ
		{
			SafeBoard(mine, show, x, y - 1);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y - 1 >= 1 && y - 1 <= 9 && show[x + 1][y - 1] == '*') //�ж�����Ϸ��� �� �ж� show���� �Ƿ�������ɨ
		{
			SafeBoard(mine, show, x + 1, y - 1);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y >= 1 && y <= 9 && show[x + 1][y] == '*') //�ж�����Ϸ��� �� �ж� show���� �Ƿ�������ɨ
		{
			SafeBoard(mine, show, x + 1, y);
		}
		if (x + 1 >= 1 && x + 1 <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x + 1][y + 1] == '*') //�ж�����Ϸ��� �� �ж� show���� �Ƿ�������ɨ
		{
			SafeBoard(mine, show, x + 1, y + 1);
		}
		if (x >= 1 && x <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x][y + 1] == '*') //�ж�����Ϸ��� �� �ж� show���� �Ƿ�������ɨ
		{
			SafeBoard(mine, show, x, y + 1);
		}
		if (x - 1 >= 1 && x - 1 <= 9 && y + 1 >= 1 && y + 1 <= 9 && show[x - 1][y + 1] == '*') //�ж�����Ϸ��� �� �ж� show���� �Ƿ�������ɨ
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

int OpenBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (mine[x][y] == '1')
	{
		printf("���ף��㱻ը���ˣ�\n");
		printf("����չʾ���£�\n");
		DisplayBoard(mine);
		printf("���·���������\n");
		return 0; //��Ϸ����
	}
	else
	{
		SafeBoard(mine, show, x, y);
		//DisplayBoard(mine); //��ӡ�������̣���Ϸʱ����ʾ��
		//printf("\n");

		system("cls"); //�����Ļ

		DisplayBoard(show);

		return 1; //��Ϸ����
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS])
{
	int x = 0;
	int y = 0;

	int ret = 0; //���� ��Ϸ�Ƿ���� �� ����ֵ

	int i = 0;
	int j = 0;
	int count = 0; //ɨ��ʤ���ж��ı�־��ͳ�� show���� ��ʣ���ٸ� *

	while (1)
	{
		printf("��������Ҫ��ɨ�����꣺");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9) //�ж������Ƿ�Ϸ�
		{
			if (show[x][y] == '*') //�ж������Ƿ��ѱ���ɨ
			{
				ret = OpenBoard(mine, show, x, y); //�Զ�����һƬ����

				if (ret == 0) //���ף�ɨ��ʧ���ж���Ϸ����
				{
					break;
				}

				//ɨ���ף�ɨ��ʤ���ж���Ϸ����
				count = 0; //ÿ�ζ�Ҫ�Ȱ� count �� 0 ����Ȼ���ۼ���һ�غϵ���ֵ
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
					printf("��ϲ�㣬ɨ�׳ɹ�����Ϸʤ����\n");
					printf("����չʾ���£�\n");
					DisplayBoard(mine);
					printf("���·���������\n");
					break;
				}

			}
			else
			{
				printf("����������ɨ������������\n");
			}
		}
		else
		{
			printf("�Ƿ����꣬����������\n");
		}
	}
}
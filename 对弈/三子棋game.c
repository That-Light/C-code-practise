#define _CRT_SECURE_NO_WARNINGS


#include "������game.h"

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
		//��ӡ������
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < COL - 1)
			{
				printf("|");
			}
		}

		printf("\n");

		//��ӡ�ָ���
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
		printf("��������������꣺");
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
				printf("�������ѱ�ռ�ã�����������\n");
			}
		}
		else
		{
			printf("����������������������\n");
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

	//������
	for (i = 0; i < ROW; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	//������
	for (i = 0; i < ROW; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//�����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	//����
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

	//ƽ��
	return 'Q';

}
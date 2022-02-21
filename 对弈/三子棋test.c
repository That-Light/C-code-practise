#define _CRT_SECURE_NO_WARNINGS

#include "������game.h"

void game()
{
	char ret = 0;

	printf("��ʼ��Ϸ\n");

	char board[ROW][COL] = { 0 };

	//��ʼ������
	InitBoard(board);
	//��ӡ����
	DisplayBoard(board);

	while (1)
	{
		//�������
		PlayerMove(board);
		DisplayBoard(board);
		//��Ӯ
		ret = IsWin(board);
		if (ret != 'C')
		{
			break;
		}

		//��������
		ComputerMove(board);
		DisplayBoard(board);
		//��Ӯ
		ret = IsWin(board);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
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
		printf("�����룺");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}

	} while (input);
}

int main()
{
	test();
	return 0;
}
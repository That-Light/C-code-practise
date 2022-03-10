#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("**********************\n");
	printf("*****   1.play   *****\n");
	printf("*****   0.exit   *****\n");
	printf("**********************\n");
}

void game()
{
	printf("��ʼ��Ϸ\n");

	//��������
	char showboard[ROWS][COLS] = { 0 };
	char mineboard[ROWS][COLS] = { 0 };

	//��ʼ������
	InitializeBoard(showboard, '*');
	InitializeBoard(mineboard, '0');

	//չʾ����
	DisplayBoard(showboard);
	printf("\n");
	//DisplayBoard(mineboard);
	//printf("\n");

	//��������
	SetMine(mineboard);

	//չʾ����
	//DisplayBoard(mineboard);
	//printf("\n");

	//��ʼ��Ϸ
	PlayGame(showboard,mineboard);

}

int main()
{
	int input = 0;

	srand((unsigned int) time(NULL));

	do
	{
		menu();
		printf("��ѡ��");
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
			printf("������������������\n");
			break;
		}
	} while (input);

	return 0;
}
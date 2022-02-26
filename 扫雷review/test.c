#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void game()
{
	system("cls"); //�����Ļ
	printf("��ʼ��Ϸ\n");

	//���� ���� �� չʾ ������
	char mine[ROWS][COLS] = { 0 }; //��������
	char show[ROWS][COLS] = { 0 }; //չʾ����

	InitBoard(mine, '0'); //��ʼ����������
	InitBoard(show, '*'); //��ʼ��չʾ����

	//DisplayBoard(mine); //��ӡ�������̣���Ϸʱ����ʾ��
	DisplayBoard(show); //��ӡչʾ����

	SetMine(mine); //��������
	//DisplayBoard(mine); //��ӡ�������̣���Ϸʱ����ʾ��

	//ɨ��
	FindMine(mine, show); //ɨ��

}

void menu()
{
	printf("****************************\n");
	printf("*****      1.play      *****\n");
	printf("*****      0.exit      *****\n");
	printf("****************************\n");
}

void test()
{
	int input = 0;

	srand((unsigned int)time(NULL));  //�����������

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
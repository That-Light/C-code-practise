#define _CRT_SECURE_NO_WARNINGS

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//void menu()
//{
//	printf("*********************************************\n");
//	printf("******       Guess  Number  Game       ******\n");
//	printf("*****      1.play           0.exit      *****\n");
//	printf("*********************************************\n");
//}
// 
//void game()
//{
//	int ret = 0;
//
//	int left = 1;
//	int right = 100;
//
//	int guess = 0;
//
//	ret = rand() % 100 + 1;
//	printf("%d\n", ret);   //������ģʽ
//
//	while (1)
//	{
//		printf("���   %d ���� %d   �ڲ²�\n", left, right);
//		printf("����");
//		scanf("%d", &guess);
//
//		if (guess > right || guess < left)
//		{
//			printf("����Ԥ�跶Χ�������²²�\n");
//			continue;
//		}
//
//		if (guess > ret)
//		{
//			printf("�´���\n");
//			right = guess - 1;
//		}
//		else if (guess < ret)
//		{
//			printf("��С��\n");
//			left = guess + 1;
//		}
//		else
//		{
//			printf("�¶���\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		input = 2;   //��
//		menu();
//
//		printf("��ѡ��");
//
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			printf("��ʼ��Ϸ\n");
//			while (getchar() != '\n')   //��
//			{
//				;
//			}
//			game();
//			break;
//		case 0:
//			printf("�˳���Ϸ\n");
//			break;
//		default:
//			printf("ѡ�����������ѡ��\n");
//			break;
//		}
//
//
//		while (getchar() != '\n')   //��
//		{
//			;
//		}
//
//	} while (input);
//
//	return 0;
//}
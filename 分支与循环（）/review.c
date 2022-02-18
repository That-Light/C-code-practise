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
//	printf("%d\n", ret);   //开发者模式
//
//	while (1)
//	{
//		printf("请从   %d —— %d   内猜测\n", left, right);
//		printf("→：");
//		scanf("%d", &guess);
//
//		if (guess > right || guess < left)
//		{
//			printf("超出预设范围，请重新猜测\n");
//			continue;
//		}
//
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//			right = guess - 1;
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//			left = guess + 1;
//		}
//		else
//		{
//			printf("猜对了\n");
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
//		input = 2;   //※
//		menu();
//
//		printf("请选择：");
//
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
//			printf("开始游戏\n");
//			while (getchar() != '\n')   //※
//			{
//				;
//			}
//			game();
//			break;
//		case 0:
//			printf("退出游戏\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//
//
//		while (getchar() != '\n')   //※
//		{
//			;
//		}
//
//	} while (input);
//
//	return 0;
//}
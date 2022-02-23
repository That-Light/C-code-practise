#define _CRT_SECURE_NO_WARNINGS


//#include "go.h"
//
//
//void game()
//{
//	printf("开始游戏\n");
//
//	char board[ROW][COL] = { 0 };
//
//
//	//初始化棋盘
//	initBoard(board);
//	////打印棋盘
//	displayBoard(board);
//
//}
//
//void menu()
//{
//	printf("***************************\n");
//	printf("***   1.play   0.exit   ***\n");
//	printf("***************************\n");
//}
//
//void test()
//{
//	int input = 0;
//
//	do
//	{
//		menu();
//		printf("请输入：");
//		scanf("%d", &input);
//
//		switch (input)
//		{
//		case 1:
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
//	} while (input);
//}
//
//int main()
//{
//	test();
//	return 0;
//}
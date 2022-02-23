#define _CRT_SECURE_NO_WARNINGS

//#include "go.h"
//
//void initBoard(char board[ROW][COL])
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		for (j = 0; j < COL; j++)
//		{
//			board[i][j] = ' ';
//		}
//	}
//}
//
//void displayBoard(char board[ROW][COL])
//{
//	int i = 0;
//	int j = 0;
//
//	for (i = 0; i < ROW; i++)
//	{
//		//打印数字行
//		for (j = 0; j < COL; j++)
//		{
//			printf(" %c ", board[i][j]);
//			if (j < COL - 1)
//			{
//				printf("|");
//			}
//		}
//
//		printf("\n");
//
//		//打印分隔行
//		if (i < ROW - 1)
//		{
//			for (j = 0; j < COL; j++)
//			{
//				printf("---");
//				if (j < COL - 1)
//				{
//					printf("|");
//				}
//			}
//		}
//
//		printf("\n");
//
//	}
//}
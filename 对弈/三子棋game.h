#define _CRT_SECURE_NO_WARNINGS


#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����
void InitBoard(char board[ROW][COL]);
void DisplayBoard(char board[ROW][COL]);

void PlayerMove(char board[ROW][COL]);
void ComputerMove(char board[ROW][COL]);

//��Ӯ
//���Ӯ������'*'
//����ө������'#'
//ƽ�֣�����'Q'
//����������'C'
char IsWin(char board[ROW][COL]);
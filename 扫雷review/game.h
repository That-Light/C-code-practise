#define _CRT_SECURE_NO_WARNINGS

#define ROW 9
#define COL 9
#define MINE_COUNT 10

#define ROWS ROW+2
#define COLS COL+2


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//����
void InitBoard(char board[ROWS][COLS], char set); //��ʼ������
void DisplayBoard(char board[ROWS][COLS]); //չʾ����
void SetMine(char board[ROWS][COLS]); //������
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS]); //ɨ��
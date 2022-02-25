#define _CRT_SECURE_NO_WARNINGS

#define ROW 9 //行数
#define COL 9 //列数
#define easy_count 10

#define ROWS ROW+2
#define COLS COL+2

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//声明
void InitBoard(char board[ROWS][COLS], char set);
void DisplayBoard(char board[ROWS][COLS]);
void SetMine(char board[ROWS][COLS]);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS]);
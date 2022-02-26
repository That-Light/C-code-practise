#define _CRT_SECURE_NO_WARNINGS

#define ROW 9
#define COL 9
#define MINE_COUNT 10

#define ROWS ROW+2
#define COLS COL+2


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//声明
void InitBoard(char board[ROWS][COLS], char set); //初始化棋盘
void DisplayBoard(char board[ROWS][COLS]); //展示棋盘
void SetMine(char board[ROWS][COLS]); //布置雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS]); //扫雷
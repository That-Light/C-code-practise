#define _CRT_SECURE_NO_WARNINGS

#define ROW 3
#define COL 3

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitBoard(char board[ROW][COL]);
void DisplayBoard(char board[ROW][COL]);

void PlayerMove(char board[ROW][COL]);
void ComputerMove(char board[ROW][COL]);

//判断
//玩家赢，返回'*'
//电脑赢，返回'#'
//平局，返回'Q'
//继续，返回'C'
char IsWin(char board[ROW][COL]);
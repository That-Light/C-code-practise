#define _CRT_SECURE_NO_WARNINGS

#define ROW 9
#define COL 9
#define MineCount 10

#define ROWS ROW+2
#define COLS COL+2


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void InitializeBoard(char board[ROWS][COLS], char set);
void DisplayBoard(char board[ROWS][COLS]);

void SetMine(mineboard);

void PlayGame(char showboard[ROWS][COLS], char mineboard[ROWS][COLS]);
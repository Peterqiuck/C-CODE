#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define ROWS ROW+2
#define COLS COL+2

#define ROW 9
#define COL 9

#define num_mine 10//ÉèÖÃ10¸öÀ×

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Initializeboard(char board[ROWS][COLS], int rows, int cols,int set);
void Printboard(char board[ROWS][COLS], int row, int col);
void Dismine(char board[ROWS][COLS], int x, int y);
void Sweepermine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
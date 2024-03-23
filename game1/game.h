#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define ROW 3
#define COL 3
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Initboard(char board[ROW][COL], int row, int col);
void Printboard(char board[ROW][COL], int row, int col);
void Playermove(char board[ROW][COL], int row, int col);
void Computermove(char board[ROW][COL], int row, int col);

char Pand(char board[ROW][COL], int row, int col);

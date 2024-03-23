#include "game.h"

void Initboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void Printboard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{  
				printf(" %c ", board[i][j]);
				if(j<col-1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void Playermove(char board[ROW][COL], int row, int col)//玩家下棋
{
	int x = 0;
	int y = 0;
	 printf("玩家走：>\n");
	 while (1)
	 {
		 printf("请输入坐标：>");
		 scanf("%d%d", &x, &y);
		 if (x >= 1 && x <= row && y >= 1 && y <= col)
		 {
			 if (board[x - 1][y - 1] == ' ')
			 {
				 board[x - 1][y - 1] = '*';
				 break;
			 }
			 else
			 {
				 printf("坐标被占用，请重新输入：>\n");
			 }
		 }
		 else
		 {
			 printf("坐标非法，请重新输入：>\n");
		 }
	 }
}

void Computermove(char board[ROW][COL], int row, int col)//电脑下棋
{
	int x = 0;
	int y = 0;
	printf("电脑走：>\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int Full(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i <row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//没满
			}
		}
	}
	return 1;//满了
}
char Pand(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')//三横相等
		{
				return board[i][0];
		}
	}
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')//三列相等
		{
				return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')//对角相等
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')//对角相等
	{
		return board[0][2];
	}
	if (1 == Full(board, ROW, COL))//判断棋盘是否满
	{
		return 'Q';
	}
	return 'C';
}
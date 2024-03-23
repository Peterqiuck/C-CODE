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

void Playermove(char board[ROW][COL], int row, int col)//�������
{
	int x = 0;
	int y = 0;
	 printf("����ߣ�>\n");
	 while (1)
	 {
		 printf("���������꣺>");
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
				 printf("���걻ռ�ã����������룺>\n");
			 }
		 }
		 else
		 {
			 printf("����Ƿ������������룺>\n");
		 }
	 }
}

void Computermove(char board[ROW][COL], int row, int col)//��������
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>\n");
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
				return 0;//û��
			}
		}
	}
	return 1;//����
}
char Pand(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')//�������
		{
				return board[i][0];
		}
	}
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')//�������
		{
				return board[0][j];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')//�Խ����
	{
		return board[0][0];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')//�Խ����
	{
		return board[0][2];
	}
	if (1 == Full(board, ROW, COL))//�ж������Ƿ���
	{
		return 'Q';
	}
	return 'C';
}
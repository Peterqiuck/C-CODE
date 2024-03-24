#include "game2.h"

void Initializeboard(char board[ROWS][COLS], int rows, int cols,int set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Printboard(char board[ROWS][COLS], int row, int col)
{
	for (int i = 0; i <=row ; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void Dismine(char board[ROWS][COLS], int x, int y)
{
	int count = 0;
	while (count<num_mine)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count++;
		}
	}
}

int NO(char mine[ROWS][COLS], int x, int y)
{
	return  mine[x - 1][y] +
			mine[x - 1][y - 1] +
			mine[x][y - 1] +
			mine[x + 1][y - 1] +
			mine[x + 1][y] +
			mine[x + 1][y + 1] +
			mine[x][y + 1] +
			mine[x - 1][y + 1] - 8 * '0';
}

void Sweepermine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int ret = 0;
	int win = 0;
	while (win<row*col-num_mine)
	{
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);

		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] != '1')
			{
				ret = NO(mine, x, y);
				show[x][y] = ret+'0';//不能用'ret'这种表示
				Printboard(show, ROW, COL);
				win++;
			}
			else
			{
				printf("很遗憾，你踩到雷了:<\n");
				Printboard(mine, ROW, COL);
				break;
			}
		}
		else
		{
			printf("坐标错误，请重新输入：<\n");
		}
	}
	if (win == ROW * COL - num_mine)
	{
		printf("恭喜你，胜利了：>\n");
	}
}
	
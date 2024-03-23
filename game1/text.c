#include "game.h"

void menu()
{
	printf("**************************\n");
	printf("*** 1.play      0.exit ***\n");
	printf("**************************\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };

	Initboard(board,ROW,COL);//初始化棋盘，设置为空格
	Printboard(board, ROW, COL);//打印棋盘边框
	while (1)
	{
		Playermove(board, ROW, COL);//玩家走
		Printboard(board, ROW, COL);
		ret =Pand(board, ROW, COL);
		if (ret != 'C')//继续
		{
			 break;
		}
		Computermove(board, ROW, COL);
		Printboard(board, ROW, COL);
		ret = Pand(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢！\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢！\n");
	}
	else if(ret == 'Q')
	{
		printf("平局！\n");
	}
}

void text()
{
	int op = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &op);
		switch (op)
		{
		case 1:game(); break;
		case 0:printf("退出游戏"); break;
		default:printf("选择错误，请重新选择\n");break;
		}
	} 
	while (op);
}

int main()
{
	text();
	return 0;
}
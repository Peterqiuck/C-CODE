#include "game2.h"

void menu()
{
	printf("********************************\n");
	printf("*******   1.play     ***********\n");
	printf("*******   0.exit     ***********\n");
	printf("********************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	Initializeboard(mine, ROWS, COLS,'0');//初始化棋盘
	Initializeboard(show, ROWS, COLS,'*');//初始化棋盘
	//Printboard(mine, ROW, COL);
	Printboard(show, ROW, COL);//打印棋盘

	Dismine(mine, ROW, COL);//分配雷位置
	Printboard(mine, ROW, COL);//打印雷的位置
	Sweepermine(mine, show, ROW, COL);//扫雷
}

void test()
{
	int op = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:game(); break;
		case 0:printf("退出游戏\n"); break;
		default:printf("输入错误，请重新输入！"); break;
		}
	} 
	while (op);
}

int main()
{
	test();
	return 0;
}
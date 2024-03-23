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

	Initboard(board,ROW,COL);//��ʼ�����̣�����Ϊ�ո�
	Printboard(board, ROW, COL);//��ӡ���̱߿�
	while (1)
	{
		Playermove(board, ROW, COL);//�����
		Printboard(board, ROW, COL);
		ret =Pand(board, ROW, COL);
		if (ret != 'C')//����
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
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else if(ret == 'Q')
	{
		printf("ƽ�֣�\n");
	}
}

void text()
{
	int op = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &op);
		switch (op)
		{
		case 1:game(); break;
		case 0:printf("�˳���Ϸ"); break;
		default:printf("ѡ�����������ѡ��\n");break;
		}
	} 
	while (op);
}

int main()
{
	text();
	return 0;
}
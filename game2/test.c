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
	Initializeboard(mine, ROWS, COLS,'0');//��ʼ������
	Initializeboard(show, ROWS, COLS,'*');//��ʼ������
	//Printboard(mine, ROW, COL);
	Printboard(show, ROW, COL);//��ӡ����

	Dismine(mine, ROW, COL);//������λ��
	Printboard(mine, ROW, COL);//��ӡ�׵�λ��
	Sweepermine(mine, show, ROW, COL);//ɨ��
}

void test()
{
	int op = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>\n");
		scanf("%d", &op);
		switch (op)
		{
		case 1:game(); break;
		case 0:printf("�˳���Ϸ\n"); break;
		default:printf("����������������룡"); break;
		}
	} 
	while (op);
}

int main()
{
	test();
	return 0;
}
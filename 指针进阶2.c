#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//����ָ��������� ������ �ص�����
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}
int Sum(int x, int y)
{
	return 2 * x + x * y;
}
void menu()
{
	printf("*************************************\n");
	printf("***1.Add     2.Sub     3.Mul*********\n");
	printf("***4.Div     5.Sum     0.exit********\n");
	printf("*************************************\n");
}
void Cou(int(*PPr)(int, int))
{
	int x = 0, y = 0;
	printf("���������ֵ��");
	scanf("%d%d", &x, &y);
	printf("%d\n", PPr(x, y));
}
int main()
{
	int op = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &op);
		switch (op)
		{
		case 0:printf("�˳�\n");
		case 1:Cou(Add); break;
		case 2:Cou(Sub); break;
		case 3:Cou(Mul); break;
		case 4:Cou(Div); break;
		case 5:Cou(Sum); break;
		default:printf("ѡ�����\n");
		}
	} while (op);
}

//����ָ������ʵ��,������ ת�Ʊ�
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int Sum(int x, int y)
//{
//	return 2 * x + x * y;
//}
//void menu()
//{
//	printf("*************************************\n");
//	printf("***1.Add     2.Sub     3.Mul*********\n");
//	printf("***4.Div     5.Sum     0.exit********\n");
//	printf("*************************************\n");
//}
//int main()
//{
//	int op = 0;
//	int x = 0, y = 0;
//	do
//	{
//		menu();
//		printf("��ѡ��>");
//		scanf("%d", &op);
//		if (op >= 1 && op <= 5)
//		{
//			printf("���������ֵ��");
//			scanf("%d%d", &x, &y);
//			int(*prr[6])(int, int) = { 0,Add,Sub,Mul,Div,Sum };
//			int ret = prr[op](x, y);
//			printf("%d\n", ret);
//		}
//		else if (op == 0)
//		{
//			printf("�˳�\n");
//		}
//		else 
//		{
//			printf("ѡ�����������ѡ��\n");
//		}
//	} while (op);
//	return 0;
//}

//char* my_strcpy(char* x, const char* y)
//{
//
//}
//int main()
//{
//	char* (*pf)(char*, const char*) = my_strcpy;
//	char* (*pstr[4])(char*, const char*) = {NULL};
//	return 0;
//}

//����ָ�������
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//int main()
//{
//  int(*pr)(int,int)=Add;
//	int (*pa[4])(int, int) = { Add,Sub,Mul,Div };
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		printf("%d\n", pa[i](8,4));
//	}
//	return 0;
//}

//����ָ��
//void print(char* p)
//{
//	printf("%s\n", p);
//}
//int main()
//{
//	char str[] = "hello world!";
//	print(str);
//	void (*pc)(char*) = print;
//	(*pc)("���˿�");
//	(*pc)(str);
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//函数指针数组进阶 计算器 回调函数
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
	printf("请输入计算值：");
	scanf("%d%d", &x, &y);
	printf("%d\n", PPr(x, y));
}
int main()
{
	int op = 0;
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &op);
		switch (op)
		{
		case 0:printf("退出\n");
		case 1:Cou(Add); break;
		case 2:Cou(Sub); break;
		case 3:Cou(Mul); break;
		case 4:Cou(Div); break;
		case 5:Cou(Sum); break;
		default:printf("选择错误\n");
		}
	} while (op);
}

//函数指针数组实例,计算器 转移表
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
//		printf("请选择：>");
//		scanf("%d", &op);
//		if (op >= 1 && op <= 5)
//		{
//			printf("请输入计算值：");
//			scanf("%d%d", &x, &y);
//			int(*prr[6])(int, int) = { 0,Add,Sub,Mul,Div,Sum };
//			int ret = prr[op](x, y);
//			printf("%d\n", ret);
//		}
//		else if (op == 0)
//		{
//			printf("退出\n");
//		}
//		else 
//		{
//			printf("选择错误，请重新选择\n");
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

//函数指针的数组
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

//函数指针
//void print(char* p)
//{
//	printf("%s\n", p);
//}
//int main()
//{
//	char str[] = "hello world!";
//	print(str);
//	void (*pc)(char*) = print;
//	(*pc)("好人卡");
//	(*pc)(str);
//	return 0;
//}
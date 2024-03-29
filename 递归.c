#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>

//递归字符串长度
int strlen_longth(char str[])
{
	if (*str == '\0')
	{
		return 0;
	}
	str++;
	return 1 + strlen_longth(str);
}
int main()
{
	char str[] = "bitghfgf";
	int ret = strlen_longth(str);
	printf("字符串长度为:%d", ret);
	return 0;
}

//递归求1+2+3+.....n连续自然数之和
//int Sum(int n)
//{
//	if (n > 1)
//	{
//		return n + Sum(n - 1);
//	}
//	return 1;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Sum(n);
//	printf("%d ", ret);
//	return 0;
//}

////递归阶乘和
//int Fac_n(int n)
//{
//	if (n == 1)
//	{
//		return 1;
//	}
//	if (n > 1)
//	{
//		return n * Fac_n(n - 1);
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = 0;
//	//int ret=Fac_n(n);
//	for (int i = 1; i <= n; i++)
//	{
//		sum +=Fac_n(i);
//	}
//	printf("%d ", sum);
//	return 0;
//}

//递归打印数字
//void print(int a)
//{
//	if (a > 9)
//	{
//		print(a/10);
//	}
//	printf("%d ",a%10);
//}
//int main()
//{
//	int a = 1255;
//	print(a);
//	return 0;
//}

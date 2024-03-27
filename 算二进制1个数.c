#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//int main()
//{
//	int a = 0;
//	int count = 0;
//	scanf("%d", &a);
//
//	while(a)
//	{
//		if ((a & 1) == 1)
//		{
//			count++;
//			a = a >> 1;
//		}
//		else
//		{
//			a = a >> 1;
//		}
//	}
//	printf("%d\n", count);
//	return 0;
//}

//强制类型转换
//int Qt(int x)
//{
//	int count = 0;
//	unsigned int m = (unsigned int)x;
//	while (m)
//	{
//		if ((m & 1) == 1)
//		{
//			count++;
//			m >>= 1;
//		}
//		else m >>= 1;
//	}
//	return count;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int ret = Qt(a);
//	printf("%d\n", ret);
//	return 0;
//}

int main()
{
	int  a = 0;
	int count = 0;
	scanf("%d", &a);
	while (a)
	{
		a = a & (a - 1);
		count++;
	}
	printf("%d\n", count);
	return 0;
}
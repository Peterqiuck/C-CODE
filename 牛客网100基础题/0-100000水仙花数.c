#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

//水仙花数
int main()
{
	for (int i = 0; i < 100000; i++)
	{
		//计算位数
		int n = 1;//位数
		int ret = i;
		while (ret /=10)
		{
			n++;
		}
		//计算和
		ret = i;
		int sum = 0;
		while (ret)
		{
			sum += pow(ret % 10, n);//每一位的n次方
			ret /= 10;
		}
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}




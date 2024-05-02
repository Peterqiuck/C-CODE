#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//一个数如果恰好等于它的因子之和，这个数就称为"完数"。例如28=1＋2＋4+7+14.编程找出1000以内的所有完数。
int main()
{
	int i,j,k,sum;
	int* arr = (int*)malloc(200);
	if (arr == NULL)
	{
		perror("空间扩展失败！\n");
		return 0;
	}		
	for (i = 2; i <= 1000; i++)
	{
		sum =arr[0]= 1;
		k = 0;
		for (j = 2; j <= i/2; j++)
		{
			if(i% j == 0)
			{
				sum += j;
				arr[++k] = j;
			}
		}
		if (sum == i)
		{
			printf("%d=%d", i,arr[0]);
			for (int j = 1; j <= k; j++)
			{
				printf("+%d", arr[j]);
			}
			printf("\n");
		}
	}
	free(arr);
	arr = NULL;
	return 0;
}

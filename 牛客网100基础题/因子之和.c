#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ"����"������28=1��2��4+7+14.����ҳ�1000���ڵ�����������
int main()
{
	int i,j,k,sum;
	int* arr = (int*)malloc(200);
	if (arr == NULL)
	{
		perror("�ռ���չʧ�ܣ�\n");
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

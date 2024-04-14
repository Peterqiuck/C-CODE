#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

int main()
{
	int n = 0;
	int arr[10][10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 9 - i; k++)
		{
			printf(" ");
		}
		arr[i][0] = 1;
		for (int j = 0; j <= i; j++)
		{
			arr[j][j] = 1;
			if (j > 0)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}


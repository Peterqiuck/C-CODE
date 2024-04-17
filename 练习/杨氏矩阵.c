#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define row 3
#define col 3

//杨氏矩阵,在矩阵中找数字，要求找的次数最少
int findnum(int arr[row][col], int* p1, int* p2,int k)
{
	int x = 0;
	int y = *p2 - 1;
	while ((x <= *p2 - 1) && (y >= 0))
	{
		if (arr[x][y] < k)
		{
			x++;
		}
		else if (arr[x][y] > k)
		{
			y--;
		}
		else
		{
			*p1 = x;
			*p2 = y;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int k = 6;
	int x = row;
	int y = col;
	int arr[row][col] = { 1,2,3,4,5,6,7,8,9 };
	int ret = findnum(arr, &x, &y,k);
	if (ret == 1)
	{
		printf("找到了，下标为%d,%d", x, y);
	}
	else
	{
		printf("没有这个数");
	}
	return 0;
}


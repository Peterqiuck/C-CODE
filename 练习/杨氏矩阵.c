#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define row 3
#define col 3

//���Ͼ���,�ھ����������֣�Ҫ���ҵĴ�������
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
		printf("�ҵ��ˣ��±�Ϊ%d,%d", x, y);
	}
	else
	{
		printf("û�������");
	}
	return 0;
}


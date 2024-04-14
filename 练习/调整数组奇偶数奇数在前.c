#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

int main()
{
	int arr[] = { 1,5,3,4,6,12,7,32,9,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		while((left<right)&&arr[left] % 2 == 1)
		{
			left++;
		}
		while ((left<right)&&arr[right] % 2 == 0)
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}


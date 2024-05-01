#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//闰年能被4整除，不能被100整除，能被400整除,2月29天，总366天
//平年365天，2月28天
int Num_day(int arr[], int Month, int Day)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < Month; i++)
	{
		count += arr[i];
	}
	return  count += Day;
}
int main()
{
	int arr[13] = { 0,31,0,31,30,31,30,31,31,30,31,30,31 };
	int year, month, day; 
	printf("请输入年月日（格式：年.月.日):");
	scanf("%d.%d.%d", &year, &month, &day);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		arr[2] = 29;
		printf("year=%d是闰年\n", year);
		int ret = Num_day(arr, month, day);
		printf("%d年%d月%d日是一年的第%d天\n",year,month,day,ret);
	}
	else
	{
		arr[2] = 28;
		printf("year=%d是平年\n", year);
		int ret = Num_day(arr, month, day);
		printf("%d年%d月%d日是一年的第%d天\n", year, month, day, ret);
	}
	return 0;
}


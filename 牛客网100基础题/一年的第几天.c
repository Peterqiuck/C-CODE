#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//�����ܱ�4���������ܱ�100�������ܱ�400����,2��29�죬��366��
//ƽ��365�죬2��28��
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
	printf("�����������գ���ʽ����.��.��):");
	scanf("%d.%d.%d", &year, &month, &day);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		arr[2] = 29;
		printf("year=%d������\n", year);
		int ret = Num_day(arr, month, day);
		printf("%d��%d��%d����һ��ĵ�%d��\n",year,month,day,ret);
	}
	else
	{
		arr[2] = 28;
		printf("year=%d��ƽ��\n", year);
		int ret = Num_day(arr, month, day);
		printf("%d��%d��%d����һ��ĵ�%d��\n", year, month, day, ret);
	}
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
	int a = 0;
	int count = 0;
	scanf("%d", &a);

	for (int i = 0; i < 8*sizeof(a); i++)
	{
		if (a & 1 == 1)
		{
			count++;
			a = a >> 1;
		}
		else
		{
			a = a >> 1;
		}
	}
	printf("%d\n", count);
	return 0;
}
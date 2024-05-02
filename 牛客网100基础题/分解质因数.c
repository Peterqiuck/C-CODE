#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//正整数分解质因数90=2*3*3*5
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d", &a);
	printf("%d=", a);
	for (int i = 2; i <= a; i++)
	{
		while (a % i == 0)
		{
			printf("%d",i);
			a /= i;
			if (a != 1)
				printf("*");
		}
	}
	return 0;
}




#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//2,22,222,2222,22222,n=5,a=2;ÇóºÍ
int main()
{
	int ret=0,sum = 0;
	int n = 5, a = 2;
	scanf("%d%d", &n, &a);
	
	for (int i = 0; i < n; i++)
	{
		ret = 10 * ret + a;
		sum += ret;
	}
	printf("%d", sum);
	return 0;
}




#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//µ›πÈƒÊ–Ú¥Ú”°
void ReversePrint(char *p)
{
	if(*p)
	{
		ReversePrint(p + 1);
		printf("%c", *p);
	}
}
int main()
{
	char str[10];
	scanf("%s", str);
	ReversePrint(str);
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>

int strlen_str(char* str)
{
	assert(str);
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char str[] = "abidsdf";
	int ret = strlen_str(str);
	printf("%d", ret);
	return 0;
}
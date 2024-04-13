#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>

//void strcpy_str1(char* str, char* str1,int sz)
//{
//	assert(str);
//	assert(str1);
//	for (int i = 0; i < sz; i++)
//	{
//		str1[i] = str[i];
//	}
//}
//int main()
//{
//	char str[] = "adfgfgf";
//	char str1[] = "********";
//	int sz = strlen(str);
//	strcpy_str1(str, str1,sz);
//	printf("%s", str1);
//	return 0;
//}

int main()
{
	char str1[] = "abcdef";
	char str2[] = "******";
	strcpy(str2, str1);
	printf("%s", str2);
	return 0;
}
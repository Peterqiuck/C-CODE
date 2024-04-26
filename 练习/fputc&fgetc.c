#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

struct st
{
	int a;
	float f;
	char str[10];
};
//只读'r'
//在文件text.txt里读出ab两个字符
int main()
{
	FILE* pr = fopen("text.txt", "r");
	if (pr == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	printf("%c", fgetc(pr));
	printf("%c", fgetc(pr));
                fclose(pf);
                pf=UNLL;
	return 0;
}

//只写'w'
//fputc在文件text.txt里输入ab两个字符
//int main()
//{
//	FILE* pf = fopen("text.txt", "w");
//	if (pf==NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	fputc('a', pf);
//	fputc('b', pf);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


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
//ֻ��'r'
//���ļ�text.txt�����ab�����ַ�
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

//ֻд'w'
//fputc���ļ�text.txt������ab�����ַ�
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


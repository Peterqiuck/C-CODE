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
int main()
{
	struct st s = {100,3.14,"sdrsd"};
	struct st tmp = { 0 };
	char str2[100] = { 0 };
	
	sprintf(str2, "%d %.2f %s", s.a, s.f, s.str);//从s->str2，结构体内容转化为字符串
	printf("%s\n", str2);
	sscanf(str2, "%d %f %s", &(tmp.a), &(tmp.f), tmp.str);//从str2->tmp，把字符串转化为结构体内容
	printf("%d %.2f %s", tmp.a, tmp.f, tmp.str);
	
	return 0;
}

//struct st
//{
//	int a;
//	float f;
//	char str[10];
//};
//int main()
//{
//	struct st s = {0};
//	fscanf(stdin, "%d %f %s", &(s.a), &(s.f), s.str);
//	printf("%d %.2f %s", s.a, s.f, s.str);
//	return 0;
//}

//int main()
//{
//	int a =11225;
//	fprintf(stdout, "%d\n", a);
//	return 0;
//}

//struct st
//{
//	int a;
//	float f;
//	char str[10];
//};
//int main()
//{
//	struct st s = {0};
//	FILE* pf = fopen("text.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	fscanf(pf, "%d %f %s", &(s.a), &(s.f), s.str);
//	printf("%d %.2f %s", s.a, s.f, s.str);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//struct st
//{
//	int a;
//	float f;
//	char str[10];
//};
//int main()
//{
//	struct st s = { 100,3.14f,"adfdfg"};
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	fprintf(pf,"%d %.2f %s", s.a, s.f, s.str);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	char str[10] = { 0 };
//	FILE* pf = fopen("text.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 0;
//	}
//	fputs("sdfsd\n",pf);
//	fputs("derte", pf);
//	
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//�и�
int main()
{
	char arr[] = "new@qq99.com.qw";
	char* p = "@.";

	char brr[1024] = { 0 };
	strcpy(brr, arr);//����arr����ֹarr������

	char* ret = NULL;
	for ( ret = strtok(brr,p); ret != NULL; ret=strtok(NULL,p))
	{
		printf("%s\n", ret);//������forѭ����ӡnew qq99 com
	}

	//���δ�ӡnew qq99 com
	//char* ret = strtok(brr, p);
	//printf("%s\n", ret);//��ӡnew
	//ret = strtok(NULL, p);
	//printf("%s\n", ret);//��ӡqq99
	//ret = strtok(NULL, p);
	//printf("%s\n", ret);//��ӡcom

	return 0;
}


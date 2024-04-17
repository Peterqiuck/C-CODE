#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//切割
int main()
{
	char arr[] = "new@qq99.com.qw";
	char* p = "@.";

	char brr[1024] = { 0 };
	strcpy(brr, arr);//拷贝arr，防止arr被更改

	char* ret = NULL;
	for ( ret = strtok(brr,p); ret != NULL; ret=strtok(NULL,p))
	{
		printf("%s\n", ret);//巧妙用for循环打印new qq99 com
	}

	//依次打印new qq99 com
	//char* ret = strtok(brr, p);
	//printf("%s\n", ret);//打印new
	//ret = strtok(NULL, p);
	//printf("%s\n", ret);//打印qq99
	//ret = strtok(NULL, p);
	//printf("%s\n", ret);//打印com

	return 0;
}


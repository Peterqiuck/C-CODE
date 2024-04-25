#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st
{
	int a;
	char b[];
};
int main()
{
	struct st* ps = (struct st*)malloc(10);
	
	memset(ps->b, 'g', 6);
	printf("%s\n", ps -> b);
	free(ps);
	ps = NULL;
	return 0;
}
//struct str 
//{
//    int len;
//    char s[];
//};
//struct foo 
//{
//    struct str* a;
//};
//int main(int argc, char** argv) 
//{
//    struct foo f = { 0 };
//    if (f.a->s)
//    {
//        printf(f.a->s);
//       // printf("%x\n", f.a->s);
//    }
//    return 0;
//}

//struct st
//{
//	int a;
//	int* str;
//};
//int main()
//{
//	struct st* p = (struct st*)malloc(sizeof(struct st)+5*sizeof(int));
//	p->a = 90;
//	p->str =malloc(5*sizeof(int));
//	for (int i = 0; i < 5; i++)
//	{
//		p->str[i] = i + 1;
//		printf("%d ", p->str[i]);
//	}
//	printf("\n");
//	int* p1 = realloc(p->str, 50);
//	if (p1 != NULL)
//	{
//		p -> str = p1;
//	}
//	for (int i = 5; i < 10; i++)
//	{
//		p->str[i] = i + 1;
//		printf("%d ", p->str[i]);
//	}
//	free(p->str);
//	p->str = NULL;
//	free(p);
//	p = NULL;
//	return 0;
//}

//void fun(char str[])
//{
//	printf("%d\n", sizeof(str));
//}
//int main()
//{
//	char str[100];
//	fun(str);
//	printf("´óÐ¡Îª%d\n", sizeof(str));
//	return 0;
//}

//typedef struct node
//{
//	int a;
//	int b;
//	int c;
//}node;
//node* fun(void)
//{
//	node p = { 10,20,22};
//	return &p;
//}
//int main()
//{
//	node* p1 = fun();
//	printf("%d ", p1->b);
//	return 0;
//}

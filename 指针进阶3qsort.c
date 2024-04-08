#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct worker
{
	char name[20];
	int age;
};
int cmp1(const void* a, const void* b)//如果是整型数组比较
{
	return *((int*)a) - *((int*)b);
}
int cmp2_by_name(const void* a, const void* b)//如果是结构体比较
{
	return strcmp( ((struct worker*)a)->name,((struct worker*)b)->name);
}

void swap(char* mid, char* nid, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *mid;
		*mid = *nid;
		*nid = tmp;
		mid++;
		nid++;
	}
}
void bobble_st(void* base, int sz, int width, int(*cmp2)(void* e1, void* e2))
{
	int i = 0;//交换的趟数
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;//比较大小，并交换相邻两个元素
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp2((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
void text1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
}
void text2()
{
	struct worker s[3] = { {"zhangsanfgfh",15},{"libaotian",45},{"diaosi",55} };
	int sz = sizeof(s) / sizeof(s[0]);
	bobble_st(s, sz, sizeof(s[0]),cmp2_by_name);
}

int main()
{
	//text1();
	text2();

	/*printf("%p\n", s[0].name);
	printf("%p\n", s[0].age);
	printf("%p\n", s[1].name);
	printf("%p\n", s[1].age);
	printf("%p\n", s[2].name);
	printf("%p\n", s[2].age);*/
	return 0;
}

//struct worker
//{
//	char name[20];
//	int age;
//};
//int cmp_x(const void*a,const void*b)
//{
//	return strcmp( ((struct worker*)a)->name  , ((struct worker*)b) ->name);
//}
//
//int main()
//{
//	struct worker s[3] = {{"zhangsanfgfh",15},{"libaotian",45},{"diaosi",55}};//按字符串长度排序
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp_x);
//	printf("%d\n", sizeof(s[0]));
//	printf("%s\n%s\n%s", s->name,(s+1)->name, (s + 2)->name);
//	return 0;
//}

//int cmp(const void*a,const void*b)
//{
//	if (*(float*)a == *(float*)b)
//		return 0;
//	else if (*(float*)a > *(float*)b)
//		return 1;
//	else return -1;
//}
//int main()
//{
//	float f[] = { 3.14,5.69,2.3,3.0,88.14,22.3,5.63 };
//	int sz = sizeof(f) / sizeof(f[0]);
//	qsort(f,sz,sizeof(float),cmp);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%f ", f[i]);
//	}
//	return 0;
//}

///* qsort example */
//#include <stdio.h>      /* printf */
//#include <stdlib.h>     /* qsort */
//
//int values[] = { 40, 10, 100, 90, 20, 25 };
//
//int compare(const void* a, const void* b)
//{
//    return (*(int*)a - *(int*)b);
//}
//
//int main()
//{
//    int n;
//    qsort(values, 6, sizeof(int), compare);
//    for (n = 0; n < 6; n++)
//        printf("%d ", values[n]);
//    return 0;
//}

//冒泡函数，整型数组排序
//void cmp_num(int arr[], int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//			}
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 5,6,8,9,4,1,3,0,7,5,3,2,7,88,5 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	cmp_num(arr, sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//qsort�ַ������� 
int cmp(const void* a, const void* b)
{
	return strlen(*(char**)a)-strlen(*(char**)b);
}
int main()
{
	char* str[3] = { "sdfsdf","abcdefgg","xyz" };
	int sz = sizeof(str) / sizeof(char*);
	qsort(str, sz, sizeof(str[0]), cmp);
	for (int i = 0; i < sz; i++)
	{
		printf("%s\n", str[i]);
	}
	return 0;
}

//ð�������ַ�����������
//struct stu
//{
//	char name[20];
//	int age;
//};
//int cmp(const void* e1, const void* e2)
//{
//	return strcmp(((struct stu*)e1)->name,((struct stu*)e2)->name);
//}
//int main()
//{
//	struct stu s[3] = {{"zhanfgfh",15},{"libaotiangffggf",45},{"diaosi",55}};//���ַ�����������
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp);
//	printf("%d\n", sizeof(s[0]));
//	printf("%s\n%s\n%s", s->name,(s+1)->name, (s + 2)->name);
//	return 0;
//}
 
//int main()
//{
//	struct stu s[3] = {{ "zhangsan",18},{ "lisi" ,20}, { "wangbadan" ,55}};
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s, sz, sizeof(s[0]), cmp);
//	printf("%d,%s\n", s->age, (*s).name);
//	printf("%d,%s\n", (s+1)->age, (s + 1)->name);
//	printf("%d,%s\n", (s + 2)->age, s[2].name);
//	return 0;
//}

//ð������qsort,���ͱȽ�
//int cmp(const void* a, const void* b)
//{
//	return *(int*)a-*(int*)b;
//}
//int main()
//{
//	int arr[]= { 155,10,3,5,6,5,5,6,9,1,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//ð������,�Ӵ�С������qsort
//void bobble_arr(int arr[], int sz)
//{
//	//����
//	int i = 0;
//	for (i = 0; i < sz-1; i++)
//	{
//		//һ��ð������
//		int j = 0;
//		int k = 1;
//		for(j=0;j<sz-1;j++)
//		{
//			if (arr[j] < arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				k = 0;
//			}
//		}
//		if (k == 1)//�����Ѿ��Ź�˳�����
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,5,6,5,5,6,9,1,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bobble_arr(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
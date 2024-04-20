#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//设计函数memmove内存拷贝
void* my_memmove(void* ps1,void* ps2,int k)
{
	assert(ps1 != NULL);//目标
	assert(ps2 != NULL);//源
	void* ret = ps2;
	//从后往前复制
	if(ps1>ps2)
	{
		while (k--)//k先进循环再递减
		{
			*(char*)ps2 = *(char*)ps1;
			++(char*)ps1;
			++(char*)ps2;
		}
		return ret;
	}
	//从前往后复制
	else
	{
		while (k--)
		{
			*((char*)ps2 + k) = *((char*)ps1 + k);
		}
		//(char*)ps1 += 19;
		//(char*)ps2 += 19;
		//while (k--)
		//{
		//	*(char*)ps2 = *(char*)ps1;
		//	--(char*)ps1;
		//	--(char*)ps2;
		//}
		return ret;
	}
}
int main()
{
	//int n = 0;
	//scanf("%d", &n);//复制的数量，这里设为5
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	//my_memmove(arr+2,arr,20);//这5个数在内存里的大小20
	my_memmove(arr, arr+2, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//模拟memcpy函数,拷贝自身会存在问题
//struct st
//{
//	char name[20];
//	int age;
//};
//void* my_memcpy(void* p1, const void* p2, int sz)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//	void* pc = p1;
//	
//	while(sz--)//先进去后减减
//	{
//		*(char*)p1 = *(char*)p2;
//		++(char*)p1;
//		++(char*)p2;
//	}
//	return pc;
//}
//int main()
//{
//	int arr1[] = { 1,2,3,4,5};
//	int arr2[5] = { 0 };
//	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
//	struct st s1[3] = { {"哈巴裸",100},{"迈克尔杰克逊",20}};
//	struct st s2[3] = { 0 };
//	my_memcpy(s2, s1, sizeof(s1));
//	my_memcpy(arr2,arr1,sizeof(arr1));
//
//	my_memcpy(arr3, arr3, sizeof(arr3));
//
//	/*memcpy(arr2, arr1, sizeof(arr1));
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}*/
//
//	return 0;
//}


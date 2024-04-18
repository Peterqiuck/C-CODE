#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//模拟memcpy函数
struct st
{
	char name[20];
	int age;
};
void* my_memcpy(void* p1, const void* p2, int sz)
{
	assert(p1 != NULL);
	assert(p2 != NULL);
	void* pc = p1;
	
	while(sz--)//先进去后减减
	{
		*(char*)p1 = *(char*)p2;
		++(char*)p1;
		++(char*)p2;
	}
	return pc;
}
int main()
{
	int arr1[] = { 1,2,3,4,5};
	int arr2[5] = { 0 };
	int arr3[] = { 1,2,3,4,5,6,7,8,9,10 };
	struct st s1[3] = { {"哈巴裸",100},{"迈克尔杰克逊",20}};
	struct st s2[3] = { 0 };
	my_memcpy(s2, s1, sizeof(s1));
	my_memcpy(arr2,arr1,sizeof(arr1));

	my_memcpy(arr3, arr3, sizeof(arr3));

	/*memcpy(arr2, arr1, sizeof(arr1));
	for (int i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}*/

	return 0;
}


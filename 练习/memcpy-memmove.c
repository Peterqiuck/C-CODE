#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//��ƺ���memmove�ڴ濽��
void* my_memmove(void* ps1,void* ps2,int k)
{
	assert(ps1 != NULL);//Ŀ��
	assert(ps2 != NULL);//Դ
	void* ret = ps2;
	//�Ӻ���ǰ����
	if(ps1>ps2)
	{
		while (k--)//k�Ƚ�ѭ���ٵݼ�
		{
			*(char*)ps2 = *(char*)ps1;
			++(char*)ps1;
			++(char*)ps2;
		}
		return ret;
	}
	//��ǰ������
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
	//scanf("%d", &n);//���Ƶ�������������Ϊ5
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	//my_memmove(arr+2,arr,20);//��5�������ڴ���Ĵ�С20
	my_memmove(arr, arr+2, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//ģ��memcpy����,����������������
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
//	while(sz--)//�Ƚ�ȥ�����
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
//	struct st s1[3] = { {"������",100},{"���˶��ܿ�ѷ",20}};
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


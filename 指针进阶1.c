#include<stdio.h>

void print(int(*p)[5], int x, int y)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			printf("%d ", *(*(p + i)+j));
			printf("%d ", (*(p + i))[j]);
			printf("%d ", *(p[i] + j));
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{5,6,7,8,9} };
	print(arr, 3, 5);
	return 0;
}

//数组指针，一个数组的指针，一个数组的地址
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	//int(*p)[10] = &arr;//p表示整个数组地址
//	int*p = arr;//p表示首元素地址
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", *(p+i));
//		//printf("%d ", (*p)[i]);
//		//printf("%d ", *(*p+i));//*p=arr
//	}
//	return 0;
//}


//指针数组，存放指针的数组
//int main()
//{
//	int arr1[] = { 1,2,65,6,8,5 };
//	int arr2[] = { 89,5,3,5,6,5 };
//	int arr3[] = { 8,5,2,23,3,5, };
//	int* parr[] = { arr1,arr2,arr3 };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 6; j++)
//		{
//			printf("%d ", *(parr[i] + j));
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	char arr[] = "dsowefnsldkf";
//	char* p = arr;
//	printf("%s\n", arr);
//	printf("%s\n", p);//输出值一样
//	//只要找到首元素地址就会一直打印下去，直到检测到'\0'
//	return 0;
//}

//int main()
//{
//	const char* pc = "asdkljdskjf";//常量字符串，指针表示字符串
//	//*pc = 'W';//报错
//	printf("%c\n", *pc);//首元素地址
//	printf("%s\n", pc);//整个字符串
//	return 0;
//}

//int main()
//{
//	char arr[] = "agbdi";
//	printf("%d\n", sizeof(arr));
//	return 0;
//}

//int main()
//{
//	printf("%d\n", printf("%d", printf("%d", 43)));//printf返回值为字符个数
//	printf("%d", 1256);
//	return 0;
//}

//int main()
//{
//	int arr[3][4] = { {2,5,88},{55,996,66} };
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		int j = 0;
//		for (j = 0; j < 4; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}
//int main()
//{
//	char* arr[5];//指针数组
//	char* (*pc)[5] = &arr;//数组指针
//	return 0;
//}
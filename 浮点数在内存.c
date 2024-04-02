#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<limits.h>

//int main()
//{
//	double a = 10.0;
//	printf("%d\n", sizeof(a));
//	return 0;
//}

int main()
{
	int a = 9;
	float* pc = (float*)&a;
	printf("%f\n", *pc);
	printf("%d\n", a);

	*pc = 9.0;
	printf("%f\n", *pc);
	printf("%d\n", a);
	printf("%f\n", a);
	return 0;
}

//int main()
//{
//	double d = 8e5;
//	printf("%lf", d);
//	return 0;
//}

//unsigned char i = 0;
//int main()
//{
//	for (i = 0; i <= 255; i++)
//	{
//		printf("哈哈\n");
//	}
//	return 0;
//}

//经典题
//int main()
//{
//	char arr[1000];
//	int i;
//	for (i = 0; i < 1000; i++)
//	{
//		arr[i] = -1 - i;
//	}
//	printf("%d", strlen(arr));
//	return 0;
//}

//int main()
//{
//	char a[10] = { 2,6,5,2,0,5,9,8 };
//	printf("%d\n", strlen(a));
//	return 0;
//}

//int main()
//{
//	unsigned int i = 0;
//	for (i = 9; i >= 0; i--)
//	{
//		printf("%u\n", i);
//		Sleep(500);
//	}
//	return 0;
//}

//int main()
//{
//	char a = 150;
//	int b = 10;
//	int c = a + b;
//	printf("%d\n", a);
//	return 0;
//}
//int num(char k)
//{
//	int count = 0;
//	for (int i = 0; i <32; i++)
//	{
//		if (((k >> i) & 1) == 1)
//		{
//			count++;
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	char a = -128;
//	int ret = num(a);
//	printf("%d\n", ret);
//	return 0;
//}

//int main()
//{
//	char a = -1;
//	signed char b = -1;
//	unsigned char c = -1;
//	printf("a=%d b=%d c=%d", a, b, c);
//	return 0;
//}

//��С���ж�
//int check_sys()
//{
//	int a = 1;//�ض�
//	return *(char*)&a;
//	//return (char)a;//����1С�ˣ�����0���
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i <= 13; i++)
	{
		arr[i] = 0;
		printf("hehe\n");
	}
	return 0;
}

//int func(int a)
//{
//	int b;
//	switch (a)
//	{
//	case 1:b = 30;
//	case 2:b = 20;
//	case 3:b = 10;
//	default:b = 11;
//	}
//	return b;
//}
//int main()
//{
//	int a = 1;
//	int ret = func(a);
//	printf("%d", ret);
//	return 0;
//}

//int main()
//{
//	int b = 100;
//	int a = b << 2;
//	printf("%d", a);
//}

//int count_a(int n)
//{
//	if (n <= 1)
//	{
//		return 0;
//	}
//	if (n % 2 == 0)
//	{
//		return n/2 + count_a(n / 2);//��������+����ƿ����
//	}
//	if (n % 2 != 0)
//	{
//		return n/2 + count_a(n / 2+1);
//	}
//}
//int main()
//{
//	int a = 0;//����ƿ����������20ƿ���ϣ�����20����ƿ����10ƿ���ϣ�����5����ƿ��������ƿ����1��
//	int n = 0;//Ǯ
//	scanf("%d", &n);
//	int ret=count_a(n);//20����ƿ
//	a = ret+n;
//	//a = 2 * n - 1;
//	printf("%d", a);
//	return 0;
//}

//����
//int main()
//{
//	int n = 0;//�ϴ����ǲ���
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n-1-i; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < 2*i+1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = 0; i <n-1; i++)
//	{
//		for (int j = 0; j < i+1; j++)
//		{
//			printf(" ");
//		}
//		for (int j = 0; j < 2*n-3-2*i; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//ˮ�ɻ���
//int main()
//{
//	
//	for (int i = 0; i < 100000; i++)
//	{
//		//����λ��
//		int n = 1;//λ��
//		int ret = i;
//		while (ret /=10)
//		{
//			n++;
//		}
//		//�����
//		ret = i;
//		int sum = 0;
//		while (ret)
//		{
//			sum += pow(ret % 10, n);//ÿһλ��n�η�
//			ret /= 10;
//		}
//		if (i == sum)
//		{
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//2,22,222,2222,22222,n=5,a=2;���
//int main()
//{
//	int n = 0, a = 0,ret=0,sum=0;
//	scanf("%d%d", &n, &a);
//	for (int i = 0; i < n; i++)
//	{
//		ret = ret * 10 + a;
//		sum += ret;
//	}
//	printf("%d", sum);
//	return 0;
//}

//int main()
//{
//	int n = 0,a=0,Sn=0,an=0;
//	int arr[20] = { 0 };
//	scanf("%d%d", &n, &a);
//	for (int i = 0; i < n; i++)
//	{
//		if (i == 0)
//		{
//			an= a;
//		}
//		if(i>0)
//		{
//			a = 10 * a;
//			an= an + a;
//		}
//		arr[i] = an;
//	}
//	for (int j = 0; j < n; j++)
//	{
//		Sn = arr[j] + Sn;	
//	}
//	printf("%d ", Sn);
//	return 0;
//}

//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);
//	
//	printf("%s", arr);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	for (int i = 0; i < n/2+1; i++)
//	{
//		for (int j = n/2+1-i; j > 0; j--)
//		{
//			printf(" ");
//		}
//		for (int k = 0; k < 2*i+1; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for (int i = 0; i < n/2; i++)
//	{
//		for (int j = 0; j < i+2; j++)
//		{
//			printf(" ");
//		}
//		for (int k =0 ; k < n - 2 - 2 * i; k++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//void Init_str(char str[row][col], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++);
//		{
//			str[i][j] = ' ';
//		}
//	}
//}
//void Print_str1(char str[row][col], int x, int y)
//{
//	int i = 0;
//	for (i = 0; i < x; i++)
//	{
//		int j = 0;
//		for (j = 0; j < y; j++)
//		{
//			str[i][j / 2] = '*';
//		}
//	}
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	char str[row][col] = { 0 };
//	Init_str(str, row, col);
//	Print_str1(str, row, col);
//	return 0;
//}

//int main()
//{
//	char* str[] = { "hello","alibaba","sexi" };
//	char** pa = str;
//	printf("%d\n", sizeof(*"hello"));
//	printf("%s\n", *str+1);
//	//printf("%c\n", *str);
//	return 0;
//}

//int main()
//{
//	char str[] = "asdlkdkg";
//	printf("%c\n", *str);
//	printf("%s\n", &str);
//	printf("%s\n", str);
//	return 0;
//}

//int main()
//{
//	int a = 5;
//	int b = 0x23;
//	int c = a + b;
//	printf("%d", c);
//	return 0;
//}

//int main()
//{
//	int arr[] = {1,2,3,4,5,};
//	int* prr = (int*)(&arr + 1);
//	printf("%d %d", *(arr + 1), *(prr - 1));
//	return 0;
//}

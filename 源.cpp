#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;


int main()
{
	char str = 69;
	char* p = &str;
	cout << str;
	return 0;
}

//������������ð��������
//void bobble(int arr[], int sz)
//{
//	for (int i = 0; i < sz-1; i++)
//	{
//		int k = 1;
//		for (int j = 0; j < sz-1-i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				k = 0;
//			}
//		}
//		if (k == 1)
//		{
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 10,9,8,7,6,5,4,3,2,1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	bobble(arr, sz);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//int main()
//{
//	char str[] = "abcdefg";
//	
//	char* p = str+5;
//	p = str;
//		printf("%c ", *p);
//	
//	return 0;
//}

//�õݹ��ӡһ������1234����ӡ���1 2 3 4
//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x/10);
//	}
//	printf("%d ", x%10);
//}
//int main()
//{
//	unsigned int a = 0;
//	cin >> a;
//	print(a);
//	return 0;
//}

//������ÿ����һ�κ���aֵ��һ
//void band(int* p)
//{
//	(*p)++;
//}
//int main()
//{
//	int a = 0;
//	printf("%d\n", a);
//	band(&a);
//	printf("%d\n", a);
//	band(&a);
//	printf("%d\n", a);
//	return 0;
//}

//enum class school
//{
//	a=100,c=102,
//	b,d=b,
//	e
//};
//
//int main()
//{
//	school sc{ school::e};
//	cout << (int)sc;
//	return 0;
//}

//���������ҵ�ĳ�����±�
//int num(int k,int arr[],int sz)//���鴫�Σ����������ǵ�ַ�������int arr[]��������һ��ָ��
//{
//	
//	int left = 0;
//	int right = sz - 1;
//
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			return mid;
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int k =7;
//	int d = 0;
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	d = num(k,arr,sz);
//	if(d==-1)
//	{
//		 printf("û�������");
//	}
//	else
//	{
//		printf("k���±�Ϊ��%d", d);
//	}
//	return 0;
//}

////�ж�һ�����ǲ�������
//int is_leap_year(int y)
//{
//	if (y % 4 == 0 && y % 100 != 0||y % 400 == 0)
//		return 1;
//	else
//		return 0;
//}
//
//int main()
//{
//	int year = 0;
//	cin >> year;
//	if (1 == is_leap_year(year))
//	{
//		printf("%d������", year);
//	}
//	else printf("%d��������", year);
//	return 0;
//}


//���Զ��庯���ж�һ�����ǲ�������
//int pad(int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)//ͷ�ļ�math.h
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;//��������1��������������0
//	/*int y = 0;
//	for (int i = 2; i < n; i++)
//	{
//		if (n % i == 0)
//		{
//			y = 1;
//			break;
//		}
//	}
//	if (y == 0)  
//		return 1; 
//	else  
//		return 0; */
//}
//int main()
//{
//	int a = 0;
//	cin >> a;
//	if (pad(a) == 1)
//		printf("%d������", a);
//	else
//		printf("%d��������",a);
//	
//	return 0;
//}



//����ػ�����
//int main()
//{
//	char password[10] = { 0 };
//	system("shutdown -s -t 60");
//    again:
//	printf("��ĵ��Խ���60s��رգ�������\"������\"���\n");
//	cin >> password;
//
//	if ((strcmp(password, "������") == 0))
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}
//��������Ϸ
//void menu()
//{
//	cout << "*******************************" << endl;
//	cout << "****1.play           0.exit****" << endl;
//	cout << "*******************************" << endl;
//}
//void game()
//{
//	int guess = 0;
//	int ret = 0;
//	ret = rand()%100+1;//������֣�һ���srand��������ʹ�ã�ͷ�ļ�stdlib.h
//	while (1)
//	{
//		cout << "������֣�>";
//		cin >> guess;
//		if(guess>ret)
//		{
//			cout << "�´���" << endl;
//		}
//		else if (guess < ret)
//		{
//			cout << "��С��" << endl;
//		}
//		else 
//		{
//			cout << "��ϲ�㣬�¶���" << endl; 
//			break;
//		}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));//ʱ�����time),ͷ�ļ�time.h
//	int op = 0;
//	do
//	{
//		menu();
//        cout << "��ѡ��>";
//	    cin >> op;
//
//		switch (op)
//		{
//		case 1:game(); break;
//		case 0:cout << "�˳���Ϸ��" << endl; break;
//		default:cout << "�����������������" << endl; break;
//		}
//	} while (op);
//
//	return 0;
//}

////��������������±꣬log
//int main()
//{
//	int k = 12;
//	int arr[] = { 1,3,5,6,7,10,12,20,66,67,88,91,100 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz-1;
//	
//	while (left <= right)
//	{
//		int mid = (left + right) / 2;
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else
//		{
//			printf("k���±�Ϊ��%d", mid);
//			break;
//		}
//	}
//	if (left > right) printf("û�������");
//	return 0;
//}

//�����������ֵ
//int main()
//{
//	int a[] = { -321,-568,-354,-4,-8,-33,-79,-52,-19,-385,-38,-64 };
//	int max=a[0];
//	int sz = sizeof(a) / sizeof(a[0]);
//	for (int i = 1; i < sz; i++)
//	{
//		if (a[i] > max)
//		{
//			max = a[i];
//		}
//	}
//	cout << max;
//	return 0;
//}


//int main()
//{
//	double sum = 0.0;
//	int i = 0;
//	int flag = 1;
//	for (i = 1; i <= 100; i++)
//	{
//		sum += flag*1.0 / i;
//		flag=-flag;
//	}
//	printf("%lf", sum);
//	return 0;
//}
//int main()
//{
//	int n = 0;
//	int c = 0;//���ܲ�
//	int a = 0;//ƻ��
//	int b = 0;//���ܲ�
//	while (b < 100)
//	{
//		b = 3 * n;
//		a = 200 - 7*n;
//		c = 4 *n -100;
//		if (a>=0&&b>=0&&c>=0)
//		{
//			printf("���ܲ���%d ƻ����%d ���ܲ���%d\n", c, a, b);
//		}
//		n++;
//    }
//	return 0;
//}


//������
//int main()
//{
//	int count = 0;
//	int i,j;
//	for (i = 101; i <= 200; i+=2)
//	{
//		int a = 0;
//		for (j = 2; j <=sqrt(i); j++)//ͷ�ļ�math.h
//		{
//			if (i % j == 0)
//			{
//				a = 1;
//				break;
//			}
//		}
//		if (a==0)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	cout << endl<<count;
//	return 0;
//}

//1000-2000֮����������Щ����������//||
//int main()
//{
//	int year = 0;
//	int count = 0;
//	for (int year = 1000; year <=2000; year++)
//	{
//		if (year % 4 == 0 && year % 100 != 0)
//		{
//			printf("%d ", year);
//			count++;
//		}
//		else if (year % 400 == 0)
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	//cout << endl;
//	printf("\n����=%d", count);
//	return 0;
//}

//���Լ��
//int main()
//{
//	int a, b,m=0;
//	cin >> a >> b;
//	
//	if (a > b)
//	{
//		m = a % b;
//		if (m==0)
//			printf("%d", b);
//		else
//		{
//			while (b % m!=0)
//			{
//				m = b % m;
//			}
//			printf("%d", m);
//		}
//	}
//	else if (a < b)
//	{
//		m = b % a;
//		if (m==0)
//			printf("%d", a);
//		else
//		{
//			while (a % m!=0)
//			{
//				m = a % m;
//			}
//			printf("%d", m);
//		}
//	}
//	else printf("%d", a);
//	return 0;
//}

////������������С��˳������
//int main()
//{
//	int a, b, c,mid;
//	cin >> a >> b >> c;
//	
//	if (a < b)
//	{
//		mid = b;
//		b = a;
//		a = mid;
//	}
//	if(a<c)
//	{
//		mid = c;
//		c = a;
//		a = mid;
//	}
//	if (b < c)
//	{
//		mid = c;
//		c = b;
//		b = mid;
//	}
//	printf("%d %d %d", a, b, c);
//	return 0;
//}

// //�������룬��������˳�ϵͳ
//int i = 1;
//char password[20] = { 0 };
//int main()
//{
//	while (i<=3)
//	{
//		printf("���������룺");
//		scanf("%s", password);
//
//		if (strcmp(password, "5620135") == 0)
//		{
//			printf("������ȷ��");
//			break;
//		}
//		else 
//		{ 
//			printf("�������\n"); 
//			i++;
//		}
//	}
//	if (i > 3)
//		printf("�˳�����");
//	return 0;
//}

//int main()
//{
//	char arr1[] = "Wellcom to this world!";
//	char arr2[] = "**********************";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	while (left <= right)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		
//		printf("%s\n", arr2);
//        Sleep(1000);//��ʱ��ͷ�ļ�stdlio
//		system("cls");//������ͷ�ļ�windows
//        left++;
//		right--;	
//	}
//	printf("%s\n", arr2);
//	return 0;
//}
// ����
//int main()
//{
//	
//	int m;
//	scanf("%d", &m);
//	int n = m / 2+1;
//	for (int i = 1; i <=n; i++)
//	{
//		for (int j = i; j <=n ; j++)
//		{
//			printf(" ");
//		}
//		for (int k = 1; k <= 2*i-1; k++)
//		{
//			printf("*");
//		}
//		cout << endl;
//	}
//
//	for (int a = 1; a <= n-1; a++)
//	{
//		for (int b = 1; b <=a+1; b++)
//		{
//			printf(" ");
//		}
//		for (int c = 1; c <= m-a*2; c++)
//		{
//			printf("*");
//		}
//		cout << endl;
//	}
//
//
//	return 0;
//}
//int main()
//{
//	int n, su;
//	cin >> n;
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j <= i; j++)
//		{
//			su = i * j;
//			cout << j << "x" << i << "=" << su << "\t";
//		}
//		cout << endl;
//	}
//	return 0;
//}


//int main()
//{
//     int n,s=1,sum=0;
//     cin >> n;
//     for (int i = 1; i <= n; i++)
//     {
//         s *= i; 
//         sum += s;
//         printf("%d\n",sum);
//     }
//     return 0;
//}

//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	char ch[] = "EOF";
//	printf("%s\n", ch);
//	return 0;
//}

//int main()
//{ 
//	int ch;
//	while ((ch = getchar()) !=EOF)
//	{
//		if (ch < '0' || ch>'9')
//			continue;
//		else
//			putchar(ch);
//	}
//	return 0;
// }
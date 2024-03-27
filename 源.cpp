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

//有序数组排序，冒泡排序函数
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

//用递归打印一个数字1234，打印结果1 2 3 4
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

//主函数每调用一次函数a值加一
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

//有序数组找到某个数下标
//int num(int k,int arr[],int sz)//数组传参，传过来的是地址，这里的int arr[]本质上是一个指针
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
//		 printf("没有这个数");
//	}
//	else
//	{
//		printf("k的下标为：%d", d);
//	}
//	return 0;
//}

////判断一个数是不是闰年
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
//		printf("%d是闰年", year);
//	}
//	else printf("%d不是闰年", year);
//	return 0;
//}


//用自定义函数判断一个数是不是素数
//int pad(int n)
//{
//	for (int i = 2; i <= sqrt(n); i++)//头文件math.h
//	{
//		if (n % i == 0)
//			return 0;
//	}
//	return 1;//素数返回1，不是素数返回0
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
//		printf("%d是素数", a);
//	else
//		printf("%d不是素数",a);
//	
//	return 0;
//}



//恶意关机程序
//int main()
//{
//	char password[10] = { 0 };
//	system("shutdown -s -t 60");
//    again:
//	printf("你的电脑将在60s后关闭，请输入\"我是猪\"解除\n");
//	cin >> password;
//
//	if ((strcmp(password, "我是猪") == 0))
//	{
//		system("shutdown -a");
//	}
//	else
//	{
//		goto again;
//	}
//	return 0;
//}
//猜数字游戏
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
//	ret = rand()%100+1;//随机数字，一般和srand（）配套使用，头文件stdlib.h
//	while (1)
//	{
//		cout << "请猜数字：>";
//		cin >> guess;
//		if(guess>ret)
//		{
//			cout << "猜大了" << endl;
//		}
//		else if (guess < ret)
//		{
//			cout << "猜小了" << endl;
//		}
//		else 
//		{
//			cout << "恭喜你，猜对了" << endl; 
//			break;
//		}
//	}
//}
//int main()
//{
//	srand((unsigned int)time(NULL));//时间戳（time),头文件time.h
//	int op = 0;
//	do
//	{
//		menu();
//        cout << "请选择：>";
//	    cin >> op;
//
//		switch (op)
//		{
//		case 1:game(); break;
//		case 0:cout << "退出游戏！" << endl; break;
//		default:cout << "输入错误，请重新输入" << endl; break;
//		}
//	} while (op);
//
//	return 0;
//}

////有序数组遍历查下标，log
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
//			printf("k的下标为：%d", mid);
//			break;
//		}
//	}
//	if (left > right) printf("没有这个数");
//	return 0;
//}

//找数组里最大值
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
//	int c = 0;//胡萝卜
//	int a = 0;//苹果
//	int b = 0;//白萝卜
//	while (b < 100)
//	{
//		b = 3 * n;
//		a = 200 - 7*n;
//		c = 4 *n -100;
//		if (a>=0&&b>=0&&c>=0)
//		{
//			printf("胡萝卜：%d 苹果：%d 白萝卜：%d\n", c, a, b);
//		}
//		n++;
//    }
//	return 0;
//}


//算素数
//int main()
//{
//	int count = 0;
//	int i,j;
//	for (i = 101; i <= 200; i+=2)
//	{
//		int a = 0;
//		for (j = 2; j <=sqrt(i); j++)//头文件math.h
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

//1000-2000之间闰年有哪些，数量多少//||
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
//	printf("\n数量=%d", count);
//	return 0;
//}

//最大公约数
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

////把三个数按大到小的顺序排列
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

// //输入密码，输错三次退出系统
//int i = 1;
//char password[20] = { 0 };
//int main()
//{
//	while (i<=3)
//	{
//		printf("请输入密码：");
//		scanf("%s", password);
//
//		if (strcmp(password, "5620135") == 0)
//		{
//			printf("密码正确！");
//			break;
//		}
//		else 
//		{ 
//			printf("密码错误！\n"); 
//			i++;
//		}
//	}
//	if (i > 3)
//		printf("退出程序！");
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
//        Sleep(1000);//延时，头文件stdlio
//		system("cls");//清屏，头文件windows
//        left++;
//		right--;	
//	}
//	printf("%s\n", arr2);
//	return 0;
//}
// 菱形
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
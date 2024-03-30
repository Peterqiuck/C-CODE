//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main()
{
	int a = 0,b=0,c=0;
	for (int i = 100; i < 1000; i++)
	{
		a = i / 100;
		b = (i / 10) % 10;
		c = i % 10;
		if (i == a * a * a + b * b * b + c * c * c)
		{
			//printf("%d ", i);
			printf("%-5d", i);
		}
	}
	return 0;
}

//递归求前n位的斐波那契数之和
//int DR(int m)
//{
//	if ((m == 1) || (m == 2)) {
//		return 1;
//	}
//	else if (m > 2)
//	{
//		return DR(m - 1) + DR(m - 2);
//	}
//}
//int main()
//{
//	int n = 0;
//	int sum = 0;//求和
//	scanf("%d", &n);
//	for (int i = 1; i <= n; i++)
//	{
//		sum += DR(i);
//	}
//	printf("前n位斐波那契数列和为：%d\n", sum);
//	return 0;
//}

//求第n位的斐波那契数列
//#define num 1000
//int main(){
//	int n = 0;
//	int sum = 0;//前n位之和
//	scanf("%d", &n);
//	int arr[num] = { 0 };
//	for (int i = 1; i <= n; i++){
//		if ((i == 1) || (i == 2)) {
//			arr[i] = 1;
//		}
//		else if (i > 2){
//			arr[i] = arr[i - 1] + arr[i - 2];
//			if (i == n) {
//				printf("第n位数为：%d ", arr[n]);
//			}
//		}
//		sum += arr[i];
//	}
//	printf("\n%d", sum);
//	return 0;
//}

//用递归求n的k次方
//double sum(int n,int k){
//	if (k == 0){
//		return 1;
//	}
//	else if (k < 0){
//		return 1.0/n*sum(n,k+1);
//	}
//	else{
//		return n * sum(n, k - 1);
//	}
//}
//int main(){
//	int n = 0,k=0;
//	double ret = 0;
//	while (1){
//		scanf("%d%d", &n, &k);
//		if (n == 0) {
//			ret = 0; break;
//		}
//		else if (n < 0){
//			printf("语法错误,请重新输入：<\n");
//		}
//		else {
//			ret = sum(n, k); break;
//		}
//	}
//	printf("%lf", ret);
//	return 0;
//}



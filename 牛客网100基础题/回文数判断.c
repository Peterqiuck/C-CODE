#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同。
// 思路，先创建数组放置该数字的每一位，然后开辟相应大小的空间，然后比较数组中位数的大小
int main()
{
    int k, a, q, sum = 0;
    printf("请输入一个整数：");
    scanf("%d", &k);
    a = k;
    while (a)
    {
        q = a % 10;
        a = a / 10;
        sum = 10 * sum + q; //翻转原数
    }
    if (k == sum)
        printf("\n%d是回文数", k);
    else
        printf("\n%d不是回文数", k);
    return 0;
}

//int main()
//{
//	int n,ret,count=1;
//	scanf("%d", &n);
//	ret = n;
//	while (ret /=10)
//	{
//		count++;
//	}
//	ret = n;
//	int* arr = (int*)malloc((count + 1) * sizeof(int));
//	if (arr == NULL)
//	{
//		perror("扩展失败\n");
//		return 0;
//	}
//	for (int i = count; i > 0; i--)
//	{
//		arr[i] = ret % 10;
//		ret /= 10;
//	}
//	int left = 1;
//	int right = count;
//	while (left<right)
//	{
//		if (arr[left] == arr[right])
//		{
//			left++;
//			right--;
//		}
//		else
//		{
//			break;
//		}
//	}
//	if (left == right)
//	{
//		printf("%d是回文数\n", n);
//	}
//	else
//	{
//		printf("%d不是回文数\n", n);
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//һ��5λ�����ж����ǲ��ǻ���������12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ��
// ˼·���ȴ���������ø����ֵ�ÿһλ��Ȼ�󿪱���Ӧ��С�Ŀռ䣬Ȼ��Ƚ�������λ���Ĵ�С
int main()
{
    int k, a, q, sum = 0;
    printf("������һ��������");
    scanf("%d", &k);
    a = k;
    while (a)
    {
        q = a % 10;
        a = a / 10;
        sum = 10 * sum + q; //��תԭ��
    }
    if (k == sum)
        printf("\n%d�ǻ�����", k);
    else
        printf("\n%d���ǻ�����", k);
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
//		perror("��չʧ��\n");
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
//		printf("%d�ǻ�����\n", n);
//	}
//	else
//	{
//		printf("%d���ǻ�����\n", n);
//	}
//	free(arr);
//	arr = NULL;
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//��������������m��n���������Լ������С������������12��16����С6�����30������m*n=��С*���
#include<stdio.h>
    int main()
    {
        int a, b, t, r;
        printf("�������������֣�\n");
        scanf("%d %d", &a, &b);
        if (a < b)
        {
            t = b; b = a; a = t;
        }
        r = a % b;
        int n = a * b;
        while (r != 0)
        {
            a = b;
            b = r;
            r = a % b;
        }
        printf("�������������Լ����%d����С��������%d\n", b, n / b);

        return 0;
    }




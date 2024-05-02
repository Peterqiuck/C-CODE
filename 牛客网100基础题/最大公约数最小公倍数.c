#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//输入两个正整数m和n，求其最大公约数和最小公倍数。例如12和16，最小6，最大30，而且m*n=最小*最大
#include<stdio.h>
    int main()
    {
        int a, b, t, r;
        printf("请输入两个数字：\n");
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
        printf("这两个数的最大公约数是%d，最小公倍数是%d\n", b, n / b);

        return 0;
    }




#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//猜凶手问题，已经确定四个人中有三个说的是真话，一个说的假话
//A说：不是我
//B说：是C
//C说：是D
//D说：C在说谎
int main()
{
	int xiongshou = 0;
	for (xiongshou = 'a'; xiongshou <= 'd'; xiongshou++)
	{
		for (xiongshou = 'a'; xiongshou <= 'd'; xiongshou++)
		{
			for (xiongshou = 'a'; xiongshou <= 'd'; xiongshou++)
			{
				for (xiongshou = 'a'; xiongshou <= 'd'; xiongshou++)
				{
					if ((xiongshou != 'a') + (xiongshou == 'c') + (xiongshou == 'd') + (xiongshou != 'd') == 3)
					{
						printf("凶手是：%c", xiongshou);
					}
				}
			}
		}
	}
	return 0;
}

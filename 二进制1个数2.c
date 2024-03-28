int main()
{
	int a = -1;
	int count = 0;
	while (a)
	{
		a = a & (a - 1);
		count++;
	}
	printf("1的个数为%d\n", count);
	return 0;
}

int main()
{
	int a = -1;
	int count = 0;
	for (int i = 0; i < 32; i++)
	{
		if (((a >> i) & 1) == 1)
		{
			count++;
		}
	}
	printf("%d ", count);
	return 0;
}

强制类型转换
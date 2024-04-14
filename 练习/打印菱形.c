int main()
{
	int n = 0;//上层大三角层数，总层数为2*n-1
	scanf("%d", &n);
	//打印上层大三角层数
	for (int i = 0; i < n; i++)
	{
		//1.打印左侧倒三角空格
		for (int j = 0; j < n-1-i; j++)
		{
			printf(" ");
		}
		//2.打印星型大三角
		for (int j = 0; j < 2*i+1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	//打印下层倒三角层数，从最长数量的星型行的下一行开始打印
	for (int i = 0; i <n-1; i++)
	{
		//3.打印左侧正三角空格
		for (int j = 0; j < i+1; j++)
		{
			printf(" ");
		}
		//4.打印星型倒三角
		for (int j = 0; j < 2*n-3-2*i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
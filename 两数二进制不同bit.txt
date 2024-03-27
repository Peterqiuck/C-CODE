//两int类型数在32位系统中，二进制数中，数字不同的bit位置的个数
int same(int m, int n)
{
	int count = 0;
	unsigned int a = (unsigned int)m;
	unsigned int b = (unsigned int)n;
	for (int i = 0; i < 32; i++)
	{
		if (((a>>i) & 1) != ((b>>i) & 1))
		{
			count++;
		}
	}
	return count;
}
int main()
{
	int m = 1999;
	int n = 2299;
	int ret=same(m, n);
	printf("%d\n", ret);
	return 0;
}
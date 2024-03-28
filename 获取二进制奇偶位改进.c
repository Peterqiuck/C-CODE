//获取一个数二进制数中奇数位与偶数位
void exchange(int m)
{
	printf("偶数位：");
	for (int i = 31; i >= 0; i-=2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\n奇数位：");
	for (int j = 30; j >= 0; j-=2)
	{
		printf("%d ", (m >> j) & 1);
	}
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	exchange(m);
	return 0;
}
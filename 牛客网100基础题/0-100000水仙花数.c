#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

//ˮ�ɻ���
int main()
{
	for (int i = 0; i < 100000; i++)
	{
		//����λ��
		int n = 1;//λ��
		int ret = i;
		while (ret /=10)
		{
			n++;
		}
		//�����
		ret = i;
		int sum = 0;
		while (ret)
		{
			sum += pow(ret % 10, n);//ÿһλ��n�η�
			ret /= 10;
		}
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}




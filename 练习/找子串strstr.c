#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//��ƺ���strstr
char* my_strstr(const char* p1, const char* p2)
{
	assert(p1 != NULL);
	assert(p2);
	char* s1 = p1;
	char* s2 = p2;
	if (*s2 == '\0')
	{
		return p1;
	}
	while (*s2!='\0')
	{
		while ((*s1 != *s2)&&(*s1 != '\0'))//�ҵ���ͬԪ�ص��׵�ַ
		{
			s1++;
		}
		char* start = s1;
		if (*s1 == '\0')//���������p1û������ͬԪ�أ����5.���磺abcd��fe
		{
			return NULL;
		}
		else
		{
			while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))//��������ͬԪ��
			{
				s1++;
				s2++;
			}
			if ((*s1 != *s2) && (*s1 != '\0') && (*s2 != '\0'))//���1.���磺abbbbccdef��bbbcc
			{
				start++;
				s1 = start;
				s2 = p2;
			}
			else if ((*s1 != *s2)&&(*s1 == '\0') && (*s2 != '\0'))//���2.ֻ�в���Ԫ����ͬ�����磺abcdef��efa
			{
				return NULL;
			}
			else if ((*s1 != *s2) && (*s1 != '\0') && (*s2 == '\0'))//���3.���磺abcdef��cd
			{
				return start;
			}
			else if ((*s1 == *s2) && (*s1 == '\0') && (*s2 == '\0'))//���4.���磺abcdef��ef
			{
				return p2;
			}
		}
	}
}
int main()
{
	//���1-���3
	char str1[] = "abbbbccdef";
	char str2[] = "bbbcc";

	//���2
	//char str1[] = "abcdef";
	//char str2[] = "efa";

	//���3
	/*char str1[] = "abcdef";
	char str2[] = "cd";*/

	//���4
	//char str1[] = "abcdef";
	//char str2[] = "ef";

	//���5
	/*char str1[] = "abcde";
	char str2[] = "hj";*/
	int ret=my_strstr(str1, str2);
	printf("%s", ret);
	return 0;
}

//���Ӵ�
//int main()
//{
//	char str1[] = "abcdefgh";
//	char str2[] = "fgh";
//	char* ret = strstr(str1, str2);
//	if (ret == NULL)
//	{
//		printf("NO");
//	}
//	else
//	{
//		printf("%s", ret);
//	}
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//设计函数strstr
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
		while ((*s1 != *s2)&&(*s1 != '\0'))//找到相同元素的首地址
		{
			s1++;
		}
		char* start = s1;
		if (*s1 == '\0')//如果检索完p1没发现相同元素，情况5.例如：abcd与fe
		{
			return NULL;
		}
		else
		{
			while ((*s1 == *s2) && (*s1 != '\0') && (*s2 != '\0'))//发现有相同元素
			{
				s1++;
				s2++;
			}
			if ((*s1 != *s2) && (*s1 != '\0') && (*s2 != '\0'))//情况1.例如：abbbbccdef与bbbcc
			{
				start++;
				s1 = start;
				s2 = p2;
			}
			else if ((*s1 != *s2)&&(*s1 == '\0') && (*s2 != '\0'))//情况2.只有部分元素相同，例如：abcdef与efa
			{
				return NULL;
			}
			else if ((*s1 != *s2) && (*s1 != '\0') && (*s2 == '\0'))//情况3.例如：abcdef与cd
			{
				return start;
			}
			else if ((*s1 == *s2) && (*s1 == '\0') && (*s2 == '\0'))//情况4.例如：abcdef与ef
			{
				return p2;
			}
		}
	}
}
int main()
{
	//情况1-情况3
	char str1[] = "abbbbccdef";
	char str2[] = "bbbcc";

	//情况2
	//char str1[] = "abcdef";
	//char str2[] = "efa";

	//情况3
	/*char str1[] = "abcdef";
	char str2[] = "cd";*/

	//情况4
	//char str1[] = "abcdef";
	//char str2[] = "ef";

	//情况5
	/*char str1[] = "abcde";
	char str2[] = "hj";*/
	int ret=my_strstr(str1, str2);
	printf("%s", ret);
	return 0;
}

//找子串
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


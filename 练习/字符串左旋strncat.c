#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//×Ö·û´®str2ÊÇ·ñÊÇstr1µÄ×óĞı×Ö·û´®
int main()
{
	char str1[20] = "abcdef";
	char str2[] = "bcdefa";
	int sz1 = strlen(str1);
	int sz2 = strlen(str2);
	if (sz1 != sz2)
	{
		printf("NO!");
	}
	else
	{
		strncat(str1, str1, sz1);//×Ö·û´®ÏŞÖÆ×·¼Ó
		char* str3 = strstr(str1, str2);//str1ÀïÃæÕÒstr2
		printf("%s", str3);
	}
	
	return 0;
}

//×Ö·û´®×óĞı
//void reverse_x(char*strx,int x)
//{
//	int left = 0;
//	int right = x - 1;
//	while (left < right)
//	{
//		char tmp = strx[left];
//		strx[left] = strx[right];
//		strx[right] = tmp;
//		left++;
//		right--;
//	}
//}
//void reverse(char str[],int k)
//{
//	int sz=strlen(str);
//	char* left = str;
//	char* right = str + k;
//	reverse_x(left,k);
//	reverse_x(right,sz-k);
//	reverse_x(str, sz);
//}
//int main()
//{
//	int k = 0;
//	scanf("%d", &k);
//	char str[] = "abcdef";
//	int sz = strlen(str);
//	if (k > sz)
//	{
//		k %= sz;
//	}
//	reverse(str,k);
//	printf("%s", str);
//	return 0;
//}

//×Ö·û´®×óĞık´Î,±©Á¦Çó½â
//void cercle_str(char str[], int k)
//{
//	int sz = strlen(str);//7
//	while(k)
//	{
//		char tmp = *str;
//		for (int i = 0; i < sz - 1; i++)
//		{
//			str[i] = str[i + 1];
//		}
//		str[sz-1] = tmp;
//		k--;
//	}
//}
//int main()
//{
//	int k = 0;
//	char str[] = "ABCDEFGod";
//	scanf("%d", &k);
//	cercle_str(str, k);
//	printf("%s", str);
//	return 0;
//}

//char* my_strcpy(char* str1, const char* str2) {
//	assert(str1 != NULL);
//	assert(str2 != NULL);
//	char* ret = str1;
//	while (*str1++ = *str2++)
//	{
//		;
//	}
//	return ret;
//}
//int main() {
//	char str1[] = "123456789";
//	char str2[] = "sex";
//	strcat(str1, str2);
//	printf("%s\n", my_strcpy(str1, str2));
//	return 0;
//}


#include<stdio.h>
#include<assert.h>

//strcpy字符串复制完美运用
char* my_strcpy(char* str1, const char* str2){
	assert(str1!=NULL);
	assert(str2!=NULL);
	char* ret = str1;
	while (*str1++ = *str2++)
	{
		;
	 }
	return ret;
}
int main(){
	char str1[] = "123456789";
	char str2[] = "sex";
	printf("%s\n", my_strcpy(str1, str2));
	return 0;
}


//递归字符串长度
//int strlen_longth(char str[])
//{
//	if (*str == '\0')
//	{
//		return 0;
//	}
//	str++;
//	return 1 + strlen_longth(str);
//}
//int main()
//{
//	char str[] = "bitghfgf";
//	int ret = strlen_longth(str);
//	printf("字符串长度为:%d", ret);
//	return 0;
//}
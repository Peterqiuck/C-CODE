#include<stdio.h>
#include<assert.h>

//strcpy�ַ���������������
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


//�ݹ��ַ�������
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
//	printf("�ַ�������Ϊ:%d", ret);
//	return 0;
//}
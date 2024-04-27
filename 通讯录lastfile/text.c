#include "contact.h"

void menu()
{
	printf("**********************************************\n");
	printf("****1.add    2.del    3.search    4.modify****\n");
	printf("****5.show   6.sort   7.save      0.exit  ****\n");
	printf("**********************************************\n");
}
int main()//如果输入的字符串数量超过限定范围，将会出现未知报错
{
	int op = 0;
	struct contact un;
	Inlicontact(&un);
	do
	{
		menu();
		printf("请选择:");
		scanf("%d", &op);
		switch(op)
		{
		case ADD:Addcontact(&un);//增加通讯录
			break;
		case del:Delcontact(&un);//删除通讯录
			break;
		case search:Searchcontact(&un);//查找通讯录
			break;
		case modify:Modifycontact(&un);//修改通讯录
			break;
		case show:Showcontact(&un);//打印通讯录
			break;
		case sort:Sortcontact(&un);//通讯录分类排序
			break; 
		case save:Savecontact(&un);//保存通讯录
			break;
		case EXIT:
			Savecontact(&un);
			freespace(&un);
			printf("退出通讯录");
			break;
		default:printf("选择错误，请重新选择：");
			break;
		}
	} while (op);
	return 0;
}
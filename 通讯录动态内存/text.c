#include "contact.h"

void menu()
{
	printf("**********************************************\n");
	printf("****1.add    2.del    3.search    4.modify****\n");
	printf("****5.show   6.sort   0.exit              ****\n");
	printf("**********************************************\n");
}
int main()//���������ַ������������޶���Χ���������δ֪����
{
	int op = 0;
	struct contact un;
	Inlicontact(&un);
	do
	{
		menu();
		printf("��ѡ��:");
		scanf("%d", &op);
		switch(op)
		{
		case ADD:Addcontact(&un);//����ͨѶ¼
			break;
		case del:Delcontact(&un);//ɾ��ͨѶ¼
			break;
		case search:Searchcontact(&un);//����ͨѶ¼
			break;
		case modify:Modifycontact(&un);//�޸�ͨѶ¼
			break;
		case show:Showcontact(&un);
			break;
		case sort:Sortcontact(&un);//ͨѶ¼��������
			break; 
		case EXIT:freespace(&un);
			printf("�˳�ͨѶ¼");
			break;
		default:printf("ѡ�����������ѡ��");
			break;
		}
	} while (op);
	return 0;
}
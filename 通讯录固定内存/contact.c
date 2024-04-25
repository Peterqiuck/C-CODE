#include "contact.h"

void Inlicontact(struct contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->count = 0;
}
void Addcontact(struct contact* ps)
{
	if (ps->count == max)
	{
		printf("ͨѶ¼����!\n");
	}
	else
	{
		printf("������������");
		scanf("%s", ps->data[ps->count].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[ps->count].age));
		printf("�������Ա�");
		scanf("%s", ps->data[ps->count].sex);
		printf("������绰��");
		scanf("%s", ps->data[ps->count].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[ps->count].addr);
			
		ps->count++;
		printf("��ӳɹ���\n");
	}
}
void Showcontact(const struct contact* ps)
{
	if (ps->count == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
	}
	else
	{
		int i = 0;
		printf("%-6s\t%-5s\t%-5s\t%-10s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		for (i = 0; i < ps->count; i++)
		{
			printf("%-6s\t%-5d\t%-5s\t%-10s\t%-20s\n",
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr);
		}
	}
}

int Search_name(const struct contact* ps, char name[name_max])
{
	int i = 0;
	for(i=0;i<ps->count;i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void Delcontact(struct contact* ps)
{
	if (0 == ps->count)
	{
		printf("ͨѶ¼Ϊ��:\n");
	}
	else
	{
		char name[name_max];
		printf("��������Ҫɾ����������");
		scanf("%s", name);
		int ret = Search_name(ps, name);
		if (-1 == ret)
		{
			printf("û���ҵ��������\n");
		}
		else
		{
			char str[name_max];
			printf("%-6s\t%-5s\t%-5s\t%-10s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
			printf("%-6s\t%-5d\t%-5s\t%-10s\t%-20s\n",
					ps->data[ret].name,
					ps->data[ret].age,
					ps->data[ret].sex,
					ps->data[ret].tele,
					ps->data[ret].addr);
			printf("��ȷ���Ƿ�ɾ������\n");
			while ("yes"||"no")
			{
				printf("�����룺yes or no\n");
				scanf("%s", str);
				if (strcmp(str,"no")==0)
				{
					printf("�˳�\n");
					break;
				}
				else if (strcmp(str, "yes") == 0)
				{
					int i;
					for (i = ret; i < ps->count-1; i++)
					{
						ps->data[i] = ps->data[i + 1];
					}
					ps->count--;
					printf("ɾ���ɹ���\n");
					break;
				}
				else
				{
					printf("�����������������!\n");
				}
			}
		}
	}
}

void Searchcontact(const struct contact* ps)
{
	if (0 == ps->count)
	{
		printf("ͨѶ¼Ϊ��:\n");
	}
	else
	{
		char name[name_max];
		printf("��������Ҫ���ҵ�������\n");
		scanf("%s", name);
		int ret = Search_name(ps, name);
		if (-1 == ret)
		{
			printf("û���ҵ��������\n");
		}
		else
		{
			printf("%-6s\t%-5s\t%-5s\t%-10s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
			printf("%-6s\t%-5d\t%-5s\t%-10s\t%-20s\n",
				ps->data[ret].name,
				ps->data[ret].age,
				ps->data[ret].sex,
				ps->data[ret].tele,
				ps->data[ret].addr);
		}
	}
}

void Modifycontact(struct contact* ps)
{
	char name[name_max];
	printf("��������Ҫ�޸ĵ�������\n");
	scanf("%s", name);
	int ret = Search_name(ps, name);
	if (-1 == ret)
	{
		printf("û���ҵ��������\n");
	}
	else
	{
		printf("%-6s\t%-5s\t%-5s\t%-10s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
		printf("%-6s\t%-5d\t%-5s\t%-10s\t%-20s\n",
			ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,
			ps->data[ret].addr);
		printf("��������Ϣ\n");
		printf("������������");
		scanf("%s", ps->data[ret].name);
		printf("���������䣺");
		scanf("%d", &(ps->data[ret].age));
		printf("�������Ա�");
		scanf("%s", ps->data[ret].sex);
		printf("������绰��");
		scanf("%s", ps->data[ret].tele);
		printf("�������ַ��");
		scanf("%s", ps->data[ret].addr);

		printf("�޸ĳɹ���\n");
	}
}

void Sortcontact(struct contact* ps)
{

}
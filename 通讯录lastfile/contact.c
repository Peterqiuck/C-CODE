#include "contact.h"

void Addspace(contact* ps)
{
	if (ps->count == ps->sz)
	{
		ps->sz += 2;
		person* ptr = (person*)realloc(ps->data, ps->sz * sizeof(person));
		if (ptr != NULL)
		{
			ps->data = ptr;
			printf("空间增加！\n");
		}
		else
		{
			printf("扩容失败！\n");
		}
	}
}

void Inlicontact(struct contact* ps)
{
	ps->count = 0;
	ps->sz = lnil_value;
	ps->data = (person*)malloc(lnil_value * sizeof(person));
	if (ps->data == NULL)
	{
		return;
	}
	FILE* pfread = fopen("contact.dat", "rb");
	if (pfread == NULL)
	{
		printf("pfread_addspace:%s\n", strerror(errno));
		return;
	}
	while (fread(&(ps->data[ps->count]), sizeof(person), 1, pfread))
	{
		ps->count++;
		Addspace(ps);
	}
	system("cls");
}

void Addcontact(contact* ps)
{
	Addspace(ps);//判断是否扩容
		printf("请输入姓名：");
		scanf("%s", ps->data[ps->count].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[ps->count].age));
		printf("请输入性别：");
		scanf("%s", ps->data[ps->count].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[ps->count].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[ps->count].addr);
			
		ps->count++;
		printf("添加成功！\n");
	
}
void Showcontact(const struct contact* ps)
{
	if (ps->count == 0)
	{
		printf("通讯录为空！\n");
	}
	else
	{
		int i = 0;
		printf("%-6s\t%-5s\t%-5s\t%-10s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
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
		printf("通讯录为空:\n");
	}
	else
	{
		char name[name_max];
		printf("请输入需要删除的姓名：");
		scanf("%s", name);
		int ret = Search_name(ps, name);
		if (-1 == ret)
		{
			printf("没有找到这个姓名\n");
		}
		else
		{
			char str[name_max];
			printf("%-6s\t%-5s\t%-5s\t%-10s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
			printf("%-6s\t%-5d\t%-5s\t%-10s\t%-20s\n",
					ps->data[ret].name,
					ps->data[ret].age,
					ps->data[ret].sex,
					ps->data[ret].tele,
					ps->data[ret].addr);
			printf("请确认是否删除：？\n");
			while ("yes"||"no")
			{
				printf("请输入：yes or no\n");
				scanf("%s", str);
				if (strcmp(str,"no")==0)
				{
					printf("退出\n");
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
					printf("删除成功！\n");
					break;
				}
				else
				{
					printf("输入错误，请重新输入!\n");
				}
			}
		}
	}
}

void Searchcontact(const struct contact* ps)
{
	if (0 == ps->count)
	{
		printf("通讯录为空:\n");
	}
	else
	{
		char name[name_max];
		printf("请输入需要查找的姓名：\n");
		scanf("%s", name);
		int ret = Search_name(ps, name);
		if (-1 == ret)
		{
			printf("没有找到这个姓名\n");
		}
		else
		{
			printf("%-6s\t%-5s\t%-5s\t%-10s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
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
	printf("请输入需要修改的姓名：\n");
	scanf("%s", name);
	int ret = Search_name(ps, name);
	if (-1 == ret)
	{
		printf("没有找到这个姓名\n");
	}
	else
	{
		printf("%-6s\t%-5s\t%-5s\t%-10s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");
		printf("%-6s\t%-5d\t%-5s\t%-10s\t%-20s\n",
			ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,
			ps->data[ret].addr);
		printf("请输入信息\n");
		printf("请输入姓名：");
		scanf("%s", ps->data[ret].name);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[ret].age));
		printf("请输入性别：");
		scanf("%s", ps->data[ret].sex);
		printf("请输入电话：");
		scanf("%s", ps->data[ret].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[ret].addr);

		printf("修改成功！\n");
	}
}

void Sortcontact(struct contact* ps)
{

}

void freespace(contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}

void Savecontact(contact* ps)
{
	int i;
	FILE* pfwrite = fopen("contact.dat", "wb");
	if (pfwrite == NULL)
	{
		printf("pfwritr_addspace:%s\n", strerror(errno));
		return;
	}
	for (i = 0; i < ps->count; i++)
	{
		fwrite(&(ps->data[i]), sizeof(person), 1, pfwrite);
	}
	printf("保存成功！\n");
}
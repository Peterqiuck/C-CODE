#pragma once
#define _CRT_SECURE_NO_WARNINGS

#define max 1000
#define name_max 20
#define sex_max 10
#define tele_max 15
#define addr_max 30

#include<stdio.h>
#include<string.h>

enum option
{
	exit,
	add,
	del,
	search,
	modify,
	show,
	sort
};
struct person
{
	char name[name_max];//姓名
	int age;            //年龄
	char sex[sex_max];  //性别
	char tele[tele_max];//电话
	char addr[addr_max];//地址
};
struct contact
{
	struct person data[max];
	int count;
};

void Inlicontact(struct contact* ps);
void Addcontact(struct contact* ps);
void Showcontact(const struct contact* ps);
void Delcontact(struct contact* ps);
void Searchcontact(const struct contact* ps);
void Modifycontact(struct contact* ps);
void Sortcontact(struct contact* ps);

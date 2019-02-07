//版本：写入文件
#ifndef __COMMUNICATION_H__
#define __COMMUNICATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DEFAULT_SZ 2
#define FILE_NAME "contactor.txt"

enum Option//菜单选项
{
	Exit,
	Add,
	Delete,
	Search,
	Modify,
	Show,
	Empty,
	Sort
};



typedef struct PeoIfo
{
	char name[10];
	int age;
	char sex[5];
	char add[30];
	char phone[15];
}PeoIfo;//联系人信息

typedef struct Contact
{
	PeoIfo *data;
	unsigned int sz;
	unsigned int capacity;
}Contact, *pContact;



void InitContact(pContact Con);//对通讯录进行初始化，

void AddComunicator(pContact Con);//添加联系人

void ShowComunicator(pContact Con);//显示联系人

int SearchComunicator(pContact Con);//寻找某个联系人

void ModifyComunicator(pContact Con);//修改联系人

void DeleteComunicator(pContact Con);//删除指定联系人

void EmptyComunicator(pContact Con);//清空通讯录

void SortComunicator(pContact Con);//对联系人进行排序

void DestoryContact(pContact Con);//销毁开辟的空间

void SaveContact(pContact Con);//将联系人保存到本地文件

void LoadContact(pContact Con);//从本地文件读取联系人的信息

#endif//__COMUNICATION_H__
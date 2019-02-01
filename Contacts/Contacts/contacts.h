////////////////////////////////////////////////////////////////////////////////
//contacts.h
//Copyright (c) 2018  葵
//All rights reserved
//
//
//文件名称：comunication.h
//摘    要：2.实现一个通讯录；
//	        通讯录可以用来存储1000个人的信息，每个人的信息包括：
//			姓名、性别、年龄、电话、住址
//	
//			提供方法：
//			1.	添加联系人信息
//			2.	删除指定联系人信息
//			3.	查找指定联系人信息
//			4.	修改指定联系人信息
//			5.	显示所有联系人信息
//			6.	清空所有联系人+
//			7.	以名字排序所有联系人
//
//
//
//当前版本：1.0
//作    者：葵
//完成日期：


#ifndef __CONTACTS_H_  //防止.h被重复引用
#define __CONTACTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define MAX_NUM  1000

//非动态添加
struct PeoIfn
{
	char name[10];
	char sex[5];
	char add[30];
	char phone[15];
	int age;
};




void AddComunicator(struct PeoIfn data[], int cou);
void ShowComunicator(struct PeoIfn data[], int cou);
void SearchComunicator(struct PeoIfn data[], int cou);
void ModifyComunicator(struct PeoIfn data[], int cou);
void DeleteComunicator(struct PeoIfn data[], int cou);
void EmptyComunicator(struct PeoIfn data[], int cou);
void SortComunicator(struct PeiIfn data[], int cou);


#endif

	
////////////////////////////////////////////////////////////////////////////////
//contacts.h
//Copyright (c) 2018  ��
//All rights reserved
//
//
//�ļ����ƣ�comunication.h
//ժ    Ҫ��2.ʵ��һ��ͨѶ¼��
//	        ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ������
//			�������Ա����䡢�绰��סַ
//	
//			�ṩ������
//			1.	�����ϵ����Ϣ
//			2.	ɾ��ָ����ϵ����Ϣ
//			3.	����ָ����ϵ����Ϣ
//			4.	�޸�ָ����ϵ����Ϣ
//			5.	��ʾ������ϵ����Ϣ
//			6.	���������ϵ��+
//			7.	����������������ϵ��
//
//
//
//��ǰ�汾��1.0
//��    �ߣ���
//������ڣ�


#ifndef __CONTACTS_H_  //��ֹ.h���ظ�����
#define __CONTACTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Option//�˵�ѡ��
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

//�Ƕ�̬���
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

	
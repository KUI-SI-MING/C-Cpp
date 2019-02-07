//�汾��д���ļ�
#ifndef __COMMUNICATION_H__
#define __COMMUNICATION_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DEFAULT_SZ 2
#define FILE_NAME "contactor.txt"

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



typedef struct PeoIfo
{
	char name[10];
	int age;
	char sex[5];
	char add[30];
	char phone[15];
}PeoIfo;//��ϵ����Ϣ

typedef struct Contact
{
	PeoIfo *data;
	unsigned int sz;
	unsigned int capacity;
}Contact, *pContact;



void InitContact(pContact Con);//��ͨѶ¼���г�ʼ����

void AddComunicator(pContact Con);//�����ϵ��

void ShowComunicator(pContact Con);//��ʾ��ϵ��

int SearchComunicator(pContact Con);//Ѱ��ĳ����ϵ��

void ModifyComunicator(pContact Con);//�޸���ϵ��

void DeleteComunicator(pContact Con);//ɾ��ָ����ϵ��

void EmptyComunicator(pContact Con);//���ͨѶ¼

void SortComunicator(pContact Con);//����ϵ�˽�������

void DestoryContact(pContact Con);//���ٿ��ٵĿռ�

void SaveContact(pContact Con);//����ϵ�˱��浽�����ļ�

void LoadContact(pContact Con);//�ӱ����ļ���ȡ��ϵ�˵���Ϣ

#endif//__COMUNICATION_H__
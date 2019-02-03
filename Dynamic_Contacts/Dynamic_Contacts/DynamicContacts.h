#ifndef __DYNAMICCONTACTS_H__ 
#define __DYNAMICCONTACTS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define DEFAULT_SZ 2

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


//��̬���
typedef struct PeoIfo
{
	char name[10];
	int age;
	char sex[5];
	char add[30];
	char phone[15];
}PeoIfo;

typedef struct Contact
{
	PeoIfo *data;
	unsigned int sz;
	unsigned int capacity;
}Contact, *pContact;



void InitContact(pContact Con);
void AddComunicator(pContact Con);
void ShowComunicator(pContact Con);
int SearchComunicator(pContact Con);
void ModifyComunicator(pContact Con);
void DeleteComunicator(pContact Con);
void EmptyComunicator(pContact Con);
void SortComunicator(pContact Con);

#endif//
#ifndef _DOUBLELIST_H__
#define _DOUBLELIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int LTDataType;

typedef struct ListNode
{
	LTDataType d;
	struct ListNode* next;//结构体的定义问题
	struct ListNode* prev;
}ListNode,*pListNode;

typedef struct List
{
	struct ListNode* head;
}List,*pList;



void ListInit(pList lt);
void ListDestory(pList lt);
void ListPushBack(pList lt, LTDataType x);
void ListPushFront(pList lt, LTDataType x);
void ListPopBack(pList lt);
void ListPopFront(pList lt);

pListNode BuyListNode(LTDataType x);
pListNode ListFind(pList lt, LTDataType x);
void ListInsert(pListNode pos, LTDataType x);
void ListErase(pListNode pos);
int ListSize(pList lt);
int ListEmpty(pList lt);
void ListPrint(pList lt);


#endif//_DOUBLELIST_H__
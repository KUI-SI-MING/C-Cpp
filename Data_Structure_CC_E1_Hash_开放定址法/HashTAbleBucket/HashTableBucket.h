#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int HTBKeyType;
typedef int HTBValueType;
#define N 10

typedef struct HashNode
{
	struct HashNode* _next;
	HTBKeyType _key;
	HTBValueType _value;
}HashNode;

typedef struct HashTableBucket
{
	HashNode** _tables;//采用二级指针是为了防止空时压入一个空节点而是压入一个空指针
	size_t _size;
	size_t _len;
}HTB, *pHTB;

void HTBInit(pHTB htb, size_t len);
void HTBDestory(pHTB htb);

int HTBInsert(pHTB htb, HTBKeyType key, HTBValueType value);
int HTBRemove(pHTB htb, HTBKeyType key);
HashNode* HTBFind(pHTB htb, HTBKeyType key);
void HTBPrint(pHTB htb);

int HTBSize(pHTB htb);
int HTBEmpty(pHTB htb);

void TestHashTableBucket();
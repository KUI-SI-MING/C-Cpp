#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_SZ 3
typedef int DataType;

typedef struct SeqList
{
	DataType *data;
	int sz;
	int capacity;
}SeqList, *pSeqList;

void InitSeqList(pSeqList pSeq);//≥ı ºªØ
void PushBack(pSeqList pSeq, DataType d);
void PrintSeqList(pSeqList pSeq);
void DestorySeqList(pSeqList pSeq);
int Find(pSeqList pSeq, DataType d);
void PopBack(pSeqList pSeq);
void Insert(pSeqList pSeq, int pos, DataType d);
void Erase(pSeqList pSeq, int pos);
int Empty(pSeqList pSeq);
void Capacity(pSeqList pSeq);
void Size(pSeqList pSeq);


#endif // __SEQLIST_H__

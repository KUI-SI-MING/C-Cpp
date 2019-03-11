////��ʼ�� 
//void InitSeqList(PSeqList pSeq);
////β������ 
//void PushBack(PSeqList pSeq, DataType data);
////β��ɾ�� 
//void PopBack(PSeqList pSeq);
////ͷ������ 
//void PushFront(PSeqList pSeq, DataType data);
////ͷ��ɾ�� 
//void PopFront(PSeqList pSeq);
////����ָ��Ԫ�� 
//int Find(PSeqList pSeq, DataType data);
////ָ��λ�ò��� 
//void Insert(PSeqList pSeq, int pos, DataType data);
////ɾ��ָ��λ��Ԫ�� 
//void Erase(PSeqList pSeq, int pos);
////ɾ��ָ��Ԫ�� 
//void Remove(PSeqList pSeq, DataType data);
////ɾ�����е�ָ��Ԫ�� 
//void RemoveAll(PSeqList pSeq, DataType data);
////����˳���Ĵ�С 
//int Size(PSeqList pSeq);
////�ж�˳����Ƿ�Ϊ�� 
//int Empty(PSeqList pSeq);
////ð������ 
//void BubbleSort(PSeqList pSeq);
////ѡ������ 
//void SelectSort(PSeqList pSeq);
////ѡ��������Ż� 
//void SelectSortOP(PSeqList pSeq);
////���ֲ��� 
//int BinarySearch(PSeqList pSeq, DataType data);
////���ֲ��ҵݹ�д�� 
//int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d);

//��ӡ 
//void PrintSeqList(PSeqList pSeq);



#ifndef __SEQLIST_H__
#define __SEQLIST_H__

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
typedef int DataType;

typedef struct SeqList
{
	DataType data[MAX];
	int sz;
}SeqList, *pSeqList;

void InitSeqList(pSeqList pSeq);//��ʼ��
void PushBack(pSeqList pSeq, DataType d);
void PrintSeqList(pSeqList pSeq);
void PopBack(pSeqList pSeq);
void PushFront(pSeqList pSeq, DataType d);
void PopFront(pSeqList pSeq);
int Find(pSeqList pSeq, DataType d);
void Insert(pSeqList pSeq, int pos, DataType d);
void Erase(pSeqList pSeq, int pos);
void Remove(pSeqList pSeq, DataType d);
void RemoveAll(pSeqList pSeq, DataType d);
int Size(pSeqList pSeq);
int Empty(pSeqList pSeq);
void BubbleSort(pSeqList pSeq);
void SelectSort(pSeqList pSeq);
void SelectSortOP(pSeqList pSeq);
int BinarySearch(pSeqList pSeq, DataType d);
int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d);

#endif // __SEQLIST_H__
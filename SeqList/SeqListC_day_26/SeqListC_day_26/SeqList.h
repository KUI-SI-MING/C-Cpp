////初始化 
//void InitSeqList(PSeqList pSeq);
////尾部插入 
//void PushBack(PSeqList pSeq, DataType data);
////尾部删除 
//void PopBack(PSeqList pSeq);
////头部插入 
//void PushFront(PSeqList pSeq, DataType data);
////头部删除 
//void PopFront(PSeqList pSeq);
////查找指定元素 
//int Find(PSeqList pSeq, DataType data);
////指定位置插入 
//void Insert(PSeqList pSeq, int pos, DataType data);
////删除指定位置元素 
//void Erase(PSeqList pSeq, int pos);
////删除指定元素 
//void Remove(PSeqList pSeq, DataType data);
////删除所有的指定元素 
//void RemoveAll(PSeqList pSeq, DataType data);
////返回顺序表的大小 
//int Size(PSeqList pSeq);
////判断顺序表是否为空 
//int Empty(PSeqList pSeq);
////冒泡排序 
//void BubbleSort(PSeqList pSeq);
////选择排序 
//void SelectSort(PSeqList pSeq);
////选择排序的优化 
//void SelectSortOP(PSeqList pSeq);
////二分查找 
//int BinarySearch(PSeqList pSeq, DataType data);
////二分查找递归写法 
//int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d);

//打印 
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

void InitSeqList(pSeqList pSeq);//初始化
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
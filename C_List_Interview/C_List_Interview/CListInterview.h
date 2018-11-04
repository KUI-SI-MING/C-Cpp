#ifndef __CListInterview_H__
#define __CListInterview_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int DataType;

typedef struct Node
{
	DataType data;
	struct Node* next;
}Node, *pNode, List, *pList;

typedef struct ComplexNode
{
	DataType data;
	struct ComplexNode* next;
	struct ComplexNode* random;
}ComplexNode;

pNode BuyNode(DataType d);
void DestroyLinkList(pList* pplist);
void PushBack(pList* pplist, DataType d);
void PrintLinkList(pList plist);
pNode Find(pList plist, DataType d);

void PrintTailToHeadPlist(pList plist);
void DelNodeNotTail(pNode pos);
void InsertNode(pNode pos, DataType d);
void JosephusCycle(pList* pplist, DataType number);
void ReverseList(pList* pplist);
void BubbleSort(pList plist);
pList Merge(pList plist1, pList plist2);
pList Merge_R(pList plist1, pList plist2);
pNode FindLastKNode(pList plist, int k);
void PopLastKNode(pList* pplist, int k);
pNode IsCycle(pList plist);
int GetCycleLength(pList meet);
pNode GetCycleEntryNode(pList plist, pList meet);
void CheckCross(pList plist1, pList plist2);
pNode GetCrossNode(pList plist1, pList plist2);
void UnionSet(pList plist1, pList plist2);
ComplexNode* BuyComplexNode(DataType d);
void printComplexList(ComplexNode* plist);
ComplexNode* CopyComplexList(ComplexNode* plist);

#endif //  __CListInterview_H__
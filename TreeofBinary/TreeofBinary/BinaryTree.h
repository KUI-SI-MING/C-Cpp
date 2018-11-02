#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Queue.h"
#include "Stack.h"

//struct TreeNode
//{
//	// data;
//	TNDataType data;
//	//struct TreeNode* childs[N];
//	SeqList childs; //->struct TreeNode*
//};
//////////////////////////////////////////////////
//������
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode, *pBTNode;

// a��һ��ǰ�����������
pBTNode BinaryTreeCreate(BTDataType* a, int n, int* pi);
void BinaryTreeDestory(pBTNode root);

int BinaryTreeSize(pBTNode root);
int BinaryTreeLeafSize(pBTNode root);
int BinaryTreeLevelKSize(pBTNode root, int k);
pBTNode BinaryTreeFind(pBTNode root, BTDataType x);

// ����  �ݹ�&�ǵݹ�
void BinaryTreePrevOrder(pBTNode root);
void BinaryTreeInOrder(pBTNode root);
void BinaryTreePostOrder(pBTNode root);
void BinaryTreeLevelOrder(pBTNode root);
int BinaryTreeComplete(pBTNode root);

void BinaryTreePrevOrderNonR(pBTNode root);
void BinaryTreeInOrderNonR(pBTNode root);
void BinaryTreePostOrderNonR(pBTNode root);

void TestBinaryTree();

///////////////////////////////////////
//��                  
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}Heap, *pHeap;

void HeapInit(pHeap hp, HPDataType* a, int n);
void HeapDestory(pHeap hp);
void HeapPush(pHeap hp, HPDataType x);
void HeapPop(pHeap hp);
HPDataType HeapTop(pHeap hp);
int HeapSize(pHeap hp);
int HeapEmpty(pHeap hp);
void HeapPrint(Heap hp);

// ��Ҫֱ�ӵ�Heap
int HeapSort(HPDataType* a, int n);///�����򽨴��
void AdjustDown(HPDataType* a, int n, int root);
void TestHeap();


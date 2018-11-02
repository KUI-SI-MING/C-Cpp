#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int BSTDataType;

typedef struct BSTreeNode
{
	struct BSTreeNode* left;
	struct BSTreeNode* right;
	BSTDataType data;
}BSTreeNode, *pBSTreeNode;

//�ǵݹ�
int BSTreeInsert(pBSTreeNode* ppTree, BSTDataType x);
int BSTreeRemove(pBSTreeNode* ppTree, BSTDataType x);
pBSTreeNode BSTreeFind(pBSTreeNode* ppTree, BSTDataType x);

//�ݹ�
int BSTreeInsert_R(pBSTreeNode* ppTree, BSTDataType x);
int BSTreeRemove_R(pBSTreeNode* ppTree, BSTDataType x);
pBSTreeNode BSTreeFind_R(pBSTreeNode* ppTree, BSTDataType x);

void BSTreeDestory(pBSTreeNode* ppTree);

void BSTInOrder(pBSTreeNode* ppTree);
void TestBSTree();
void TestBSTree_R();


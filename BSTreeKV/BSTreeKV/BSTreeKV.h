#pragma once



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


///////////////////////////////////////////////////////
//Key
//Key/Vealue
typedef char* KeyType;
typedef int ValueType;
//typedef char* ValueType;


typedef struct BSTreeNode
{
	struct BSTreeNode* left;
	struct BSTreeNode* right;

	 KeyType key;
	ValueType value;

}BSTreeNode, *pBSTreeNode;

pBSTreeNode BuyBSTreeNode(KeyType key, ValueType value);
int BSTreeInsert(pBSTreeNode* ppTree, KeyType key, ValueType value);
pBSTreeNode BSTreeFind(pBSTreeNode* ppTree, KeyType key);
void BSTreeInOrder(pBSTreeNode* ppTree);


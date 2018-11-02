#include"BSTreeKV.h"

pBSTreeNode BuyBSTreeNode(KeyType key, ValueType value)
{
	pBSTreeNode newnode = (pBSTreeNode)malloc(sizeof(BSTreeNode));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->key = (KeyType)malloc(strlen(key) + 1);
	strcpy(newnode->key, key);
	newnode->value = value;

	return newnode;
}

int BSTreeInsert(pBSTreeNode* ppTree, KeyType key, ValueType value)
{
	////非递归
	//pBSTreeNode cur = NULL;
	//pBSTreeNode parent = NULL;
	////空树
	//if (*ppTree == NULL)
	//{
	//	*ppTree = BuyBSTreeNode(key, value);
	//	return 1;
	//}
	////非空树
	//cur = *ppTree;
	////找到某一个叶子结点当做插入节点的父亲
	//while (cur)
	//{
	//	if (strcmp(cur->key, key) > 0)
	//	{
	//		parent = cur;
	//		cur = cur->left;
	//	}
	//	else if (strcmp(cur->key, key) < 0)
	//	{
	//		parent = cur;
	//		cur = cur->right;
	//	}
	//	else
	//	{
	//		return 0;
	//	}
	//}
	////在叶子节点的一端插入
	//if (strcmp(parent->key, key) < 0)
	//{
	//	parent->right = BuyBSTreeNode(key, value);
	//}
	//else
	//{
	//	parent->left = BuyBSTreeNode(key, value);
	//}
	//return 1;

	//递归
	if (*ppTree == NULL)
	{
		*ppTree = BuyBSTreeNode(key, value);
		return 1;
	}
	if (strcmp((*ppTree)->key, key) > 0)
	{
		return BSTreeInsert(&(*ppTree)->left, key, value);
	}
	else if (strcmp((*ppTree)->key, key) < 0)
	{
		return BSTreeInsert(&(*ppTree)->right, key, value);
	}
	else
	{
		return 0;
	}
}

pBSTreeNode BSTreeFind(pBSTreeNode* ppTree, KeyType key)
{
	////非递归
	//pBSTreeNode cur = *ppTree;
	//while (cur)
	//{
	//	if (strcmp(cur->key, key) < 0)
	//	{
	//		cur = cur->right;
	//	}
	//	else if (strcmp(cur->key, key) > 0)
	//	{
	//		cur = cur->left;
	//	}
	//	else
	//	{
	//		return cur;
	//	}
	//}
	//return NULL;

	//递归
	if (*ppTree == NULL)
	{
		return NULL;
	}
	if (strcmp((*ppTree)->key, key) > 0)
	{
		return BSTreeFind(&(*ppTree)->left, key);
	}
	else if (strcmp((*ppTree)->key, key) < 0)
	{
		return BSTreeFind(&(*ppTree)->right, key);
	}
	else
	{
		return *ppTree;
	}
}

void BSTreeInOrder(pBSTreeNode* ppTree)
{
	if (*ppTree == NULL)
	{
		return;
	}
	BSTreeInOrder(&(*ppTree)->left);
	printf(" %s  %d \n\n", (*ppTree)->key, (*ppTree)->value);
	BSTreeInOrder(&(*ppTree)->right);
}

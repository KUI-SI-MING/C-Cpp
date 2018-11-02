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
	////�ǵݹ�
	//pBSTreeNode cur = NULL;
	//pBSTreeNode parent = NULL;
	////����
	//if (*ppTree == NULL)
	//{
	//	*ppTree = BuyBSTreeNode(key, value);
	//	return 1;
	//}
	////�ǿ���
	//cur = *ppTree;
	////�ҵ�ĳһ��Ҷ�ӽ�㵱������ڵ�ĸ���
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
	////��Ҷ�ӽڵ��һ�˲���
	//if (strcmp(parent->key, key) < 0)
	//{
	//	parent->right = BuyBSTreeNode(key, value);
	//}
	//else
	//{
	//	parent->left = BuyBSTreeNode(key, value);
	//}
	//return 1;

	//�ݹ�
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
	////�ǵݹ�
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

	//�ݹ�
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

#include "BinarySearchTree.h"

pBSTreeNode BuyBSTreeNode(BSTDataType x)
{
	pBSTreeNode newnode = (pBSTreeNode)malloc(sizeof(BSTreeNode));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = x;

	return newnode;
}

int BSTreeInsert(pBSTreeNode* ppTree, BSTDataType x)
{
	pBSTreeNode cur = NULL;
	pBSTreeNode parent = NULL;
	//空树
	if (*ppTree == NULL)
	{
		*ppTree = BuyBSTreeNode(x);
		return 1;
	}
	//非空树
	cur = *ppTree;
	//找到某一个叶子结点当做插入节点的父亲
	while (cur)
	{
		if (cur->data > x)
		{
			parent = cur;
			cur = cur->left;                                        
		}
		else if (cur->data < x)
		{
			parent = cur;
			cur = cur->right;
		}
		else
		{
			return 0;
		}
	}
	//在叶子节点的一端插入
	if (parent->data < x)
	{
		parent->right = BuyBSTreeNode(x);
	}
	else
	{
		parent->left = BuyBSTreeNode(x);
	}
	return 1;
}

pBSTreeNode BSTreeFind(pBSTreeNode* ppTree, BSTDataType x)
{
	pBSTreeNode cur = *ppTree;
	while (cur)
	{
		if (cur->data < x)
		{
			cur = cur->right;
		}
		else if (cur->data > x)
		{
			cur = cur->left;
		}
		else
		{
			return cur;
		}
	}
	return NULL;
}

void BSTInOrder(pBSTreeNode* ppTree)
{

	if (*ppTree == NULL)
	{
		return;
	}
	BSTInOrder(&(*ppTree)->left);
	printf(" %d ", (*ppTree)->data);
	BSTInOrder(&(*ppTree)->right);
}

void BSTreeDestory(pBSTreeNode* ppTree)
{
	if (*ppTree == NULL)
	{
		return;
	}
	BSTreeDestory(&(*ppTree)->left);
	BSTreeDestory(&(*ppTree)->right);
	free(*ppTree);
	*ppTree = NULL;
	ppTree = NULL;
}

int BSTreeRemove(pBSTreeNode* ppTree, BSTDataType x)
{
	pBSTreeNode cur;
	pBSTreeNode parent;

	parent = NULL;
	cur = *ppTree;
	
	while (cur)
	{
		//找到X的位置
		if (cur->data < x)
		{
			parent = cur;
			cur = cur->right;
		}
		else if (cur->data > x)
		{
			parent = cur;
			cur = cur->left;
		}
		else
		{
			//开始删除

			//1.左为空/右为空
			//2.左右都不为空
			if (cur->left == NULL)
			{
				if (parent == NULL)
				{
					*ppTree = cur->right;
				}
				else
				{
					if (cur == parent->left)
					{
						parent->left = cur->right;
					}
					else
					{
						parent->right = cur->right;
					}
				}
			}
			else if (cur->right == NULL)
			{
				if (parent == NULL)
				{
					*ppTree = cur->left;
				}
				else
				{
					if (cur == parent->left)
					{
						parent->left = cur->left;
					}
					else
					{
						parent->right = cur->left;
					}
				}
			}
			else
			{
				//左右都不为空
				pBSTreeNode replace = cur->right;
				while (replace->left)
				{
					replace = replace->left;
				}
				cur->data = replace->data;
				return BSTreeRemove(&cur->right, replace->data);//？？？？？？？？？？
			}
			//free(cur);//?????????
			return 1;
		}                                                                                            
	}
	return 0;
}

int BSTreeInsert_R(pBSTreeNode* ppTree, BSTDataType x)
{
	if (*ppTree == NULL)
	{
		*ppTree = BuyBSTreeNode(x);
		return 1;
	}
	if ((*ppTree)->data > x)
	{
		return BSTreeInsert_R(&(*ppTree)->left, x);
	}
	else if ((*ppTree)->data < x)
	{
		return BSTreeInsert_R(&(*ppTree)->right, x);
	}
	else
	{
		return 0;
	}
}

int BSTreeRemove_R(pBSTreeNode* ppTree, BSTDataType x)
{
	if (*ppTree == NULL)
	{
		return - 1;
	}
	if ((*ppTree)->data < x)
	{
		return  BSTreeRemove_R(&(*ppTree)->right, x);
	}
	else if ((*ppTree)->data > x)
	{
		return BSTreeRemove_R(&(*ppTree)->left, x);
	}
	else
	{
		pBSTreeNode del = *ppTree;
		if ((*ppTree)->left == NULL)
		{
			*ppTree = (*ppTree)->right;
			//free(del);//???????????????????
		}
		else if ((*ppTree)->right == NULL)
		{
			*ppTree = (*ppTree)->left;
			//free(del);//??????????????????????
		}
		else
		{
			pBSTreeNode replace = (*ppTree)->right;
			while (replace->left)
			{
				replace = replace->left;
			}
			(*ppTree)->data = replace->data;
			return BSTreeRemove_R(&(*ppTree)->right, replace->data);
		}
	}
	return 1;
}

pBSTreeNode BSTreeFind_R(pBSTreeNode* ppTree, BSTDataType x)
{
	if (*ppTree == NULL)
	{
		return NULL;
	}
	if ((*ppTree)->data > x)
	{
		return BSTreeFind_R(&(*ppTree)->left, x);
	}
	else if ((*ppTree)->data < x)
	{
		return BSTreeFind_R(&(*ppTree)->right, x);
	}
	else
	{
		return *ppTree;
	}
}

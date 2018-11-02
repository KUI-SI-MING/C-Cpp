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
	//����
	if (*ppTree == NULL)
	{
		*ppTree = BuyBSTreeNode(x);
		return 1;
	}
	//�ǿ���
	cur = *ppTree;
	//�ҵ�ĳһ��Ҷ�ӽ�㵱������ڵ�ĸ���
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
	//��Ҷ�ӽڵ��һ�˲���
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
		//�ҵ�X��λ��
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
			//��ʼɾ��

			//1.��Ϊ��/��Ϊ��
			//2.���Ҷ���Ϊ��
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
				//���Ҷ���Ϊ��
				pBSTreeNode replace = cur->right;
				while (replace->left)
				{
					replace = replace->left;
				}
				cur->data = replace->data;
				return BSTreeRemove(&cur->right, replace->data);//��������������������
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

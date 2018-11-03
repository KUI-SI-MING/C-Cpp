#include "List.h"

pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->data = d;
	newNode->next = NULL;

	return newNode;
}

void InitLinkList(pList* pplist)
{
	assert(pplist != NULL);
	*pplist = BuyNode(1);
}

void PrintLinkList(pList plist)
{
	pList cur = plist;
	//链表为空
	if (cur == NULL)
	{
		printf("  NULL  \n");
		printf("\n");
	}
	//链表不为空
	else
	{
		while (cur != NULL)
		{
			printf(" %d -->", cur->data);
			cur = cur->next;
		}
		printf("NULL\n");
		printf("\n");
	}
}

int GetListLength(pList plist)
{
	int count = 0;
	pList cur = plist;

	while (cur)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
void DestroyLinkList(pList* pplist)
{
	assert(pplist != NULL);
	pNode cur = *pplist;
	while (cur)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	//链表为空时不做处理
}

void PushBack(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	pNode cur = *pplist;

	//空链表
	if (*pplist == NULL)
	{
		*pplist = BuyNode(d);
	}
	//非空链表
	else
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = BuyNode(d);
	}
}

void PopBack(pList* pplist)
{
	assert(pplist != NULL);
	pList cur = *pplist;
	if (*pplist == NULL)
	{
		printf(" 空链表 \n");
		printf("\n");
	}
	else if (cur->next == NULL)
	{
		free(cur);
		cur = NULL;
		*pplist = NULL;
		printf("单节点链表,成功删除尾节点！\n");
		printf("\n");
	}
	else
	{

		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}    
		free(cur->next);
		cur->next = NULL;   
		printf("多节点链表，成功删除尾节点！\n");
		printf("\n");
	}
}

void PushFront(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	pNode newNode = BuyNode(d);
	//*pplist newNode first
	newNode->next = *pplist;//新节点指向第一个节点
	*pplist = newNode;//头指向新节点
}

void PopFront(pList* pplist)
{
	assert(pplist != NULL);
	pList del = *pplist;
	if (*pplist == NULL)
	{
		printf(" 空链表 \n");
		printf("\n");
	}
	else if (del->next == NULL)
	{
		free(del);
		del = NULL;
		*pplist = NULL;
		printf("单节点链表,成功删除头节点！\n");
		printf("\n");
	}
	else
	{
		*pplist = del->next;
		free(del);
		del = NULL;
		printf("多节点链表，成功删除尾节点！\n");
		printf("\n");
	}
}

pNode Find(pList plist, DataType d)
{
	assert(plist != NULL);
	pList cur = plist;

	if (cur == NULL)//空链表
	{
		return NULL;
	}
	while ((cur->data != d) && (cur->next) != NULL)//未找到d && 链表未找完
	{
		cur = cur->next;
	}
	if (cur->data == d)//找到
	{
		return cur;
	}
	else//找不到
	{
		return NULL;
	}
}
void Insert(pList* pplist, pNode pos, DataType d)
{
	assert(pplist != NULL);
	assert(*pplist != NULL);
	pList cur = NULL;
	pNode newNode = NULL;

	//当 pos 不存在时
	if (NULL == pos)
	{
		printf("要插入的位置不存在！插入失败！\n");
		printf("\n");
		return;
	}
	else
	{
		//当pos是第一个节点时
		if (pos == *pplist)
		{
			PushFront(pplist, 4);
		}
		else
		{
			cur = *pplist;
			while (cur && (cur->next) != pos)
			{
				cur = cur->next;
			}
			if (cur != NULL)
			{
				newNode = BuyNode(d);
				newNode->next = pos;
				cur->next = newNode;
			}
		}
	}
	printf("插入成功！\n");
	printf("\n");
}

void Erase(pList* pplist, pNode pos)
{
	assert(pplist != NULL);
	assert(*pplist != NULL);
	pList cur = *pplist;

	//当 pos 不存在时
	if (NULL == pos)
	{
		printf("要删除的位置不存在！删除失败！\n");
		printf("\n");
		return;
	}
	else
	{
		//当pos是第一个节点时
		if (pos == *pplist)
		{
			PopFront(pplist);
		}
		else
		{
			//替换删除法
			while (cur && (cur->next) != pos)
			{
				cur = cur->next;
			}
			if (cur != NULL)
			{
				cur->next = pos->next;
				free(pos);
				pos = NULL;
			}
		}
		printf("删除成功！\n");
		printf("\n");
	}
}

void Remove(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	assert(*pplist != NULL);
	pList del = *pplist;
	pList pre = NULL;

	while (del)
	{
		if (del->data == d)
		{
			if (del == *pplist)//当d是第一个节点时
			{
				PopFront(pplist);
			}
			else
			{
				pre->next = del->next;
				free(del);
				del = NULL;
			}
			printf("修改成功！\n");
			printf("\n");
			return;
		}
		else
		{
			pre = del;
			del = del->next;
		}
	}
	printf("未找到该值!\n");
	printf("\n");
}

void RemoveAll(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	assert(*pplist != NULL);
	pList del = *pplist;
	pList pre = NULL;
	int flag = 0;

	while (del)
	{
		if (del->data == d)
		{
			if (del == *pplist)//当d是第一个节点时
			{
				PopFront(pplist);
				flag++;
			}
			else
			{
				pre->next = del->next;
				free(del);
				del = pre;//重新从前一个节点开始
				flag++;
			}
		}
		else
		{
			pre = del;
			del = del->next;
		}
	}
	if (flag == 0)
	{
		printf("未找到该值!\n");
		printf("\n");
	}
	else
	{
		printf("修改成功！\n");
		printf("\n");
	}
}

void EraseNotTailNode(pNode pos)
{
	assert((pos->next) != NULL);
	pNode del = NULL;

	if (pos == NULL)
	{
		printf("未找到该节点！\n");
		printf("\n");
		return;
	}
	del = pos->next;
	pos->data = pos->next->data;
	pos->next = del->next;
	free(del);
	del = NULL;
	printf("修改成功！\n");
	printf("\n");
}
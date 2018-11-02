#include "DoubleList.h"

pListNode BuyListNode(LTDataType x)
{
	pListNode newnode = (pListNode)malloc(sizeof(ListNode));
	assert(newnode);//防止开辟空间失败
	newnode->d = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

void ListInit(pList lt)
{
	assert(lt);

	lt->head = (pListNode)malloc(sizeof(ListNode));
	assert(lt->head);
	lt->head->next = lt->head;
	lt->head->prev = lt->head;
}

void ListDestory(pList lt)
{
	assert(lt);

	pListNode cur = lt->head;

	while (cur->next != lt->head)//当前节点不等于头节点时进行
	{
		cur = cur->next;
		pListNode del = cur;
		free(del);
		del = NULL;
	}
}

pListNode ListFind(pList lt, LTDataType x)
{
	assert(lt);


	pListNode pos = lt->head->next;
	while (pos != lt->head)
	{
		if (pos->d == x)
		{
			return pos;
		}
		pos = pos->next;
	}
	return NULL;
}

void ListInsert(pListNode pos, LTDataType x)
{
	assert(pos);

	pListNode newNode = BuyListNode(x);
	//prev newNode pos
	newNode->next = pos;
	newNode->prev = pos->prev;
	pos->prev->next = newNode;
	pos->prev = newNode;
}

void ListPushBack(pList lt, LTDataType x)
{
	assert(lt);

	//tail  newNode head
	ListInsert(lt->head, x);
}

void ListPushFront(pList lt, LTDataType x)
{
	assert(lt);

	ListInsert(lt->head->next, x);
}

void ListErase(pListNode pos)
{
	if (pos == NULL)
	{
		printf("无此数据！\n\n");
		return;
	}
	//pos->prev pos pos->next
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
	pos = NULL;
}

void ListPopBack(pList lt)
{
	assert(lt);

	ListErase(lt->head->prev);
}

void ListPopFront(pList lt)
{
	assert(lt);

	ListErase(lt->head->next);
}

int ListSize(pList lt)
{
	assert(lt);
	int listSzie = 0;

	pListNode cur = lt->head->next;
	while (cur != lt->head)
	{
		listSzie++;
		cur = cur->next;
	}
	return listSzie;
}

void ListPrint(pList lt)
{
	pListNode cur = lt->head->next;
	while (cur != lt->head)
	{
		printf(" %d ", cur->d);
		cur = cur->next;
	}
	printf("\n\n");
}

int ListEmpty(pList lt)
{
	assert(lt);

	if (ListSize(lt) != 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
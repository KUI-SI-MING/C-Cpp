#include "List.h"

void Test()
{
	pList plist = NULL;
	InitLinkList(&plist);
	PrintLinkList(plist);
	DestroyLinkList(&plist);
}

void TestPushBack()
{
	pList plist = NULL;

	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);

	PrintLinkList(plist);
	DestroyLinkList(&plist);
}

void TestGetListLength()
{
	pList plist = NULL;
	int count = 0;
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintLinkList(plist);

	count = GetListLength(plist);
	printf("该链表长度为: %d \n", count);
	printf("\n");
}
void TestPopBack()
{
	pList plist = NULL;

	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintLinkList(plist);

	PopBack(&plist);
	PrintLinkList(plist);

	PopBack(&plist);
	PrintLinkList(plist);

	PopBack(&plist);
	PrintLinkList(plist);

	PopBack(&plist);
	PrintLinkList(plist);

	PopBack(&plist);
	PrintLinkList(plist);

	PopBack(&plist);
	PrintLinkList(plist);

	DestroyLinkList(&plist);
}

void TestPushFront()
{
	pList plist = NULL;

	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);

	PrintLinkList(plist);
	DestroyLinkList(&plist);
}

void TestPopFront()
{
	pList plist = NULL;

	PushFront(&plist, 1);
	PushFront(&plist, 2);
	PushFront(&plist, 3);
	PushFront(&plist, 4);
	PushFront(&plist, 5);
	PrintLinkList(plist);

	PopFront(&plist);
	PrintLinkList(plist);

	PopFront(&plist);
	PrintLinkList(plist);

	PopFront(&plist);
	PrintLinkList(plist);

	PopFront(&plist);
	PrintLinkList(plist);

	PopFront(&plist);
	PrintLinkList(plist);

	PopFront(&plist);
	PrintLinkList(plist);

	DestroyLinkList(&plist);
}

void TestFind()
{
	pList plist = NULL;
	pNode pos = NULL;
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintLinkList(plist);

	pos = Find(plist, 3);//按值查找
	if (pos == NULL)
	{
		printf("找不到！\n");
		printf("\n");
	}
	else
	{
		printf(" 找到了该值为：%d \n", pos->data);
		printf("\n");
	}
}

void TestInsert()
{
	pList plist = NULL;
	pNode pos = NULL;
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintLinkList(plist);
	pos = Find(plist, 3);
	//pos = Find(plist, 6);

	Insert(&plist, pos, 4);
	PrintLinkList(plist);
}


void TestErase()
{
	pList plist = NULL;
	pNode pos = NULL;
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintLinkList(plist);
	pos = Find(plist, 3);
	//pos = Find(plist, 6);

	Erase(&plist, pos);
	PrintLinkList(plist);
}

void TestRemove()
{
	pList plist = NULL;
	
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 3);
	PushBack(&plist, 5);
	PushBack(&plist, 3);
	PrintLinkList(plist);

	Remove(&plist, 3);
	PrintLinkList(plist);
	Remove(&plist, 6);
	PrintLinkList(plist);
}

void TestRemoveAll()
{
	pList plist = NULL;

	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 3);
	PushBack(&plist, 5);
	PushBack(&plist, 3);
	PrintLinkList(plist);

	RemoveAll(&plist, 3);
	PrintLinkList(plist);

	RemoveAll(&plist, 6);
	PrintLinkList(plist);
}

void TextEraseNotTailNode()//删除非尾节点
{
	pList plist = NULL;
	pNode pos = NULL;
	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 3);
	PushBack(&plist, 4);
	PushBack(&plist, 5);
	PrintLinkList(plist);

	pos = Find(plist, 4);
	EraseNotTailNode(pos);//无头部,根据给定位置删除
	PrintLinkList(plist);
}

int main()
{
	//Test();
	//TestPushBack();
	//TestGetListLength();
	//TestPopBack();
	//TestPushFront();
	//TestPopFront();
	//TestFind();
	//TestInsert();
	//TestErase();
	//TestRemove();
	//TestRemoveAll();
	TextEraseNotTailNode();
	system("pause");
	return 0;
}
#include "DoubleList.h"

void test()
{
	List head;
	LTDataType in = 0;
	LTDataType ine = 0;
	pListNode pos;

	ListInit(&head);
	///////////////////////////////////////////////////////////////////////
	//尾插
	/*ListPushBack(&head, 1);
	ListPushBack(&head, 2);
	ListPushBack(&head, 3);
	ListPushBack(&head, 4);
	ListPushBack(&head, 5);
*/
	///////////////////////////////////////////////////////////////////////
	//头插
	ListPushFront(&head, 1);
	ListPushFront(&head, 2);
	ListPushFront(&head, 3);
	ListPushFront(&head, 4);
	ListPushFront(&head, 5);
	ListPushFront(&head, 6);
	ListPushFront(&head, 7);
	ListPushFront(&head, 8);

	if (ListEmpty(&head) != 0)
	{
		printf(" 双向链表的大小是: %d \n\n", ListSize(&head));
		printf("链表数据是：");
		ListPrint(&head);
	}
	else
	{
		printf("空链表\n\n");
	}
	///////////////////////////////////////////////////////////////////////
	//头删
	/*ListPopFront(&head);
	ListPopFront(&head);
	ListPopFront(&head);
*/
///////////////////////////////////////////////////////////////////////
//尾删
	ListPopBack(&head);
	ListPopBack(&head);
	ListPopBack(&head);

	if(ListEmpty(&head) != 0)
	{
		printf(" 修改后双向链表的大小是: %d \n\n", ListSize(&head));
		printf("链表数据是：");
		ListPrint(&head);
	}
	else
	{
		printf("空链表\n\n");
	}
///////////////////////////////////////////////////////////////////////
//查询
	printf("请输入要查找的数据：");
	scanf("%d", &in);
	printf("\n\n");
	pos = ListFind(&head, in);
	if (pos == NULL)
	{
		printf("无此数据\n\n");
	}
	else
	{
		printf("该数据是：%d \n\n", pos->d);
	}
///////////////////////////////////////////////////////////////////////
//插入
	printf("请输入要插入的数据：");
	scanf("%d", &ine);
	printf("\n\n");
	ListInsert(pos, ine);
	printf("插入成功\n\n");
	if (ListEmpty(&head) != 0)
	{
		printf(" 修改后双向链表的大小是: %d \n\n", ListSize(&head));
		printf("链表数据是：");
		ListPrint(&head);
	}
	else
	{
		printf("空链表\n\n");
	}
///////////////////////////////////////////////////////////////////////
//删除
	ListErase(pos);
	if (ListEmpty(&head) != 0)
	{
		printf(" 删除后双向链表的大小是: %d \n\n", ListSize(&head));
		printf("链表数据是：");
		ListPrint(&head);
	}
	else
	{
		printf("空链表\n\n");
	}

}

int main()
{

	test();
	system("pause");
	return 0;
}
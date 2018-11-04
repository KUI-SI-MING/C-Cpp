#include "CListInterview.h"


ComplexNode* BuyComplexNode(DataType d)
{
	ComplexNode *p = (ComplexNode *)malloc(sizeof(ComplexNode));
	p->data = d;
	p->next = NULL;
	p->random = NULL;
	return p;
}
void test()
{
	/*pList plist = NULL;
	DataType a = 0;
	DataType i = 0;
	DataType num = 0;
	pNode pos = NULL;

	PushBack(&plist, 1);
	PushBack(&plist, 2);
	PushBack(&plist, 5);
	PushBack(&plist, 5);
	PushBack(&plist, 3);
	PushBack(&plist, 6);
	PushBack(&plist, 7);
	PushBack(&plist, 9);*/
	//PrintLinkList(plist);

	int i = 0;
	pList plist1 = NULL;
	pList plist2 = NULL;
	pList newList = NULL;

	for (i = 1; i <= 9; i += 2)
	{
		PushBack(&plist1, i);
	}
	PrintLinkList(plist1);

	for (i = 1; i <= 8; i += 2)
	{
		PushBack(&plist2, i);
	}
	PrintLinkList(plist2);

	////一、由尾到头打印单链表
	//PrintTailToHeadPlist(plist);
	//printf("\n\n");

	//二、删除一个无头单链表的非尾节点，不能遍历链表
	/*printf("请输入你想删除的数字：");
	scanf("%d", &i);
	printf("\n");
	pos = Find(plist, i);
	if (pos != NULL)
	{

		DelNodeNotTail(pos);
		PrintLinkList(plist);
	}
	else
	{
		printf("删除失败！\n\n");
	}*/

	////三、在无头单链表的一个节点前插入一个节点，不能遍历链表
	//printf("请输入你想插入的数字：");
	//scanf("%d", &a);
	//printf("\n");
	//printf("请输入你想插入位置的数字：");
	//scanf("%d", &i);
	//printf("\n");
	//pos = Find(plist, i);
	//if (pos != NULL)
	//{

	//	InsertNode(pos, a);
	//	PrintLinkList(plist);
	//}
	//else
	//{
	//	printf("插入失败！\n\n");
	//}

	////四、单链表实现约瑟环
	//printf("请输入跳过个数：");
	//scanf("%d", &num);
	//printf("\n");
	//JosephusCycle(&plist, num);

	////五、逆置单向链表
	//ReverseList(&plist);
	//PrintLinkList(plist);

	////六、单链表排序
	//BubbleSort(plist);
	//PrintLinkList(plist);

	////七、合并两个有序链表，合并后依然有序
	//newList = Merge(plist1, plist2);
	//PrintLinkList(newList);
	//DestroyLinkList(newList);
	////八、递归版本
	//newList = Merge_R(plist1, plist2);
	//PrintLinkList(newList);
	//DestroyLinkList(newList);

	////九、寻找单链表中间节点
	//pos = FindMidNode(plist);
	//printf("中间元素: %d \n\n", pos->data);

	////十、查找单链表的倒数第K个节点，要求只能遍历一次链表
	//pos = FindLastKNode(plist, 2);
	//if (pos != NULL)
	//{
	//	printf(" %d \n\n", pos->data);
	//}

	////十一、删除链表倒数第K个节点
	//PopLastKNode(&plist, 2);
	//PrintLinkList(plist);

	////十二、判断链表是否带环，若带环，求环长度
	//int CycleLength = 0;
	//Find(plist, 9)->next = Find(plist, 3);
	//pNode Entry = NULL;
	//pos = IsCycle(plist);
	//Entry = GetCycleEntryNode(plist, pos);
	//if (pos != NULL)
	//{
	//	printf(" 环的相遇点: %d \n\n", pos->data);
	//	printf("环的长度为：%d \n\n", CycleLength = GetCycleLength(pos));
	//	printf("环的入口点为: %d \n\n", Entry->data);
	//}
	//else
	//{
	//	printf(" 不带环!\n\n");
	//}

	////十三、判断两条链表是否相交，链表不带环,求交点
	//Find(plist2, 6)->next = Find(plist1, 3);
	//PrintLinkList(plist1);
	//PrintLinkList(plist2);
	//pNode CrossNode = NULL;
	//CheckCross(plist1,plist2);
	//CrossNode = GetCrossNode(plist1, plist2);
	//if (CrossNode != NULL)
	//{
	//	printf("两条链表的相交点: %d \n\n", CrossNode->data);
	//}

	//十四、两条链表的交集
	UnionSet(plist1, plist2);

	////十五、复杂链表的复制
 //   ComplexNode* newList = NULL;
 //   ComplexNode* plist = NULL;
	//ComplexNode* p1 = BuyComplexNode(5);
	//ComplexNode* p2 = BuyComplexNode(4);
	//ComplexNode* p3 = BuyComplexNode(3);
	//ComplexNode* p4 = BuyComplexNode(2);
	//ComplexNode* p5 = BuyComplexNode(1);
	//plist = p1;
	//p1->next = p2;
	//p2->next = p3;
	//p3->next = p4;
	//p4->next = p5;

	//p1->random = p3;
	//p2->random = p1;
	//p3->random = NULL;
	//p4->random = p2;
	//p5->random = p4;

	//printComplexList(plist);
	//newList = CopyComplexList(plist);
	//printComplexList(plist);
	//DestroyLinkList(plist);
}

int main() 
{
	test();
	system("pause");
	return 0;
}
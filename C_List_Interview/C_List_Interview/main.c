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

	////һ����β��ͷ��ӡ������
	//PrintTailToHeadPlist(plist);
	//printf("\n\n");

	//����ɾ��һ����ͷ������ķ�β�ڵ㣬���ܱ�������
	/*printf("����������ɾ�������֣�");
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
		printf("ɾ��ʧ�ܣ�\n\n");
	}*/

	////��������ͷ�������һ���ڵ�ǰ����һ���ڵ㣬���ܱ�������
	//printf("�����������������֣�");
	//scanf("%d", &a);
	//printf("\n");
	//printf("�������������λ�õ����֣�");
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
	//	printf("����ʧ�ܣ�\n\n");
	//}

	////�ġ�������ʵ��Լɪ��
	//printf("����������������");
	//scanf("%d", &num);
	//printf("\n");
	//JosephusCycle(&plist, num);

	////�塢���õ�������
	//ReverseList(&plist);
	//PrintLinkList(plist);

	////��������������
	//BubbleSort(plist);
	//PrintLinkList(plist);

	////�ߡ��ϲ��������������ϲ�����Ȼ����
	//newList = Merge(plist1, plist2);
	//PrintLinkList(newList);
	//DestroyLinkList(newList);
	////�ˡ��ݹ�汾
	//newList = Merge_R(plist1, plist2);
	//PrintLinkList(newList);
	//DestroyLinkList(newList);

	////�š�Ѱ�ҵ������м�ڵ�
	//pos = FindMidNode(plist);
	//printf("�м�Ԫ��: %d \n\n", pos->data);

	////ʮ�����ҵ�����ĵ�����K���ڵ㣬Ҫ��ֻ�ܱ���һ������
	//pos = FindLastKNode(plist, 2);
	//if (pos != NULL)
	//{
	//	printf(" %d \n\n", pos->data);
	//}

	////ʮһ��ɾ����������K���ڵ�
	//PopLastKNode(&plist, 2);
	//PrintLinkList(plist);

	////ʮ�����ж������Ƿ���������������󻷳���
	//int CycleLength = 0;
	//Find(plist, 9)->next = Find(plist, 3);
	//pNode Entry = NULL;
	//pos = IsCycle(plist);
	//Entry = GetCycleEntryNode(plist, pos);
	//if (pos != NULL)
	//{
	//	printf(" ����������: %d \n\n", pos->data);
	//	printf("���ĳ���Ϊ��%d \n\n", CycleLength = GetCycleLength(pos));
	//	printf("������ڵ�Ϊ: %d \n\n", Entry->data);
	//}
	//else
	//{
	//	printf(" ������!\n\n");
	//}

	////ʮ�����ж����������Ƿ��ཻ����������,�󽻵�
	//Find(plist2, 6)->next = Find(plist1, 3);
	//PrintLinkList(plist1);
	//PrintLinkList(plist2);
	//pNode CrossNode = NULL;
	//CheckCross(plist1,plist2);
	//CrossNode = GetCrossNode(plist1, plist2);
	//if (CrossNode != NULL)
	//{
	//	printf("����������ཻ��: %d \n\n", CrossNode->data);
	//}

	//ʮ�ġ���������Ľ���
	UnionSet(plist1, plist2);

	////ʮ�塢��������ĸ���
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
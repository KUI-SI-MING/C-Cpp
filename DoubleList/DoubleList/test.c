#include "DoubleList.h"

void test()
{
	List head;
	LTDataType in = 0;
	LTDataType ine = 0;
	pListNode pos;

	ListInit(&head);
	///////////////////////////////////////////////////////////////////////
	//β��
	/*ListPushBack(&head, 1);
	ListPushBack(&head, 2);
	ListPushBack(&head, 3);
	ListPushBack(&head, 4);
	ListPushBack(&head, 5);
*/
	///////////////////////////////////////////////////////////////////////
	//ͷ��
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
		printf(" ˫������Ĵ�С��: %d \n\n", ListSize(&head));
		printf("���������ǣ�");
		ListPrint(&head);
	}
	else
	{
		printf("������\n\n");
	}
	///////////////////////////////////////////////////////////////////////
	//ͷɾ
	/*ListPopFront(&head);
	ListPopFront(&head);
	ListPopFront(&head);
*/
///////////////////////////////////////////////////////////////////////
//βɾ
	ListPopBack(&head);
	ListPopBack(&head);
	ListPopBack(&head);

	if(ListEmpty(&head) != 0)
	{
		printf(" �޸ĺ�˫������Ĵ�С��: %d \n\n", ListSize(&head));
		printf("���������ǣ�");
		ListPrint(&head);
	}
	else
	{
		printf("������\n\n");
	}
///////////////////////////////////////////////////////////////////////
//��ѯ
	printf("������Ҫ���ҵ����ݣ�");
	scanf("%d", &in);
	printf("\n\n");
	pos = ListFind(&head, in);
	if (pos == NULL)
	{
		printf("�޴�����\n\n");
	}
	else
	{
		printf("�������ǣ�%d \n\n", pos->d);
	}
///////////////////////////////////////////////////////////////////////
//����
	printf("������Ҫ��������ݣ�");
	scanf("%d", &ine);
	printf("\n\n");
	ListInsert(pos, ine);
	printf("����ɹ�\n\n");
	if (ListEmpty(&head) != 0)
	{
		printf(" �޸ĺ�˫������Ĵ�С��: %d \n\n", ListSize(&head));
		printf("���������ǣ�");
		ListPrint(&head);
	}
	else
	{
		printf("������\n\n");
	}
///////////////////////////////////////////////////////////////////////
//ɾ��
	ListErase(pos);
	if (ListEmpty(&head) != 0)
	{
		printf(" ɾ����˫������Ĵ�С��: %d \n\n", ListSize(&head));
		printf("���������ǣ�");
		ListPrint(&head);
	}
	else
	{
		printf("������\n\n");
	}

}

int main()
{

	test();
	system("pause");
	return 0;
}
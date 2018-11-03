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
	//����Ϊ��
	if (cur == NULL)
	{
		printf("  NULL  \n");
		printf("\n");
	}
	//����Ϊ��
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
	//����Ϊ��ʱ��������
}

void PushBack(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	pNode cur = *pplist;

	//������
	if (*pplist == NULL)
	{
		*pplist = BuyNode(d);
	}
	//�ǿ�����
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
		printf(" ������ \n");
		printf("\n");
	}
	else if (cur->next == NULL)
	{
		free(cur);
		cur = NULL;
		*pplist = NULL;
		printf("���ڵ�����,�ɹ�ɾ��β�ڵ㣡\n");
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
		printf("��ڵ������ɹ�ɾ��β�ڵ㣡\n");
		printf("\n");
	}
}

void PushFront(pList* pplist, DataType d)
{
	assert(pplist != NULL);
	pNode newNode = BuyNode(d);
	//*pplist newNode first
	newNode->next = *pplist;//�½ڵ�ָ���һ���ڵ�
	*pplist = newNode;//ͷָ���½ڵ�
}

void PopFront(pList* pplist)
{
	assert(pplist != NULL);
	pList del = *pplist;
	if (*pplist == NULL)
	{
		printf(" ������ \n");
		printf("\n");
	}
	else if (del->next == NULL)
	{
		free(del);
		del = NULL;
		*pplist = NULL;
		printf("���ڵ�����,�ɹ�ɾ��ͷ�ڵ㣡\n");
		printf("\n");
	}
	else
	{
		*pplist = del->next;
		free(del);
		del = NULL;
		printf("��ڵ������ɹ�ɾ��β�ڵ㣡\n");
		printf("\n");
	}
}

pNode Find(pList plist, DataType d)
{
	assert(plist != NULL);
	pList cur = plist;

	if (cur == NULL)//������
	{
		return NULL;
	}
	while ((cur->data != d) && (cur->next) != NULL)//δ�ҵ�d && ����δ����
	{
		cur = cur->next;
	}
	if (cur->data == d)//�ҵ�
	{
		return cur;
	}
	else//�Ҳ���
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

	//�� pos ������ʱ
	if (NULL == pos)
	{
		printf("Ҫ�����λ�ò����ڣ�����ʧ�ܣ�\n");
		printf("\n");
		return;
	}
	else
	{
		//��pos�ǵ�һ���ڵ�ʱ
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
	printf("����ɹ���\n");
	printf("\n");
}

void Erase(pList* pplist, pNode pos)
{
	assert(pplist != NULL);
	assert(*pplist != NULL);
	pList cur = *pplist;

	//�� pos ������ʱ
	if (NULL == pos)
	{
		printf("Ҫɾ����λ�ò����ڣ�ɾ��ʧ�ܣ�\n");
		printf("\n");
		return;
	}
	else
	{
		//��pos�ǵ�һ���ڵ�ʱ
		if (pos == *pplist)
		{
			PopFront(pplist);
		}
		else
		{
			//�滻ɾ����
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
		printf("ɾ���ɹ���\n");
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
			if (del == *pplist)//��d�ǵ�һ���ڵ�ʱ
			{
				PopFront(pplist);
			}
			else
			{
				pre->next = del->next;
				free(del);
				del = NULL;
			}
			printf("�޸ĳɹ���\n");
			printf("\n");
			return;
		}
		else
		{
			pre = del;
			del = del->next;
		}
	}
	printf("δ�ҵ���ֵ!\n");
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
			if (del == *pplist)//��d�ǵ�һ���ڵ�ʱ
			{
				PopFront(pplist);
				flag++;
			}
			else
			{
				pre->next = del->next;
				free(del);
				del = pre;//���´�ǰһ���ڵ㿪ʼ
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
		printf("δ�ҵ���ֵ!\n");
		printf("\n");
	}
	else
	{
		printf("�޸ĳɹ���\n");
		printf("\n");
	}
}

void EraseNotTailNode(pNode pos)
{
	assert((pos->next) != NULL);
	pNode del = NULL;

	if (pos == NULL)
	{
		printf("δ�ҵ��ýڵ㣡\n");
		printf("\n");
		return;
	}
	del = pos->next;
	pos->data = pos->next->data;
	pos->next = del->next;
	free(del);
	del = NULL;
	printf("�޸ĳɹ���\n");
	printf("\n");
}
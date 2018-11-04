#include "CListInterview.h"

pNode BuyNode(DataType d)
{
	pNode newNode = (pNode)malloc(sizeof(Node));
	newNode->data = d;
	newNode->next = NULL;

	return newNode;
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

void PrintTailToHeadPlist(pList plist)
{
	////�ݹ�汾
	//pList cur = plist;
	//if (cur == NULL)
	//{
	//	return;
	//}
	//PrintTailToHeadPlist(cur->next);
	//printf("-->%d ", cur->data);
	//�ǵݹ�汾
	pList cur = NULL;
	pList tail = NULL;

	//������
	if (plist == NULL)
	{
		printf("������!\n");
		printf("\n");
		return;
	}
	//���ڵ�����
	if (plist->next == NULL)
	{
		printf("-->%d", plist->data);
		printf("\n");
	}
	//��ڵ�����
	while (tail != plist)
	{
		cur = plist;
		while (cur->next != tail)
		{
			cur = cur->next;
		}
		tail = cur;
		printf("-->%d", cur->data);
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

void DelNodeNotTail(pNode pos)//�滻ɾ����
{
	pList del = pos;
	pos->data = pos->next->data;
	pos->next = pos->next->next;
	free(del->next);
	del = NULL;

}

void InsertNode(pNode pos, DataType d)
{
	////��
	//pNode newNode = NULL;
	//DataType tmp = 0;
	//newNode = BuyNode(d);


	//newNode->next = pos->next;
	//pos->next = newNode;

	//tmp = pos->data;
	//pos->data = newNode->data;
	//newNode->data = tmp;

	//��
	pNode newNode = NULL;

	newNode = BuyNode(pos->data);
	newNode->next = pos->next;
	pos->next = newNode;
	pos->data = d;

}

void JosephusCycle(pList* pplist, DataType number)
{
	assert(pplist != NULL);
	assert(*pplist != NULL);
	pNode tail = NULL;
	pList cur = NULL;
	pList kill = NULL;
	int count = 0;
	//���ڵ�����ֱ���ͷ�
	if ((*pplist)->next == NULL)
	{
		printf("���ܹ���Լɪ��\n");
		return;
	}
	cur = *pplist;
	while (cur->next != NULL)
	{
		cur = cur->next;//�ҵ�β�ڵ�
	}
	tail = cur;
	tail->next = *pplist;//���ɻ�
	cur = *pplist;
	printf("���˳���ǣ�");
	while (cur != cur->next)
	{
		count = number;
		while (--count)
		{
			cur = cur->next;
		}
		printf("%d-->", cur->data);
		kill = cur->next;
		cur->data = cur->next->data;
		cur->next = cur->next->next;
		free(kill);
		kill = NULL;
	}
	printf("%d\n\n", cur->data);
	printf("���һ��Ԫ����: %d \n\n", cur->data);
}

void ReverseList(pList* pplist)
{
	assert(pplist != NULL);
	////����ָ�뷨
	//pNode pos1 = NULL;
	//pNode pos2 = NULL;
	//pNode pos3 = NULL;

	//if (*pplist == NULL)
	//{
	//	printf("������\n\n");
	//	return;
	//}
	//else if ((*pplist)->next == NULL)
	//{
	//	return;
	//}
	//else
	//{
	//	pos1 = *pplist;
	//	pos2 = pos1->next;
	//	pos3 = pos2->next;
	//	while (pos2)
	//	{
	//		pos2->next = pos1;
	//		pos1 = pos2;
	//		pos2 = pos3;
	//		if (pos3 != NULL)
	//		{
	//			pos3 = pos3->next;
	//		}
	//	}
	//	(*pplist)->next = NULL;//�׽ڵ��ÿ�
	//	*pplist = pos1;
	//}
	//��ͷ�巨
	pList cur = NULL;
	pList tmp = NULL;
	pNode head = NULL;
	cur = *pplist;
	tmp = cur->next;
	while (cur != NULL)
	{
		cur->next = head;
		head = cur;
		cur = tmp;
		if (tmp != NULL)
		{
			tmp = tmp->next;
		}
		*pplist = head;
	}
}

void BubbleSort(pList plist)
{
	pNode cur = NULL;
	pNode next = NULL;
	pNode tail = NULL;
	DataType tmp = 0;
	//ָ��ð������
	if ((plist == NULL) || ((plist->next) == NULL))
	{
		return;
	}
	else
	{
		while (plist != tail)
		{
			cur = plist;
			next = cur->next;
			while (next != tail)
			{
				if ((cur->data == next->data) || (cur->data < next->data))
				{
					cur = next;
					next = cur->next;
				}
				else if (cur->data > next->data)
				{
					tmp = cur->data;
					cur->data = next->data;
					next->data = tmp;
					cur = next;
					next = cur->next;
				}
			}
			tail = cur;

		}
	}
}
pList Merge(pList plist1, pList plist2)
{
	pList newlist = NULL;
	pNode tail = NULL;
	if (plist1 == plist2)
	{
		return plist1;
	}
	else if (plist1 == NULL)
	{
		return plist2;
	}
	else if (plist2 == NULL)
	{
		return plist1;
	}
	else
	{
		if (plist1->data < plist2->data)
		{
			newlist = plist1;
			plist1 = plist1->next;
		}
		else
		{
			newlist = plist2;
			plist2 = plist2->next;
		}
		//�����������ҽ�Сֵβ��
		tail = newlist;
		while ((plist1 != NULL) && (plist2 != NULL))
		{
			if (plist1->data < plist2->data)
			{
				tail->next = plist1;
				plist1 = plist1->next;
			}
			else
			{
				tail->next = plist2;
				plist2 = plist2->next;
			}
			tail = tail->next;
			//׷��ʣ�ಿ��
			if (plist1 == NULL)
			{
				tail->next = plist2;
			}
			else
			{
				tail->next = plist1;
			}
		}
	}
	return newlist;
}

pList Merge_R(pList plist1, pList plist2)
{
	pList newlist = NULL;
	pNode tail = NULL;
	if (plist1 == plist2)
	{
		return plist1;
	}
	else if (plist1 == NULL)
	{
		return plist2;
	}
	else if (plist2 == NULL)
	{
		return plist1;
	}
	else
	{
		if (plist1->data < plist2->data)
		{
			newlist = plist1;
			newlist->next = Merge_R(plist1->next, plist2);
		}
		else
		{
			newlist = plist2;
			newlist->next = Merge_R(plist1, plist2->next);
		}
	}
		
	return newlist;
}

pNode FindMidNode(pList plist)
{
	pNode fast = plist;
	pNode slow = plist;

	if ((plist == NULL) || (plist->next == NULL))
	{
		return plist;
	}
	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}

pNode FindLastKNode(pList plist, int k)
{
	pNode fast = NULL;
	pNode slow = NULL;
	if (plist == NULL);
	fast = plist;
	slow = plist;
	//��һ��ָ������k��
	while (k--)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		fast = fast->next;
	}
	//����һ����
	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

void PopLastKNode(pList* pplist, int k)
{
	assert(pplist != NULL);
	pNode del = NULL;

	del = FindLastKNode(*pplist, k);
	del->data = del->next->data;
	del->next = del->next->next;
	free(del->next);
	del = NULL;
}

pNode IsCycle(pList plist)
{
	assert(plist != NULL);
	pNode fast = NULL;
	pNode slow = NULL;

	fast = plist;
	slow = plist;
	while ((fast != NULL) && (fast->next != NULL))
	{
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast)
		{
			return slow;
		}
	}
	return NULL;
}

int GetCycleLength(pList meet)
{
	int Length = 1;
	pNode cur = NULL;

	assert(meet != NULL);
	cur = meet;
	while (cur->next != meet)
	{
		Length++;
		cur = cur->next;
	}
	return Length;
}

pNode GetCycleEntryNode(pList plist, pList meet)
{
	pNode cur = plist;
	assert(meet != NULL);
	if (plist == NULL)
	{
		return NULL;
	}
	while (cur != meet)
	{
		cur = cur->next;
		meet = meet->next;
	}
	return cur;
}

void CheckCross(pList plist1, pList plist2)
{
	assert(plist1 != NULL);
	assert(plist2 != NULL);

	while (plist1 != NULL)
	{
		plist1 = plist1->next;
	}
	while (plist2 != NULL)
	{
		plist2 = plist2->next;
	}
	if (plist1 == plist2)
	{
		printf("���������ཻ��\n\n");
	}
	else
	{
		printf("���������ཻ��\n\n");
	}
}

pNode GetCrossNode(pList plist1, pList plist2)
{
	pList cur1 = NULL;
	pList cur2 = NULL;
	int len1 = 0;
	int len2 = 0;
	int gap = 0;
	cur1 = plist1;
	cur2 = plist2;
	while(cur1 != NULL)
	{
		len1++;
		cur1 = cur1->next;
	}
	while (cur2 != NULL)
	{
		len2++;
		cur2 = cur2->next;
	}
	gap = abs(len1-len2);
	cur1 = plist1;
	cur2 = plist2;
	if (len1 < len2)
	{
		cur1 = plist2;
		cur2 = plist1;
	}
	while (gap--)
	{
		cur1 = cur1->next;
	}
	while (cur1 != cur2)
	{
		cur1 = cur1->next;
		cur2 = cur2->next;
	}
	return cur1;

}

void UnionSet(pList plist1, pList plist2)
{
	if ((plist1 == NULL) || (plist2 == NULL))
	{
		printf("�޽�����\n\n");
		return;
	}
	//printf("����Ϊ:");
	printf("�Ϊ��");
	while (plist1 && plist2)
	{
		if (plist1->data < plist2->data)
		{
			//�
			printf(" %d ", plist1->data);
			plist1 = plist1->next;
		}
		else if (plist1->data > plist2->data)
		{
			//�
			printf(" %d ", plist2->data);
			plist2 = plist2->next;
		}
		else
		{
			//����
			//printf(" %d ", plist1->data);
			plist1 = plist1->next;
			plist2 = plist2->next;
		}
	}
	//�
	if (plist2 != NULL)
	{
		plist1 = plist2;
	}
	while (plist1)
	{
		printf(" %d ", plist1->data);
		plist1 = plist1->next;
	}
	printf("\n\n");
}

void printComplexList(ComplexNode* plist)
{
	ComplexNode* cur = plist;
	while (cur)
	{
		printf(" %d : ", cur->data);
		if (cur->random != NULL)
			printf(" (%d)--> ", cur->random->data);
		else
			printf("(NULL)-->");
		cur = cur->next;
	}
	printf("over\n\n");
}

ComplexNode* CopyComplexList(ComplexNode* plist)
{
	ComplexNode* cur = plist;
	ComplexNode* next = plist->next;
	//�ڵ�ǰ�ڵ�ĺ�߲���һ����ǰ�ڵ������
	while (cur)
	{
		ComplexNode* newnode = BuyComplexNode(cur->data);
		newnode->next = next;
		cur->next = newnode;
		cur = next;
		if (cur != NULL)
			next = cur->next;
	}
	//��������ڵ��randomָ��
	cur = plist;
	ComplexNode* cp = cur->next;
	while (cur != NULL)
	{
		if (cur->random != NULL)
		    cp->random = cur->random->next;
		cur = cp->next;
		if (cur != NULL)
		    cp = cur->next;ork
	}
	//�������
	ComplexNode* newlist = NULL;
	cur = plist;
	cp = cur->next;
	newlist = cp;
	while (cur)
	{
		cur->next = cp->next;
		if (cur->next != NULL)
			cp->next = cur->next->next;
		cur = cur->next;
		cp = cp->next;
	}
	return newlist;
}
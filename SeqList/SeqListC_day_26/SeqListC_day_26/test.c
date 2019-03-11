#include "SeqList.h"

//��ʼ��
void InitSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);
	pSeq->sz = 0;
	memset(pSeq->data, 0, sizeof(pSeq->data));
}

void PushBack(pSeqList pSeq, DataType d)
{
	assert(pSeq != NULL);
	//�Ƿ����
	if (pSeq->sz == MAX)
	{
		printf("˳����������޷����룡\n");
		return;
	}
	//��
	pSeq->data[pSeq->sz] = d;
	pSeq->sz++;
}

void PrintSeqList(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ�գ�\n");
		return;
	}
	for (i = 0; i < pSeq->sz; i++)
	{
		printf(" %d ", pSeq->data[i]);
	}
	printf("\n");
}

void PopBack(pSeqList pSeq)
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("˳���Ϊ�գ��޷�ɾ����\n");
		return;
	}
	pSeq->sz--;
}

void PushFront(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == MAX)
	{
		printf("˳����������޷�����\n");
		return;
	}
	for (i = pSeq->sz - 1; i >= 0; i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[0] = d;
	pSeq->sz++;
}

void PopFront(pSeqList pSeq)
{
	int i = 0;
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("˳����ѿգ��޷�ɾ����\n");
		return;
	}
	for (i = 0; i < pSeq->sz-1; i++)//ע���ұ߽�
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

int Find(pSeqList pSeq, DataType d)
{
	int i = 0;
	assert(pSeq != NULL);
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			return i;
		}
	}
	return -1;
}
void Insert(pSeqList pSeq, int pos, DataType d)
{
	int i = 0;
	assert(pSeq != NULL);
	assert(pos >=0 && pos <=pSeq->sz);

	if (pSeq->sz == MAX)
	{
		printf("˳����������޷����룡\n");
		return;
	}
	for (i = pSeq->sz - 1; i >= pos;i--)
	{
		pSeq->data[i + 1] = pSeq->data[i];
	}
	pSeq->data[pos] = d;
	pSeq->sz++;
}

void Erase(pSeqList pSeq, int pos)
{
	int i = 0;
	assert(pSeq != NULL);
	assert(pos >= 0 && pos <= pSeq->sz);

	if (pSeq->sz == 0)
	{
		printf("˳����ѿգ��޷�ɾ����\n");
		return;
	}
	for (i = pos; i < pSeq->sz-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

void Remove(pSeqList pSeq, DataType d)
{
	int i = 0;
	int pos = 0;
	assert(pSeq != NULL);

	if (pSeq->sz == 0)
	{
		printf("˳����ѿգ��޷�ɾ����\n");
		return;
	}

#if 0
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			break;
		}
	}
	if (i == pSeq->sz)
	{
		printf("ɾ����Ԫ�ز����ڣ�\n");
		return;
	}
	for (; i < pSeq->sz-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
#endif
	if (pos = (Find(pSeq, d) != -1))
	{
		Erase(pSeq, pos);

	}
}

void RemoveAll(pSeqList pSeq, DataType d)
{
	int i = 0;
	int j = 0;
	
	assert(pSeq != NULL);

	if (pSeq->sz == 0)
	{
		printf("˳����ѿգ��޷�ɾ����\n");
		return;
	}
#if 0
	int pos = 0;
	while ((pos = Find(pSeq, d)) != -1)
	{
		Erase(pSeq, pos);
	}
#endif
#if 0
	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] == d)
		{
			for (j = i; j < pSeq->sz-1; j++)
			{
				pSeq->data[j] = pSeq->data[j + 1];
			}
			pSeq->sz--;
			--i;//��� 1 1 1 1 4 5 �����ֻҪŲһ�¾Ͱ�ǰһλ���ж�һ��
		}
	}
#endif
#if 0
	DataType *tmp = (DataType *)malloc(sizeof(DataType) * pSeq->sz);

	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] != d)
		{
			tmp[j++] = pSeq->data[i];//j����ɾ��֮���Ԫ�ظ���
		}
	}
	memcpy(pSeq->data, tmp, j*sizeof(DataType));
	pSeq->sz = j;
	free(tmp);
	tmp = NULL;
#endif

	for (i = 0; i < pSeq->sz; i++)
	{
		if (pSeq->data[i] != d)
		{
			pSeq->data[j++] = pSeq->data[i];
		}
	}
	pSeq->sz = j;
}

int Size(pSeqList pSeq)
{
	assert(pSeq != NULL);
	return pSeq->sz;
}

int Empty(pSeqList pSeq)
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		return 0;
	}
	return 1;
}

void swap(DataType* p1, DataType* p2)
{
	DataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void BubbleSort(pSeqList pSeq)
{
	assert(pSeq != NULL);
	int i = 0;
	int j = 0;
	int flag = 0;
	for (i = 0; i < pSeq->sz-1; i++)
	{
		flag = 0;
		for (j = 0; j < pSeq->sz-1-i; j++)
		{
			if (pSeq->data[j] > pSeq->data[j + 1])
			{
				swap(pSeq->data + j, pSeq->data + j + 1);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return;
		}
	}
}

void SelectSort(pSeqList pSeq)
{
	int i = 0;
	int j = 0;
	assert(pSeq != NULL);

	for (i = 0; i < pSeq->sz; i++)
	{
		int max = 0;
		for (j = 1; j < pSeq->sz-i; j++)
		{
			if (pSeq->data[max] < pSeq->data[j])
			{
				max = j;
			}
		}
		if (max != pSeq->sz - 1 - i)
		{
			swap(pSeq->data + max, pSeq->data + pSeq->sz - 1 - i);
		}
	}
}

void SelectSortOP(pSeqList pSeq)
{
	assert(pSeq != NULL);
	int i = 0;
	int max = 0;
	int min = 0;
	int start = 0;
	int end = pSeq->sz - 1;
	while (start < end)
	{
		max = start;
		min = start;
		for (i = start; i <= end; i++)
		{
			if (pSeq->data[i] > pSeq->data[max])
			{
				max = i;
			}
			if (pSeq->data[i] < pSeq->data[min])
			{
				min = i;
			}
		}
		if (min != start)//��Сֵ������ǰ��ʱ���н���
		{
			swap(pSeq->data + start, pSeq->data + min);
		}
		if (max == start)//�����ֵ����ǰ��ʱ��ִ�����Ͼ��������ֵ�Ѿ�������min ��λ����
		{
			max = min;
		}
		if (max != end)
		{
			swap(pSeq->data + max, pSeq->data + end);
		}
		start++;
		end--;
	}
}

int BinarySearch(pSeqList pSeq, DataType d)
{
	assert(pSeq != NULL);
	int left = 0;
	int right = pSeq->sz - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (pSeq->data[mid] > d)
		{
			right = mid - 1;
		}
		else if (pSeq->data[mid] < d)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int BinarySearch_R(pSeqList pSeq, int left, int right, DataType d)
{
	assert(pSeq != NULL);
	int mid = 0;
	if (left > right)
	{
		return -1;
	}
	mid = left + (right - left) / 2;
	if (pSeq->data[mid] > d)
		return BinarySearch_R(pSeq, left, mid - 1, d);
	else if (pSeq->data[mid] < d)
		return BinarySearch_R(pSeq, mid + 1, right, d);
	else
		return mid;
}
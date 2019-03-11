#include "SeqList.h"

void InitSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);
	pSeq->data = malloc(DEFAULT_SZ * sizeof(DataType));
	if (pSeq->data == NULL)
	{
		perror("use malloc");
		exit(EXIT_FAILURE);
	}
	pSeq->capacity = DEFAULT_SZ;
	pSeq->sz = 0;
}

void CheckCapacity(pSeqList pSeq)
{
	assert(pSeq != NULL);
	if (pSeq->sz == pSeq->capacity)
	{
		DataType* tmp = (DataType*)realloc(pSeq->data, (pSeq->capacity + 2)*sizeof(DataType));
		if (tmp != NULL)
		{
			pSeq->data = tmp;
		}
		pSeq->capacity += 2;
		printf("增容成功！\n");
	}
}

void PushBack(pSeqList pSeq, DataType d)
{
	assert(pSeq != NULL);
	CheckCapacity(pSeq);
	pSeq->data[pSeq->sz] = d;
	pSeq->sz++;
}

int Empty(pSeqList pSeq)
{
	return pSeq->sz == 0;
}

void PopBack(pSeqList pSeq)
{
	assert(pSeq != NULL);
	if (Empty(pSeq))
	{
		printf("顺序表为空！\n");
	}
	pSeq->sz--;
}

void PrintSeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);
	int i = 0;
	for (i = 0; i < pSeq->sz; i++)
	{
		printf(" %d ",pSeq->data[i]);
	}
	printf("\n");
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
	assert(pos >= 0);

	if (pSeq->sz == pSeq->capacity)
	{
		CheckCapacity(pSeq);
	}
	for (i = pSeq->sz - 1; i >= pos; i--)
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
		printf("顺序表已空！无法删除！\n");
		return;
	}
	for (i = pos; i < pSeq->sz-1; i++)
	{
		pSeq->data[i] = pSeq->data[i + 1];
	}
	pSeq->sz--;
}

void Capacity(pSeqList pSeq)
{
	assert(pSeq != NULL);
	if (pSeq->capacity == 0)
	{
		printf("动态顺序表无容量！\n");
	}
	else
	{
		printf("动态顺序表的容量为: %d \n",pSeq->capacity);
	}
}

void Size(pSeqList pSeq)
{
	assert(pSeq != NULL);
	if (pSeq->sz == 0)
	{
		printf("动态顺序无元素！\n");
	}
	else
	{
		printf("动态顺序表的元素个数为: %d \n", pSeq->sz);
	}
}
void DestorySeqList(pSeqList pSeq)
{
	assert(pSeq != NULL);
	free(pSeq->data);
	pSeq->data = NULL;
	pSeq->capacity = 0;
	pSeq->sz = 0;
}




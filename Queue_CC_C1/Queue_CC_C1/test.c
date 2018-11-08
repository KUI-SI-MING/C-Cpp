#include "Queue.h"

void QueueInit(pQueue pq)
{
	assert(pq);
	pq->front = NULL;
	pq->back = NULL;
}

void QueueDestory(pQueue pq)
{
	assert(pq);
	QueueNode* tmp = NULL;

	tmp = pq->front;
	while (tmp)
	{
		pq->front = tmp;
		tmp = tmp->next;
		free(pq->front);
		pq->front = NULL;
	}
}


QueueNode* BuyQueueNode(DataType x)
{
	QueueNode* newNode = NULL;
	newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void QueuePush(pQueue pq, DataType x)
{
	assert(pq);

	QueueNode* newNode = BuyQueueNode(x);
	assert(newNode);

	if (pq->front == NULL)//╤сапн╙©у
	{
		pq->back = pq->front = newNode;
	}
	else
	{
		pq->back->next = newNode;
		pq->back = newNode;
	}

}
void QueuePop(pQueue pq)
{
	assert(pq && pq->front);

	QueueNode* del = NULL;

	del = pq->front;
	pq->front = pq->front->next;
	free(del);
	del = NULL;
}

DataType QueueFront(pQueue  pq)
{
	assert(pq && pq->front);

	return pq->front->data;
}

int QueueEmpty(pQueue pq)
{
	assert(pq);

	return (pq->front == NULL) ? 0 : 1;

}

int QueueSize(pQueue pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = NULL;
	cur = pq->front;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}
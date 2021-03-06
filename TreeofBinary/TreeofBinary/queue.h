#ifndef _QUEUE_H__
#define _QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct BinaryTreeNode* DataType;//类型的定义

typedef struct QueueNode
{
	struct QueueNode* next;
	DataType data;
}QueueNode;

typedef struct Queue
{
	QueueNode* front; // 队头
	QueueNode* back;  // 队尾
}Queue, *pQueue;

void QueueInit(pQueue pq);
void QueueDestory(pQueue pq);

QueueNode* BuyQueueNode(DataType x);
void QueuePush(pQueue pq, DataType x);
void QueuePop(pQueue pq);
DataType QueueFront(pQueue  pq);
int QueueEmpty(pQueue pq);
int QueueSize(pQueue pq);

#endif // _QUEUE_H__
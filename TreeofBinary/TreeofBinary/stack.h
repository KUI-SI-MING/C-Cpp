#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

////��̬ջ
//typedef int Datatype;
//
//#define N 10
//typedef struct Stack
//{
//	Datatype a[N];
//	int top;//ջ��
//}Stack;

//��̬ջ
typedef struct BinaryTreeNode* Datatype;

typedef struct Stack
{
	Datatype* a;
	int top;//ջ��
	int capacity;//����
}Stack, *pStack;

void StackInit(pStack ps);
void DestoryStack(pStack ps);

void StackPush(pStack ps, Datatype x);
Datatype StackTop(pStack ps);
int StackEmpty(pStack ps);
void StackPop(pStack ps);
int StackSize(pStack ps);
#endif // __STACK_H__
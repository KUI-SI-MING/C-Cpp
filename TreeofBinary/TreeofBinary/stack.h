#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

////¾²Ì¬Õ»
//typedef int Datatype;
//
//#define N 10
//typedef struct Stack
//{
//	Datatype a[N];
//	int top;//Õ»¶¥
//}Stack;

//¶¯Ì¬Õ»
typedef struct BinaryTreeNode* Datatype;

typedef struct Stack
{
	Datatype* a;
	int top;//Õ»¶¥
	int capacity;//ÈÝÁ¿
}Stack, *pStack;

void StackInit(pStack ps);
void DestoryStack(pStack ps);

void StackPush(pStack ps, Datatype x);
Datatype StackTop(pStack ps);
int StackEmpty(pStack ps);
void StackPop(pStack ps);
int StackSize(pStack ps);
#endif // __STACK_H__
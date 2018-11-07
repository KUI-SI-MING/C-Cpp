#pragma once

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>


//
//typedef int DataType;
//
//#define N 10
//typedef struct Stack
//{
//	DataType _a[N];
//	int _top; // ջ��
//}Stack;//��̬ջ

typedef struct Pos
{
	int _row;
	int _col;
}Pos;//�Թ�λ�õ�

typedef Pos DataType;

typedef struct Stack
{
	DataType* _a;	//�ڵ�ָ��
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;

void StackInit(Stack* ps);//��ʼ��
void StackDestory(Stack* ps);//����

void StackPush(Stack* ps, DataType x);//ѹջ
void StackPop(Stack* ps);//��ջ
DataType StackTop(Stack* ps);//ȡջ��Ԫ��
int StackEmpty(Stack* ps);//�п�
int StackSize(Stack* ps);//ջ�Ĵ�С

//void TestStack();
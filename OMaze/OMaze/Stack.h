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
//	int _top; // 栈顶
//}Stack;//静态栈

typedef struct Pos
{
	int _row;
	int _col;
}Pos;//迷宫位置点

typedef Pos DataType;

typedef struct Stack
{
	DataType* _a;	//节点指针
	int _top;		// 栈顶
	int _capacity;  // 容量 
}Stack;

void StackInit(Stack* ps);//初始化
void StackDestory(Stack* ps);//销毁

void StackPush(Stack* ps, DataType x);//压栈
void StackPop(Stack* ps);//出栈
DataType StackTop(Stack* ps);//取栈顶元素
int StackEmpty(Stack* ps);//判空
int StackSize(Stack* ps);//栈的大小

//void TestStack();
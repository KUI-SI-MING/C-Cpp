#include "Stack.h"

void StackInit(Stack* ps)
{
	ps->_a = (DataType*)malloc(sizeof(DataType)* 3);//动态开辟空间
	assert(ps);//防止开辟失败
	ps->_capacity = 3;
	ps->_top = 0;
}
void StackDestory(Stack* ps)
{
	assert(ps);//断言

	if (ps->_a)
	{
		free(ps->_a);
		ps->_a = NULL;
		ps->_capacity = ps->_top = 0;
	}
	while (ps->_top--)
	{
		free(ps->_top);//???????
	}
	ps->_capacity = 0;
}

void StackPush(Stack* ps, DataType x)
{
	assert(ps);

	if (ps->_top == ps->_capacity)//越界
	{
		ps->_a = (DataType*)realloc(ps->_a, sizeof(DataType)*(ps->_capacity * 2));//增容
		assert(ps->_a);

		ps->_capacity *= 2;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps->_a);
	assert(ps->_top > 0);

	ps->_top--;
}
DataType StackTop(Stack* ps)
{
	assert(ps->_a && ps->_top > 0);
	return ps->_a[ps->_top - 1];
}
//空 0
//非空 1
int StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->_top == 0 ? 0 : 1;
}
int StackSize(Stack* ps)
{
	assert(ps);

	return ps->_top;
}

//测试代码
//void TestStack()
//{
//	Stack s;
//	StackInit(&s);
//
//	StackPush(&s, 1);
//	StackPush(&s, 2);
//	StackPush(&s, 3);
//	StackPush(&s, 4);
//
//	while (StackEmpty(&s))
//	{
//		printf("%d ",StackTop(&s));
//		StackPop(&s);
//	}
//	printf("\n");
//
//
//	StackDestory(&s);
//}

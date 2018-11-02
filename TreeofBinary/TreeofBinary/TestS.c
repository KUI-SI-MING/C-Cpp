#include "Stack.h"

void StackInit(pStack ps)
{
	ps->a = (Datatype*)malloc(sizeof(Stack)* 3);
	assert(ps);
	ps->capacity = 3;
	ps->top = 0;
}

void DestoryStack(pStack ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->top = -1;
}

void StackPush(pStack ps, Datatype x)
{
	assert(ps);

	if (ps->capacity == ps->top)
	{
		ps->a = (Datatype*)realloc(ps->a, sizeof(Stack)* 2);
		assert(ps->a);
		ps->capacity += 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

Datatype StackTop(pStack ps)
{
	assert(ps);
	if (ps->top == 0)
	{
		printf("¿ÕÕ»\n\n");
		return 0;
	}
	return ps->a[ps->top - 1];
}

int StackEmpty(pStack ps)
{
	return (ps->top == 0) ? 0 : 1;
}

void StackPop(pStack ps)
{
	assert(ps);
	ps->top--;
}

int StackSize(pStack ps)
{
	assert(ps);
	return ps->top;
}
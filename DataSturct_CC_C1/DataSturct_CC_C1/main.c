#include "Stack.h"

void test()
{
	Stack s;
	
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);

	printf("栈容量是: %d \n\n", StackSize(&s));
	while(StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n\n");
	printf("栈容量是: %d \n\n", StackSize(&s));
	  
	DestoryStack(&s);
}

int main()
{
	test();
	system("pause");
	return 0;
}
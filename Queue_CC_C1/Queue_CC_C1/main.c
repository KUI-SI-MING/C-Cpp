#include "Queue.h"

void test()
{
	Queue q;

	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	printf("����������: %d \n\n", QueueSize(&q));
	while (QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n\n");
	printf("ջ������: %d \n\n", QueueSize(&q));

	QueueDestory(&q);
}

int main()
{
	test();
	system("pause");
	return 0;
}
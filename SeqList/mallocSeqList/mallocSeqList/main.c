#include "SeqList.h"

void test()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PushBack(&seq, 5);
	PushBack(&seq, 6);
	PrintSeqList(&seq);

	PopBack(&seq);
	PrintSeqList(&seq);
	//
	if ((pos = Find(&seq, 2)) != -1)
	{
		Insert(&seq, pos, 8);
		Insert(&seq, pos, 8);
	}
	PrintSeqList(&seq);

	if ((pos = Find(&seq, 5)) != -1)
	{
		Erase(&seq, pos);
	}
	else
	{
		printf("找不到该元素！\n");
	}
	PrintSeqList(&seq);

	Capacity(&seq);
	Size(&seq);
	DestorySeqList(&seq);
}
int main()
{
	test();
	system("pause");
	return 0;
}
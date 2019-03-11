#include "SeqList.h"

//尾插
void TestPushBack()
{
	SeqList seq;
	InitSeqList(&seq);
	PushBack(&seq, 1);
	PushBack(&seq, 2);
	PushBack(&seq, 3);
	PushBack(&seq, 4);
	PrintSeqList(&seq);
	PopBack(&seq);
	PrintSeqList(&seq);
}

//头插
void TestPushFront()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
}

void TestFind()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	PopFront(&seq);
	PrintSeqList(&seq);
	pos = Find(&seq, 3);
	if (-1 == pos)
	{
		printf("找不到！\n");
	}
	else
	{
		printf("找到了！下标是：%d \n", pos);
	}
}

void TestInsert()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	pos = Find(&seq, 3);
	if (pos != -1)
	{
		Insert(&seq, pos, 5);
	}
	PrintSeqList(&seq);
}

void TestErase()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PrintSeqList(&seq);
	pos = Find(&seq, 3);
	if (pos != -1)
	{
		Erase(&seq, pos);
	}
	PrintSeqList(&seq);
}

void TestRemove()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PrintSeqList(&seq);
	Remove(&seq, 3);
	PrintSeqList(&seq);
}

void TestRemoveAll()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	PrintSeqList(&seq);
	if (Empty(&seq))
	{
		printf("顺序表大小为：%d \n", Size(&seq));
	}
	else
	{
		printf("顺序表为空！\n");
	}
	RemoveAll(&seq, 3);
	PrintSeqList(&seq);
}

void TestBubbleSort()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	printf("原顺序表为：");
	PrintSeqList(&seq);
	BubbleSort(&seq);
	printf("排序后顺序表为：");
	PrintSeqList(&seq);
}
void TestSelectSort()
{
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 4);
	PushFront(&seq, 2);
	PushFront(&seq, 3);
	PushFront(&seq, 1);
	printf("原顺序表为：");
	PrintSeqList(&seq);
	SelectSort(&seq);
	printf("排序后顺序表为：");
	PrintSeqList(&seq);
	printf("原顺序表为：");
	PrintSeqList(&seq);
	SelectSortOP(&seq);
	printf("优化后排序后顺序表为：");
	PrintSeqList(&seq);
}

void TestBinarySearch()
{
	int pos = 0;
	SeqList seq;
	InitSeqList(&seq);
	PushFront(&seq, 1);
	PushFront(&seq, 2);
	PushFront(&seq, 7);
	PushFront(&seq, 4);
	PushFront(&seq, 5);
	PushFront(&seq, 6);
	PushFront(&seq, 3);
	SelectSortOP(&seq);
	PrintSeqList(&seq);
	if ((pos = BinarySearch(&seq, 3)) != -1)
	{
		printf("下标是： %d \n",pos);
	}
	else
	{
		printf("找不到！\n");
	}
	if ((pos = BinarySearch_R(&seq, 0, seq.sz-1, 3)) != -1)
	{
		printf("下标是： %d \n", pos);
	}
	else
	{
		printf("找不到！\n");
	}

}
int main()
{
	//TestPushBack();
	//TestPushFront();
	//TestFind();
	//TestInsert();
	//TestErase();
	//TestRemove();
	//TestRemoveAll();
	//TestBubbleSort();
	//TestSelectSort();
	TestBinarySearch();
	system("pause");
	return 0;
}
#include "BinaryTree.h"

void TestBinaryTree()
{
	char array[] = { 'A', 'B', 'D', '#', '#', '#', 'C',
		'E', '#', '#', 'F', '#', '#' };
	size_t i = 0;
	BTDataType input = 0;
	int com = 0;
	pBTNode pos = NULL;

	pBTNode tree = BinaryTreeCreate(array, sizeof(array) / sizeof(BTDataType), &i);

	if (BinaryTreeSize(tree) != 0)
	{
		printf("该二叉树的大小是：%d \n\n", BinaryTreeSize(tree));
		printf("该二叉树的叶子节点的大小是: %d \n\n", BinaryTreeLeafSize(tree));
		printf("该二叉树的前序是：\n");
		BinaryTreePrevOrder(tree);//递归
		printf("\n\n");
		BinaryTreePrevOrderNonR(tree);//非递归
		printf("\n\n");
		printf("该二叉树的中序是：\n");
		BinaryTreeInOrderNonR(tree);//非递归
		printf("\n\n");
		BinaryTreeInOrder(tree);//递归
		printf("\n\n");
		printf("该二叉树的后序是:\n");
		BinaryTreePostOrder(tree);//递归
		printf("\n\n");
		BinaryTreePostOrderNonR(tree);//非递归
		printf("\n\n");
		printf("该二叉树的层序是:");
		BinaryTreeLevelOrder(tree);
		printf("\n\n");

	}
	com = BinaryTreeComplete(tree);
	if (com == 0)
	{
		printf("该二叉树是完全二叉树\n\n");
	}
	else
	{
		printf("该二叉树不是完全二叉树\n\n");
	}
	printf("请输入查找的数据: ");
	scanf("%c", &input);
	printf("\n\n");
	pos = BinaryTreeFind(tree, input);
	if (pos != NULL)
	{
		printf("查询成功，该数据是：%c \n\n", pos->data);
	}
	else
	{
		printf("无此数据！\n\n");
	}
	BinaryTreeDestory(tree);
}


/////////////////////////////////////////////////////////////////////////
void TestHeap()
{
	HPDataType arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;

	HeapInit(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	HeapPrint(hp);

	HeapPush(&hp, 11);
	HeapPrint(hp);

	HeapPush(&hp, 22);
	HeapPrint(hp);

	HeapPush(&hp, 33);
	HeapPrint(hp);

	HeapPush(&hp, 44);
	HeapPrint(hp);

	HeapPush(&hp, 100);
	HeapPrint(hp);

	HeapPop(&hp);
	HeapPrint(hp);

	if (HeapEmpty(&hp))
	{
		printf("堆顶: %d \n\n", HeapTop(&hp));
		printf("堆大小：%d \n\n", HeapSize(&hp));
	}


	HeapDestory(&hp);
}
//////////////////////////////////////////////////////////////
//堆排序
void TestHeapSort()
{
	//创建大堆
	HPDataType arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;

	int i = 0;
	int flag = 0;
	int n = sizeof(arr) / sizeof(arr[0]);
	hp.a = (HPDataType*)malloc(sizeof(HPDataType)* n);//给堆开辟与数组相同个数的空间
	hp.capacity = n;
	hp.size = n - 1;

	for (i = 0; i < n; i++)
	{
		hp.a[i] = arr[i];
	}
	for (i = ((n - 2) / 2); i >= 0; --i)
	{
		AdjustDown(hp.a, hp.size + 1, i);
	}
	printf("源堆: ");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", hp.a[i]);
	}
	printf("\n\n");
	//排序
	flag = HeapSort(hp.a, n);

	if (flag != 0)
	{
		printf("升序成功!\n\n");
		for (i = 0; i < n; i++)
		{
			printf(" %d ", hp.a[i]);
		}
		printf("\n\n");
	}
	else
	{
		printf("升序失败!\n\n");
	}
}

int main()
{
	//TestBinaryTree();
	//TestHeap();
	TestHeapSort();
	system("pause");
	return 0;
}
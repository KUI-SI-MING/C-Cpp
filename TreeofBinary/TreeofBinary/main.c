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
		printf("�ö������Ĵ�С�ǣ�%d \n\n", BinaryTreeSize(tree));
		printf("�ö�������Ҷ�ӽڵ�Ĵ�С��: %d \n\n", BinaryTreeLeafSize(tree));
		printf("�ö�������ǰ���ǣ�\n");
		BinaryTreePrevOrder(tree);//�ݹ�
		printf("\n\n");
		BinaryTreePrevOrderNonR(tree);//�ǵݹ�
		printf("\n\n");
		printf("�ö������������ǣ�\n");
		BinaryTreeInOrderNonR(tree);//�ǵݹ�
		printf("\n\n");
		BinaryTreeInOrder(tree);//�ݹ�
		printf("\n\n");
		printf("�ö������ĺ�����:\n");
		BinaryTreePostOrder(tree);//�ݹ�
		printf("\n\n");
		BinaryTreePostOrderNonR(tree);//�ǵݹ�
		printf("\n\n");
		printf("�ö������Ĳ�����:");
		BinaryTreeLevelOrder(tree);
		printf("\n\n");

	}
	com = BinaryTreeComplete(tree);
	if (com == 0)
	{
		printf("�ö���������ȫ������\n\n");
	}
	else
	{
		printf("�ö�����������ȫ������\n\n");
	}
	printf("��������ҵ�����: ");
	scanf("%c", &input);
	printf("\n\n");
	pos = BinaryTreeFind(tree, input);
	if (pos != NULL)
	{
		printf("��ѯ�ɹ����������ǣ�%c \n\n", pos->data);
	}
	else
	{
		printf("�޴����ݣ�\n\n");
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
		printf("�Ѷ�: %d \n\n", HeapTop(&hp));
		printf("�Ѵ�С��%d \n\n", HeapSize(&hp));
	}


	HeapDestory(&hp);
}
//////////////////////////////////////////////////////////////
//������
void TestHeapSort()
{
	//�������
	HPDataType arr[] = { 53, 17, 78, 9, 45, 65, 87, 23, 31 };
	Heap hp;

	int i = 0;
	int flag = 0;
	int n = sizeof(arr) / sizeof(arr[0]);
	hp.a = (HPDataType*)malloc(sizeof(HPDataType)* n);//���ѿ�����������ͬ�����Ŀռ�
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
	printf("Դ��: ");
	for (i = 0; i < n; i++)
	{
		printf(" %d ", hp.a[i]);
	}
	printf("\n\n");
	//����
	flag = HeapSort(hp.a, n);

	if (flag != 0)
	{
		printf("����ɹ�!\n\n");
		for (i = 0; i < n; i++)
		{
			printf(" %d ", hp.a[i]);
		}
		printf("\n\n");
	}
	else
	{
		printf("����ʧ��!\n\n");
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
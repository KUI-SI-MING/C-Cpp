#include "BinaryTree.h"

pBTNode BuyBTNode(BTDataType x)
{
	pBTNode newnode = (pBTNode)malloc(sizeof(BTNode));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

pBTNode BinaryTreeCreate(BTDataType* a, int n, int* pi)//�Ե�ǰ�������ȡַ��������Ϊȡֵ����ÿ�εݹ鷵�غ� i ��ֵ��û�иı�
{
	assert(a);

	if (a[*pi] != '#')
	{
		pBTNode root = BuyBTNode(a[*pi]);
		++(*pi);
		root->left = BinaryTreeCreate(a, n, pi);
		++(*pi);
		root->right = BinaryTreeCreate(a, n, pi);

		return root;
	}
	else
	{
		return NULL;
	}
}

void BinaryTreeDestory(pBTNode root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
	root = NULL;

}

int BinaryTreeSize(pBTNode root)
{
	if (root == NULL)
	{
		return 0;
	}
	static int treesize = 0;

	++treesize;
	BinaryTreeSize(root->left);
	BinaryTreeSize(root->right);

	return treesize + 1;//���ϸ��ڵ�

}

int BinaryTreeLeafSize(pBTNode root)//Ҷ�ӽڵ�ĸ���
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}

	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}

int BinaryTreeLevelKSize(pBTNode root, int k)//��k ��ĸ���
{
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}

pBTNode BinaryTreeFind(pBTNode root, BTDataType x)
{
	if (root == NULL || root->data == x)
	{
		return root;
	}

	pBTNode pos = BinaryTreeFind(root->left, x);

	if (pos != NULL)
	{
		return pos;
	}
	else
	{
		pos = BinaryTreeFind(root->right, x);
	}

	if (pos != NULL)
	{
		return pos;
	}
	else
	{
		return NULL;
	}
}

void BinaryTreePrevOrder(pBTNode root)
{
	if (root == NULL)
	{
		return;
	}
	printf(" %c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreePrevOrderNonR(pBTNode root)
{
	pBTNode cur = root;

	Stack s;
	StackInit(&s);

	while (cur || StackEmpty(&s))
	{
		//�ȷ���������
		while (cur)
		{
			printf(" %c ", cur->data);
			StackPush(&s, cur);
			cur = cur->left;
		}
		pBTNode top = StackTop(&s);
		StackPop(&s);

		//��������������

		cur = top->right;

	}
}

void BinaryTreeInOrder(pBTNode root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeInOrder(root->left);
	printf(" %c ", root->data);
	BinaryTreeInOrder(root->right);
}

void BinaryTreeInOrderNonR(pBTNode root)
{
	pBTNode cur = root;

	Stack s;
	StackInit(&s);

	while (cur || StackEmpty(&s))
	{
		//��ѹջ������
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}
		pBTNode top = StackTop(&s);
		printf(" %c ", top->data);
		StackPop(&s);
		//��������������

		cur = top->right;
	}
}

void BinaryTreePostOrder(pBTNode root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf(" %c ", root->data);
}

void BinaryTreePostOrderNonR(pBTNode root)
{
	pBTNode cur = root;
	pBTNode prev = NULL;

	Stack s;
	StackInit(&s);
	while (cur || StackEmpty(&s))
	{
		//��ѹջ������
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}
		pBTNode top = StackTop(&s);
		if (top->right == NULL || top->right == prev)//��top������������topd��ǰһ��ʱ��ӡtop��ȷ��A���һ������ӡ
		{
			printf(" %c ", top->data);
			prev = top;
			StackPop(&s);
		}
		else
		{
			cur = top->right;
		}
	}
}

void BinaryTreeLevelOrder(pBTNode root)
{
	if (root == NULL)
	{
		return;
	}
	Queue q;
	QueueInit(&q);
	pBTNode front = NULL;

	QueuePush(&q, root);
	while (QueueEmpty(&q))
	{
		front = QueueFront(&q);
		printf(" %c ", front->data);
		QueuePop(&q);
		if (front->left != NULL)
		{
			QueuePush(&q, front->left);
		}
		if (front->right != NULL)
		{
			QueuePush(&q, front->right);
		}
	}

}

int BinaryTreeComplete(pBTNode root)
{
	if (root == NULL)
	{
		return -1;
	}
	Queue q;
	QueueInit(&q);
	pBTNode front = NULL;

	QueuePush(&q, root);
	while (QueueEmpty(&q))//����Ԫ�ؽ�����к��ͷŵ��ǿ�Ԫ��(����Ҷ�ӽ��Ŀ�)
	{
		front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			break;
		}
	}
	//�ж϶������Ƿ�ȫΪ�գ���������ȫ��������ȫ
	while (QueueEmpty(&q))
	{
		front = QueueFront(&q);
		if (front)
		{
			QueueDestory(&q);
			return -1;
		}
		else
		{
			QueuePop(&q);
		}
	}
	return 0;
}

/////////////////////////////////////////////////////////////////////

void Swap(HPDataType* m, HPDataType* n)
{
	HPDataType tmp = 0;
	tmp = *m;
	*m = *n;
	*n = tmp;
}


void AdjustDown(HPDataType* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		//ѡ�����д��һ��
		if (a[child + 1] > a[child] && child + 1 < n)
		{
			child += 1;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);//�ں����ⲿ���н���Ҫ��ַ
			parent = child;
			child = child * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

//���
void HeapInit(pHeap hp, HPDataType* a, int n)
{
	assert(hp && a);
	int i = 0;
	hp->a = (HPDataType*)malloc(sizeof(HPDataType)*  n);
	hp->capacity = n;
	hp->size = n - 1;
	for (i = 0; i <= hp->size; i++)
	{
		hp->a[i] = a[i];
	}
	for (i = ((n - 2) / 2); i >= 0; --i)
	{
		AdjustDown(hp->a, hp->size + 1, i);
	}
}

void AdjustUp(HPDataType* a, int n, int child)
{
	assert(a);
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[parent] < a[child])
		{
			Swap(&a[parent], &a[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}


void HeapPush(pHeap hp, HPDataType x)
{
	int i = 0;
	int number = hp->size + 1;
	if (number == hp->capacity)
	{
		hp->a = (HPDataType*)realloc(hp->a, sizeof(HPDataType)* 2 * hp->capacity);//ע��realloc�������ڴ�ʹ������� ��ֹ�ڴ�Խ��
		assert(hp->a);
		hp->capacity += 2;
	}
	hp->size += 1;
	hp->a[hp->size] = x;
	AdjustUp(hp->a, hp->size + 1, hp->size);
}

void HeapDestory(pHeap hp)
{
	assert(hp);

	free(hp->a);
	hp->a = NULL;
	hp->capacity = 0;
	hp->size = -1;
}

void HeapPrint(Heap hp)
{
	int i = 0;
	if (hp.size == 0)
	{
		printf("�ն�\n\n");
		return;
	}
	printf("�ѣ�");
	for (i = 0; i <= hp.size; i++)
	{
		printf(" %d ", hp.a[i]);
	}
	printf("\n\n");
}

void HeapPop(pHeap hp)
{
	assert(hp);
	int i = 0;

	Swap(&hp->a[0], &hp->a[hp->size]);
	hp->size -= 1;
	for (i = 0; i <= hp->size; i++)
	{
		AdjustDown(hp->a, hp->size + 1, i);
	}
}

HPDataType HeapTop(pHeap hp)
{
	assert(hp);

	return hp->a[0];
}

int HeapSize(pHeap hp)
{
	assert(hp);

	return hp->size + 1;
}

int HeapEmpty(pHeap hp)
{
	assert(hp);
	if (hp->size == -1)
	{
		return 0;
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////
int HeapSort(HPDataType* a, int n)
{
	assert(a);
	int end = n - 1;
	while (end >= 0)
	{
		//printf("(%d)", end);
		Swap(&a[0], &a[end]);//�����Ժ��ں����ĵ���������Ӧȥ��β�ڵ㣬����������һ��
		--end;
		n--;
		AdjustDown(a, n, 0);
	}
	if (end < 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
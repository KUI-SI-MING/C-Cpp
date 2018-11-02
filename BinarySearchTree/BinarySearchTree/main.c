#include "BinarySearchTree.h"


void TestBSTree()
{
	pBSTreeNode ptree = NULL;

	BSTreeInsert(&ptree, 4);
	BSTreeInsert(&ptree, 2);
	BSTreeInsert(&ptree, 1);
	BSTreeInsert(&ptree, 3);
	BSTreeInsert(&ptree, 5);
	BSTreeInsert(&ptree, 7);
	BSTreeInsert(&ptree, 6);
	BSTreeInsert(&ptree, 9);
	BSTreeInsert(&ptree, 0);
	BSTreeInsert(&ptree, 10);

	BSTInOrder(&ptree);
	printf("\n\n");

	if (BSTreeRemove(&ptree, 2))
	{

		BSTInOrder(&ptree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}

	if (BSTreeRemove(&ptree, 1))
	{

		BSTInOrder(&ptree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}
	if (BSTreeRemove(&ptree, 5))
	{

		BSTInOrder(&ptree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}
	if (BSTreeRemove(&ptree, 8))
	{

		BSTInOrder(&ptree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}

	BSTInOrder(&ptree);
	printf("\n\n");


	/*const pBSTreeNode node = BSTreeFind(&ptree, 5);
	if (node != NULL)
	{
		printf(" ’“µΩ %d \n\n", node->data);
	}
	else
	{
		printf("’“≤ªµΩ\n\n");
	}

	BSTInOrder(&ptree);
	printf("\n\n");
*/

	//BSTreeDestory(&ptree);
}

void TestBSTree_R()
{
	int i = 0;
	pBSTreeNode pTree = NULL;
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		BSTreeInsert_R(& pTree, a[i]);
	}

	BSTInOrder(&pTree);
	printf("\n\n");

	if (BSTreeRemove_R(&pTree, 0))
	{

		BSTInOrder(&pTree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}

	if (BSTreeRemove_R(&pTree, 1))
	{

		BSTInOrder(&pTree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}
	if (BSTreeRemove_R(&pTree, 2))
	{

		BSTInOrder(&pTree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}
	if (BSTreeRemove_R(&pTree, 3))
	{

		BSTInOrder(&pTree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}
	if (BSTreeRemove_R(&pTree, 4))
	{

		BSTInOrder(&pTree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}
	if (BSTreeRemove_R(&pTree, 5))
	{

		BSTInOrder(&pTree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}
	if (BSTreeRemove_R(&pTree, 6))
	{

		BSTInOrder(&pTree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");
	}
	if (BSTreeRemove_R(&pTree, 7))
	{

		BSTInOrder(&pTree);
		printf("\n\n");
	}
	else
	{
		printf("…æ≥˝ ß∞‹!\n\n");

	}
	BSTInOrder(&pTree);
	printf("\n\n");
}

int main()
{
	//TestBSTree();
	TestBSTree_R();
	system("pause");
	return 0;
}
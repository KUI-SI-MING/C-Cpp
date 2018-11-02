#include "BSTreeKV.h"


void TestBSTree1()
{
	char str[10];
	pBSTreeNode pTree = NULL;
	
	BSTreeInsert(&pTree, "insert", 1);
	BSTreeInsert(&pTree, "sort", 1);
	BSTreeInsert(&pTree, "find", 1);
	BSTreeInsert(&pTree, "tree", 1);
	BSTreeInsert(&pTree, "destory", 1);
	while (1)
	{
		printf("请输入查询单词：");
		scanf("%s", str);
		printf("\n");
		if (BSTreeFind(&pTree, str))
		{
			printf("正确的单词\n\n");
		}
		else
		{
			printf("错误的单词\n\n");
		}
	}
}


void TestBSTree2()
{
	pBSTreeNode ptree = NULL;

	BSTreeInsert(&ptree, "tree", "树");
	BSTreeInsert(&ptree, "sort", "排序");
	BSTreeInsert(&ptree, "binary", "二分");
	BSTreeInsert(&ptree, "return", "返回");
	BSTreeInsert(&ptree, "hash", "哈希");
	BSTreeInsert(&ptree, "list", "链表");

	printf("tree: %s \n\n", BSTreeFind(&ptree, "tree")->value);
	printf("return: %s \n\n", BSTreeFind(&ptree, "return")->value);
	printf("hash: %s \n\n", BSTreeFind(&ptree, "hash")->value);
	printf("list: %s \n\n", BSTreeFind(&ptree, "list")->value);
}
void TestBSTree3()
{
	pBSTreeNode pTree = NULL;
	char str[10] = { '0' };

	while (1)
	{
		pBSTreeNode node;
		printf("请输入:");
		scanf("%s", str);
		printf("\n");
		if (strcmp(str, "exit") == 0)
		{
			break;
		}

		node = BSTreeFind(&pTree, str);
		if (node)
		{
			node->value++;
		}
		else
		{
			BSTreeInsert(&pTree, str, 1);
		}
	}

	BSTreeInOrder(&pTree);
}



int main()
{
	//TestBSTree1();
	//TestBSTree2();
	TestBSTree3();

	system("pause");
	return 0;
}
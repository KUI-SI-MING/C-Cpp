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
		printf("�������ѯ���ʣ�");
		scanf("%s", str);
		printf("\n");
		if (BSTreeFind(&pTree, str))
		{
			printf("��ȷ�ĵ���\n\n");
		}
		else
		{
			printf("����ĵ���\n\n");
		}
	}
}


void TestBSTree2()
{
	pBSTreeNode ptree = NULL;

	BSTreeInsert(&ptree, "tree", "��");
	BSTreeInsert(&ptree, "sort", "����");
	BSTreeInsert(&ptree, "binary", "����");
	BSTreeInsert(&ptree, "return", "����");
	BSTreeInsert(&ptree, "hash", "��ϣ");
	BSTreeInsert(&ptree, "list", "����");

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
		printf("������:");
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
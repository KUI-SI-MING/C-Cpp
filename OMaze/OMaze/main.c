#include "maze.h"

void TestMaze()
{
	Pos entry;
	entry._row = 5;
	entry._col = 2;

	Pos exit;
	exit._row = 4;
	exit._col = 5;
	printf("�Թ���ͼ:\n");
	PrintfMaze();
	if (GetMazePath(entry, exit))
	{
		printf("�г��ڣ����·��Ϊ��%d \n\n", size);
	}
	else
	{
		printf("�޳��ڣ�\n\n");
	}
	printf("�߳����Թ���ͼ:\n");
	PrintfMaze();
}

int main()
{
	TestMaze();
	system("pause");
	return 0;
}
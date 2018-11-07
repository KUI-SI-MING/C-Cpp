#include "maze.h"

void TestMaze()
{
	Pos entry;
	entry._row = 5;
	entry._col = 2;

	Pos exit;
	exit._row = 4;
	exit._col = 5;
	printf("迷宫地图:\n");
	PrintfMaze();
	if (GetMazePath(entry, exit))
	{
		printf("有出口，最短路径为：%d \n\n", size);
	}
	else
	{
		printf("无出口！\n\n");
	}
	printf("走出后迷宫地图:\n");
	PrintfMaze();
}

int main()
{
	TestMaze();
	system("pause");
	return 0;
}
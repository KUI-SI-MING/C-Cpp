#include"Maze.h"


int CheckAccess(Pos cur, Pos next)
{
	if (next._row >= 0 && next._row < N
		&&next._col >= 0 && next._col < N
		&& (maze[next._row][next._col] == 1 || maze[next._row][next._col] > maze[cur._row][cur._col] + 1))//当下一个坐标的值为1 或者比当前值加一还大就可以走
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int size = 0;
int GetMazePath(Pos entry, Pos exit)
{
	Stack path;
	int flag = 0;
	StackInit(&path);
	StackPush(&path, entry);
	maze[entry._row][entry._col] = 2;//入口初始化为2
	while (StackEmpty(&path))
	{
		//Pos cur = entry;//当前位置
		Pos cur = StackTop(&path);//栈顶取出的当前位置

		if (cur._col == 5)//多条通路
		/*if (cur._row == exit._row
			&&cur._col == exit._col)*///当一条路径找到出口时，打印路径并且看路径长短
		{
			flag = 1;
			for (int i = 0; i < path._top; i++)
			{
				printf("[%d %d]->", path._a[i]._row, path._a[i]._col);
			}
			printf(" Exit\n\n");
			if (size == 0 || StackSize(&path) < size)
			{
				size = StackSize(&path);//路径的长短 
			}
		}
		Pos next;
		//上
		next = cur;//当前位置
		next._row -= 1;//下一个位置
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);//下一个位置可以通，入栈
			continue;
		}
		//下
		next = cur;
		next._row += 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);//下一个位置可以通，入栈
			continue;
		}
		//左
		next = cur;
		next._col -= 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);//下一个位置可以通，入栈
			continue;
		}
		//右
		next = cur;
		next._col += 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);//下一个位置可以通，入栈
			continue;
		}

		//走到四个方向不通的位置
		//回溯
		StackPop(&path);
	}
	if (flag == 0)//判断是否找到出口
		return 0;
	else
		return 1;
}


void PrintfMaze()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}

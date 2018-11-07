#include"Maze.h"


int CheckAccess(Pos cur, Pos next)
{
	if (next._row >= 0 && next._row < N
		&&next._col >= 0 && next._col < N
		&& (maze[next._row][next._col] == 1 || maze[next._row][next._col] > maze[cur._row][cur._col] + 1))//����һ�������ֵΪ1 ���߱ȵ�ǰֵ��һ����Ϳ�����
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
	maze[entry._row][entry._col] = 2;//��ڳ�ʼ��Ϊ2
	while (StackEmpty(&path))
	{
		//Pos cur = entry;//��ǰλ��
		Pos cur = StackTop(&path);//ջ��ȡ���ĵ�ǰλ��

		if (cur._col == 5)//����ͨ·
		/*if (cur._row == exit._row
			&&cur._col == exit._col)*///��һ��·���ҵ�����ʱ����ӡ·�����ҿ�·������
		{
			flag = 1;
			for (int i = 0; i < path._top; i++)
			{
				printf("[%d %d]->", path._a[i]._row, path._a[i]._col);
			}
			printf(" Exit\n\n");
			if (size == 0 || StackSize(&path) < size)
			{
				size = StackSize(&path);//·���ĳ��� 
			}
		}
		Pos next;
		//��
		next = cur;//��ǰλ��
		next._row -= 1;//��һ��λ��
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);//��һ��λ�ÿ���ͨ����ջ
			continue;
		}
		//��
		next = cur;
		next._row += 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);//��һ��λ�ÿ���ͨ����ջ
			continue;
		}
		//��
		next = cur;
		next._col -= 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);//��һ��λ�ÿ���ͨ����ջ
			continue;
		}
		//��
		next = cur;
		next._col += 1;
		if (CheckAccess(cur, next))
		{
			maze[next._row][next._col] = maze[cur._row][cur._col] + 1;
			StackPush(&path, next);//��һ��λ�ÿ���ͨ����ջ
			continue;
		}

		//�ߵ��ĸ�����ͨ��λ��
		//����
		StackPop(&path);
	}
	if (flag == 0)//�ж��Ƿ��ҵ�����
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

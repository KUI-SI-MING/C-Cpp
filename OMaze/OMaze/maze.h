#pragma once

#include"Stack.h"

#define N 6
int size;
static int maze[N][N] = {//static,ֻ��maze.c�пɼ�
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 },

	/*{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 0, 1, 0 },
	{ 0, 0, 1, 1, 1, 1 },
	{ 0, 0, 1, 0, 0, 0 },*/

	//{ 0, 0, 0, 0, 0, 0 },
	//{ 0, 0, 1, 0, 0, 0 },
	//{ 0, 0, 1, 0, 0, 0 },
	//{ 0, 0, 1, 1, 1, 0 },
	//{ 0, 0, 1, 0, 1, 1 },
	//{ 0, 0, 1, 0, 0, 0 },
};




int GetMazePath(Pos entry, Pos exit);//��ȡ�Թ�ͨ·:�ҵ�ͨ·/�Ҳ���ͨ·
int CheckAccess(Pos cur, Pos next);
void PrintfMaze();

void TestMaze();
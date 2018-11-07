#pragma once

#include"Stack.h"

#define N 6
int size;
static int maze[N][N] = {//static,只在maze.c中可见
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




int GetMazePath(Pos entry, Pos exit);//获取迷宫通路:找到通路/找不到通路
int CheckAccess(Pos cur, Pos next);
void PrintfMaze();

void TestMaze();
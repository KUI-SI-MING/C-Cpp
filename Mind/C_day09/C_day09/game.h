//*Copyright(c) 2018,葵
//*All rights reserved.
//*
//*文件名称：排雷游戏
//*
//*当前版本：1.1
//*作者：葵
//*完成日期：2018年5月5日
//*
//*取代版本：1.0
//*作者：葵
//*


#ifndef  _GAME_H_
#define  _GAME_H_


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


enum OPTION
{
	PLAY = 1,
	EXIT = 2
};


#define ROW 5
#define COL 5
#define ROWS ROW+2
#define COLS COL+2

void interface();
int  Choose(int a);
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void PrintBoard(char board[ROWS][COLS], int rows, int cols);
void SetMine(char board[ROWS][COLS],int row,int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int GetMineCount(char mine[ROWS][COLS], int x, int  y);
void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y);


#endif//_GAME_H_
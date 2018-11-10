#pragma once  
#ifndef _GAME_H__  
#define _GAME_H__  
#define COL 9  
#define ROW 9  
#define COLS COL+2  
#define ROWS ROW+2  
void gotoxy(int x, int y);//光标移动函数,光标想在哪里就在哪里  
void init_mine(int mine[ROWS][COLS], int rows, int cols, int count);//初始化雷的分布  
void init_show(char show[ROWS][COLS], int rows, int cols);//初始化雷的界面  
void printf_mine(int mine[ROWS][COLS], int row, int col);//打印雷的信息  
void printf_show(char show[ROWS][COLS], int row, int col);//打印扫雷界面  
int sweep_mine(int mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//输入坐标和扫雷扩展  
int what_is_win(char show[ROWS][COLS], int row, int col, int count);//判断胜利  
void menu();//菜单  
int choose_mode();//难度选择  
#endif  
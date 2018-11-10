#pragma once  
#ifndef _GAME_H__  
#define _GAME_H__  
#define COL 9  
#define ROW 9  
#define COLS COL+2  
#define ROWS ROW+2  
void gotoxy(int x, int y);//����ƶ�����,������������������  
void init_mine(int mine[ROWS][COLS], int rows, int cols, int count);//��ʼ���׵ķֲ�  
void init_show(char show[ROWS][COLS], int rows, int cols);//��ʼ���׵Ľ���  
void printf_mine(int mine[ROWS][COLS], int row, int col);//��ӡ�׵���Ϣ  
void printf_show(char show[ROWS][COLS], int row, int col);//��ӡɨ�׽���  
int sweep_mine(int mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//���������ɨ����չ  
int what_is_win(char show[ROWS][COLS], int row, int col, int count);//�ж�ʤ��  
void menu();//�˵�  
int choose_mode();//�Ѷ�ѡ��  
#endif  
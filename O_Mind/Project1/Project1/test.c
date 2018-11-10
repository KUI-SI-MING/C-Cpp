#include<stdio.h>  
#include<windows.h>  
#include<string.h>  
#include<time.h>  
#include "Game.h"  

void game()
{
	int mine[11][11] = { 0 };
	char show[11][11] = { 0 };
	int count = 0;//产生雷的个数  
	int flag = 1;//游戏结束标志,先让游戏进行着  
	count = choose_mode();
	init_mine(mine, ROWS, COLS, count);//确定雷的坐标  
	init_show(show, ROWS, COLS);//初始化show数组作为显示界面  
	while (flag)//判断游戏是否结束 是否踩雷 flag为1为踩到了雷  
	{
		system("cls");
		printf_show(show, ROW, COL);//打印扫雷界面  
		flag = sweep_mine(mine, show, ROW, COL);//扫一个雷  
		if (what_is_win(show, ROW, COL, count))//如果胜利了就退出游戏  
		{
			gotoxy(12, 20);
			printf("胜利啦!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			break;
		}
	}

	printf_show(show, ROW, COL);//打印扫雷界面  
	printf_mine(mine, ROW, COL);//打印雷全部信息  
	gotoxy(20, 20);
	printf("*号代表雷      ");
}


int main()
{
	int input;
	srand((unsigned int)time(NULL));//能产生随机数   
	menu();
	do
	{
	retrat:
		printf("请选择>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 0: break;
		case 1:game(); system("pause"); system("cls"); menu(); goto retrat;
			//default:break;  
		}
	} while (input);
	system("pause");
	return 0;
}
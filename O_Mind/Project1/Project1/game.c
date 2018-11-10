#include "Game.h"  
#include <conio.h>  
#include<windows.h>  
#include<time.h>  
#include<stdio.h>  


void gotoxy(int x, int y)//光标移动函数,光标想在哪里就在哪里  
{
	COORD coord = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void menu()
{
	printf("***********扫雷游戏***作者:弱鸡****\n");
	printf("************1.play*****************\n");
	printf("***********************************\n");
	printf("************0.exit*****************\n");
	printf("***********************************\n");
}


int choose_mode()
{
	int num;
	system("cls");
	printf("**************************************\n");
	printf("************1.容易**********10个雷****\n");
	printf("**************************************\n");
	printf("************2.中等**********20个雷****\n");
	printf("**************************************\n");
	printf("************3.困难**********30个雷****\n");
	printf("**************************************\n"); \
		printf("请输入选择>");
	scanf_s("%d", &num);
	switch (num)
	{
	case 1:return 10;
	case 2:return 20;
	case 3:return 30;
	}
}


void init_show(char show[ROWS][COLS], int rows, int cols)
{
	int i;
	int j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			show[i][j] = '0';
		}
	}
}


void init_mine(int mine[ROWS][COLS], int rows, int cols, int count)//随机布置雷，布置雷后让周围的非雷单位全部自加一  
{
	int x;
	int y;
	int c = 0;//计算产生雷的个数  
	c = count;
	while (c)
	{
		x = rand() % (rows - 2) + 1;
		y = rand() % (cols - 2) + 1;
		if (9 != mine[x][y])//如果没有雷  
		{
			mine[x][y] = 9;//本地标记为雷  
			c--;//产生一个雷，c减一  


			if (9 != mine[x][y - 1])//检查周围是否是雷如果不是就加一，表示周边的点边上有一个雷  
				mine[x][y - 1]++;


			if (9 != mine[x][y + 1])
				mine[x][y + 1]++;


			if (9 != mine[x - 1][y + 1])
				mine[x - 1][y + 1]++;


			if (9 != mine[x - 1][y])
				mine[x - 1][y]++;


			if (9 != mine[x - 1][y - 1])
				mine[x - 1][y - 1]++;


			if (9 != mine[x + 1][y - 1])
				mine[x + 1][y - 1]++;


			if (9 != mine[x + 1][y])
				mine[x + 1][y]++;


			if (9 != mine[x + 1][y + 1])
				mine[x + 1][y + 1]++;

		}
	}
}


void printf_mine(int arr[ROWS][COLS], int row, int col)//9代表雷  
{
	int x;
	int y;
	for (x = 1; x <= row; x++)
	{
		for (y = 1; y <= col; y++)
		{
			gotoxy(15 + x, y * 2);
			if (9 == arr[x][y])
			{
				printf("*");
			}
			else
			{

				printf("%-2d", arr[x][y]);
			}
		}
		printf("\n");
	}
}


void printf_show(char show[ROWS][COLS], int row, int col)
{
	int x;
	int y;
	for (x = 0; x <= row; x++)
	{
		gotoxy(0, x * 2);
		printf("%2d", x);
		gotoxy(x, 0);
		printf("%2d", x);
	}
	for (x = 1; x <= row; x++)
	{
		for (y = 1; y <= col; y++)
		{
			gotoxy(x, y * 2);
			if ('0' == show[x][y])
			{
				printf("▇");
			}
			else
			{
				printf("%2c", show[x][y]);
			}
		}
		printf("\n");
	}
}



//递归扩展，如果当前位置周围没雷，扩展，把扩展后的位置看成当前位置再次判断是否扩展，反反复复，直到不能扩展为止  
void sweepmine(int mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col)//递归扩张函数  
{
	if (0 == mine[x][y])
	{
		show[x][y] = ' ';


	}
	if (' ' != show[x - 1][y])//已经判断过的四周没有雷的点会被赋空格字符，如果已经判断过了就不需要再判断了  
	{
		if (0 == mine[x - 1][y] && x - 1 >= 1)
		{
			sweepmine(mine, show, x - 1, y, row, col);
		}
		else
		{
			show[x - 1][y] = '0' + mine[x - 1][y];
		}
	}


	if (' ' != show[x + 1][y])
	{
		if (0 == mine[x + 1][y] && x + 1 <= row && ' ' != show[x + 1][y])
		{
			sweepmine(mine, show, x + 1, y, row, col);
		}
		else
		{
			show[x + 1][y] = '0' + mine[x + 1][y];
		}
	}


	if (' ' != show[x][y - 1])
	{
		if (0 == mine[x][y - 1] && y - 1 >= 1 && ' ' != show[x][y - 1])
		{
			sweepmine(mine, show, x, y - 1, row, col);
		}
		else
		{
			show[x][y - 1] = '0' + mine[x][y - 1];
		}
	}


	if (' ' != show[x - 1][y - 1])
	{
		if (0 == mine[x - 1][y - 1] && x - 1 >= 1 && y - 1 >= 1 && ' ' != show[x - 1][y - 1])
		{
			sweepmine(mine, show, x - 1, y - 1, row, col);
		}
		else
		{
			show[x - 1][y - 1] = '0' + mine[x - 1][y - 1];
		}
	}


	if (' ' != show[x + 1][y - 1])
	{
		if (0 == mine[x + 1][y - 1] && x + 1 <= row && y - 1 >= 1 && ' ' != show[x + 1][y - 1])
		{
			sweepmine(mine, show, x + 1, y - 1, row, col);
		}
		else
		{
			show[x + 1][y - 1] = '0' + mine[x + 1][y - 1];
		}
	}


	if (' ' != show[x + 1][y + 1])
	{
		if (0 == mine[x + 1][y + 1] && x + 1 <= row && y + 1 <= col && ' ' != show[x + 1][y + 1])
		{
			sweepmine(mine, show, x + 1, y + 1, row, col);
		}
		else
		{
			show[x + 1][y + 1] = '0' + mine[x + 1][y + 1];
		}
	}


	if (' ' != show[x - 1][y + 1])
	{
		if (0 == mine[x - 1][y + 1] && x - 1 >= 1 && y + 1 <= col && ' ' != show[x - 1][y + 1])
		{
			sweepmine(mine, show, x - 1, y + 1, row, col);
		}
		else
		{
			show[x - 1][y + 1] = '0' + mine[x - 1][y + 1];
		}
	}


	if (' ' != show[x][y + 1])
	{
		if (0 == mine[x][y + 1] && y + 1 <= col && ' ' != show[x][y + 1])
		{
			sweepmine(mine, show, x, y + 1, row, col);
		}
		else
		{
			show[x][y + 1] = '0' + mine[x][y + 1];
		}
	}
}


int what_is_win(char show[ROWS][COLS], int row, int col, int count)
{
	int x;
	int y;
	int countt;
	countt = 0;
	for (x = 1; x <= row; x++)
	{
		for (y = 1; y <= col; y++)
		{
			if ('0' != show[x][y])//'0'表示未知区域，不是即表示已知区域，判断一直区域范围  
				countt++;
		}
	}
	return (countt >= (row*col - count));
}


int sweep_mine(int mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//扫雷执行函数  函数返回值为1为继续游戏，为0表示踩雷游戏结束  
{
	static int n = 0;//代表查雷次数  
	int x;
	int y;
	while (1)
	{
		n++;//查雷次数加以  
		printf("请输入一个坐标>");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row &&y >= 1 && y <= col)
		{
			if (9 == mine[x][y])//第一次就踩雷，要避开  
			{
				if (1 == n)
				{
					int i = rand() % row + 1;
					int j = rand() % col + 1;
					while (9 == mine[x][y])//如果本地有雷就一直找一个没雷的地方替换  
					{
						mine[x][y] = mine[i][j] ^ mine[x][y];
						mine[i][j] = mine[i][j] ^ mine[x][y];
						mine[x][y] = mine[i][j] ^ mine[x][y];
						i = rand() % row + 1;
						j = rand() % col + 1;
					}
				}
				else
				{
					n = 0;//本次游戏结束时初始化为0  
					printf("你踩雷了\n");
					return 0;
				}
			}
			else if (0 == mine[x][y])
			{
				sweepmine(mine, show, x, y, row, col);
			}
			else
			{
				show[x][y] = '0' + mine[x][y];
			}
			break;
		}
		else
		{
			printf("输入有误\n");
		}
	}
	return 1;//返回1 游戏还在继续  
}

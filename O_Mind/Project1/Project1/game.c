#include "Game.h"  
#include <conio.h>  
#include<windows.h>  
#include<time.h>  
#include<stdio.h>  


void gotoxy(int x, int y)//����ƶ�����,������������������  
{
	COORD coord = { y, x };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void menu()
{
	printf("***********ɨ����Ϸ***����:����****\n");
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
	printf("************1.����**********10����****\n");
	printf("**************************************\n");
	printf("************2.�е�**********20����****\n");
	printf("**************************************\n");
	printf("************3.����**********30����****\n");
	printf("**************************************\n"); \
		printf("������ѡ��>");
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


void init_mine(int mine[ROWS][COLS], int rows, int cols, int count)//��������ף������׺�����Χ�ķ��׵�λȫ���Լ�һ  
{
	int x;
	int y;
	int c = 0;//��������׵ĸ���  
	c = count;
	while (c)
	{
		x = rand() % (rows - 2) + 1;
		y = rand() % (cols - 2) + 1;
		if (9 != mine[x][y])//���û����  
		{
			mine[x][y] = 9;//���ر��Ϊ��  
			c--;//����һ���ף�c��һ  


			if (9 != mine[x][y - 1])//�����Χ�Ƿ�����������Ǿͼ�һ����ʾ�ܱߵĵ������һ����  
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


void printf_mine(int arr[ROWS][COLS], int row, int col)//9������  
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
				printf("�~");
			}
			else
			{
				printf("%2c", show[x][y]);
			}
		}
		printf("\n");
	}
}



//�ݹ���չ�������ǰλ����Χû�ף���չ������չ���λ�ÿ��ɵ�ǰλ���ٴ��ж��Ƿ���չ������������ֱ��������չΪֹ  
void sweepmine(int mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col)//�ݹ����ź���  
{
	if (0 == mine[x][y])
	{
		show[x][y] = ' ';


	}
	if (' ' != show[x - 1][y])//�Ѿ��жϹ�������û���׵ĵ�ᱻ���ո��ַ�������Ѿ��жϹ��˾Ͳ���Ҫ���ж���  
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
			if ('0' != show[x][y])//'0'��ʾδ֪���򣬲��Ǽ���ʾ��֪�����ж�һֱ����Χ  
				countt++;
		}
	}
	return (countt >= (row*col - count));
}


int sweep_mine(int mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//ɨ��ִ�к���  ��������ֵΪ1Ϊ������Ϸ��Ϊ0��ʾ������Ϸ����  
{
	static int n = 0;//������״���  
	int x;
	int y;
	while (1)
	{
		n++;//���״�������  
		printf("������һ������>");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row &&y >= 1 && y <= col)
		{
			if (9 == mine[x][y])//��һ�ξͲ��ף�Ҫ�ܿ�  
			{
				if (1 == n)
				{
					int i = rand() % row + 1;
					int j = rand() % col + 1;
					while (9 == mine[x][y])//����������׾�һֱ��һ��û�׵ĵط��滻  
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
					n = 0;//������Ϸ����ʱ��ʼ��Ϊ0  
					printf("�������\n");
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
			printf("��������\n");
		}
	}
	return 1;//����1 ��Ϸ���ڼ���  
}

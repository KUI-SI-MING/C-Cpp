#include "game.h"

extern int nume ;//全局变量声明



//初始化数组
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}


//打印数组
void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (j = 0; j <= row; j++)
	{
		printf("%-2d ", j);
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		printf("%-2d", i+1);
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//设置炸弹
void SetMine(char board[ROWS][COLS])
{
	int count =nume;
	int x = 0;
	int y = 0;
	while (count)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if ('0' == board[x][y])
		{
			board[x][y] = '1';//有雷的地方设置为字符1
			count--;
		}
	}
}



//返回玩家输入坐标周围的雷数
static int GetMineCount(char mine[ROWS][COLS], int x, int y)
{

	int minecount = 0;


	if (mine[x - 1][y] == '1')
		minecount++;
	if (mine[x - 1][y + 1] == '1')
		minecount++;
	if (mine[x][y + 1] == '1')
		minecount++;
	if (mine[x + 1][y + 1] == '1')
		minecount++;
	if (mine[x + 1][y] == '1')
		minecount++;
	if (mine[x + 1][y - 1] == '1')
		minecount++;
	if (mine[x][y - 1] == '1')
		minecount++;
	if (mine[x - 1][y - 1] == '1')
		minecount++;
	return minecount;
}



//利用函数递归调用实现的扩展函数
void expand(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)
{
	if (0 == GetMineCount(mine, x, y))
		{
			show[x][y] = ' ';
			if (show[x][y - 1] == '*')
			{
				expand(mine, show, row, col, x, (y - 1));
			}

			if (show[x - 1][y - 1] == '*')
			{
				expand(mine, show, row, col, x, (y - 1));
			}
			if (show[x][y + 1] == '*')
			{
				expand(mine,show, row, col, x, (y + 1));
			}

			if (show[x - 1][y] == '*')
			{
				expand(mine, show, row, col, (x - 1), y);
			}

			if (show[x - 1][y + 1] == '*')
			{
				expand(mine, show, row, col, x, (y - 1));
			}

			if (show[x + 1][y] == '*')
			{
				expand(mine, show, row, col, (x + 1), y);
			}
			if (show[x + 1][y - 1] == '*')
			{
				expand(mine, show, row, col, x, (y - 1));
			}
			if (show[x + 1][y - 1] == '*')
			{
				expand(mine, show, row, col, x, (y - 1));
			}
		}
	else
	{
		show[x][y] = GetMineCount(mine, x, y) + '0';
	}
}



//找雷函数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int num = 0;
	int i = 0;
	int j = 0;
	int count = 0;

	while (1)
	{
		printf("请输入您的坐标-->：");
		scanf("%d%d", &x, &y);
		printf("\n");
		if (0 == (x >= 1 && x <= row && y >= 1 && y <= col))
		{
			printf("输入非法！请重新输入！\n");
			printf("\n");
		}
		while (1 == (x >= 1 && x <= row && y >= 1 && y <= col))
		{
			x--;
			y--;
			if ('*' != show[x][y])
			{
				printf("输入已确认区域，请重新输入！\n");
				printf("\n");
				break;
			}
			if ('*' == show[x][y])
			{
				if ('1' == mine[x][y])
				{
					if (0 == count)//判断是否第一次就踩到雷了
					{
						printf("炸了！再给你一次机会！\n");
						printf("\n");
						count = 1;
						break;
					}
					else
					{
						system("cls");
						printf("   -_-恭喜你中奖了，你踩到雷了！GAME OVER!\n");
						printf("\n");
						return 0;
					}
				}
				else
				{
					expand(mine, show, row, col, x, y);
					PrintBoard(show, ROW, COL);
					break;
				}
			}
		}
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (show[i][j] == '*')//通过判断 * 的多少来判断是否排雷成功
				{
					num++;
				}
			}
		}
		if (num == nume)
		{
			system("cls");
			printf("  ^_^恭喜你，扫雷成功！^_^\n");
			printf("\n");
			return;
		}
		num = 0;
	}
}

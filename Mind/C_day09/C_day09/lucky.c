#include "game.h"
int nume = 0 ;//全局变量定义


//菜单函数
void MENU()
{
		printf("                          #####                             \n");
		printf("                   ######       ######                      \n");
		printf("              #######    1.PLAY     #######                 \n");
		printf("              #######    2.EXIT     #######                 \n");
		printf("                   ######       ######                      \n");
		printf("                          #####                             \n");
}


//选择界面
void interface()
{
	printf("*********************************************************************\n");
	printf("********************   1.菜鸟   *************************************\n");
	printf("********************   2.高手   *************************************\n");
	printf("********************   3.老鸟   *************************************\n");
	printf("*********************************************************************\n");
	printf("\n");
}


//难度选择,返回不同的雷的数目
int  Choose(int a)
{
	int num = 0;
	switch (a)
	{
	case 1:
		num = ROW;
		break;
	case 2:
		num = ROW + ROW / 2;
		break;
	case 3:
		num = ROW * 2 ;
		break;
	default:
	{
			   printf("输入错误，请重新输入！");
			   break;
	}
	}
	return num;
}



//游戏函数
void game()
{
	char mine[ROWS][COLS] = { '0' };  
	char show[ROWS][COLS] = { '0' };



	InitBoard(mine, ROW, COL, '0');//布雷的函数初始化为‘0’
	InitBoard(show, ROWS, COLS, '*');//显示的函数初始化为‘0’



	//PrintBoard(mine, ROW, COL);
	PrintBoard(show, ROW, COL);


	SetMine(mine,ROW,COL);//生成随机位置的雷
	PrintBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);//找雷函数
}


//执行函数
void TEST()
{
	srand((unsigned)time(NULL));
	int input = 0;
	int i = 0;
	do
	{
		MENU();
		printf("请选择->");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
		{
				  interface();
				  printf("请选择难度->");
				  scanf("%d", &i);
				  printf("\n");
				  nume= Choose(i);//全局变量赋予其雷的数目
				  game();
				  break;
		}
		case 2:
			printf("您将退出游戏！\n");
			printf("\n");
			return;
		default:
			printf("您输错了，请再输入！\n");
			break;
		}
	} while (input);
}



//主函数
int main()
{
	TEST();
	system("pause");
	return 0;
}

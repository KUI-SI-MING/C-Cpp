#include<stdio.h>  
#include<windows.h>  
#include<string.h>  
#include<time.h>  
#include "Game.h"  

void game()
{
	int mine[11][11] = { 0 };
	char show[11][11] = { 0 };
	int count = 0;//�����׵ĸ���  
	int flag = 1;//��Ϸ������־,������Ϸ������  
	count = choose_mode();
	init_mine(mine, ROWS, COLS, count);//ȷ���׵�����  
	init_show(show, ROWS, COLS);//��ʼ��show������Ϊ��ʾ����  
	while (flag)//�ж���Ϸ�Ƿ���� �Ƿ���� flagΪ1Ϊ�ȵ�����  
	{
		system("cls");
		printf_show(show, ROW, COL);//��ӡɨ�׽���  
		flag = sweep_mine(mine, show, ROW, COL);//ɨһ����  
		if (what_is_win(show, ROW, COL, count))//���ʤ���˾��˳���Ϸ  
		{
			gotoxy(12, 20);
			printf("ʤ����!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
			break;
		}
	}

	printf_show(show, ROW, COL);//��ӡɨ�׽���  
	printf_mine(mine, ROW, COL);//��ӡ��ȫ����Ϣ  
	gotoxy(20, 20);
	printf("*�Ŵ�����      ");
}


int main()
{
	int input;
	srand((unsigned int)time(NULL));//�ܲ��������   
	menu();
	do
	{
	retrat:
		printf("��ѡ��>");
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
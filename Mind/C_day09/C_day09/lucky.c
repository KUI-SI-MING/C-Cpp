#include "game.h"
int nume = 0 ;//ȫ�ֱ�������


//�˵�����
void MENU()
{
		printf("                          #####                             \n");
		printf("                   ######       ######                      \n");
		printf("              #######    1.PLAY     #######                 \n");
		printf("              #######    2.EXIT     #######                 \n");
		printf("                   ######       ######                      \n");
		printf("                          #####                             \n");
}


//ѡ�����
void interface()
{
	printf("*********************************************************************\n");
	printf("********************   1.����   *************************************\n");
	printf("********************   2.����   *************************************\n");
	printf("********************   3.����   *************************************\n");
	printf("*********************************************************************\n");
	printf("\n");
}


//�Ѷ�ѡ��,���ز�ͬ���׵���Ŀ
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
			   printf("����������������룡");
			   break;
	}
	}
	return num;
}



//��Ϸ����
void game()
{
	char mine[ROWS][COLS] = { '0' };  
	char show[ROWS][COLS] = { '0' };



	InitBoard(mine, ROW, COL, '0');//���׵ĺ�����ʼ��Ϊ��0��
	InitBoard(show, ROWS, COLS, '*');//��ʾ�ĺ�����ʼ��Ϊ��0��



	//PrintBoard(mine, ROW, COL);
	PrintBoard(show, ROW, COL);


	SetMine(mine,ROW,COL);//�������λ�õ���
	PrintBoard(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);//���׺���
}


//ִ�к���
void TEST()
{
	srand((unsigned)time(NULL));
	int input = 0;
	int i = 0;
	do
	{
		MENU();
		printf("��ѡ��->");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case 1:
		{
				  interface();
				  printf("��ѡ���Ѷ�->");
				  scanf("%d", &i);
				  printf("\n");
				  nume= Choose(i);//ȫ�ֱ����������׵���Ŀ
				  game();
				  break;
		}
		case 2:
			printf("�����˳���Ϸ��\n");
			printf("\n");
			return;
		default:
			printf("������ˣ��������룡\n");
			break;
		}
	} while (input);
}



//������
int main()
{
	TEST();
	system("pause");
	return 0;
}

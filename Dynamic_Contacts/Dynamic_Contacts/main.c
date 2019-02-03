#include "DynamicContacts.h"

//菜单函数
void Menu()
{
	printf("***************************************************\n");
	printf("****         MY   COMUNICATION  BOOK           ****\n");
	printf("****  1.Add                        2.Delete    ****\n");
	printf("****  3.Search                     4.Modify    ****\n");
	printf("****  5.Show                       6.Empty     ****\n");
	printf("****  7.Sort                       0.Exit      ****\n");
	printf("***************************************************\n");
}


void Test()
{
	int input = 0;
	Contact my_con;
	InitContact(&my_con);
	do
	{
		Menu();
		printf("\n");
		printf("请输入你的选择:>");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case Add:
		{
					AddComunicator(&my_con);
					break;
		}
		case Delete:
		{
					   DeleteComunicator(&my_con);
					   break;
		}
		case Search:
		{
					   SearchComunicator(&my_con);
					   break;
		}
		case Modify:
		{
					   ModifyComunicator(&my_con);
					   break;
		}
		case Show:
		{
					 ShowComunicator(&my_con);
					 break;
		}
		case Empty:
		{
					  EmptyComunicator(&my_con);
					  break;
		}
		case Sort:
		{
					 SortComunicator(&my_con);
					 break;
		}
		case Exit:
		{
					 printf("将退出通讯录！\n");
					 printf("\n");
					 break;

		}
		default:
		{
				   printf("输入错误，请重新输入！\n");
				   printf("\n");
				   break;
		}
		}
	} while (input);
}



int main()
{
	Test();
	system("pause");
	return 0;
}

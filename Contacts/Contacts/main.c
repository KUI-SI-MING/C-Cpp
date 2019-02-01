#include "contacts.h"

//�˵�����
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
	int count = 0;
	struct PeoIfn data[MAX_NUM] = { 0 };
	do
	{
		Menu();
		printf("\n");
		printf("���������ѡ��:>");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case Add:
		{

					count++;
					AddComunicator(data, count);
					break;
		}
		case Delete:
		{
					   DeleteComunicator(data, count);
					   count--;
					   break;
		}
		case Search:
		{
					   SearchComunicator(data, count);
					   break;
		}
		case Modify:
		{
					   ModifyComunicator(data, count);
					   break;
		}
		case Show:
		{
					 ShowComunicator(data, count);
					 break;
		}
		case Empty:
		{
					  EmptyComunicator(data, count);
					  count = 0;
					  break;
		}
		case Sort:
		{
					 SortComunicator(data, count);
					 break;
		}
		case Exit:
		{
					 printf("���˳�ͨѶ¼��\n");
					 printf("\n");
					 break;

		}
		default:
		{
				   printf("����������������룡\n");
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
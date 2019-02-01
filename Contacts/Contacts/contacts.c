#include "contacts.h"
int Sname = 0;


//AddComunicator函数
void AddComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	int i = cou - 1;
	if (cou == MAX_NUM)
	{
		printf("该通讯录已满！无法存储！");
		return;
	}
	printf("请输入姓名：  ");
	scanf("%s", &data[i].name);
	printf("\n");
	printf("请输入年龄：  ");
	scanf("%d", &data[i].age);
	printf("\n");
	printf("请输入性别：  ");
	scanf("%s", &data[i].sex);
	printf("\n");
	printf("请输入地址：  ");
	scanf("%s", &data[i].add);
	printf("\n");
	printf("请输入电话：  ");
	scanf("%s", &data[i].phone);
	printf("\n");
	printf("添加成功\n");
	printf("\n");
}


//ShowComunicator函数
void ShowComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	if (cou == 0)
	{
		printf("通讯录为空！\n");
		printf("\n");
		return;
	}
	int i = 0;
	printf("***********************************************************************\n");
	printf("姓名\t\t年龄\t\t性别\t\t地址\t\t电话\t\t");
	printf("\n");
	for (i = 0; i < cou; i++)
	{
		printf("%s\t\t%d\t\t%s\t\t%s\t\t%s\t\t", data[i].name, data[i].age, data[i].sex, data[i].add, data[i].phone);
		printf("\n");
	}
	printf("***********************************************************************\n");
	printf("\n");
}


//搜寻单人信息
void SearchOne(struct PeoIfn data[], int cou)
{
	int i = 0;
	char str[10] = "0";
	printf("请输入您寻找的姓名： ");
	scanf("%s", str);
	printf("\n");
	for (i = 0; i < cou; i++)
	{

		if ((strcmp(str, data[i].name)) == 0)
		{
			Sname = i;
			return;


		}
	}
	printf("对不起！您的通讯录中没有 %s 的信息.\n", str);
	printf("\n");
}

//寻找函数
void SearchComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	SearchOne(data, cou);
	int s = Sname;
	printf("***********************************************************************\n");
	printf("姓名\t\t年龄\t\t性别\t\t地址\t\t电话\t\t");
	printf("\n");
	printf("%s\t\t%d\t\t%s\t\t%s\t\t%s\t\t", data[s].name, data[s].age, data[s].sex, data[s].add, data[s].phone);
	printf("***********************************************************************\n");
	printf("\n");
}

//修改函数
void  ModifyComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	SearchComunicator(data, cou);//找到你想修改的人的信息
	int pos = Sname;
	printf("请输入姓名： ");
	scanf("%s", data[pos].name);
	printf("\n");
	printf("请输入年龄： ");
	scanf("%d", &data[pos].age);
	printf("\n");
	printf("请输入性别： ");
	scanf("%s", data[pos].sex);
	printf("\n");
	printf("请输入地址： ");
	scanf("%s", data[pos].add);
	printf("\n");
	printf("请输入电话： ");
	scanf("%s", data[pos].phone);
	printf("\n");
	printf("修改完成\n");
	printf("\n");
}


//删除函数
void DeleteComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	SearchComunicator(data, cou);//找到你想删除的人的信息
	int pos = Sname;
	int i = 0;
	for (i = pos; i < cou - 1; i++)//可以删除最后一个元素之前的所有元素
	{
		data[i] = data[i + 1];
	}
	printf("删除成功！\n");
	printf("\n");
}

//清空函数
void EmptyComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	int i = 0;
	struct PeoIfn tmp = { 0 };
	for (i = 0; i < cou; i++)
	{
		data[i] = tmp;
	}
	printf("通讯录清空成功！\n");
	printf("\n");
}


int cmp(const void*a, const void*b)

{

	return *(int*)a - *(int*)b;

}

//排序函数
void SortComunicator(struct PeiIfn data[], int cou)
{
	system("cls");
	if (0 == cou)
	{
		printf("通讯录为空！无法排序！\n");
		printf("\n");
		return;
	}
	qsort(data, cou, sizeof(struct PeoIfn), cmp);//快速排序时注意元素起始位置，结构体的存储方式第一个即姓名
	printf("排序成功！\n");
	printf("\n");
}
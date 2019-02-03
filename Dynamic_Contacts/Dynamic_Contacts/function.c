#include "DynamicContacts.h"

void InitContact(pContact Con)
{
	assert(Con != NULL);
	Con->data = malloc(DEFAULT_SZ * sizeof(PeoIfo));
	if (Con->data == NULL)
	{
		perror("use malloc");
		exit(EXIT_FAILURE);
	}
	memset(Con->data, 0, DEFAULT_SZ * sizeof(PeoIfo));
	Con->sz = 0;
	Con->capacity = DEFAULT_SZ;
}
void CheckCapacity(pContact Con)
{
	assert(Con != NULL);
	if (Con->sz == Con->capacity)
	{
		PeoIfo* p = (PeoIfo*)realloc(Con->data, (Con->capacity + 2) * sizeof(PeoIfo));//疑问：为什么要用capacity + 2 来控制个数当我用DEFAULT_SZ时显示了断点
		if (p != NULL)
		{
			Con->data = p;
			Con->capacity += 2;
			printf("扩容成功！\n");
			printf("\n");
		}
	}
}

void AddComunicator(pContact Con)
{
	assert(Con != NULL);
	system("cls");
	CheckCapacity(Con);
	printf("请输入姓名：  ");
	scanf("%s", Con->data[Con->sz].name);
	printf("\n");
	printf("请输入年龄：  ");
	scanf("%d", &Con->data[Con->sz].age);
	printf("\n");
	printf("请输入性别：  ");
	scanf("%s", Con->data[Con->sz].sex);
	printf("\n");
	printf("请输入地址：  ");
	scanf("%s", Con->data[Con->sz].add);
	printf("\n");
	printf("请输入电话：  ");
	scanf("%s", Con->data[Con->sz].phone);
	printf("\n");
	printf("添加成功\n");
	Con->sz++;
	printf("\n");
}

void ShowComunicator(pContact Con)
{
	assert(Con != NULL);
	system("cls");
	if (Con->sz == 0)
	{
		printf("通讯录为空！\n");
		printf("\n");
		return;
	}
	unsigned int i = 0;
	printf("***********************************************************************\n");
	printf("姓名\t\t年龄\t\t性别\t\t地址\t\t电话\t\t");
	printf("\n");
	for (i = 0; i < Con->sz; i++)
	{
		printf("%s\t\t%d\t\t%s\t\t%s\t\t%s\t\t", Con->data[i].name, Con->data[i].age, Con->data[i].sex, Con->data[i].add, Con->data[i].phone);
		printf("\n");
	}
	printf("***********************************************************************\n");
	printf("\n");
}

int  SearchComunicator(pContact Con)
{
	assert(Con != NULL);
	system("cls");
	char str[10] = "0";
	unsigned int i = 0;

	printf("请输入您寻找的姓名： ");
	scanf("%s", str);
	printf("\n");
	for (i = 0; i < Con->sz; i++)
	{
		if ((strcmp(str, Con->data[i].name)) == 0)
		{
			printf("***********************************************************************\n");
			printf("姓名\t\t年龄\t\t性别\t\t地址\t\t电话\t\t");
			printf("\n");
			printf("%s\t\t%d\t\t%s\t\t%s\t\t%s\t\t", Con->data[i].name, Con->data[i].age, Con->data[i].sex, Con->data[i].add, Con->data[i].phone);
			printf("***********************************************************************\n");
			printf("\n");
			return i;
		}
	}
	printf("对不起！您的通讯录中没有 %s 的信息.\n", str);
	printf("\n");
	return -1;
}
void ModifyComunicator(pContact Con)
{
	assert(Con != NULL);
	int pos = 0;
	system("cls");
	pos = SearchComunicator(Con);
	if (pos == -1)
	{
		return;
	}
	printf("请输入修改后的名字：");
	scanf("%s", Con->data[pos].name);
	printf("\n");
	printf("请输入修改后的年龄：");
	scanf("%d", &Con->data[pos].age);
	printf("\n");
	printf("请输入修改后的性别：");
	scanf("%s", Con->data[pos].sex);
	printf("\n");
	printf("请输入修改后的地址：");
	scanf("%s", Con->data[pos].add);
	printf("\n");
	printf("请输入修改后的电话：");
	scanf("%s", Con->data[pos].phone);
	printf("\n");
	printf("修改成功！\n");
	printf("\n");
}

void DeleteComunicator(pContact Con)
{
	assert(Con != NULL);
	system("cls");
	int pos = 0;
	pos = SearchComunicator(Con);
	if (pos == -1)
	{
		return;
	}
	else
	{
		Con->data[pos] = Con->data[Con->sz - 1];
		Con->sz--;
		printf("删除成功！\n");
		printf("\n");
	}
}

void EmptyComunicator(pContact Con)
{
	assert(Con != NULL);
	system("cls");
	Con->sz = 0;
	printf("通讯录已清空！\n");
	printf("\n");
}

int cmp(const void*a, const void*b)

{

	return *(int*)a - *(int*)b;

}

void my_namesort(pContact Con)
{
	assert(Con != NULL);
	unsigned int i = 0;
	unsigned int j = 0;
	for (i = 0; i < Con->sz; i++)
	{
		for (j = 0; j < Con->sz - 1 - i; j++)
		{
			if (strcmp((Con->data[j]).name, (Con->data[j + 1]).name) > 0)
			{
				PeoIfo tmp = Con->data[j];
				Con->data[j] = Con->data[j + 1];
				Con->data[j + 1] = tmp;
			}
		}
	}
}

void my_numbersort(pContact Con)
{
	assert(Con != NULL);
	unsigned int i = 0;
	unsigned int j = 0;
	for (i = 0; i < Con->sz; i++)
	{
		for (j = 0; j < Con->sz - 1 - i; j++)
		{
			if ((Con->data[j]).age >(Con->data[j + 1]).age)
			{
				PeoIfo tmp = Con->data[j];
				Con->data[j] = Con->data[j + 1];
				Con->data[j + 1] = tmp;
			}
		}
	}
}
void SortComunicator(pContact Con)
{
	assert(Con != NULL);
	system("cls");
	int input = 0;
	printf("*******************************************\n");
	printf("************1、按姓名排序******************\n");
	printf("************             ******************\n");
	printf("************             ******************\n");
	printf("************2、按年龄排序******************\n");
	printf("*******************************************\n");
	do
	{
		printf("请输入你的选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
				  my_namesort(Con);
				  printf("\n");
				  printf("排序成功！\n");
				  printf("\n");
				  return;
		}
		case 2:
		{
				  my_numbersort(Con);
				  printf("\n");
				  printf("排序成功！\n");
				  printf("\n");
				  return;
		}
		default:
		{
				   printf("输入错误！请重新输入！\n");
				   break;
		}
		}
	} while (input);
}
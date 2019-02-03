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
		PeoIfo* p = (PeoIfo*)realloc(Con->data, (Con->capacity + 2) * sizeof(PeoIfo));//���ʣ�ΪʲôҪ��capacity + 2 �����Ƹ���������DEFAULT_SZʱ��ʾ�˶ϵ�
		if (p != NULL)
		{
			Con->data = p;
			Con->capacity += 2;
			printf("���ݳɹ���\n");
			printf("\n");
		}
	}
}

void AddComunicator(pContact Con)
{
	assert(Con != NULL);
	system("cls");
	CheckCapacity(Con);
	printf("������������  ");
	scanf("%s", Con->data[Con->sz].name);
	printf("\n");
	printf("���������䣺  ");
	scanf("%d", &Con->data[Con->sz].age);
	printf("\n");
	printf("�������Ա�  ");
	scanf("%s", Con->data[Con->sz].sex);
	printf("\n");
	printf("�������ַ��  ");
	scanf("%s", Con->data[Con->sz].add);
	printf("\n");
	printf("������绰��  ");
	scanf("%s", Con->data[Con->sz].phone);
	printf("\n");
	printf("��ӳɹ�\n");
	Con->sz++;
	printf("\n");
}

void ShowComunicator(pContact Con)
{
	assert(Con != NULL);
	system("cls");
	if (Con->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		printf("\n");
		return;
	}
	unsigned int i = 0;
	printf("***********************************************************************\n");
	printf("����\t\t����\t\t�Ա�\t\t��ַ\t\t�绰\t\t");
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

	printf("��������Ѱ�ҵ������� ");
	scanf("%s", str);
	printf("\n");
	for (i = 0; i < Con->sz; i++)
	{
		if ((strcmp(str, Con->data[i].name)) == 0)
		{
			printf("***********************************************************************\n");
			printf("����\t\t����\t\t�Ա�\t\t��ַ\t\t�绰\t\t");
			printf("\n");
			printf("%s\t\t%d\t\t%s\t\t%s\t\t%s\t\t", Con->data[i].name, Con->data[i].age, Con->data[i].sex, Con->data[i].add, Con->data[i].phone);
			printf("***********************************************************************\n");
			printf("\n");
			return i;
		}
	}
	printf("�Բ�������ͨѶ¼��û�� %s ����Ϣ.\n", str);
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
	printf("�������޸ĺ�����֣�");
	scanf("%s", Con->data[pos].name);
	printf("\n");
	printf("�������޸ĺ�����䣺");
	scanf("%d", &Con->data[pos].age);
	printf("\n");
	printf("�������޸ĺ���Ա�");
	scanf("%s", Con->data[pos].sex);
	printf("\n");
	printf("�������޸ĺ�ĵ�ַ��");
	scanf("%s", Con->data[pos].add);
	printf("\n");
	printf("�������޸ĺ�ĵ绰��");
	scanf("%s", Con->data[pos].phone);
	printf("\n");
	printf("�޸ĳɹ���\n");
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
		printf("ɾ���ɹ���\n");
		printf("\n");
	}
}

void EmptyComunicator(pContact Con)
{
	assert(Con != NULL);
	system("cls");
	Con->sz = 0;
	printf("ͨѶ¼����գ�\n");
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
	printf("************1������������******************\n");
	printf("************             ******************\n");
	printf("************             ******************\n");
	printf("************2������������******************\n");
	printf("*******************************************\n");
	do
	{
		printf("���������ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
				  my_namesort(Con);
				  printf("\n");
				  printf("����ɹ���\n");
				  printf("\n");
				  return;
		}
		case 2:
		{
				  my_numbersort(Con);
				  printf("\n");
				  printf("����ɹ���\n");
				  printf("\n");
				  return;
		}
		default:
		{
				   printf("����������������룡\n");
				   break;
		}
		}
	} while (input);
}
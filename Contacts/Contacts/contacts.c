#include "contacts.h"
int Sname = 0;


//AddComunicator����
void AddComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	int i = cou - 1;
	if (cou == MAX_NUM)
	{
		printf("��ͨѶ¼�������޷��洢��");
		return;
	}
	printf("������������  ");
	scanf("%s", &data[i].name);
	printf("\n");
	printf("���������䣺  ");
	scanf("%d", &data[i].age);
	printf("\n");
	printf("�������Ա�  ");
	scanf("%s", &data[i].sex);
	printf("\n");
	printf("�������ַ��  ");
	scanf("%s", &data[i].add);
	printf("\n");
	printf("������绰��  ");
	scanf("%s", &data[i].phone);
	printf("\n");
	printf("��ӳɹ�\n");
	printf("\n");
}


//ShowComunicator����
void ShowComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	if (cou == 0)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		printf("\n");
		return;
	}
	int i = 0;
	printf("***********************************************************************\n");
	printf("����\t\t����\t\t�Ա�\t\t��ַ\t\t�绰\t\t");
	printf("\n");
	for (i = 0; i < cou; i++)
	{
		printf("%s\t\t%d\t\t%s\t\t%s\t\t%s\t\t", data[i].name, data[i].age, data[i].sex, data[i].add, data[i].phone);
		printf("\n");
	}
	printf("***********************************************************************\n");
	printf("\n");
}


//��Ѱ������Ϣ
void SearchOne(struct PeoIfn data[], int cou)
{
	int i = 0;
	char str[10] = "0";
	printf("��������Ѱ�ҵ������� ");
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
	printf("�Բ�������ͨѶ¼��û�� %s ����Ϣ.\n", str);
	printf("\n");
}

//Ѱ�Һ���
void SearchComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	SearchOne(data, cou);
	int s = Sname;
	printf("***********************************************************************\n");
	printf("����\t\t����\t\t�Ա�\t\t��ַ\t\t�绰\t\t");
	printf("\n");
	printf("%s\t\t%d\t\t%s\t\t%s\t\t%s\t\t", data[s].name, data[s].age, data[s].sex, data[s].add, data[s].phone);
	printf("***********************************************************************\n");
	printf("\n");
}

//�޸ĺ���
void  ModifyComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	SearchComunicator(data, cou);//�ҵ������޸ĵ��˵���Ϣ
	int pos = Sname;
	printf("������������ ");
	scanf("%s", data[pos].name);
	printf("\n");
	printf("���������䣺 ");
	scanf("%d", &data[pos].age);
	printf("\n");
	printf("�������Ա� ");
	scanf("%s", data[pos].sex);
	printf("\n");
	printf("�������ַ�� ");
	scanf("%s", data[pos].add);
	printf("\n");
	printf("������绰�� ");
	scanf("%s", data[pos].phone);
	printf("\n");
	printf("�޸����\n");
	printf("\n");
}


//ɾ������
void DeleteComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	SearchComunicator(data, cou);//�ҵ�����ɾ�����˵���Ϣ
	int pos = Sname;
	int i = 0;
	for (i = pos; i < cou - 1; i++)//����ɾ�����һ��Ԫ��֮ǰ������Ԫ��
	{
		data[i] = data[i + 1];
	}
	printf("ɾ���ɹ���\n");
	printf("\n");
}

//��պ���
void EmptyComunicator(struct PeoIfn data[], int cou)
{
	system("cls");
	int i = 0;
	struct PeoIfn tmp = { 0 };
	for (i = 0; i < cou; i++)
	{
		data[i] = tmp;
	}
	printf("ͨѶ¼��ճɹ���\n");
	printf("\n");
}


int cmp(const void*a, const void*b)

{

	return *(int*)a - *(int*)b;

}

//������
void SortComunicator(struct PeiIfn data[], int cou)
{
	system("cls");
	if (0 == cou)
	{
		printf("ͨѶ¼Ϊ�գ��޷�����\n");
		printf("\n");
		return;
	}
	qsort(data, cou, sizeof(struct PeoIfn), cmp);//��������ʱע��Ԫ����ʼλ�ã��ṹ��Ĵ洢��ʽ��һ��������
	printf("����ɹ���\n");
	printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

//1.ʹ��main�����Ĳ�����ʵ��һ��������������������Խ���������������һ�������� - a��ѡ��ִ�мӷ����� - s��ѡ��ִ�м������� - m��ѡ��ִ�г˷����� - d��ѡ��ִ�г�����
//������������Ϊ��������
//
//���磺�����в������룺test.exe - a 1 2
//ִ��1 + 2���3
//

int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)

{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}

int main(int argc, char *argv[], char *envp[])
{
	int x = 0;
	int y = 0;
	int ret = 0;
	if (argc != 4)
	{
		printf("��������\n");
		system("pause");
		return 0;
	}
	x = atoi(argv[2]);
	y = atoi(argv[3]);
	switch (*(argv[1] + 1))
	{
	case'a':
	{
			   ret = Add(x, y);
			   break;
	}
	case's':
	{
			   ret = Sub(x, y);
			   break;
	}
	case'm':
	{
			   ret = Mul(x, y);
			   break;
	}
	case'd':
	{
			   ret = Div(x, y);
			   break;
	}
	default:
	{
			   printf("�ڶ�������������\n");
			   break;
	}
	}
	printf("%d \n", ret);
	system("pause");
	return 0;
}

//2.дð����������������ַ�����

void bubble_sort_str(char *str[], int sz)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (strcmp(*(str + j), *(str + j + 1))>0)
			{
				char *tmp = *(str + j);
				*(str + j) = *(str + j + 1);
				*(str + j + 1) = tmp;
			}
		}
	}
}
int main()
{
	int i = 0;
	char *str[] = { "cccc", "bbbb", "dddd", "aaaa" };
	bubble_sort_str(str, sizeof(str) / sizeof(*str));
	for (i = 0; i < sizeof(str) / sizeof(*str); i++)
	{
		printf("%s ", *(str + i));
	}
	printf("\n");
	system("pause");
	return 0;
}
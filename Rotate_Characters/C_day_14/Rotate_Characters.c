#include <stdio.h>
#include <stdlib.h>

//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

void spin(char str[], int right, int k)
{
	char tmp;
	int i = 0;

	while(k--)
	{
		tmp = str[0];
		for (i = 0; i < right; i++)
		{
			str[i] = str[i + 1];
		}
		str[right] = tmp;
	}
}

int main()
{
	char str[] = { 'A', 'B', 'C', 'D' };
	int  k = 0;
	int sz = sizeof(str) / sizeof(str[0]);
	int i = 0;

	printf("ԭ�ַ�Ϊ:");
	for (i = 0; i < sz; i++)
	{
		printf("%c ", str[i]);
	}
	printf("\n");
	printf("�����뷭ת����k:");
	scanf("%d", &k);
	spin(str, sz - 1, k);
	printf("����k��%d���ַ���Ϊ:", k);
	for (i = 0; i < sz; i++)
	{
		printf("%c ", str[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 �� AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.


//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC

void left_spin(char str[], int right, int k)
{
	char tmp;
	int i = 0;

	tmp = str[0];
	for (i = 0; i < right; i++)
	{
		str[i] = str[i + 1];
	}
	str[right - 1] = tmp;
}

void right_spin(char str[], int right, int k)
{
	char tmp;
	int i = 0;

	tmp = str[right - 1];
	for (i = right - 1; i >= 0; i--)
	{
		str[i] = str[i - 1];
	}
	str[0] = tmp;
}

int Strcmp(char str1[],char str2[], int sz)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < sz; i++)
	{
		if (str1[i] == str2[i])
			count++;
	}
	if (sz == count)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//int main()
//{
//	char str1[5] ;
//	char str2[5] ;
//	int i = 0;
//	int count = 0;
//
//	printf("����������str1��");
//	scanf("%s", str1);
//	printf("\n");
//	printf("\n");
//	printf("����������str2��");
//	scanf("%s", str2);
//	printf("\n");
//	printf("\n");
//
//	if (Strcmp(str1, str2, 5) == 1)
//	{
//		printf("����ԭ������ͬ\n");
//	}
//	for (i = 0; i < 5; i++)
//	{
//		if (Strcmp(str1, str2, 5) == 1)
//		{
//			printf("���� ��1    ���� %d ����ת�������\n", count);
//			break;
//		}
//		else
//		{
//			left_spin(str2, 5, 1);
//			count++;
//		}
//		 if (4 == i)
//		 printf("���� ��0    ���������ת���߶�������ȣ�\n");
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
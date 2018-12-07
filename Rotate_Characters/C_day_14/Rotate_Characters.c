#include <stdio.h>
#include <stdlib.h>

//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

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

	printf("原字符为:");
	for (i = 0; i < sz; i++)
	{
		printf("%c ", str[i]);
	}
	printf("\n");
	printf("请输入翻转个数k:");
	scanf("%d", &k);
	spin(str, sz - 1, k);
	printf("左旋k：%d个字符后为:", k);
	for (i = 0; i < sz; i++)
	{
		printf("%c ", str[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

//2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.


//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//
//AABCD右旋一个字符得到DAABC

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
//	printf("请输入数组str1：");
//	scanf("%s", str1);
//	printf("\n");
//	printf("\n");
//	printf("请输入数组str2：");
//	scanf("%s", str2);
//	printf("\n");
//	printf("\n");
//
//	if (Strcmp(str1, str2, 5) == 1)
//	{
//		printf("两者原本就相同\n");
//	}
//	for (i = 0; i < 5; i++)
//	{
//		if (Strcmp(str1, str2, 5) == 1)
//		{
//			printf("返回 ：1    经过 %d 次旋转两者相等\n", count);
//			break;
//		}
//		else
//		{
//			left_spin(str2, 5, 1);
//			count++;
//		}
//		 if (4 == i)
//		 printf("返回 ：0    无论如何旋转两者都不会相等！\n");
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
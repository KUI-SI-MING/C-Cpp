#include <stdio.h>
#include <stdlib.h>

//1.使用main函数的参数，实现一个整数计算器，程序可以接受三个参数，第一个参数“ - a”选项执行加法，“ - s”选项执行减法，“ - m”选项执行乘法，“ - d”选项执行除法，
//后面两个参数为操作数。
//
//例如：命令行参数输入：test.exe - a 1 2
//执行1 + 2输出3
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
		printf("参数有误\n");
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
			   printf("第二个参数有问题\n");
			   break;
	}
	}
	printf("%d \n", ret);
	system("pause");
	return 0;
}

//2.写冒泡排序可以排序多个字符串。

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
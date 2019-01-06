#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <assert.h>

/////////////////////////////////////////////////////////////
////使用可变参数，实现函数，求函数参数的平均值。
//int Average(int n, ...)
//{
//	va_list arg;
//	int i = 0;
//	int sum = 0;
//	va_start(arg, n);
//	for (i = 0; i < n; i++)
//	{
//		sum += va_arg(arg, int);
//	}
//	va_end(arg);
//	return sum / n;
//
//}
//
//int main()
//{
//	int a = 1;
//	int b = 5;
//	int c = 4;
//	int ave1 = Average(2, a, b);
//	int ave2 = Average(3, a, b, c);
//	printf("(%d + %d) / 2 = %d\n", a, b, ave1);
//	printf("(%d + %d + %d) / 3 = %d\n", a, b, c, ave2);
//	system("pause");
//	return 0;
//}

/////////////////////////////////////////////////////
//使用可变参数，实现函数，求函数参数的最大值。
//int max(int n, ...)
//{
//	va_list arg;
//	int i = 0;
//	int tmp = 0;
//	va_start(arg, n);//arg指向了a
//	for (i = 0; i < n; i++)
//	{
//		int mil = va_arg(arg, int);//arg取出了a且指向了b
//		if (tmp < mil)
//		{
//			tmp = mil;
//		}
//	}
//	va_end(arg);
//	return tmp;
//}
//int main()
//{
//	int a = 1;
//	int b = 5;
//	int c = 6;
//	int max = max(3, a, b, c);
//	printf("max = %d \n", max);
//	system("pause");
//	return 0;
//}


//4.1.模拟实现printf函数，可完成下面的功能
////完成下面函数的调用。 
////print("s ccc d.\n","hello",'b','i','t'，100); 
////函数原型： 
////print(char *format, ...) 
void print_int(int num)
{
	if (num > 9)
	{
		print_int(num / 10);
	}
	putchar(num % 10 + '0');
}


void print(const char *formest, ...)
{
	assert(formest != NULL);
	va_list arg;
	va_start(arg, formest);
	while (*formest)
	{
		switch (*formest)
		{
		case 's':
		{
					char *str = va_arg(arg, char*);
					while (*str)
					{
						putchar(*str);
						str++;
					}
		}
			break;
		case'c':
		{
				   char ch = va_arg(arg, char);
				   putchar(ch);
		}
			break;
		case'd':
		{
				   int ret = va_arg(arg, int);
				   print_int(ret);
		}
			break;
		default:
		{
				   putchar(*formest);
				   break;
		}
		}
		formest++;
	}
	va_end(arg);
}

int main()
{
	print("s ccc d.\n", "hello", 'k', 'u', 'i', 159);
	system("pause");
	return 0;
}
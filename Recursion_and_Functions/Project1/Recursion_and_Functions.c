#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//////////////////////////////////////////////////////////
//1.递归和非递归分别实现求第n个斐波那契数。
//非递归
int fun(int n)
{
	int a = 1;
	int b = 1;
	int c = 1;
	while (n > 2)
	{
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}

//递归
int rec(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	else
	{
		return rec(n - 1) + rec(n - 2);
	}
}

int main()
{
	int ret1 = 0;
	int ret2 = 0;
	int n = 0;
	printf("请输入整数n:");
	scanf("%d", &n);
	ret1 = fun(n);
	printf(" 第 %d 个斐波那契数列：%d \n", n, ret1);
	ret2 = rec(n);
	printf(" 第 %d 个斐波那契数列：%d \n", n, ret2);
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////
//2.编写一个函数实现n^k，使用递归实现
int rec(int n, int k)
{
	if (k == 1)
	{

		return n;
	}
	else
	{
		return n * rec(n, k - 1);
	}
}

int main()
{
	int ret = 0;
	int n = 0;
	int k = 0;
	printf("请输入整数 n 和 k :");
	scanf("%d%d", &n, &k);
	printf("\n");
	ret = rec(n, k);
	printf("%d 的 %d 次方为：%d \n", n, k, ret);
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////
//3写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和，例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
int DigitSum(n)
{
	if (n < 10)
	{
		return n;
	}
	else
	{
		return n % 10 + DigitSum(n / 10);
	}
}

int main()
{
	int ret = 0;
	int n = 0;
	printf("请输入整数 n :");
	scanf("%d0", &n);
	printf("\n");
	ret = DigitSum(n);
	printf(" %d 的各位数字之和为： %d \n", n, ret);
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////
//4. 编写一个函数reverse_string(char * string)（递归实现） 
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中
//的字符串操作函数。

void reverse_string(char * string)
{
	assert("NULL");
	if (*string != '\0')
	{
		reverse_string(string + 1);
		printf("%c", *(string));
	}
}
int main()
{
	char str[] = "abcdefghi";
	printf("源字符串 ：%s\n", str);
	printf("旋转之后: ");
	reverse_string(str);
	printf("\n");
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////
//5.递归和非递归分别实现strlen 
//非递归
int  FunStrlen(char *str)
{
	int count = 0;
	while (*(str++))
	{
		count++;
	}
	return count;
}

//递归
int RecStrlen(char *str)
{
	if (*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + RecStrlen(str + 1);
	}
}
int main()
{
	int len1 = 0;
	int len2 = 0;
	char str[] = "abcdefghi";

	printf("源字符串 ：%s\n", str);
	len1 = FunStrlen(str);
	len2 = RecStrlen(str);
	printf("字符串的长度是：%d\n", len1);
	printf("字符串的长度是：%d\n", len2);
	system("pause");
	return 0;
}

////////////////////////////////////////////////////
//6.递归和非递归分别实现求n的阶乘
//非递归
int  FunFactorial(int n)
{
	int ret = 1;
	while (n >= 1)
	{
		ret *= n;
		n--;
	}
	return ret;
}

//递归
int  RecFactorial(int n)
{
	if (1 == n)
	{
		return 1;
	}
	else
	{
		return  n *  RecFactorial(n - 1);
	}
}

int main()
{
	int n = 0;
	int ret1 = 0;
	int ret2 = 0;
	printf("请输入整数 n ：");
	scanf("%d", &n);
	ret1 = FunFactorial(n);
	ret2 = RecFactorial(n);
	printf(" %d 的阶乘为：%d\n", n, ret1);
	printf(" %d 的阶乘为：%d\n", n, ret2);
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////
//7.递归方式实现打印一个整数的每一位
void  Number(int n)
{
	if (n > 9)
	{
		Number(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int n = 0;
	printf("请输入整数 n ：");
	scanf("%d", &n);
	printf("\n %d 的各位为：", n);
	Number(n);
	printf("\n");
	system("pause");
	return 0;
}
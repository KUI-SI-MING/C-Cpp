#include <stdio.h>
#include <stdlib.h>
#include<math.h>

////////////////////////////////
4.编程实现：
两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
输入例子 :
1999 2299
输出例子 : 7
int main()
{
	int m = 0;
	int n = 0;
	int i = 0;
	int count = 0;
	printf("请输入两个整数：");
	scanf("%d%d", &m,&n);
	for (i = 0; i < 32; i++)
	{
		if (((m >> i) & 1 )!= ((n >> i) & 1))
			count++;
	}
	printf("%d 和 %d 一共有%d个数不同\n",m, n, count);
	system("pause");
	return 0;
}

//高配
int main()
{
	int m = 0;
	int n = 0;
	int i = 0;
	int count = 0;
	printf("请输入两个整数：");
	scanf("%d%d", &m,&n);
	i = m^n;
	while (i)
	{
		i = i&(i - 1);//数1的个数
		count++;
	}
	printf(" %d 和 %d 的二进制表达中一共有%d个数不同\n",m, n, count);
	system("pause");
	return 0;
}


/////////////////////////////////////
//2.输出一个整数的每一位。
int main()
{
		int  num = 0;
		int tmp = 0;
		printf("请输入一个整数：");
		scanf("%d", &num);
		num= abs(num);//取绝对值
		printf("该数的每一位分别为：");
		while ((num % 10) != 0)
		{
			tmp = num % 10;
			printf("[%d] ", tmp);
			num /= 10;
		}
		printf("\n");
	system("pause");
	return 0;
}

/////////////////////////////////////////////////////////
//2.获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
int main()
{
	int a = 0;
	int i = 0;
	int j = 0;
    int even[16] = { 0 };
	int odd[16] = { 0 };
	printf(" 请输入一个整数:");
	scanf("%d", &a);
	for (i=0,j=0; j < 32;i++,j+=2)//for（i=31;i>=0;i-=2）  printf("%d",a[i]=(a[i]&1));
	{
		even[16-1-i] = (a >> j) & 1;//倒序输入数组元素，整数的二进制由右向左读，输出时由右向左输出
	}
	for (i = 0, j = 1; j < 32; i++, j += 2)//for（i=30;i>=0;i-=2）  printf("%d",a[i]=(a[i]&1));简单高效
	{
		odd[16 - 1 - i] = (a >> j) & 1;
	}
	printf("偶数位的二进制序列为:");
	for (i = 0; i < 16; i++)
		printf("%d ", even[i]);
	printf("\n");
	printf("奇数位的二进制序列为:");
	for (i = 0; i < 16; i++)
  	printf("%d ",  odd[i]);

	printf("\n");
	system("pause");
	return 0;
}

///////////////////////////////////////
//1.写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
//}
//函数
//int count_one_bits(unsigned int value)
//{
//	int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (1 ==( (value >> i) & 1))
//			count++;
//	}
//	return count;
//}

//高配
int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		count++;
		value = value&(value - 1);//每运行一次，value二进制低位的1就减少一个直到value=0
	}
	return count;
}

int main()
{
	int count_one_bits(unsigned int value);
	int count = 0;
	int a = 0;
	printf(" 请输入一个整数:");
	scanf("%d", &a);
	count = count_one_bits(a);
	printf("[%d]中1的个数是[%d]个\n",a, count);
	system("pause");
	return 0;
}
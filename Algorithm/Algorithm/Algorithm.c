#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

////1.一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
////找出这两个数字，编程实现。
////
//
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 3, 4, 1 };
//	int num = 0;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int pos = 0;
//	int x = 0;
//	int y = 0;
//	for (i = 0; i < sz; i++)
//	{
//		num ^= arr[i];//把所有的数组元素按位异或num即2和5异或的结果
//	}
//     //2:...0 1 0
//	 //5:...1 0 1
//	//2^5...1 1 1
//	printf("num = %d\n",num);//num的二进制值为111，
//	for (i = 0; i < 32; i++)
//	{
//		if (1 == ((num >> i) & 1))//把num中的由低位到高位的第一个1的位数找出来
//		{
//			pos = i;
//			break;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)//根据取得1的位数把数组元素分成两类1，二进制POS位为1的，2，二进制pos位为0的
//		{
//			x ^= arr[i];//把5分到二进制低位为1的那一组且异或得出结果
//		}
//		y = x^ num;//5^(2^5)==2
//	}
//	printf("x = %d,y = %d\n",x, y);
//	system("pause");
//	return 0;
//}
//
//
//
////2.喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。
//bug:当钱数是偶数时可以解决问题，钱数是奇数存在bug
//int NumOfWat(int value)
//{
//	int a = value / 1;//汽水数
//	int b = a;//空瓶换的汽水数
//	int c = 0;//换完之后的空瓶数
//	int count = 0;
//	while (1)
//	{
//		b = b / 2;
//		if (((1 == b % 2) && (b != 1)) == 1)
//		{
//			c++;
//		}
//		a += b;
//		if ((1 == b) && (0 == c))
//		{
//			return a;
//		}
//		if (b == 1)
//		{
//			b += c;
//			c--;
//		}
//
//	}
//}
//
//
//int main()
//{
//	int price = 20;
//	int ret = NumOfWat(price);
//	printf(" 可以买 %d 瓶汽水\n", ret);
//	system("pause");
//	return 0;
//}


//3.模拟实现strcpy
//char *my_strcpy(char *target, const char *source)
//{
//	char *start = target;
//	assert(target != NULL);
//	assert(source != NULL);
//	while (*target++ = *source++)
//	{
//		;
//	}
//	return start;
//}
//
//char *my_strcat(char *target, const char *source)
//{
//	char *start = target;
//	assert(target != NULL);
//	assert(source != NULL);
//	while (*target)
//	{
//		target++;
//	}
//	while (*target++ = *source++)
//	{
//		;
//	}
//	return start;
//}
//int main()
//{
//	char str1[10] = "0";//防止越界产生
//	char str2[15] = "abcdef";
//	char str3[] = "ghijk";
//	printf("str1: %s \n", my_strcpy(str1, str2));
//	printf("str2: %s \n", my_strcat(str2, str3));
//	system("pause");
//	return 0;
//}


//4.模拟实现strcat


//5.模拟实现strlen

//方式一：设置计数器
//int my_strlen(const char * str)
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str)
//	{
//		str++;
//		count++;
//	}
//	return count;
//
//}

////不能创建临时变量计数器——递归
//int my_strlen(const char * str)
//{
//	assert(str != NULL);
//	
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(str + 1);
//}

//指针 — 指针 
int my_strlen(char *s)
{
	assert(s != NULL);

	char *p = s;
	while (*p != '\0')
	{
		p++;
	}
	return p - s;
}
int main()
{
	char str[] = "abcdef";

	printf(" %d \n", my_strlen(str));//6

	system("pause");
	return 0;
}

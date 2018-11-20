#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
//
//1.编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回 值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832


//1,位权相加
//unsigned int Reverse_Binary(unsigned int value)
//{
//	int i = 0, bytes_num = sizeof(int)* 8;
//	unsigned int sum = 0;
//	for (i = 0; i < bytes_num; i++)
//	{
//		sum += ((value >> i) & 1)*(unsigned int)pow(2, bytes_num - i - 1);
//	}
//	return sum;
//}


////2，位移
//unsigned int Reverse_Binary(unsigned int value)
//{
//	int i = 0, ret = 0;
//	for (i = 0; i < 32; i++)
//	{
//		ret <<= 1;//左移31位
//		ret |= ((value >> i) & 1);
//	}
//	return ret;
//}
//int main()
//{
//    int num = 25;
//	unsigned int ret=Reverse_Binary(num);
//	printf("转换后 num= [%u] [%x]\n", ret, ret);
//	system("pause");
//	return 0;
//}


////2.不使用（a + b） / 2这种方式，求两个数的平均值。
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//int average = a + (b - a) / 2;
//	int average = (a&b) + ((a^b) >> 1);//相同的位的平均值+不同的位的平均值（相同：1&1=1；0&0=0，不同的位>>1有除二的效果）
//	printf("平均值 average= %d\n", average);
//	system("pause");
//	return 0;
//}
//
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//int main()
//{
//	int arr[] = { 2, 3, 4, 5, 6, 4, 3, 2, 5 };
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		ret ^= arr[i];//a^b^a=b
//	}
//	printf("转换后 num= %d\n", ret);
//	system("pause");
//	return 0;
//}

//4.有一个字符数组的内容为:"student a am i", 请你将数组的内容改为"i am a student".
//			要求：
//			不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。

//int my_strlen(const char*str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//void SWAP_str(char *left, char *right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//	while (left < right)
//	{
//		 char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void SWAP(char *str)
//{
//    char  *cur = str;
//	char *left = str;
//    char *right = str+my_strlen(str)-1;
//	assert(str != NULL);
//	//交换整个字符串
//	SWAP_str(left, right);
//	//交换单词
//	while (*cur)
//	{
//		char *start = cur;
//		while ((*cur != ' ') && (*cur != '\0'))
//		{
//			cur++;
//		}
//		SWAP_str(start, cur - 1);
//		if (*cur == ' ')
//			cur++;
//	}
//}
//int main()
//{
//	char str[] =  "student a am i" ;
//	SWAP(str);
//	printf("转换后 str= %s\n",str);
//	system("pause");
//	return 0;
//}


//int my_strlen(const char*str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//
//void reverse_str(char *left, char*right)
//{
//	assert(left != NULL);
//	assert(right != NULL);
//
//	while (left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void reverse(char *str)
//{
//	char *cur = str;
//	char*left = str;
//	char*right = str + my_strlen(str) - 1;
//	assert(str != NULL);
//	//1. 逆序整个字符串
//	reverse_str(left, right);
//	//2. 逆序单词
//	while (*cur)
//	{
//		char *start = cur;
//		while ((*cur != ' ') && (*cur != '\0'))
//		{
//			cur++;
//		}
//		reverse_str(start, cur - 1);
//		if (*cur == ' ')
//			cur++;
//	}
//}
//int main()
//{
//	char arr[] = "student a am i";
//
//	//i am a student
//	//int ma a tneduts
//	reverse(arr);
//	printf("%s\n", arr);
//	system("pause");
//	return 0;
//}
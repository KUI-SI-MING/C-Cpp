#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
//
//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ��� ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832


//1,λȨ���
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


////2��λ��
//unsigned int Reverse_Binary(unsigned int value)
//{
//	int i = 0, ret = 0;
//	for (i = 0; i < 32; i++)
//	{
//		ret <<= 1;//����31λ
//		ret |= ((value >> i) & 1);
//	}
//	return ret;
//}
//int main()
//{
//    int num = 25;
//	unsigned int ret=Reverse_Binary(num);
//	printf("ת���� num= [%u] [%x]\n", ret, ret);
//	system("pause");
//	return 0;
//}


////2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//int main()
//{
//	int a = 10;
//	int b = 20;
//	//int average = a + (b - a) / 2;
//	int average = (a&b) + ((a^b) >> 1);//��ͬ��λ��ƽ��ֵ+��ͬ��λ��ƽ��ֵ����ͬ��1&1=1��0&0=0����ͬ��λ>>1�г�����Ч����
//	printf("ƽ��ֵ average= %d\n", average);
//	system("pause");
//	return 0;
//}
//
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//int main()
//{
//	int arr[] = { 2, 3, 4, 5, 6, 4, 3, 2, 5 };
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//	{
//		ret ^= arr[i];//a^b^a=b
//	}
//	printf("ת���� num= %d\n", ret);
//	system("pause");
//	return 0;
//}

//4.��һ���ַ����������Ϊ:"student a am i", ���㽫��������ݸ�Ϊ"i am a student".
//			Ҫ��
//			����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

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
//	//���������ַ���
//	SWAP_str(left, right);
//	//��������
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
//	printf("ת���� str= %s\n",str);
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
//	//1. ���������ַ���
//	reverse_str(left, right);
//	//2. ���򵥴�
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
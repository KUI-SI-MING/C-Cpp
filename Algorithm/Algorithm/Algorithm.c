#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

////1.һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
////�ҳ����������֣����ʵ�֡�
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
//		num ^= arr[i];//�����е�����Ԫ�ذ�λ���num��2��5���Ľ��
//	}
//     //2:...0 1 0
//	 //5:...1 0 1
//	//2^5...1 1 1
//	printf("num = %d\n",num);//num�Ķ�����ֵΪ111��
//	for (i = 0; i < 32; i++)
//	{
//		if (1 == ((num >> i) & 1))//��num�е��ɵ�λ����λ�ĵ�һ��1��λ���ҳ���
//		{
//			pos = i;
//			break;
//		}
//	}
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)//����ȡ��1��λ��������Ԫ�طֳ�����1��������POSλΪ1�ģ�2��������posλΪ0��
//		{
//			x ^= arr[i];//��5�ֵ������Ƶ�λΪ1����һ�������ó����
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
////2.����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�
//bug:��Ǯ����ż��ʱ���Խ�����⣬Ǯ������������bug
//int NumOfWat(int value)
//{
//	int a = value / 1;//��ˮ��
//	int b = a;//��ƿ������ˮ��
//	int c = 0;//����֮��Ŀ�ƿ��
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
//	printf(" ������ %d ƿ��ˮ\n", ret);
//	system("pause");
//	return 0;
//}


//3.ģ��ʵ��strcpy
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
//	char str1[10] = "0";//��ֹԽ�����
//	char str2[15] = "abcdef";
//	char str3[] = "ghijk";
//	printf("str1: %s \n", my_strcpy(str1, str2));
//	printf("str2: %s \n", my_strcat(str2, str3));
//	system("pause");
//	return 0;
//}


//4.ģ��ʵ��strcat


//5.ģ��ʵ��strlen

//��ʽһ�����ü�����
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

////���ܴ�����ʱ���������������ݹ�
//int my_strlen(const char * str)
//{
//	assert(str != NULL);
//	
//	if (*str == '\0')
//		return 0;
//	else
//		return 1 + my_strlen(str + 1);
//}

//ָ�� �� ָ�� 
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

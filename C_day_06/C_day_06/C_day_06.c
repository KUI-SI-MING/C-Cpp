#include <stdio.h>
#include <stdlib.h>
#include<math.h>

////////////////////////////////
4.���ʵ�֣�
����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
�������� :
1999 2299
������� : 7
int main()
{
	int m = 0;
	int n = 0;
	int i = 0;
	int count = 0;
	printf("����������������");
	scanf("%d%d", &m,&n);
	for (i = 0; i < 32; i++)
	{
		if (((m >> i) & 1 )!= ((n >> i) & 1))
			count++;
	}
	printf("%d �� %d һ����%d������ͬ\n",m, n, count);
	system("pause");
	return 0;
}

//����
int main()
{
	int m = 0;
	int n = 0;
	int i = 0;
	int count = 0;
	printf("����������������");
	scanf("%d%d", &m,&n);
	i = m^n;
	while (i)
	{
		i = i&(i - 1);//��1�ĸ���
		count++;
	}
	printf(" %d �� %d �Ķ����Ʊ����һ����%d������ͬ\n",m, n, count);
	system("pause");
	return 0;
}


/////////////////////////////////////
//2.���һ��������ÿһλ��
int main()
{
		int  num = 0;
		int tmp = 0;
		printf("������һ��������");
		scanf("%d", &num);
		num= abs(num);//ȡ����ֵ
		printf("������ÿһλ�ֱ�Ϊ��");
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
//2.��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�
int main()
{
	int a = 0;
	int i = 0;
	int j = 0;
    int even[16] = { 0 };
	int odd[16] = { 0 };
	printf(" ������һ������:");
	scanf("%d", &a);
	for (i=0,j=0; j < 32;i++,j+=2)//for��i=31;i>=0;i-=2��  printf("%d",a[i]=(a[i]&1));
	{
		even[16-1-i] = (a >> j) & 1;//������������Ԫ�أ������Ķ�������������������ʱ�����������
	}
	for (i = 0, j = 1; j < 32; i++, j += 2)//for��i=30;i>=0;i-=2��  printf("%d",a[i]=(a[i]&1));�򵥸�Ч
	{
		odd[16 - 1 - i] = (a >> j) & 1;
	}
	printf("ż��λ�Ķ���������Ϊ:");
	for (i = 0; i < 16; i++)
		printf("%d ", even[i]);
	printf("\n");
	printf("����λ�Ķ���������Ϊ:");
	for (i = 0; i < 16; i++)
  	printf("%d ",  odd[i]);

	printf("\n");
	system("pause");
	return 0;
}

///////////////////////////////////////
//1.дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
//int count_one_bits(unsigned int value)
//{
//	// ���� 1��λ�� 
//}
//����
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

//����
int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value)
	{
		count++;
		value = value&(value - 1);//ÿ����һ�Σ�value�����Ƶ�λ��1�ͼ���һ��ֱ��value=0
	}
	return count;
}

int main()
{
	int count_one_bits(unsigned int value);
	int count = 0;
	int a = 0;
	printf(" ������һ������:");
	scanf("%d", &a);
	count = count_one_bits(a);
	printf("[%d]��1�ĸ�����[%d]��\n",a, count);
	system("pause");
	return 0;
}
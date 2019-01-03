#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//////////////////////////////////////////////////////////
//1.�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲���������
//�ǵݹ�
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

//�ݹ�
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
	printf("����������n:");
	scanf("%d", &n);
	ret1 = fun(n);
	printf(" �� %d ��쳲��������У�%d \n", n, ret1);
	ret2 = rec(n);
	printf(" �� %d ��쳲��������У�%d \n", n, ret2);
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////
//2.��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
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
	printf("���������� n �� k :");
	scanf("%d%d", &n, &k);
	printf("\n");
	ret = rec(n, k);
	printf("%d �� %d �η�Ϊ��%d \n", n, k, ret);
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////
//3дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�ͣ����磬����DigitSum(1729)����Ӧ�÷���1 + 7 + 2 + 9�����ĺ���19
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
	printf("���������� n :");
	scanf("%d0", &n);
	printf("\n");
	ret = DigitSum(n);
	printf(" %d �ĸ�λ����֮��Ϊ�� %d \n", n, ret);
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////
//4. ��дһ������reverse_string(char * string)���ݹ�ʵ�֣� 
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C��������
//���ַ�������������

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
	printf("Դ�ַ��� ��%s\n", str);
	printf("��ת֮��: ");
	reverse_string(str);
	printf("\n");
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////////
//5.�ݹ�ͷǵݹ�ֱ�ʵ��strlen 
//�ǵݹ�
int  FunStrlen(char *str)
{
	int count = 0;
	while (*(str++))
	{
		count++;
	}
	return count;
}

//�ݹ�
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

	printf("Դ�ַ��� ��%s\n", str);
	len1 = FunStrlen(str);
	len2 = RecStrlen(str);
	printf("�ַ����ĳ����ǣ�%d\n", len1);
	printf("�ַ����ĳ����ǣ�%d\n", len2);
	system("pause");
	return 0;
}

////////////////////////////////////////////////////
//6.�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//�ǵݹ�
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

//�ݹ�
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
	printf("���������� n ��");
	scanf("%d", &n);
	ret1 = FunFactorial(n);
	ret2 = RecFactorial(n);
	printf(" %d �Ľ׳�Ϊ��%d\n", n, ret1);
	printf(" %d �Ľ׳�Ϊ��%d\n", n, ret2);
	system("pause");
	return 0;
}

//////////////////////////////////////////////////////
//7.�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
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
	printf("���������� n ��");
	scanf("%d", &n);
	printf("\n %d �ĸ�λΪ��", n);
	Number(n);
	printf("\n");
	system("pause");
	return 0;
}
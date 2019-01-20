#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//1.ʵ��strcpy
//2.ʵ��strcat




//3.ʵ��strstr
//char *my_strstr(const char *str1, const char *str2)
//{
//	assert(str1);
//	assert(str2);
//
//	char *cp = (char *)str1;
//	char *substr = (char *)str2;
//	char *s1 = NULL;
//
//	if (*str2 == '\0')
//	{
//		return NULL;
//	}
//	while (*cp)
//	{
//		s1 = cp;
//		substr = str2;
//		while (*s1 && *substr && (*s1 == *substr))
//		{
//			s1++;
//			substr++;
//		}
//		if (*substr == '\0')
//		{
//			return cp;
//		}
//		cp++;
//		if (*cp == '\0')
//			return NULL;
//	}
//}
//
//int main()
//{
//	const char str1[] = "abbbcccdefgh";
//	const char str2[] = "ghi";
//	char *ret = my_strstr(str1, str2);
//	if (ret == NULL)
//	{
//		printf(" str2 ���� str1 �����ַ���\n");
//	}
//	else
//	{
//		printf(" str2 �� atr1 �Ĵ� %d λ��ʼ�����ַ���\n",ret - str1+1);
//	}
//	system("pause");
//	return 0;
//}
//

//4.ʵ��strchr��strchr�Ǽ������һ��������ԭ��Ϊextern char *strchr(const char *s,char c)�����Բ����ַ���s���״γ����ַ�c��λ�á���
//char *my_strchr(const char *str, char c)
//{
//	assert(str != NULL);
//	while (*str)
//	{
//		if (*(str++) == c)//��ʵ�ʵ�ַ�����˺���++����
//		{
//			return str - 1;
//		}
//	}
//	return NULL;
//}
//
//
//int main()
//{
//	char str[] = "abcdefdgh";
//	char c = 'a';
//	char *p = my_strchr(str, c);
//	if (NULL == *p)
//	{
//		printf(" %s �ַ�����û�� %c �ַ�\n",str, c);
//	}
//	else
//	{
//		printf("%c �״γ����� %s ��λ���ǣ�%d \n",c, str, p - str  + 1);
//	}
//	system("pause");
//	return 0;
//}
//
////5.ʵ��strcmp
//
//int my_strcmp(const char *s1, const char *s2)
//{
//	assert(s1 != NULL);
//	assert(s2 != NULL);
//	int ret = 0;
//	while (!(ret = *(unsigned char *)s1 - *(unsigned char *)s2) && *s2)//�ã�����������ѭ�������Ƚϻ�Ϊ�����õ���ֵ����
//	{
//		++s1;
//		++s2;
//	}
//	if (ret < 0)
//	{
//		ret = -1;
//	}
//	else if (ret > 0)
//	{
//		ret = 1;
//	}
//	return ret;
//}
//int main()
//{
//	char str1[] = "cd";
//	char str2[] = "ab";
//	int i = my_strcmp(str1, str2);
//	if (0 == i)
//	{
//		printf("str1 :%s �� str2 :%s ���\n",str1, str2);
//	}
//	else if (0 < i)
//	{
//		printf("str1:%s ���� str2:%s \n",str1, str2);
//	}
//	else
//	{
//		printf("str1:%s С�� str2:%s \n", str1, str2);
//	}
//	system("pause");
//	return 0;
//}
////6.ʵ��memcpy(memcpyָ����c��c++ʹ�õ��ڴ濽��������memcpy�����Ĺ����Ǵ�Դsrc��ָ���ڴ��ַ����ʼλ�ÿ�ʼ����n���ֽڵ�Ŀ��dest��ָ���ڴ��ַ����ʼλ���С�)
//void *my_memcpy(void *dst, const void * src, size_t count)
//{
//	void *ret = dst;
//	while (count--)
//	{
//		*(char *)dst = *(char *)src;
//		dst = (char *)dst + 1;
//		src = (char *)src + 1;
//	}
//	return ret;
//}
//int main()
//{
//	char str1[10] = "abc";
//	char str2[] = "defgh";
//	char *ret = my_memcpy(str1, str2, 6);
//	printf("%s \n",ret);
//	system("pause");
//	return 0;
//}

//7.ʵ��memmove(memmove���ڴ�src����count���ֽڵ�dest�����Ŀ�������Դ�������ص��Ļ���
//memmove�ܹ���֤Դ���ڱ�����֮ǰ���ص�������ֽڿ�����Ŀ�������С������ƺ�src���ݻᱻ���ġ����ǵ�Ŀ��������Դ����û���ص����memcpy����������ͬ��)
void *my_memmove(void *dst, const void *src, size_t count)
{
	void *ret = dst;
	if (dst <= src || (char *)dst >= ((char *)src + count))
	{
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	else
	{
		dst = (char *)dst + count - 1;
		src = (char *)src + count - 1;
		while (count--)
		{
			*(char *)dst = *(char *)src;
			dst = (char *)dst + 1;
			src = (char *)src + 1;
		}
	}
	return ret;
}
int main()
{
	int a[7] = { 1, 2, 3, 4, 5, 6, 7 };
	int b[4] = { 5, 5, 5, 5 };
	int i = 0;
	int *ret = my_memmove(a + 1, b, 16);
	for (i = 0; i < 7; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}


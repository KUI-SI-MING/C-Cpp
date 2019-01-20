#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//1.实现strcpy
//2.实现strcat




//3.实现strstr
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
//		printf(" str2 不是 str1 的子字符串\n");
//	}
//	else
//	{
//		printf(" str2 是 atr1 的从 %d 位开始的子字符串\n",ret - str1+1);
//	}
//	system("pause");
//	return 0;
//}
//

//4.实现strchr（strchr是计算机的一个函数，原型为extern char *strchr(const char *s,char c)，可以查找字符串s中首次出现字符c的位置。）
//char *my_strchr(const char *str, char c)
//{
//	assert(str != NULL);
//	while (*str)
//	{
//		if (*(str++) == c)//对实际地址进行了后置++操作
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
//		printf(" %s 字符串中没有 %c 字符\n",str, c);
//	}
//	else
//	{
//		printf("%c 首次出现在 %s 的位置是：%d \n",c, str, p - str  + 1);
//	}
//	system("pause");
//	return 0;
//}
//
////5.实现strcmp
//
//int my_strcmp(const char *s1, const char *s2)
//{
//	assert(s1 != NULL);
//	assert(s2 != NULL);
//	int ret = 0;
//	while (!(ret = *(unsigned char *)s1 - *(unsigned char *)s2) && *s2)//用！操作符控制循环，将比较换为减法得到数值正负
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
//		printf("str1 :%s 和 str2 :%s 相等\n",str1, str2);
//	}
//	else if (0 < i)
//	{
//		printf("str1:%s 大于 str2:%s \n",str1, str2);
//	}
//	else
//	{
//		printf("str1:%s 小于 str2:%s \n", str1, str2);
//	}
//	system("pause");
//	return 0;
//}
////6.实现memcpy(memcpy指的是c和c++使用的内存拷贝函数，memcpy函数的功能是从源src所指的内存地址的起始位置开始拷贝n个字节到目标dest所指的内存地址的起始位置中。)
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

//7.实现memmove(memmove用于从src拷贝count个字节到dest，如果目标区域和源区域有重叠的话，
//memmove能够保证源串在被覆盖之前将重叠区域的字节拷贝到目标区域中。但复制后src内容会被更改。但是当目标区域与源区域没有重叠则和memcpy函数功能相同。)
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


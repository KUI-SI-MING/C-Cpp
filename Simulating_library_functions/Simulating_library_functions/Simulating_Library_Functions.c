#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//1.模拟实现strncpy

char * my_strncpy(char * dst, const char * sou, size_t num)
{
	assert(dst != NULL);
	assert(sou != NULL);
	char *ret = dst;
	while (num--)
	{
		*dst = *sou;
		dst++;
		sou++;
	}
	return ret;
}

int main()
{
	char str1[] = "abcdefghi";
	char str2[] = "uvwxvz";
	char * ret1 = NULL;
	char * ret2 = NULL;

	//库函数strncpy
	size_t i = sizeof(str2);
	printf(" %d \n", i);
	ret1 = strncpy(str1, str2, 3);

	//my_strcnpy
	ret2 = my_strncpy(str1, str2, 3);
	printf(" %s \n", ret1);
	printf(" %s \n", ret2);

	system("pause");
	return 0;
}



//2.模拟实现strncat

char * my_strncat(char * dst, const char * sou, int num)
{
	assert(dst != NULL);
	assert(sou != NULL);
	char *ret = dst;
	while (*dst)
	{
		dst++;
	}
	while (num--)
	{
		*dst = *sou;
		dst++;
		sou++;
	}
	return ret;
}

int main()
{
	char str1[20] = "abcdefghi";
	char str2[10] = "uvwxvz";
	char * ret1 = NULL;
	char * ret2 = NULL;

	//库函数strncpy
	size_t i = sizeof(str2);
	printf(" %d \n", i);
	ret1 = strncat(str1, str2, 3);

	//my_strcncat
	ret2 = my_strncat(str1, str2, 3);
	printf(" %s \n", ret1);
	printf(" %s \n", ret2);

	system("pause");
	return 0;
}
//3.模拟实现strncmp
int  my_strncmp(const char * dst, const char * sou, size_t num)
{
	assert(dst != NULL);
	assert(sou != NULL);
	while (*dst == *sou)
	{
		num--;
		if (0 == num)
		{
			return 0;
		}
	}
	if (*dst < *sou)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

int main()
{
	char str1[] = "abcdefghi";
	char str2[] = "uvwxvz";

	//库函数strncmp
	size_t i = sizeof(str2);
	printf(" %d \n", i);
	int ret1 = strncmp(str1, str2, 3);

	//my_strcnpy
	int ret2 = my_strncmp(str1, str2, 3);
	printf(" %d \n", ret1);
	printf(" %d \n", ret2);

	if (0 == ret1)
	{
		printf(" str1 和 str2 相等\n");
	}
	else if (ret1 < 0)
	{
		printf(" str1 小于 str2\n");
	}
	else
	{
		printf(" str1 大于 str2\n");
	}

	if (0 == ret2)
	{
		printf(" str1 和 str2 相等\n");
	}
	else if (ret2 < 0)
	{
		printf(" str1 小于 str2\n");
	}
	else
	{
		printf(" str1 大于 str2\n");
	}
	system("pause");
	return 0;
}
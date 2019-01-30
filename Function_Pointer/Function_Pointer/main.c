#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//extern char arr[];
//extern char p[];
//extern *arr;//error

//1.理解函数指针和定义
//2.理解函数指针数组和定义，转移表
//3.理解指向函数指针数组的指针和定义
//4.理解回调函数的使用
//6.使用qsort函数排序各种类型的数据。
//7.模仿qsort的功能实现一个通用的冒泡排序。

//void test(int** ptr)
//{
//	printf("num = %d\n", **ptr);
//}
////计算器
//int add(int a, int b)
//{
//	return a + b;
//}
//int sub(int a, int b)
//{
//	return a - b;
//}
//int mul(int a, int b)
//{
//	return a*b;
//}
//int Div(int a, int b)
//{
//	return a / b;
//}

//函数指针
//void test(const char* str)
//{
//	printf("%s\n", str);
//}
//
////回调函数，模拟实现qsort
//int int_cmp(const void * p1, const void * p2)
//{
//	return (*(int *)p1 > *(int *)p2);
//}
//void _swap(void *p1, void * p2, int size)
//{
//	int i = 0;
//	for (i = 0; i< size; i++)
//	{
//		char tmp = *((char *)p1 + i);
//		*((char *)p1 + i) = *((char *)p2 + i);
//		*((char *)p2 + i) = tmp;
//	}
//}
//void bubble(void *base, int count, int size, int(*cmp)(void *, void *))//冒泡
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i< count - 1; i++)
//	{
//		for (j = 0; j<count - i - 1; j++)
//		{
//			if (cmp((char *)base + j*size, (char *)base + (j + 1)*size) >
//				0)
//			{
//				_swap((char *)base + j*size, (char *)base + (j + 1)*size, size);//交换函数
//			}
//		}
//	}
//}
//
//int main()
//{
//int arr[10] = { 0 };
//arr;//表示数组.首元素的地址
//&arr;//表示数组的地址
//printf("%p\n", arr);
//printf("%p\n", &arr);
//printf("%p\n", arr + 1);//第二个元素
//printf("%p\n", &arr + 1);//跳过了整个数组的地址


//int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//int *ptr1 = (int *)(&aa + 1);//&aa即整个数组的地址，+1 即跳过数组的第一个地址，
//int *ptr2 = (int *)(*(aa + 1));//aa即为二维数组首元素的地址即第一行的地址，aa + 1即第二行的地址，然后解引用，就是第二行第一个元素的地址

//printf("%d,%d\n", *(ptr1 - 1), *(ptr2 - 1));
//printf("%p %p \n",*(aa), &aa[0][0]);//对某行的地址进行解引用，就得到了某行首元素的地址
//printf("%p,%p \n",*(aa + 1), &aa[1][0]);


//⼀一维数组
/*int a[] = { 1, 2, 3, 4 };

printf("%d\n", sizeof(a));
printf("%d\n", sizeof(a + 0));
printf("%d\n", sizeof(*a));
printf("%d\n", sizeof(a + 1));
printf("%d\n", sizeof(a[1]));
printf("%d\n", sizeof(&a));
printf("%d\n", sizeof(&a + 1));
printf("%d\n", sizeof(&a[0]));
printf("%d\n", sizeof(&a[0] + 1));*/

//字符数组
/*char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };*/
/*printf("%d\n", sizeof(arr));
printf("%d\n", sizeof(arr + 0));
printf("%d\n", sizeof(*arr));
printf("%d\n", sizeof(arr[1]));
printf("%d\n", sizeof(&arr));
printf("%d\n", sizeof(&arr + 1));
printf("%d\n", sizeof(&arr[0] + 1));*/

//printf("%d\n", strlen(arr));
//printf("%d\n", strlen(arr + 0));
////printf("%d\n", strlen(*arr));error
////printf("%d\n", strlen(arr[1]));error
//printf("%d\n", strlen(&arr));
//printf("%d\n", strlen(&arr + 1));
//printf("%d\n", strlen(&arr[0] + 1));

//char *p = "abcdef";
//printf("%d\n", sizeof(p));
//printf("%d\n", sizeof(p + 1));
//printf("%d\n", sizeof(*p));
//printf("%d\n", sizeof(p[0]));
//printf("%d\n", sizeof(&p));
//printf("%d\n", sizeof(&p + 1));
//printf("%d\n", sizeof(&p[0] + 1));

//printf("%d\n", strlen(p));
//printf("%d\n", strlen(p + 1));
////printf("%d\n", strlen(*p));
////printf("%d\n", strlen(p[0]));
//printf("%d\n", strlen(&p));//随机
//printf("%d\n", strlen(&p + 1));//随机
//printf("%d\n", strlen(&p[0] + 1));//随机

//int a[3][4] = { 0 };

//printf("%d\n", sizeof(a));
//printf("%d\n", sizeof(a[0][0]));
//printf("%d\n", sizeof(a[0]));
//printf("%d\n", sizeof(a[0] + 1));
//printf("%d\n", sizeof(a + 1));
//printf("%d\n", sizeof(&a[0] + 1));
//printf("%d\n", sizeof(*a));//*a相当于得到了数组第一行的数组名
//printf("%d\n", sizeof(a[3]));

//全局变量
//printf("%s\n", arr);//abcdef
////printf("%s\n", p);//随机值
//printf("%s \n",(char *)*(int *)p);//强转为 int * 找到所有的字节后再解引用即得到首地址（类似于二维数组的首元素），再强转为 char *型进行打印

//二级指针传参
//int n = 10;
//int*p = &n;
//int **pp = &p;
//test(pp);//10
//test(&p);//10

//函数指针
//(*(void(*)())0());//void (*)()是一个参数为空，返回类型为空的函数指针，该语句的作用把0强转为参数为空的函数指针，然后调用
//void(*signal(int, void(*)(int)))(int);//signal是一个有一个参数是int 一个是void 型的函数的声明
//int x, y;
//int input = 1;
//int ret = 0;
//int(*p[5])(int x, int y) = { 0, add, sub, mul, Div }; //转移表
//while (input)
//{
//	printf("*************************\n");
//	printf(" 1:add 2:sub \n");
//	printf(" 3:mul 4:div \n");
//	printf("*************************\n");
//	printf("请选择：");
//	scanf("%d", &input);
//	if ((input < 4 && input > 1))
//	{
//		printf("输入操作数：");
//		scanf("%d %d", &x, &y);
//		ret = (*p[input])(x, y);
//	}
//	else
//		printf("输入有误\n");
//	printf("ret = %d\n", ret);
//}


////函数指针pfun
//void(*pfun)(const char*) = test;
////函数指针的数组pfunArr
//void(*pfunArr[5])(const char* str);
//pfunArr[0] = test;
////指向函数指针数组pfunArr的指针ppfunArr
//void(*(*ppfunArr)[10])(const char*) = &pfunArr;

//int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
//
//int i = 0;
//bubble(arr, sizeof(arr) / sizeof(arr[0]), sizeof (int), int_cmp);//int_cmp 即比较函数的地址
//for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//{
//	printf("%s ", arr[i]);
//}
//printf("\n");
//system("pause");
//return 0;
//}

//字符串比较
int int_than(const void *p1, const void *p2)
{
	assert(p1 != NULL);
	assert(p2 != NULL);

	return strcmp(*(int *)p1, *(int *)p2);//强转为int * 再解引用即可获得四个字节的内容
	//return strcmp(*(char **)p1, *(char**)p2);//强转成二级字符指针，这样解一级引用还是指针，这样就可取得4个字节的内容即是取得数组
	//一个元素的全部地址取得的地址就是整个字符串首元素地址，传入strcm函数进行比较。
}

//整数比较
//int int_than(const void *p1, const void *p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//
//	return *(int *)p1 > *(int *)p2;
//}

//字符比较
//int int_than(const void *p1, const void *p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//
//	return *(char *)p1 > *(char *)p2;
//}


//单精度
//int int_than(const void *p1, const void *p2)
//{
//	assert(p1 != NULL);
//	assert(p2 != NULL);
//
//	return *(float *)p1 > *(float *)p2;
//}

void my_swap(void *p1, void *p2, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		char tmp = *((char *)p1 + i);
		*((char *)p1 + i) = *((char *)p2 + i);
		*((char *)p2 + i) = tmp;
	}
}

void my_qsort(void *start, int count, int sz, int(than)(void *, void *))//void*型指针保证类型的兼容性，传入什么类型都可
//以进行排序在内部，将指针转成char*类型，是的每一字节进行交换，使得不必考虑虑参数类型
{
	assert(start != NULL);
	int i = 0;
	int j = 0;
	for (i = 0; i < count - 1; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if ((than((char *)start + j * sz, (char *)start + (j + 1)*sz)) >0)//因为不确定类型，然后强转为一个字节进行比较
			{
				my_swap((char *)start + j * sz, (char *)start + (j + 1) * sz, sz);//用理，一个字节一个字节的比较
			}
		}
	}
}
//
int main()
{
	//作业：模拟实现qsort
	char *str[] = { "aaaa", "eeee", "bbbb", "cccc" };//字符串
	//int  str[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };//整形数字
	//char str[] = { 'c', 'b', 'a', 'f', 'd' };//字符
	//float  str[] = { 6.4f, 53.2f, 1.0f, 2.85f };//单精度浮点数
	int i = 0;

	//my_qsort(str, sizeof(str) / sizeof(str[0]), sizeof(char *), int_than);
	//my_qsort(str, sizeof(str) / sizeof(str[0]), sizeof(int), int_than);
	//my_qsort(str, sizeof(str) / sizeof(str[0]), sizeof(char), int_than);
	my_qsort(str, sizeof(str) / sizeof(str[0]), sizeof(float), int_than);
	for (i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		printf(" %s ", str[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
//
//int main()
//{
//练习一
//int a[5] = { 1, 2, 3, 4, 5 };
//int *ptr = (int *)(&a + 1);
//printf("%d,%d", *(a + 1), *(ptr - 1));//2, 5	

////练习二
//struct Test
//{
//	int Num;
//	char *pcName;
//	shortsDate;
//	char cha[2];
//	shortsBa[4];
//}*p;//假设结构体的字节数为20 即0x14;

//假设p 的值为0x100000。 如下表表达式的值分别为多少？
//	p + 0x1 = 0x___ ?//p +1 代表跳过整个结构体，即0x10 00 14
//	(unsigned long)p + 0x1 = 0x___ ? // 0x10 00 01
//	(unsigned int*)p + 0x1 = 0x___ ?// 0x10 00 04强转为int * 加一 即加四个字节

//练习三
//int a[4] = { 1, 2, 3, 4 };
//int *ptr1 = (int *)(&a + 1);
//int *ptr2 = (int *)((int)a + 1);
//printf("%x,%x", ptr1[-1], *ptr2);//0x00 00 00 04  0x02 00 00 00 解释：a[4]小端存储：01 00 00 00 02 00 00 00 03 00 00 00 04 00 00 00  ((int *)（int）a + 1)
////把首地址强转为int 后再加一 即相当于增加一个字节然后强转为int * 后指向 00 00 00 02这四个字节的首地址，再int 打印，就会得到小端的0x 02 00 00 00 

//练习四
//int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//int *p;
//p = a[0];
//printf("%d", p[0]);//1 逗号表达式，二维数组的初始化用大括号

////练习五
//int a[5][5];
//int(*p)[4];
//p = a;
//printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);//FF FF FF FC  -4   指针减指针为中间元素个数，低 - 高为负值。
////a[][]按照一行的内存排列，p[4] 即 p + 4 即指向第五列元素，也就是指向 a[3][4] 这两个地址之间相差 -4 ， %p  会将-4 的补码打印出来


//练习六
//int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//int *ptr1 = (int *)(&aa + 1);
//int *ptr2 = (int *)(*(aa + 1));
//printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));// 10 5 *（aa + 1）即对第二行的地址进行 解引用，会得到第二行首元素的地址

//练习七

//char *a[] = { "work", "at", "alibaba" };
//char**pa = a;
//pa++;
//printf("%s\n", *pa);//at

////练习八
//char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
//char**cp[] = { c + 3, c + 2, c + 1, c };
//char***cpp = cp;
//printf("%s\n", **++cpp);//POINT
//printf("%s\n", *--*++cpp + 3);//ER   （*++cpp）拿出了c + 1 的内容也就是指向NEW 的地址，然后再减一 就得到 ENTER的地址
//printf("%s\n", *cpp[-2] + 3);//ST
//printf("%s\n", cpp[-1][-1] + 1);//EW   cpp[-1] == *(cpp - 1)拿出了 cp + 1 的内容 即POINT的地址; 然后cpp[-1][-1] 也就是对这个地址减一后 再加一解引用 就得到 EW

/*system("pause");
return 0;
}*/
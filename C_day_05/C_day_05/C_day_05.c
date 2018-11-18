#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
int main()
{
	char c1;
	while (1)
	{
		printf("请输入一个字符：");
		gets(&c1);
		//fgets(&c1, sizeof(char), stdin);//自动加\0
		//c1 = getchar();//自动加\n
		//scanf("%c", &c1);//自动加\n
		if (65 <= c1 && c1 <= 90){
			printf("该字符的小写字符为：%c\n", c1 = c1 + 32);
		}
		else if (97 <= c1 && c1 <= 122){
			printf("该字符的大写字符为：%c\n", c1 = c1 - 32);
		}
		else
		{
			printf("不能输出该字符\n");
		}
	}
	system("pause");
	return 0;
}

//编写代码模拟三次密码输入的场景。
int main()
{
	int i =1;
	char password[] = "bittechnology";
	char input[20] = { 0 };
	while ((i++) < 4)
	{
		printf("请输入您的密码:");
		scanf("%s", input);
		if (strcmp(password, input) == 0)
		{
			printf("登录成功！\n");
			break;
		}
		else
		{
			if (i == 4)
			{
				printf("即将退出程序！\n");
				break;
			}
			printf("密码错误！请重新输入！\n");
		}
		
	}
	system("pause");
	return 0;
}

//写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回-1.（折半查找） 
 int  search(int a[], int left, int right, int key)
{
    int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (a[mid] >key)
		{
			right = mid - 1;
		}
		else if (a[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			printf("该数的下标为:");
			return mid;
		}
	}
	printf("找不到该数故返回");
	return -1;//找不到
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
	int key = 0;
	int left = 0;
	int num = 0;
	int right = sizeof(a) / sizeof(a[0])- 1;//函数内部无法使用
	printf("请输入想要查找的数字：");
	scanf("%d", &key);
	num = search(a, left, right, key);
	printf("%d\n", num);
	system("pause");
	return 0;
}

void menu()
{
	printf("                          #####                             \n");
	printf("                   ######       ######                      \n");
	printf("              #######    1.PLAY     #######                 \n");
	printf("              #######    2.EXIT     #######                 \n");
	printf("                   ######       ######                      \n");
	printf("                          #####                             \n");
}
//生成随机数
void  game()
{
	int ret = 0;
	ret = rand() % 100 +1;// 缩小范围1~100
	int input = 0;
	do
	{
		printf("输入你猜的数字:");
		scanf("%d", &input);
		if (input == ret)
		{
			printf("恭喜你！猜对了！\n");
			break;
		}
		else if (input > ret)
			printf("猜大了\n");
		else
			printf("猜小了\n");
	} while (1);
}
//主体 
int main()
{
	int input = 0;
	int flag = 0;
	srand((unsigned)time(NULL));//时间种子
	do 
	{
		menu();
		printf("选择:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			flag = 0;
			break;
		default:
			printf("选择错误!请重新输入!\n");
			break;
		}
		if (flag == 0)
			break;
	} while (input);
	system("pause");
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������
int main()
{
	char c1;
	while (1)
	{
		printf("������һ���ַ���");
		gets(&c1);
		//fgets(&c1, sizeof(char), stdin);//�Զ���\0
		//c1 = getchar();//�Զ���\n
		//scanf("%c", &c1);//�Զ���\n
		if (65 <= c1 && c1 <= 90){
			printf("���ַ���Сд�ַ�Ϊ��%c\n", c1 = c1 + 32);
		}
		else if (97 <= c1 && c1 <= 122){
			printf("���ַ��Ĵ�д�ַ�Ϊ��%c\n", c1 = c1 - 32);
		}
		else
		{
			printf("����������ַ�\n");
		}
	}
	system("pause");
	return 0;
}

//��д����ģ��������������ĳ�����
int main()
{
	int i =1;
	char password[] = "bittechnology";
	char input[20] = { 0 };
	while ((i++) < 4)
	{
		printf("��������������:");
		scanf("%s", input);
		if (strcmp(password, input) == 0)
		{
			printf("��¼�ɹ���\n");
			break;
		}
		else
		{
			if (i == 4)
			{
				printf("�����˳�����\n");
				break;
			}
			printf("����������������룡\n");
		}
		
	}
	system("pause");
	return 0;
}

//д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ�������-1.���۰���ң� 
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
			printf("�������±�Ϊ:");
			return mid;
		}
	}
	printf("�Ҳ��������ʷ���");
	return -1;//�Ҳ���
}

int main()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};
	int key = 0;
	int left = 0;
	int num = 0;
	int right = sizeof(a) / sizeof(a[0])- 1;//�����ڲ��޷�ʹ��
	printf("��������Ҫ���ҵ����֣�");
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
//���������
void  game()
{
	int ret = 0;
	ret = rand() % 100 +1;// ��С��Χ1~100
	int input = 0;
	do
	{
		printf("������µ�����:");
		scanf("%d", &input);
		if (input == ret)
		{
			printf("��ϲ�㣡�¶��ˣ�\n");
			break;
		}
		else if (input > ret)
			printf("�´���\n");
		else
			printf("��С��\n");
	} while (1);
}
//���� 
int main()
{
	int input = 0;
	int flag = 0;
	srand((unsigned)time(NULL));//ʱ������
	do 
	{
		menu();
		printf("ѡ��:");
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
			printf("ѡ�����!����������!\n");
			break;
		}
		if (flag == 0)
			break;
	} while (input);
	system("pause");
	return 0;
}
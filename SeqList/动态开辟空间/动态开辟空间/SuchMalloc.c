#include <stdio.h>
#include <stdlib.h>

////malloc 
//int main()
//{
//	//code 1
//	int num = 0;
//	scanf("%d", &num);
//	//int arr[num] = { 0 };
//	
//	//code 2
//	int *ptr = NULL;
//	ptr = (int*)malloc(num*sizeof(int));
//	if (ptr != NULL)
//	{
//		int i = 0;
//		for (i = 0; i < num; i++)
//		{
//			*(ptr + i) = 0;
//		}
//	}
//	free(ptr);//�ͷź�ptr��ֵ�ǿ����ڴ�ĵ�ַ��
//	ptr = NULL;//�����ÿ�
//	system("pause");
//	return 0;
//}

//calloc
int main()
{
	int *p = calloc(10, sizeof(int));//����10����СΪsizeof(int)�Ŀռ�
	if (p != NULL)
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			//*(p + i) = i;
			printf("%d ", *(p + i));
		}
	}
	free(p);
	p = NULL;
	system("pause");
	return 0;
}
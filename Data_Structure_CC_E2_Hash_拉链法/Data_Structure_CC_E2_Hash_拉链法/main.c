#include "HashTable.h"

void Test()
{
	HashNode ht;
	int input = 0;

	HashTableInit(&ht);

	HashTableInsert(&ht, 13, 11);
	HashTableInsert(&ht, 1, 22);
	HashTableInsert(&ht, 15, 33);
	HashTableInsert(&ht, 26, 44);
	HashTableInsert(&ht, 18, 55);
	HashTableInsert(&ht, 25, 66);
	HashTableInsert(&ht, 27, 77);
	HashTableInsert(&ht, 4, 88);

	printf("请输入你想查找的Key ：");
	scanf("%d", &input);
	printf("\n\n");
	printf("经查找有:Key = %d, Value = %d\n\n", HashTableFind(&ht, input)->_key,HashTableFind(&ht, input)->_value);

	printf("请输入你想删除的Key ：");
	scanf("%d", &input);
	printf("\n\n");
	if (1 == HashTableRemove(&ht, input))
	{
		printf("删除成功！\n\n");
	}
	else
	{
		printf("删除失败！\n\n");
	}

	HashTableDestory(&ht);
	
}

int main()
{
	Test();
	system("pause");
	return 0;
}
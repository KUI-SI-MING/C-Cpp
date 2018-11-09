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

	printf("������������ҵ�Key ��");
	scanf("%d", &input);
	printf("\n\n");
	printf("��������:Key = %d, Value = %d\n\n", HashTableFind(&ht, input)->_key,HashTableFind(&ht, input)->_value);

	printf("����������ɾ����Key ��");
	scanf("%d", &input);
	printf("\n\n");
	if (1 == HashTableRemove(&ht, input))
	{
		printf("ɾ���ɹ���\n\n");
	}
	else
	{
		printf("ɾ��ʧ�ܣ�\n\n");
	}

	HashTableDestory(&ht);
	
}

int main()
{
	Test();
	system("pause");
	return 0;
}
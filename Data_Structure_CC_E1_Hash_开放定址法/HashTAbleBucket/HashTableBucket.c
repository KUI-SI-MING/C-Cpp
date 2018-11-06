#include "HashTableBucket.h"

unsigned long GetNextPrime(size_t len)
{
	static size_t index = 0;
	//素数表
	static const unsigned long _PrimeList[28] =
	{
		53ul, 97ul, 193ul, 389ul, 769ul,
		1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
		49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
		1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
		50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
		1610612741ul,
	};

	for (int i = 0; i < 28; i++)
	{
		if (_PrimeList[i] > len)
			return _PrimeList[i];
	}
	return _PrimeList[27];
	//return _PrimeList[index++];

}


void HTBInit(pHTB htb, size_t len)
{
	assert(htb);

	unsigned long TrueLen = GetNextPrime(len);
	htb->_tables = (HashNode**)malloc(sizeof(HashNode*)* TrueLen);
	assert(htb->_tables);
	memset(htb->_tables, 0, sizeof(HashNode*) * TrueLen);//第三个参数是字节数
	htb->_len = TrueLen;
	htb->_size = 0;
}

void HTBDestory(pHTB htb)
{
	assert(htb);
	int i = 0;

	//释放节点桶
	for (i = 0; i < htb->_len; ++i)
	{
		HashNode* cur = htb->_tables[i];
		while (cur)
		{

			HashNode* next = cur->_next;
			free(cur);

			cur = next;
		}
		htb->_tables[i] = NULL;//释放哈希表中的指针
	}
	//释放数组
	free(htb->_tables);
	htb->_tables = NULL;
	htb->_size = 0;
	htb->_len = 0;
}

size_t HashFunc(HTBKeyType key, size_t len)
{
	return key % len;
}

HashNode* BuyHTBNode(HTBKeyType key, HTBValueType value)
{
	HashNode* newnode = malloc(sizeof(HashNode));
	newnode->_key = key;
	newnode->_value = value;
	newnode->_next = NULL;

	return newnode;
}

void CheckCapacity(pHTB htb)
{
	assert(htb);

	if (htb->_size == htb->_len)
	{
		HTB newhtb;
		newhtb._len = GetNextPrime(htb->_len);
		HTBInit(&newhtb, newhtb._len);
		for (int i = 0; i < htb->_len; ++i)
		{
			HashNode* cur = htb->_tables[i];
			while(cur)
			{
				HashNode* next = cur->_next;
				size_t index = HashFunc(cur->_key,newhtb._len);

				cur->_next = newhtb._tables[index];
				newhtb._tables[index] = cur;

				cur = next;
			}
			htb->_tables[i] = NULL;
		}
		HTBDestory(htb);
		htb->_tables = newhtb._tables;
		htb->_size = newhtb._size;
		htb->_len = newhtb._len;
	}
}

int HTBInsert(pHTB htb, HTBKeyType key, HTBValueType value)
{
	assert(htb);

	//key是否存在
	//插入
	CheckCapacity(htb);//注意传值
	size_t index = HashFunc(key, htb->_len);
	HashNode* cur = htb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			return -1;//value值存在时返回0
		}
		cur = cur->_next;
	}
	HashNode* newnode = BuyHTBNode(key, value);
	newnode->_next = htb->_tables[index];
	htb->_tables[index] = newnode;
	htb->_size++;
	return 0;
}

int HTBRemove(pHTB htb, HTBKeyType key)
{
	assert(htb);

	size_t index = HashFunc(key, htb->_len);
	HashNode* cur = htb->_tables[index];
	HashNode* prev = NULL;
	while (cur)
	{
		if (cur->_key == key)
		{
			if (prev == NULL)
			{
				htb->_tables[index] = cur->_next;//当第一个节点是key时
			}
			else
			{
				prev->_next = cur->_next;//当第一个节点不是时，prev已经被赋值
			}
			free(cur);
			--htb->_size;
			return 0;
		}
		prev = cur;
		cur = cur->_next;
	}
	return -1;
}


void HTBPrint(pHTB htb)
{
	int i = 0;
	HashNode* cur = NULL;
	//printf("%d\n", htb->_len);
	for (i = 0; i < htb->_len; i++)
	{
		cur = htb->_tables[i];
		if (cur == NULL)
		{
			printf("Tables[%d]:NULL\n", i);
			continue;
		}
		printf("Tables[%d]:", i);
		while (cur)
		{
			printf("[%d-%d]->", cur->_key, cur->_value);
			cur = cur->_next;
		}
		printf("NULL");
		printf("\n");
	}
	printf("\n");
}

int HTBSize(pHTB htb)
{
	assert(htb);

	return htb->_size;
}

int HTBEmpty(pHTB htb)
{
	assert(htb);

	return htb->_size == 0;
}

HashNode* HTBFind(pHTB htb, HTBKeyType key)
{
	assert(htb);

	size_t index = HashFunc(key, htb->_len);
	HashNode* cur = htb->_tables[index];
	while (cur)
	{
		if (cur->_key == key)
		{
			return cur;
		}

		cur = cur->_next;
	}
	return NULL;
}
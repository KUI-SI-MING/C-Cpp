#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int KeyType;
typedef int ValueType;

typedef struct HashNode
{
	KeyType _key;
	ValueType _value;
	struct HashNode* _next;
}HashNode;

typedef struct HashTable
{
	//HashNode** _tables; 
	HashNode** _tables;
	size_t _size;
	size_t _N;
}HashTable,*pHashTable;

HashNode* BuyHashNode(KeyType key, ValueType value);
size_t HashFunc(KeyType key, size_t N);
size_t GetNextPrimeNum(size_t cur);
void HashTableInit(pHashTable ht);
int HashTableInsert(pHashTable ht, KeyType key, ValueType value);
HashNode* HashTableFind(pHashTable ht, KeyType key);
int HashTableRemove(pHashTable ht, KeyType key);
void HashTableDestory(pHashTable ht);
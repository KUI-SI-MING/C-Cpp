#include "HashTableBucket.h"

void TestHashTableBucket()
{
	HTB htb;

	HTBInit(&htb, N);

	HTBInsert(&htb, 15, 1);
	HTBInsert(&htb, 25, 2);
	HTBInsert(&htb, 3, 3);
	HTBInsert(&htb, 53, 4);
	HTBInsert(&htb, 16, 5);
	HTBInsert(&htb, 5, 6);
	HTBInsert(&htb, 1, 7);
	HTBInsert(&htb, 11, 8);
	HTBInsert(&htb, 106, 9);


	/*srand(time(0));
	for (int i = 0; i < 100; ++i)
	{
		HTBInsert(&htb, rand(), 0);
	}
*/

	HTBPrint(&htb);
	HTBRemove(&htb, 53);
	HTBRemove(&htb, 106);
	printf("É¾³ýÖ®ºó:\n\n");
	HTBPrint(&htb);

	HTBDestory(&htb);
}


int main()
{
	TestHashTableBucket();
	system("pause");
	return 0;
}
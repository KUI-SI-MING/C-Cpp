#include "CommentConvert.h"

void test()
{
	FILE * psInt = NULL;
	FILE * psOut = NULL;
	psInt = fopen("input.c", "r");//打开input.c流
	if (NULL == psInt)
	{

		perror("open the file to read");
		system("pause");
		exit(EXIT_FAILURE);
	}
	psOut = fopen("output.c", "w");//打开output.c流
	if (NULL == psOut)
	{

		perror("open the file to write");
		fclose(psInt);
		psInt = NULL;
		system("pause");
		exit(EXIT_FAILURE);
	}
	CommentComvert(psInt, psOut);
	fclose(psInt);
	psInt = NULL;
	fclose(psOut);
	psOut = NULL;
}


int main()
{
	test();
	system("pause");
	return 0;
}
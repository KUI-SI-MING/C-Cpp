#include "CommentConvert.h"


void DoNulstate(FILE* psInt, FILE * psOut, enum State *s)
{
	int first = fgetc(psInt);//读取第一个字符
	switch (first)
	{
	case'/':
	{
			   int second = fgetc(psInt);//读取第二个字符
			   switch (second)
			   {
			   case'*':
			   {
						  fputc('/' , psOut);
						  fputc('/', psOut);
						  *s = C_STATE;//读取到 /* 后进入C模式
						  break;
			   }
			   case'/':
			   {
						  fputc(first, psOut);
						  fputc(second, psOut);
						  *s = CPP_STATE;//读取到 // 后进入C++模式
						  break;
			   }
			   default:
			   {
						  fputc(first, psOut);// 表示没有 开始转换 
						  *s = NUL_STATE;
						  break;
			   }
			   }
			   break;
	}
	case EOF:
	{
				*s = END_STATE;//读取到 EOF 即文件结束
				break;
	}
	default:
	{
	    fputc(first, psOut);//转换普通字符
		*s = NUL_STATE;
		break;
	}	
	}
}

void DoCstate(FILE* psInt, FILE * psOut, enum State *s)
{
	int first = fgetc(psInt);
	switch (first)
	{
	case'*':
	{
			   int second = fgetc(psInt);//判断C模式是否结束
			   switch (second)
			   {
			   case'/':
			   {
						  int third = fgetc(psInt);//获取第三个字符 来判断连续注释和换行问题
						  if (third != '\n' && third != EOF)
						  {
							  ungetc(third, psInt);
						  }
						  fputc(third, psOut);
						  *s = NUL_STATE;
						  break;
			   }
			   default:
			   {
						  ungetc(second, psOut);
						  fputc(first, psOut);
						  *s = C_STATE;
						  break;
			   }
			   }
	}
	case'\n':                          //多行注释
	{
				fputc('\n', psOut);
				fputc('/', psOut);
				fputc('/', psOut);
				*s = CPP_STATE;
				break;
	}
	default:
	{
			   fputc(first, psOut);
			   *s = C_STATE;
			   break;
	}
	}
}

void DoCppstate(FILE* psInt, FILE * psOut, enum State *s)
{
	int first = fgetc(psInt);
	switch(first)
	{
	case'\n':
	{
				fputc(first, psOut);
				*s = NUL_STATE;
			    break;
	}
	case EOF:
	{
				*s = END_STATE;
				break;
	}
	default:
	{
			   fputc(first, psOut);
			   *s = CPP_STATE;
			   break;
	}
	}
}
void DoEndstate(enum State *s)
{
	*s = END_STATE;
}

void CommentComvert(FILE *psInt, FILE * psOut)
{
	enum State s = NUL_STATE;
	while (s != END_STATE)
	{
		switch (s)
		{
		case NUL_STATE:
		{
						  DoNulstate(psInt, psOut, &s);
						  break;
		}
		case C_STATE:
		{
						DoCstate(psInt, psOut, &s);
						break;
		}
		case CPP_STATE:
		{
						  DoCppstate(psInt, psOut, &s);
						  break;
		}
		case END_STATE:
		{
						  DoEndstate(&s);
						  return;
		}
		default:
			break;
		}
	}
	printf("转换成功！\n");
}
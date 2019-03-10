#include "CommentConvert.h"


void DoNulstate(FILE* psInt, FILE * psOut, enum State *s)
{
	int first = fgetc(psInt);//��ȡ��һ���ַ�
	switch (first)
	{
	case'/':
	{
			   int second = fgetc(psInt);//��ȡ�ڶ����ַ�
			   switch (second)
			   {
			   case'*':
			   {
						  fputc('/' , psOut);
						  fputc('/', psOut);
						  *s = C_STATE;//��ȡ�� /* �����Cģʽ
						  break;
			   }
			   case'/':
			   {
						  fputc(first, psOut);
						  fputc(second, psOut);
						  *s = CPP_STATE;//��ȡ�� // �����C++ģʽ
						  break;
			   }
			   default:
			   {
						  fputc(first, psOut);// ��ʾû�� ��ʼת�� 
						  *s = NUL_STATE;
						  break;
			   }
			   }
			   break;
	}
	case EOF:
	{
				*s = END_STATE;//��ȡ�� EOF ���ļ�����
				break;
	}
	default:
	{
	    fputc(first, psOut);//ת����ͨ�ַ�
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
			   int second = fgetc(psInt);//�ж�Cģʽ�Ƿ����
			   switch (second)
			   {
			   case'/':
			   {
						  int third = fgetc(psInt);//��ȡ�������ַ� ���ж�����ע�ͺͻ�������
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
	case'\n':                          //����ע��
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
	printf("ת���ɹ���\n");
}
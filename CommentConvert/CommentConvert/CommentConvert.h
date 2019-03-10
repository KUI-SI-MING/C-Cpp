#ifndef __COMMENTCOMVERT_H__
#define __COMMENTCOMVERT_H__

//×¢ÊÍ±íµÄ×ª»»
#include <stdio.h>
#include <stdlib.h>


enum State
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
};


void CommentComvert(FILE *psInt, FILE* psOut);
void DoNulstate(FILE* psInt, FILE * psOut, enum State *s);
void DoCstate(FILE* psInt, FILE * psOut, enum State *s);
void DoCppstate(FILE* psInt, FILE * psOut, enum State *s);
void DoEndstate(enum State *s);



#endif//__COMMENTCOMVERT_H__
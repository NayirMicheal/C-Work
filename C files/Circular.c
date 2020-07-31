#include<stdio.h>
#include"BitMath.h"
#define CIR_SHIFT_RIGHT(VAR,SHIFT_NUM) 	do{char bit=GETBIT(VAR,0);\
											VAR=VAR>>1;\
										if(bit==1)\
											SETBIT(VAR,(sizeof(VAR)*8)-1);\
										else\
											CLRBIT(VAR,(sizeof(VAR)*8)-1);\
										SHIFT_NUM--;\
										 }while(SHIFT_NUM)
#define CIR_SHIFT_LEFT(VAR,SHIFT_NUM) 	do{char bit=GETBIT(VAR,(sizeof(VAR)*8)-1);\
											VAR=VAR<<1;\
										if(bit==1)\
											SETBIT(VAR,0);\
										else\
											CLRBIT(VAR,0);\
										SHIFT_NUM--;\
										 }while(SHIFT_NUM)											 

void main (void)
{
	char x=0b10001000;
	int cir_times=1;
	CIR_SHIFT_LEFT(x,cir_times);

	printf("%d",x);
}

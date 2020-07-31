/*
 * main.c
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_int.h"
#include "GIE_int.h"
#define TCCR0 *((u8*)0x53)
#define TCNT0 *((u8*)0x52)
#define TIMSK *((u8*)0x59)
#define TIFR *((u8*)0x58)

volatile static u16 count;
void Timer_init(void)
{
TCNT0=112;
SET_BIT(TIMSK,0);
SET_BIT(TIFR,0);
TCCR0=0b00000010;
}
void  __vector_11  (void) __attribute__((signal,used));
void  __vector_11  (void)
{
	count++;
	if(count==977)
	{
		TOG_BIT(PORTA,0);
		count=0;
		TCNT0=112;
	}
}
void main(void)
{
	DIO_voidInitialize();
	Timer_init();
	GIE_EnableGlobalInterrupt();
	while(1)
	{


	}
}




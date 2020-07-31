/*
 * main.c
 *
 *  Created on: 12 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DIO_register.h"
#include "DIO_int.h"
#include "GIE_int.h"
#include "TIM_int.h"
#include "nigry.h"
volatile u16 i=0;
void DAC_Song(void)
{
	asm ("LPM %0, Z"  "\n\t"  : "=r" (PORTA)  : "z" (&nigry_raw[i]) );
	//PORTA=file_raw[i];
	i++;
	if(i==15139)
	{
		i=0;
	}
}
void main (void)
{
	DIO_voidInitialize();
	TIM_voidSetCallBackCTC(DAC_Song);
	TIM_voidInitialize();
	TIM_voidEnableIntCTC();
	GIE_EnableGlobalInterrupt();
	while(1)
	{

	}
}

/*
 * main.c
 *
 *  Created on: 18 Apr 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DIO_register.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "TIM_int.h"
#include "GIE_int.h"
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
	u16 Data;
	u8 Freq;
	DIO_voidInitialize();

	ADC_voidInit();
	TIM_voidSetCallBackCTC(DAC_Song);
	TIM_voidInitialize();
	TIM_voidEnableIntCTC();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		ADC_voidStartConversion(ADC0,&Data);
		Freq=(u8)(Data / 4);
		TIM_voidInitCTCRegister(Freq);
	}
}


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
#include "SWD_int.h"
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
	DIO_voidSetPinValue(DIO_u8_PIN_24,DIO_u8_HIGH);  //pull up sw1
	DIO_voidSetPinValue(DIO_u8_PIN_25,DIO_u8_HIGH);  //pull up sw2
	DIO_voidSetPinValue(DIO_u8_PIN_26,DIO_u8_HIGH);  //pull up sw3
	TIM_voidSetCallBackCTC(DAC_Song);
	TIM_voidInitialize();
	TIM_voidEnableIntCTC();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		if(SWD_u8GetSwitchState(SWD_u8_SW1)==SWD_u8PUSHED)
		{
			TIM_voidInitCTCRegister(75);
		}
		if(SWD_u8GetSwitchState(SWD_u8_SW2)==SWD_u8PUSHED)
		{
			TIM_voidInitCTCRegister(150);
		}
		if(SWD_u8GetSwitchState(SWD_u8_SW3)==SWD_u8PUSHED)
		{
			TIM_voidInitCTCRegister(225);
		}
	}
}

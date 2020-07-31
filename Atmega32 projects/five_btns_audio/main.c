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
/////////////////////////
#include "hello.h"
#include "help.h"
#include "hungry.h"
#include "nayir.h"
#include "bye.h"
////////////////////////
volatile u16 i=0;
u8 flag=0;
void DAC_Song(void)
{
	if(flag==1)
	{
		asm ("LPM %0, Z"  "\n\t"  : "=r" (PORTA)  : "z" (&hello_raw[i]) ); //PORTA=file_raw[i];
		i++;
		if(i==5666)
		{
			i=0;
		}
	}
	else if(flag==2)
	{
		asm ("LPM %0, Z"  "\n\t"  : "=r" (PORTA)  : "z" (&help_raw[i]) ); //PORTA=file_raw[i];
		i++;
		if(i==2508)
		{
			i=0;
		}
	}
	else if(flag==3)
	{
		asm ("LPM %0, Z"  "\n\t"  : "=r" (PORTA)  : "z" (&hungry_raw[i]) ); //PORTA=file_raw[i];
		i++;
		if(i==5851)
		{
			i=0;
		}
	}
	else if(flag==4)
	{
		asm ("LPM %0, Z"  "\n\t"  : "=r" (PORTA)  : "z" (&nayir_raw[i]) ); //PORTA=file_raw[i];
		i++;
		if(i==5387)
		{
			i=0;
		}
	}
	else if(flag==5)
	{
		asm ("LPM %0, Z"  "\n\t"  : "=r" (PORTA)  : "z" (&bye_raw[i]) ); //PORTA=file_raw[i];
		i++;
		if(i==4458)
		{
			i=0;
		}
	}
	else
	{

	}
}
void main (void)
{
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_24,DIO_u8_HIGH);  //pull up sw1
	DIO_voidSetPinValue(DIO_u8_PIN_25,DIO_u8_HIGH);  //pull up sw2
	DIO_voidSetPinValue(DIO_u8_PIN_26,DIO_u8_HIGH); //pull up sw3
	DIO_voidSetPinValue(DIO_u8_PIN_27,DIO_u8_HIGH); //pull up sw4
	DIO_voidSetPinValue(DIO_u8_PIN_28,DIO_u8_HIGH); //pull up sw5
	TIM_voidSetCallBackCTC(DAC_Song);
	TIM_voidInitialize();
	TIM_voidEnableIntCTC();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		if(SWD_u8GetSwitchState(SWD_u8_SW1)==SWD_u8PUSHED)
		{
			flag=1;
		}
		else if(SWD_u8GetSwitchState(SWD_u8_SW2)==SWD_u8PUSHED)
		{
			flag=2;
		}
		else if(SWD_u8GetSwitchState(SWD_u8_SW3)==SWD_u8PUSHED)
		{
			flag=3;
		}
		else if(SWD_u8GetSwitchState(SWD_u8_SW4)==SWD_u8PUSHED)
		{
			flag=4;
		}
		else if(SWD_u8GetSwitchState(SWD_u8_SW5)==SWD_u8PUSHED)
		{
			flag=5;
		}
		else
		{
			flag=0;
			i=0;
		}
	}
}

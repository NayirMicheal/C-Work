/*
 * main.c
 *
 *  Created on: 5 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_int.h"
#include "TIM_int.h"
#include "GIE_int.h"
#include "KEYPAD_int.h"
#include "RTO2_init.h"


void KeypadTask(void);
void BuzzerTask(void);
u8 periodicity=0;
static u8 onFlag=0;
Task TaskKeypad=
{200,0,RTO_u8_ACTIVE_STATE,KeypadTask};
Task TaskBuzzer ={0,0,RTO_u8_ACTIVE_STATE,BuzzerTask};
void main (void)
{

	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH); //Pull up resistor
	DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_HIGH); //Pull up resistor
	DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_HIGH); //Pull up resistor
	DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_HIGH); //Pull up resistor
	TIM_voidInitialize();
	TIM_voidEnableInt();
	RTO_voidInitialize();
	GIE_EnableGlobalInterrupt();
	RTO_voidCreateTask(&TaskKeypad,0);
	while(1)
	{

	}
}
void BuzzerTask(void)
{
	if(onFlag==0)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_HIGH);
		onFlag=1;
	}
	else if(onFlag==1)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		onFlag=0;
	}
}
void KeypadTask(void)
{
	u16 keyspressed;
	u8 i;
	static u8 TaskCreated=0;
	keyspressed=KEYPAD_u16GetStatus();
	for(i=0;i<16;i++)
	{
		if(1==GET_BIT(keyspressed,i))
		{
			if(0==TaskCreated)
			{
				TaskBuzzer.u8periodicity=i;
				RTO_voidCreateTask(&TaskBuzzer,1);
				TaskCreated=1;
			}
		}
		else if(keyspressed==0)
		{
			if(onFlag==1)
			{
				BuzzerTask();
				onFlag=0;
			}
				RTO_voidDeleteTask(1);
				TaskCreated=0;

		}
	}
}

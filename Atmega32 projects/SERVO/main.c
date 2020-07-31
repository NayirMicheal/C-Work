/*
 * main.c
 *
 *  Created on: 21 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_int.h"
#include "DIO_int.h"
#include "TIM_int.h"

u8 T_ON=25;
#define T_TOTAl 200
u8 degrees []={8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};
static  u8 counter;
static u8 innercounter=0;
static u8 i=1;
void Servo(void)
{
	TIM_voidInitCountingRegister(156);
	counter++;
	if(T_ON == counter)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
	}
	else if(T_TOTAl==counter)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
		counter=0;
		innercounter++;
	}
	if(innercounter == 10)
	{
		T_ON=degrees[i];
		i++;
		innercounter=0;
		if(i==17)
		{
			i=0;
		}
	}
}
void main(void)
{
	DIO_voidInitialize();
	TIM_voidInitialize();
	TIM_voidSetCallBack(Servo);
	TIM_voidEnableInt();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
	}
}

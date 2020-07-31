/*
 * main.c
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DELAY.h"
#include "DIO_int.h"
#include"GIE_int.h"
#include "EXTI_int.h"
void App(void)
{
	static u8 flag=0;
	if(flag==0)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
		flag=1;

	}
	else if(flag==1)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
		flag=0;
	}
Delay_ms(200);
}
void main(void)
{
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_26,DIO_u8_HIGH);
	EXTI_voidInit();
	EXTI_voidSetCallback(App);
	EXTI_voidEnable();
	GIE_EnableGlobalInterrupt();

	while(1)
	{

	}

}


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
#include "LED_MATRIX_int.h"
volatile static u8 flag=0;
u8 Gaffar[8]={0, 144, 147, 253, 147, 144, 0, 0};
u8 GaffarDance[8]={0, 72, 147, 253, 147, 72, 0, 0};
void App(void)
{
	if(flag==0)
	{
		flag=1;
	}
	else if(flag==1)
	{
		flag=0;
	}
}
void main(void)
{
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_26,DIO_u8_HIGH); //pull up resistor
	EXTI_voidInit();
	EXTI_voidSetCallback(App);
	EXTI_voidEnable();
	GIE_EnableGlobalInterrupt();

	while(1)
	{
		if(flag==0)
		{
			for(u8 i=0;i<7;i++)
				LED_MATRIX_voidLedMatrixOutputImage(Gaffar);
		}
		else if(flag==1)
		{
			for(u8 i=0;i<7;i++)
				LED_MATRIX_voidLedMatrixOutputImage(Gaffar);
			for(u8 i=0;i<7;i++)
				LED_MATRIX_voidLedMatrixOutputImage(GaffarDance);

		}
	}

}


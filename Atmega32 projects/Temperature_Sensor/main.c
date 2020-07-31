/*
 * main.c
 *
 *  Created on: 18 Apr 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DELAY.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "GIE_int.h"
void main (void)
{
	u16 Data;
	u32 Temperature;
	u32 BigData;
	DIO_voidInitialize();
	ADC_voidInit();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		ADC_voidStartConversion(ADC0,&Data);
		BigData =(u32) Data;
		Temperature = (u32)(((u32)(u32)BigData * (u16)500) /(u16)1024);

		if(Temperature==16)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_10,DIO_u8_LOW);
		}
		else if (Temperature >= 20 &&  Temperature <30)
		{

			DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PIN_10,DIO_u8_LOW);
		}
		else if (Temperature >30)
		{

			DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_10,DIO_u8_HIGH);
		}

	}
}


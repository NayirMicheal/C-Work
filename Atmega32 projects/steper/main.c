/*
 * main.c
 *
 *  Created on: 21 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DELAY.h"
#include "DIO_int.h"
void main(void)
{
	DIO_voidInitialize();

	while(1)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
		Delay_ms(2);
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
		Delay_ms(2);
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_HIGH);
		DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
		Delay_ms(2);
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_HIGH);
		Delay_ms(2);
	}
}

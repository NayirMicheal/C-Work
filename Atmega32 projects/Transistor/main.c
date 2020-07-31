/*
 * main.c
 *
 *  Created on: 7 Feb 2018
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
		Delay_ms(3000);
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
		Delay_ms(3000);
	}

}


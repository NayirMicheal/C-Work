/*
 * main.c
 *
 *  Created on: 6 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"DIO_int.h"
#include "DELAY.h"
#include "DIO_register.h"
int main (void)
{
	DIO_voidInitialize();

	while(1)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_HIGH);
		Delay_ms(20);
		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		Delay_ms(15);

	}
	return 0;
}

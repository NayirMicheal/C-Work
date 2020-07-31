/*
 * main.c
 *
 *  Created on: 19 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "DELAY.h"
#include "DIO_register.h"
#include "DIO_int.h"
#include "SWITCH_int.h"

void main (void)
{
	DIO_voidInitialize();

	while(1)
	{
		if(SWITCH_u8getSwitchState()==SWITCH_u8_PUSHED)
		{
				DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_HIGH);
		}
		else if (SWITCH_u8getSwitchState()==SWITCH_u8_RELEASED)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		}
	}
}

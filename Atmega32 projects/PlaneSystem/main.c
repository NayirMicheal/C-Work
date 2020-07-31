/*
 * main.c
 *
 *  Created on: 24 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"DIO_int.h"
#include"LEDS_int.h"
#include"SWD_int.h"
#include"SEVENSEG_int.h"
void main (void)
{
	DIO_voidInitialize();
	while(1)
	{
		for(u8 SwAndLedLoc=0;SwAndLedLoc<8;SwAndLedLoc++)
		{
			if(SWD_u8GetSwitchState(SwAndLedLoc)==SWD_u8PUSHED)
			{
				LEDS_voidSetLedOn(SwAndLedLoc);
			}
			else if(SWD_u8GetSwitchState(SwAndLedLoc)==SWD_u8RELEASED)
			{
				LEDS_voidSetLedOff(SwAndLedLoc);
			}
		}

	}
}

/*
 * main.c
 *
 *  Created on: 31 Jan 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DELAY.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "SEVENSEG_int.h"
#include "KEYPAD_int.h"
void main (void)
{
	u16 StatusKeys;
	u8 segtable[16]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000010,0b11111000,0b10000000,0b10010000,0b10001000,0b00000000,0b11000110,0b01000000,0b10000110,0b10001110};	DIO_voidInitialize();
	while(1)
	{
		StatusKeys=KEYPAD_u16GetStatus();
		for(u8 i=0;i<16;i++)
		{
			if(GET_BIT(StatusKeys,i))
			{
				SevenSeg_voidDisplayOnSeg(~segtable[i]);
				break;
			}
			else
			{
				DIO_voidSetPinValue(DIO_u8_PIN_24,DIO_u8_LOW);
			}
		}
		Delay_ms(200);
	}
}

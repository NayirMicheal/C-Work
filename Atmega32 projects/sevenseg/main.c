/*
 * main.c
 *
 *  Created on: 3 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_int.h"
#include"DIO_register.h"
#include"DELAY.h"
u8 segtable [10]={0b11000000,0b11111001,0b10100100,0b10110000,0b00011001,0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};
void DisplayNum(u8 num);
int main (void)
{
	DIO_voidInitialize();

	while(1)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_HIGH);
		PORTA=segtable[9];
		Delay_ms(1);
		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
		PORTA=segtable[5];
		Delay_ms(1);
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);

	}
}
void DisplayNum(u8 num)
{
	PORTA=segtable[num];
	PORTD=segtable[9-num];
}

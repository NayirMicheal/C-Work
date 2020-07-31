/*
 * main.c
 *
 *  Created on: 15 Jan 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DELAY.h"
#include "DIO_int.h"
#include "LCD_int.h"
void main (void)
{
	DIO_voidInitialize();
	LCD_voidInitialize();
u8 name []="nayir";

	while(1)
	{
LCD_voidClearDisplay();

LCD_voidWriteString(name,0,0);
Delay_ms(1000);

LCD_voidClearDisplay();

LCD_voidWriteString(name,3,1);
Delay_ms(1000);

LCD_voidClearDisplay();

LCD_voidWriteString(name,7,0);
Delay_ms(1000);

LCD_voidClearDisplay();

LCD_voidWriteString(name,11,1);
Delay_ms(1000);

	}
}

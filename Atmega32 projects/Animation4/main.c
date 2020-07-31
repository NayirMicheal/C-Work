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
	voidWriteCmd(0b01000000);

	voidWriteData(17);
	voidWriteData(10);
	voidWriteData(31);
	voidWriteData(27);
	voidWriteData(17);
	voidWriteData(31);
	voidWriteData(0);
	voidWriteData(0);

	voidWriteData(21);
	voidWriteData(10);
	voidWriteData(31);
	voidWriteData(27);
	voidWriteData(17);
	voidWriteData(31);
	voidWriteData(10);
	voidWriteData(31);

	voidWriteData(0);
	voidWriteCmd(0b10001110);
	voidWriteData(1);
	voidWriteCmd(0b10001101);
	voidWriteData(2);
	voidWriteCmd(0b10001100);
	voidWriteData(3);




	while(1)
	{
		LCD_voidInitialize();
		voidWriteCmd(0b10000000);
		voidWriteData(0);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);
		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(1);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(1);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(1);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(1);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(1);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(1);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(1);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(1);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(1);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(1);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(1);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(0xff);
		voidWriteData(1);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);

		LCD_voidClearDisplay();
		voidWriteData(0xfe);
		voidWriteData(1);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		voidWriteData(0xff);
		Delay_ms(1000);
	}
}

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
	LCD_voidWriteCmd(0b01000000);

	LCD_voidWriteData(0);
	LCD_voidWriteData(0);
	LCD_voidWriteData(4);
	LCD_voidWriteData(1);
	LCD_voidWriteData(1);
	LCD_voidWriteData(31);
	LCD_voidWriteData(0);
	LCD_voidWriteData(0);

	LCD_voidWriteData(1);
	LCD_voidWriteData(1);
	LCD_voidWriteData(1);
	LCD_voidWriteData(1);
	LCD_voidWriteData(1);
	LCD_voidWriteData(1);
	LCD_voidWriteData(0);
	LCD_voidWriteData(0);

	LCD_voidWriteData(0);
	LCD_voidWriteData(0);
	LCD_voidWriteData(0);
	LCD_voidWriteData(1);
	LCD_voidWriteData(1);
	LCD_voidWriteData(31);
	LCD_voidWriteData(0);
	LCD_voidWriteData(14);

	LCD_voidWriteData(0);
	LCD_voidWriteData(0);
	LCD_voidWriteData(0);
	LCD_voidWriteData(0);
	LCD_voidWriteData(0);
	LCD_voidWriteData(1);
	LCD_voidWriteData(2);
	LCD_voidWriteData(4);
	LCD_voidWriteCmd(0b10001111);
	LCD_voidWriteData(0);
	LCD_voidWriteCmd(0b10001110);
	LCD_voidWriteData(1);
	LCD_voidWriteCmd(0b10001101);
	LCD_voidWriteData(2);
	LCD_voidWriteCmd(0b10001100);
	LCD_voidWriteData(3);




	while(1)
	{



	}
}

/*
 * main.c
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DELAY.h"
#include "DIO_int.h"
#include "LCD_int.h"

void main(void)
{
	DIO_voidInitialize();
	LCD_voidInitialize();
	LCD_voidClearDisplay();
	DIO_voidSetPinValue(DIO_u8_PIN_4,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_5,DIO_u8_HIGH);
	while(1)
	{
		if(DIO_u8GetPinValue(DIO_u8_PIN_4)==DIO_u8_LOW)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
			LCD_voidWriteStringCurrentPosition("RIGHT");
		}
		else if(DIO_u8GetPinValue(DIO_u8_PIN_5)==DIO_u8_LOW)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_HIGH);
			LCD_voidWriteStringCurrentPosition("LEFT");
		}
		else{
			DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
			LCD_voidWriteStringCurrentPosition("STOP");
		}
		Delay_ms(100);
		LCD_voidClearDisplay();

	}

}


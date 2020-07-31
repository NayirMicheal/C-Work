/*
 * main.c
 *
 *  Created on: 23 Apr 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DELAY.h"
#include "DIO_int.h"
#include "GIE_int.h"
#include "UART.h"
#include "UART_H.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
void main (void)
{
	u8 Data[1];
	u16 Len;
	u16 KeypadReturn;
	u8 presskey=0;
	s8 pressedIndex=-1;
	u8 arrayTosend [2];
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_10,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_11,DIO_u8_HIGH);
	LCD_voidInitialize();
	UART_voidInit();
	UART_EnableRecieveInterrupt();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		KeypadReturn=KEYPAD_u16GetStatus();
		for(u8 i=0;i<16 && (!presskey);i++)
		{
			if(GET_BIT(KeypadReturn,i))
			{
				presskey=1;
				pressedIndex=i+1;
			}
		}
		if(pressedIndex > 0)
		{
			u8 i;
			if(pressedIndex >9)
			{
				i=1;
			}
			else
			{
				i=0;
			}
			while(pressedIndex)
			{
				arrayTosend[i]=(pressedIndex % 10)+'0';
				if(pressedIndex >9)
				{
					i--;
				}
				else
				{
					i++;
				}
				pressedIndex /=10;
			}
			UART_H_sendCommand(arrayTosend);
			pressedIndex=-1;
			presskey=0;
			arrayTosend[0]='\0';
			arrayTosend[1]='\0';
		}
		Uart_Receive(Data,&Len);
		if(Len == 1)
		{
			Data[1]='\0';
			LCD_voidWriteStringCurrentPosition(Data);
			Len=0;
		}
		Delay_ms(50);
	}
}

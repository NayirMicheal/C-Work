/*
 * main.c
 *
 *  Created on: 23 Apr 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY.h"
#include "DIO_int.h"
#include "GIE_int.h"
#include "UART.h"
#include "UART_H.h"
#include "LCD_int.h"

void main (void)
{
	u8 Data[20];
	u16 Len;
	DIO_voidInitialize();
	LCD_voidInitialize();
	UART_voidInit();
	UART_EnableRecieveInterrupt();
	GIE_EnableGlobalInterrupt();
	UART_H_sendCommand((u8 *)"AT+UART");
	while(1)
	{
		Uart_Receive(Data,&Len);
		if(Len >0)
		{
			Data[Len]='\0';
			LCD_voidWriteStringCurrentPosition(Data);
			Len=0;
		}
	}
}

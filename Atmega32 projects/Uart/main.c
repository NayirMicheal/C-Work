/*
 * main.c
 *
 *  Created on: 23 Apr 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DIO_int.h"
#include "UART.h"

void main (void)
{
	DIO_voidInitialize();
	UART_voidInit();
	UART_voidSend('N');
	UART_voidSend('A');
	UART_voidSend('Y');
	UART_voidSend('I');
	UART_voidSend('R');
	while(1)
	{

	}
}

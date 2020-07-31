/*
 * UART_H.c
 *
 *  Created on: 25 Apr 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART.h"

void UART_H_sendCommand(u8 * StringPtr)
{
	while(*StringPtr)
	{
		UART_voidSend(*StringPtr);
		StringPtr++;
	}
}


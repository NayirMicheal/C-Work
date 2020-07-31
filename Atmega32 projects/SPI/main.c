/*
 * main.c
 *
 *  Created on: 2 May 2018
 *      Author: Nayir
 */

#include "STD_TYPES.h"
#include "DIO_int.h"
#include "SPI_int.h"
#include "GIE_int.h"
#include "DELAY.h"
void main(void)
{
	//u8 data;
	DIO_voidInitialize();
	SPI_init();
	SPI_interruptEnable();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		SPI_transmit(5);
		Delay_ms(100);
	//	data=SPI_receive();
	//	if(data==1)
	//	{
	//		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
	//	}
//		else
//		{
//			DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
//		}
	}
}


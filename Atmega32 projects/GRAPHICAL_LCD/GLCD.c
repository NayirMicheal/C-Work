/*
 * GLCD.c
 *
 *  Created on: 2 May 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DELAY.h"
#include "DIO_int.h"
#include "SPI_int.h"
#include "GLCD.h"
static void GLCD_writeData(u8 Data)
{
	DIO_voidSetPinValue(DC_PIN,DIO_u8_HIGH);
	DIO_voidSetPinValue(CE_PIN,DIO_u8_LOW);
	SPI_transmit(Data);
	SPI_waitForTransferCompleteFlag();
	DIO_voidSetPinValue(CE_PIN,DIO_u8_HIGH);
}

static void GLCD_writeCommand(u8 command)
{
	DIO_voidSetPinValue(DC_PIN,DIO_u8_LOW);
	DIO_voidSetPinValue(CE_PIN,DIO_u8_LOW);
	SPI_transmit(command);
	SPI_waitForTransferCompleteFlag();
	DIO_voidSetPinValue(CE_PIN,DIO_u8_HIGH);
}

void GLCD_updateGlcd(u8 * ptr)
{
	for(u16 i=0;i<504;i++)
	{
		GLCD_writeData(ptr[i]);
	}
}

void GLCD_init(void)
{
	DIO_voidSetPinValue(RST_PIN,DIO_u8_HIGH);
	Delay_ms(2);
	DIO_voidSetPinValue(RST_PIN,DIO_u8_LOW);
	Delay_ms(2);
	DIO_voidSetPinValue(RST_PIN,DIO_u8_HIGH);
	Delay_ms(2);

	GLCD_writeCommand(0x21); //PD Power Down(active),V vertical or Horizonal, H Basic or Extended
	GLCD_writeCommand(0xBE); // to modify the contrast
	GLCD_writeCommand(0x06); //temperature coffiecent 2
	GLCD_writeCommand(0x13); // Baising system
	GLCD_writeCommand(0x20); // jump to basic instruction set
	GLCD_writeCommand(0x0c); //noraml mode display
}

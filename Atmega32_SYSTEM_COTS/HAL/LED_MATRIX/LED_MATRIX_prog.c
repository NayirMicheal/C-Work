/*
 * LED_MATRIX_prog.c
 *
 *  Created on: 16 Jan 2018
 *      Author: Nayir
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY.h"

#include"DIO_int.h"
#include "DIO_register.h"
#include"LED_MATRIX_priv.h"
#include "LED_MATRIX_int.h"
#include "LED_MATRIX_config.h"

void LED_MATRIX_voidCloseLedMatrix(void)
{
#if u8_LED_MATRIX_COL_PORT == u8_LED_MATRIX_PORTA
		PORTA=0xff;
#elif u8_LED_MATRIX_COL_PORT == u8_LED_MATRIX_PORTB
		PORTB=0xff;
#elif u8_LED_MATRIX_COL_PORT == u8_LED_MATRIX_PORTC
		PORTC=0xff;
#elif u8_LED_MATRIX_COL_PORT == u8_LED_MATRIX_PORTD
		PORTD=0xff;
#endif

}
void LED_MATRIX_voidLedMatrixOutputImage(u8* u8ImageCopy)
{
	u8 u8ColsActivationLoc [8] ={0b11111110,0b11111101,0b11111011,0b11110111,0b11101111,0b11011111,0b10111111,0b01111111};
	for(u8 u8ColAndRowsLoc=0;u8ColAndRowsLoc<u8_LED_MATRIX_SIZE;u8ColAndRowsLoc++)
	{
#if u8_LED_MATRIX_COL_PORT == u8_LED_MATRIX_PORTA
		PORTA=u8ColsActivationLoc[u8ColAndRowsLoc];
#elif u8_LED_MATRIX_COL_PORT == u8_LED_MATRIX_PORTB
		PORTB=u8ColsActivationLoc[u8ColAndRowsLoc];
#elif u8_LED_MATRIX_COL_PORT == u8_LED_MATRIX_PORTC
		PORTC=u8ColsActivationLoc[u8ColAndRowsLoc];
#elif u8_LED_MATRIX_COL_PORT == u8_LED_MATRIX_PORTD
		PORTD=u8ColsActivationLoc[u8ColAndRowsLoc];
#endif

#if u8_LED_MATRIX_ROW_PORT == u8_LED_MATRIX_PORTA
		PORTA=u8ImageCopy[u8ColAndRowsLoc];
#elif u8_LED_MATRIX_ROW_PORT == u8_LED_MATRIX_PORTB
		PORTB=u8ImageCopy[u8ColAndRowsLoc];
#elif u8_LED_MATRIX_ROW_PORT == u8_LED_MATRIX_PORTC
		PORTC=u8ImageCopy[u8ColAndRowsLoc];
#elif u8_LED_MATRIX_ROW_PORT == u8_LED_MATRIX_PORTD
		PORTD=u8ImageCopy[u8ColAndRowsLoc];
#endif
		Delay_ms(2);
	}

}

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

#include"LED_MATRIX_priv.h"
#include "LED_MATRIX_int.h"
#include "LED_MATRIX_config.h"

u8 cols [8] ={0b11111110,0b11111101,0b11111011,0b11110111,0b11101111,0b11011111,0b10111111,0b01111111};
void voidLedMatrixOutputImage(u8* u8ImageCopy)
{

	for(u8 u8CounterLocal=0; u8CounterLocal< u8_LED_MATRIX_SIZE; u8CounterLocal++)
	{
		/*Columns from 0 to 7 enable and disable depend on the row*/
		if(GET_BIT(cols[u8CounterLocal],0)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_0,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_0,DIO_u8_LOW);
		}

		if(GET_BIT(cols[u8CounterLocal],1)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_1,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_1,DIO_u8_LOW);
		}

		if(GET_BIT(cols[u8CounterLocal],2)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_2,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_2,DIO_u8_LOW);
		}

		if(GET_BIT(cols[u8CounterLocal],3)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_3,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_3,DIO_u8_LOW);
		}

		if(GET_BIT(cols[u8CounterLocal],4)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_4,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_4,DIO_u8_LOW);
		}

		if(GET_BIT(cols[u8CounterLocal],5)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_5,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_5,DIO_u8_LOW);
		}

		if(GET_BIT(cols[u8CounterLocal],6)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_6,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_6,DIO_u8_LOW);
		}

		if(GET_BIT(cols[u8CounterLocal],7)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_7,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_7,DIO_u8_LOW);
		}
		/*Out the suitable image on each row*/

		if(GET_BIT(u8ImageCopy[u8CounterLocal],0)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_0,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_0,DIO_u8_LOW);
		}

		if(GET_BIT(u8ImageCopy[u8CounterLocal],1)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_1,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_1,DIO_u8_LOW);
		}

		if(GET_BIT(u8ImageCopy[u8CounterLocal],2)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_2,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_2,DIO_u8_LOW);
		}

		if(GET_BIT(u8ImageCopy[u8CounterLocal],3)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_3,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_3,DIO_u8_LOW);
		}

		if(GET_BIT(u8ImageCopy[u8CounterLocal],4)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_4,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_4,DIO_u8_LOW);
		}

		if(GET_BIT(u8ImageCopy[u8CounterLocal],5)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_5,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_5,DIO_u8_LOW);
		}

		if(GET_BIT(u8ImageCopy[u8CounterLocal],6)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_6,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_6,DIO_u8_LOW);
		}

		if(GET_BIT(u8ImageCopy[u8CounterLocal],7)){
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_7,DIO_u8_HIGH);
		}
		else
		{
			DIO_voidSetPinValue(u8_LED_MATRIX_PIN_COL_7,DIO_u8_LOW);
		}
		Delay_ms(u8_LED_MATRIX_POV_DELAY);
	}
}

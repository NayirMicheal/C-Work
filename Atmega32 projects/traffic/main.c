/*
 * main.c
 *
 *  Created on: 3 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DIO_int.h"
#include"DIO_register.h"
#include"DELAY.h"
#define U8_RED_TRAFFIC_COUNTER 30
#define U8_YELLOW_TRAFFIC_COUNTER 5
#define U8_GREEN_TRAFFIC_COUNTER 30
#define U8_ZERO_COUNTER 0
#define U8_DECIMAL_DIVIDOR_CONVERTER 10
u8 segtable [10]={0b11000000,0b11111010,0b10100100,0b10110000,0b00011010,0b10010001,0b10000001,0b11111000,0b10000000,0b10010000};

void voidDisplayOnSeg(u8 u8Seg1Cpy,u8 u8Seg2Cpy);
int main (void)
{
	u8 u8TrafficCounter;
	u8 u8SegDigit1;
	u8 u8SegDigit2;
	DIO_voidInitialize();

	while(1)
	{
		u8TrafficCounter=U8_RED_TRAFFIC_COUNTER;
		DIO_voidSetPinValue(DIO_u8_PIN_10,DIO_u8_HIGH); //Red
			DIO_voidSetPinValue(DIO_u8_PIN_11,DIO_u8_LOW); //Yellow
			DIO_voidSetPinValue(DIO_u8_PIN_12,DIO_u8_LOW); //GREEN
		while(u8TrafficCounter!=U8_ZERO_COUNTER)
		{
		u8SegDigit1=u8TrafficCounter % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8TrafficCounter/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		for(u16 u8DelayCounter=0;u8DelayCounter<500;u8DelayCounter++){
		voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
		}
		u8TrafficCounter--;
		}
		u8TrafficCounter=U8_YELLOW_TRAFFIC_COUNTER;
		DIO_voidSetPinValue(DIO_u8_PIN_10,DIO_u8_LOW); //Red
		DIO_voidSetPinValue(DIO_u8_PIN_11,DIO_u8_HIGH); //Yellow
		DIO_voidSetPinValue(DIO_u8_PIN_12,DIO_u8_LOW); //Yellow
		while(u8TrafficCounter !=U8_ZERO_COUNTER )
		{
			u8SegDigit1=u8TrafficCounter % U8_DECIMAL_DIVIDOR_CONVERTER;
			u8SegDigit2=(u8TrafficCounter/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
			for(u16 u16DelayCounter=0;u16DelayCounter<500;u16DelayCounter++){
			voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
			}
			u8TrafficCounter--;
		}
		u8TrafficCounter=U8_GREEN_TRAFFIC_COUNTER;

		DIO_voidSetPinValue(DIO_u8_PIN_10,DIO_u8_LOW); //Red
		DIO_voidSetPinValue(DIO_u8_PIN_11,DIO_u8_LOW); //Yellow
		DIO_voidSetPinValue(DIO_u8_PIN_12,DIO_u8_HIGH); //Yellow
		while(u8TrafficCounter !=U8_ZERO_COUNTER)
		{
			u8SegDigit1=u8TrafficCounter % U8_DECIMAL_DIVIDOR_CONVERTER;
			u8SegDigit2=(u8TrafficCounter/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
			for(u16 u16DelayCounter=0;u16DelayCounter<500;u16DelayCounter++){
				voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
			}
			u8TrafficCounter--;

		}
	}
}
void voidDisplayOnSeg(u8 u8Seg1Cpy,u8 u8Seg2Cpy)
{
	DIO_voidSetPinValue(DIO_u8_PIN_16,DIO_u8_HIGH);
	PORTA=segtable[u8Seg1Cpy];
	Delay_ms(1);
	DIO_voidSetPinValue(DIO_u8_PIN_16,DIO_u8_LOW);
	DIO_voidSetPinValue(DIO_u8_PIN_17,DIO_u8_HIGH);
	PORTA=segtable[u8Seg2Cpy];
	Delay_ms(1);
	DIO_voidSetPinValue(DIO_u8_PIN_17,DIO_u8_LOW);
}

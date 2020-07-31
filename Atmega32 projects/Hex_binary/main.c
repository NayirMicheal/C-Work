/*
 * main.c
 *
 *  Created on: 3 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DELAY.h"
#include"DIO_register.h"
#include"DIO_int.h"
#include"LEDS_int.h"

#define u8_INDEX0 0
#define u8_INDEX1 1
#define u8_INDEX2 2
#define u8_INDEX3 3
#define u8_INDEX4 4
#define u8_INDEX5 5
#define u8_INDEX6 6
#define u8_INDEX7 7
#define U8_HEX_DIVIDOR_CONVERTER 16
#define u8_FULL_UNSIGNED_EIGHT_BIT_NUMBER 255
#define u8_LED_COUTER 100
#define u8_SEVEN_DIGHT 128
#define u8_SIX_DIGHT 64
#define u8_FIVE_DIGHT 32
#define u8_FOUR_DIGHT 16
#define u8_THREE_DIGHT 8
#define u8_TWO_DIGHT 4
#define u8_ONE_DIGHT 2
#define u8_ZERO_DIGHT 1
u8 segtable [16]={0b11000000,0b11111010,0b10100100,0b10110000,0b10011010,0b00010001,0b10000001,0b11111000,0b10000000,0b10010000,0b10001000,0b00000000,0b11000101,0b01000000,0b10000101,0b10001101};
void voidDecimalDexCounter(void);
void voidDisplayOnSeg(u8 u8Seg1Cpy,u8 u8Seg2Cpy);
int main (void)
{
	DIO_voidInitialize();

	while(1)
	{
	/*PORTA for Segment*/
	/*PORTB for Led*/
	/*PORTC pin 0 , 1 for Common Anode*/
	voidDecimalDexCounter();
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

void voidDecimalDexCounter(void)
{
	u8 u8CounterLoc;
	u8 u8HexCounterLoc;
	u8 u8SegDigit1;
	u8 u8SegDigit2;
	for(u8 temp=1;temp<=u8_FULL_UNSIGNED_EIGHT_BIT_NUMBER;temp++)
	{
		u8CounterLoc=temp;
		u8HexCounterLoc=temp;
		if((u8CounterLoc-u8_SEVEN_DIGHT)>=u8_INDEX0)
		{
			u8CounterLoc-=u8_SEVEN_DIGHT;
			LEDS_voidSetLedOn(LEDS_u8_LED7);
		}
		if((u8CounterLoc-u8_SIX_DIGHT)>=u8_INDEX0)
		{
			u8CounterLoc-=u8_SIX_DIGHT;
			LEDS_voidSetLedOn(LEDS_u8_LED6);
		}
		if((u8CounterLoc-u8_FIVE_DIGHT)>=u8_INDEX0)
		{
			u8CounterLoc-=u8_FIVE_DIGHT;
			LEDS_voidSetLedOn(LEDS_u8_LED5);
		}
		if((u8CounterLoc-u8_FOUR_DIGHT)>=u8_INDEX0)
		{
			u8CounterLoc-=u8_FOUR_DIGHT;
			LEDS_voidSetLedOn(LEDS_u8_LED4);
		}
		if((u8CounterLoc-u8_THREE_DIGHT)>=u8_INDEX0)
		{
			u8CounterLoc-=u8_THREE_DIGHT;
			LEDS_voidSetLedOn(LEDS_u8_LED3);
		}
		if((u8CounterLoc-u8_TWO_DIGHT)>=u8_INDEX0)
		{
			u8CounterLoc-=u8_TWO_DIGHT;
			LEDS_voidSetLedOn(LEDS_u8_LED2);
		}
		if((u8CounterLoc-u8_ONE_DIGHT)>=u8_INDEX0)
		{
			u8CounterLoc-=u8_ONE_DIGHT;
			LEDS_voidSetLedOn(LEDS_u8_LED1);
		}
		if((u8CounterLoc-u8_ZERO_DIGHT)>=u8_INDEX0)
		{
			u8CounterLoc-=u8_ZERO_DIGHT;
			LEDS_voidSetLedOn(LEDS_u8_LED0);
		}
		for(u8 u8DelayCounter=0;u8DelayCounter<150;u8DelayCounter++)
		{
			u8SegDigit1=u8HexCounterLoc % 16;
			u8SegDigit2=(u8HexCounterLoc/16)%16;
			voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
		}
		LEDS_voidSetLedOff(LEDS_u8_LED0);
		LEDS_voidSetLedOff(LEDS_u8_LED1);
		LEDS_voidSetLedOff(LEDS_u8_LED2);
		LEDS_voidSetLedOff(LEDS_u8_LED3);
		LEDS_voidSetLedOff(LEDS_u8_LED4);
		LEDS_voidSetLedOff(LEDS_u8_LED5);
		LEDS_voidSetLedOff(LEDS_u8_LED6);
		LEDS_voidSetLedOff(LEDS_u8_LED7);
		for(u8 u8DelayCounter=0;u8DelayCounter<150;u8DelayCounter++)
		{
			u8SegDigit1=u8HexCounterLoc % U8_HEX_DIVIDOR_CONVERTER;
			u8SegDigit2=(u8HexCounterLoc/U8_HEX_DIVIDOR_CONVERTER)%U8_HEX_DIVIDOR_CONVERTER;
			voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
		}
	}
}

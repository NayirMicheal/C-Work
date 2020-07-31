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
#define u8_FULL_UNSIGNED_EIGHT_BIT_NUMBER 255
#define u8_LED_COUTER 30
#define u8_SEVEN_DIGHT 128
#define u8_SIX_DIGHT 64
#define u8_FIVE_DIGHT 32
#define u8_FOUR_DIGHT 16
#define u8_THREE_DIGHT 8
#define u8_TWO_DIGHT 4
#define u8_ONE_DIGHT 2
#define u8_ZERO_DIGHT 1
#define U8_FIRST_ANIMATION 1
#define U8_DECIMAL_DIVIDOR_CONVERTER 10
#define U8_PATERN_ARRAY_SIZE 10
#define U8_FOR_1_COUNTER 100
#define U8_FOR_2_COUNTER 150
#define U8_FOR_3_COUNTER 250
u8 segtable [U8_PATERN_ARRAY_SIZE]={0b11000000,0b11111010,0b10100100,0b10110000,0b00011010,0b10010001,0b10000001,0b11111000,0b10000000,0b10010000};
void voidAnimationOne(u8 u8SegDigit1,u8 u8SegDigit2);
void voidAnimationTwo(u8 u8SegDigit1,u8 u8SegDigit2);
void voidAnimationThree(u8 u8SegDigit1,u8 u8SegDigit2);
void voidAnimationFour(u8 u8SegDigit1,u8 u8SegDigit2);
void voidAnimationFive(u8 u8SegDigit1,u8 u8SegDigit2);
void voidAnimationSix(u8 u8SegDigit1,u8 u8SegDigit2);
void voidDisplayOnSeg(u8 u8Seg1Cpy,u8 u8Seg2Cpy);
int main (void)
{
	u8 u8AnimationNumber;
	u8 u8SegDigit1;
	u8 u8SegDigit2;
	DIO_voidInitialize();

	while(1)
	{
		/*PORTA for Segment*/
		/*PORTB for Led*/
		/*PORTC pin 0 , 1 for Common Anode*/
		u8AnimationNumber=U8_FIRST_ANIMATION;/*First Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationOne(u8SegDigit1,u8SegDigit2);

		u8AnimationNumber++;/*Second Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationTwo(u8SegDigit1,u8SegDigit2);

		u8AnimationNumber++;/*Third Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationThree(u8SegDigit1,u8SegDigit2);

		u8AnimationNumber++;/*Fourth Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationFour(u8SegDigit1,u8SegDigit2);

		u8AnimationNumber++;/*FiFth Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationThree(u8SegDigit1,u8SegDigit2);

		u8AnimationNumber++;/*Sixth Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationTwo(u8SegDigit1,u8SegDigit2);


		u8AnimationNumber++;/*Seventh Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationOne(u8SegDigit1,u8SegDigit2);

		u8AnimationNumber++;/*Eight Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationThree(u8SegDigit1,u8SegDigit2);

		u8AnimationNumber++;/*ninth Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationTwo(u8SegDigit1,u8SegDigit2);

		u8AnimationNumber++;/*Tenth Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationOne(u8SegDigit1,u8SegDigit2);

		u8AnimationNumber++;/*Eleventh Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationFive(u8SegDigit1,u8SegDigit2);

		u8AnimationNumber++;/*twelve Animation*/
		u8SegDigit1=u8AnimationNumber % U8_DECIMAL_DIVIDOR_CONVERTER;
		u8SegDigit2=(u8AnimationNumber/U8_DECIMAL_DIVIDOR_CONVERTER)%U8_DECIMAL_DIVIDOR_CONVERTER;
		voidAnimationSix(u8SegDigit1,u8SegDigit2);
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
void voidAnimationOne(u8 u8SegDigit1,u8 u8SegDigit2)
{

	for(u8 u8IndexLoc=0;u8IndexLoc< LEDS_u8_NUMBEROFLEDS;u8IndexLoc++)
	{
		LEDS_voidSetLedOn(u8IndexLoc%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX1)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX2)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX3)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX4)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX5)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX6)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX7)%LEDS_u8_NUMBEROFLEDS);
		if(u8IndexLoc!=u8_INDEX7)
		for(u8 u8DelayCounter=0;u8DelayCounter<U8_FOR_1_COUNTER;u8DelayCounter++)
			voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
	}

	for(u8 u8IndexLoc=LEDS_u8_NUMBEROFLEDS;u8IndexLoc>u8_INDEX0;u8IndexLoc--)
	{
		LEDS_voidSetLedOn((u8IndexLoc-u8_INDEX1)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX1)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX2)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX3)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX4)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX5)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX6)%LEDS_u8_NUMBEROFLEDS);
		if (u8IndexLoc!=u8_INDEX1)
			for(u8 u8DelayCounter=0;u8DelayCounter<U8_FOR_1_COUNTER;u8DelayCounter++)
				voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
	}
}

void voidAnimationTwo(u8 u8SegDigit1,u8 u8SegDigit2)
{
	for(u8 u8IndexLoc=0;u8IndexLoc < (LEDS_u8_NUMBEROFLEDS/u8_INDEX2);u8IndexLoc++)
	{
		LEDS_voidSetLedOn(u8IndexLoc);
		LEDS_voidSetLedOn(u8_INDEX7-u8IndexLoc);
		for(u8 u8DelayCounter=0;u8DelayCounter<U8_FOR_2_COUNTER;u8DelayCounter++)
			voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
	}
	for(u8 u8IndexLoc=3;u8IndexLoc<LEDS_u8_NUMBEROFLEDS/u8_INDEX2;u8IndexLoc++)
		{
		LEDS_voidSetLedOff(u8IndexLoc);
		LEDS_voidSetLedOff(u8_INDEX7-u8IndexLoc);
		if(u8IndexLoc!=u8_INDEX3)
			for(u8 u8DelayCounter=0;u8DelayCounter<U8_FOR_2_COUNTER;u8DelayCounter++)
				voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
		}
}
void voidAnimationThree(u8 u8SegDigit1,u8 u8SegDigit2)
{
	LEDS_voidSetLedOn(LEDS_u8_LED0);
	LEDS_voidSetLedOn(LEDS_u8_LED1);
	LEDS_voidSetLedOn(LEDS_u8_LED2);
	LEDS_voidSetLedOn(LEDS_u8_LED3);
	LEDS_voidSetLedOn(LEDS_u8_LED4);
	LEDS_voidSetLedOn(LEDS_u8_LED5);
	LEDS_voidSetLedOn(LEDS_u8_LED6);
	LEDS_voidSetLedOn(LEDS_u8_LED7);
	for(u8 u8DelayCounter=0;u8DelayCounter<U8_FOR_3_COUNTER;u8DelayCounter++)
		voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
	LEDS_voidSetLedOff(LEDS_u8_LED0);
	LEDS_voidSetLedOff(LEDS_u8_LED1);
	LEDS_voidSetLedOff(LEDS_u8_LED2);
	LEDS_voidSetLedOff(LEDS_u8_LED3);
	LEDS_voidSetLedOff(LEDS_u8_LED4);
	LEDS_voidSetLedOff(LEDS_u8_LED5);
	LEDS_voidSetLedOff(LEDS_u8_LED6);
	LEDS_voidSetLedOff(LEDS_u8_LED7);
	for(u8 u8DelayCounter=0;u8DelayCounter<U8_FOR_3_COUNTER;u8DelayCounter++)
			voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);

}

void voidAnimationFour(u8 u8SegDigit1,u8 u8SegDigit2)
{
	u8 u8CounterLoc=0;
	for(u8 u8ForCounterLoc=1;u8ForCounterLoc<=u8_LED_COUTER;u8ForCounterLoc++)
	{
		u8CounterLoc=u8ForCounterLoc;
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
		for(u8 u8DelayCounterLoc=0;u8DelayCounterLoc<U8_FOR_2_COUNTER;u8DelayCounterLoc++)
		{
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
		for(u8 u8DelayCounterLoc=0;u8DelayCounterLoc<U8_FOR_2_COUNTER;u8DelayCounterLoc++)
		{
			voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
		}
	}
}
void voidAnimationFive(u8 u8SegDigit1,u8 u8SegDigit2)
{
	for(u8 u8IndexLoc=0;u8IndexLoc< LEDS_u8_NUMBEROFLEDS/u8_INDEX2;u8IndexLoc++)
	{
		LEDS_voidSetLedOn(u8IndexLoc%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX1)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOn((u8IndexLoc+u8_INDEX2)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX3)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOn((u8IndexLoc+u8_INDEX4)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX5)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOn((u8IndexLoc+u8_INDEX6)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX7)%LEDS_u8_NUMBEROFLEDS);
		if(u8IndexLoc!=u8_INDEX7)
		for(u8 u8DelayCounterLoc=0;u8DelayCounterLoc<U8_FOR_2_COUNTER;u8DelayCounterLoc++)
			voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
	}

}

void voidAnimationSix(u8 u8SegDigit1,u8 u8SegDigit2)
{
	for(u8 u8IndexLoc=0;u8IndexLoc< LEDS_u8_NUMBEROFLEDS/u8_INDEX2;u8IndexLoc++)
	{
		LEDS_voidSetLedOn(u8IndexLoc%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOn((u8IndexLoc+u8_INDEX1)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOn((u8IndexLoc+u8_INDEX2)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOn((u8IndexLoc+u8_INDEX3)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX4)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX5)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX6)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+u8_INDEX7)%LEDS_u8_NUMBEROFLEDS);
		if(u8IndexLoc!=u8_INDEX7)
		for(u8 u8DelayCounterLoc=0;u8DelayCounterLoc<U8_FOR_2_COUNTER;u8DelayCounterLoc++)
			voidDisplayOnSeg(u8SegDigit1,u8SegDigit2);
	}

}

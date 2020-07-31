/*
 * main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: felo
 */

#include"STD_TYPES.h"
#include"DIO_int.h"
#include"LEDS_int.h"
#include"DELAY.h"
#define u8_INDEX0 0
#define u8_INDEX1 1
#define u8_INDEX2 2
#define u8_INDEX3 3
#define u8_INDEX4 4
#define u8_INDEX5 5
#define u8_INDEX6 6
#define u8_INDEX7 7
#define u8_FULL_UNSIGNED_EIGHT_BIT_NUMBER 255
#define u8_SEVEN_DIGHT 128
#define u8_SIX_DIGHT 64
#define u8_FIVE_DIGHT 32
#define u8_FOUR_DIGHT 16
#define u8_THREE_DIGHT 8
#define u8_TWO_DIGHT 4
#define u8_ONE_DIGHT 2
#define u8_ZERO_DIGHT 1
void voidAnimationOne(void);
void voidAnimationTwo(void);
void voidAnimationThree(void);
void voidAnimationFour(void);
int main(void)
{

	DIO_voidInitialize();
	LEDS_voidSetLedOff(LEDS_u8_LED0);
	LEDS_voidSetLedOff(LEDS_u8_LED1);
	LEDS_voidSetLedOff(LEDS_u8_LED2);
	LEDS_voidSetLedOff(LEDS_u8_LED3);
	LEDS_voidSetLedOff(LEDS_u8_LED4);
	LEDS_voidSetLedOff(LEDS_u8_LED5);
	LEDS_voidSetLedOff(LEDS_u8_LED6);
	LEDS_voidSetLedOff(LEDS_u8_LED7);
	while(1)
	{

		voidAnimationOne();

		voidAnimationTwo();
		voidAnimationTwo();

		voidAnimationThree();
		voidAnimationThree();
		voidAnimationThree();
		//voidAnimationThree();
		voidAnimationFour();
	}
return 0;
}
void voidAnimationOne(void)
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
		Delay_ms(300);
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
		Delay_ms(300);
	}
}

void voidAnimationTwo(void)
{
	for(u8 u8IndexLoc=0;u8IndexLoc < (LEDS_u8_NUMBEROFLEDS/u8_INDEX2);u8IndexLoc++)
	{
		LEDS_voidSetLedOn(u8IndexLoc);
		LEDS_voidSetLedOn(u8_INDEX7-u8IndexLoc);
		Delay_ms(300);
	}
	for(u8 u8IndexLoc=3;u8IndexLoc<LEDS_u8_NUMBEROFLEDS;u8IndexLoc++)
		{
			LEDS_voidSetLedOff(u8IndexLoc);
			LEDS_voidSetLedOff(u8_INDEX7-u8IndexLoc);
			if(u8IndexLoc!=u8_INDEX3)
			Delay_ms(300);
		}
}
void voidAnimationThree(void)
{


		LEDS_voidSetLedOn(LEDS_u8_LED0);
		LEDS_voidSetLedOn(LEDS_u8_LED1);
		LEDS_voidSetLedOn(LEDS_u8_LED2);
		LEDS_voidSetLedOn(LEDS_u8_LED3);
		LEDS_voidSetLedOn(LEDS_u8_LED4);
		LEDS_voidSetLedOn(LEDS_u8_LED5);
		LEDS_voidSetLedOn(LEDS_u8_LED6);
		LEDS_voidSetLedOn(LEDS_u8_LED7);
		Delay_ms(500);
		LEDS_voidSetLedOff(LEDS_u8_LED0);
		LEDS_voidSetLedOff(LEDS_u8_LED1);
		LEDS_voidSetLedOff(LEDS_u8_LED2);
		LEDS_voidSetLedOff(LEDS_u8_LED3);
		LEDS_voidSetLedOff(LEDS_u8_LED4);
		LEDS_voidSetLedOff(LEDS_u8_LED5);
		LEDS_voidSetLedOff(LEDS_u8_LED6);
		LEDS_voidSetLedOff(LEDS_u8_LED7);
		Delay_ms(500);

}

void voidAnimationFour(void)
{
	u8 u8CounterLoc=0;
	for(u8 temp=1;temp<=u8_FULL_UNSIGNED_EIGHT_BIT_NUMBER;temp++)
	{
		u8CounterLoc=temp;
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
		Delay_ms(300);
		LEDS_voidSetLedOff(LEDS_u8_LED0);
		LEDS_voidSetLedOff(LEDS_u8_LED1);
		LEDS_voidSetLedOff(LEDS_u8_LED2);
		LEDS_voidSetLedOff(LEDS_u8_LED3);
		LEDS_voidSetLedOff(LEDS_u8_LED4);
		LEDS_voidSetLedOff(LEDS_u8_LED5);
		LEDS_voidSetLedOff(LEDS_u8_LED6);
		LEDS_voidSetLedOff(LEDS_u8_LED7);
		Delay_ms(300);
	}
}

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

#define U8_INDEX0 0
#define U8_INDEX1 1
#define U8_INDEX2 2
#define U8_INDEX3 3
#define U8_INDEX4 4
#define U8_INDEX5 5
#define U8_SEVEN_SEGMENT_PATERN_NUMBERS 6
u8 u8SegPatern [U8_SEVEN_SEGMENT_PATERN_NUMBERS]={0b11111101,0b11111110,0b11111011,0b11110111,0b11101111,0b11011111};
void voidAnimationOne(void);
void voidDisplayPatern(u8 u8Patern);
int main (void)
{
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_16,DIO_u8_HIGH);
	while(1)
	{
		/*PORTA for segment and common on pin7 portA*/
		/*PORTB for Led 6 pins only*/
		voidAnimationOne();

	}
}
void voidDisplayPatern(u8 u8Patern)
{
	Delay_ms(1);
	PORTA=u8SegPatern[u8Patern];
	Delay_ms(1);
}
void voidAnimationOne(void)
{
	for(u8 u8IndexLoc=0;u8IndexLoc< LEDS_u8_NUMBEROFLEDS;u8IndexLoc++)
	{
		LEDS_voidSetLedOn(u8IndexLoc%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+U8_INDEX1)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+U8_INDEX2)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+U8_INDEX3)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+U8_INDEX4)%LEDS_u8_NUMBEROFLEDS);
		LEDS_voidSetLedOff((u8IndexLoc+U8_INDEX5)%LEDS_u8_NUMBEROFLEDS);
		for(u8 u8DelayCounter=0;u8DelayCounter<150;u8DelayCounter++)
			voidDisplayPatern(u8IndexLoc);
	}
}


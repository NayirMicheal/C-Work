/*
 * main.c
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "LEDS_int.h"
#include "SEVENSEG_int.h"
#include "GIE_int.h"
#include "RTO_int.h"
#define MOTOR_RIGHT DIO_u8_PIN_27
#define MOTOR_LEFT DIO_u8_PIN_28
#define BUZZER DIO_u8_PIN_29
u8 leds[8]={0,1,2,3,4,5,6,7};
u8 segtable[10]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};
static u8 X_Eng=-1,Y_ENG=0,X_AR=15,Y_AR=1;
u8 charcterOne[8]={16, 16, 20, 17, 17, 31, 0, 0};
u8 charcterTwo[8]={0, 0, 0, 0, 9, 15, 8, 27};
void Leds_Task(void)
{
	static u8 ledcounter=0;
	static u8 upflag=0;
	for(u8 localCounter=0;localCounter<8;localCounter++)
	{
		if(localCounter==ledcounter)
		{
			LEDS_voidSetLedOn(leds[localCounter]);
		}
		else
		{
			LEDS_voidSetLedOff(leds[localCounter]);
		}
		if(ledcounter == 0)
		{
			upflag=1;
		}
		else if(ledcounter == 7)
		{
			upflag=0;
		}
	}
	if(upflag==1)
	{
		ledcounter++;
	}
	else if(upflag==0)
	{
		ledcounter--;
	}
}
void Motor_Task(void)
{
	static u8 right=0;
	if(right==0)
	{
		DIO_voidSetPinValue(MOTOR_RIGHT,DIO_u8_HIGH);
		DIO_voidSetPinValue(MOTOR_LEFT,DIO_u8_LOW);
		right=1;
	}
	else if(right==1)
	{
		DIO_voidSetPinValue(MOTOR_RIGHT,DIO_u8_LOW);
		DIO_voidSetPinValue(MOTOR_LEFT,DIO_u8_HIGH);
		right=0;
	}
}
void SevenSeg_Task(void)
{
	static u8 segment_counter=0;
	static u8 upflagsegment=0;

	if(segment_counter==0)
	{
		upflagsegment=1;
	}
	else if(segment_counter==9)
	{
		upflagsegment=0;
	}

	if(upflagsegment==1)
	{
		segment_counter++;
	}
	else if(upflagsegment==0)
	{
		segment_counter--;
	}
	SevenSeg_voidDisplayOnSeg(~segtable[segment_counter]);
}
void Buzzer_Task(void)
{
	u8 static buzzercounter=0;
	buzzercounter++;
	if(buzzercounter==1)
	{
		DIO_voidSetPinValue(BUZZER,DIO_u8_HIGH);
	}
	else if(buzzercounter==2)
	{
		DIO_voidSetPinValue(BUZZER,DIO_u8_LOW);
	}
	else if(buzzercounter==5)
	{
		buzzercounter=0;
	}

}
void LCD_E_TASK(void)
{
	LCD_voidClearDisplay();
	LCD_voidWriteStringXY("Nayir",X_Eng,Y_ENG);
	LCD_voidWriteCustomChar(0,X_AR,Y_AR);
	LCD_voidWriteCustomChar(1,X_AR-1,Y_AR);
	X_Eng++;
	if(X_Eng==17)
	{
		X_Eng=0;
	}
}
void LCD_A_TASK(void)
{
	LCD_voidClearDisplay();
	LCD_voidWriteStringXY("Nayir",X_Eng,Y_ENG);
	LCD_voidWriteCustomChar(0,X_AR,Y_AR);
	LCD_voidWriteCustomChar(1,X_AR-1,Y_AR);
	X_AR--;
	if(X_AR==0)
	{
		X_AR=15;
	}
}
void main(void)
{
	DIO_voidInitialize();
	LCD_voidInitialize();
	LCD_voidDrawCustomChar(charcterOne,0);
	LCD_voidDrawCustomChar(charcterTwo,1);
	Timer0_init();
	GIE_EnableGlobalInterrupt();
	while(1)
	{


	}
}




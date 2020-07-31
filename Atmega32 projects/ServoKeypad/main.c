/*
 * main.c
 *
 *  Created on: 21 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_int.h"
#include "DIO_int.h"
#include "TIM_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
#include "DELAY.h"
u16 T_ON=6;
#define T_TOTAl 200UL
static  u16 counter;
void SetDegree(u8 degree)
{
	T_ON=degree+6;
}
void Servo(void)
{
	TIM_voidInitCountingRegister(156);
	counter++;
	if(T_ON == counter)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
	}
	else if(T_TOTAl==counter)
	{
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
		counter=0;
	}
}
void main(void)
{
	u16 KeypadPressed=0;
	static u8 released=1;
	u8 degree=0;
	DIO_voidInitialize();
	//////////////////////////////////////////////
	// pull up resistor for the keypad
	DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_10,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_11,DIO_u8_HIGH);
	//////////////////////////////////////////////
	LCD_voidInitialize();
	TIM_voidInitialize();
	TIM_voidSetCallBack(Servo);
	TIM_voidEnableInt();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		KeypadPressed=KEYPAD_u16GetStatus();
		switch(KeypadPressed)
		{
		case 0:
			released=1;
			break;
		case 1:
			if(1==released)
			{
				degree=(degree*10)+1;
				LCD_voidWriteStringCurrentPosition((u8 *)"1");
				released=0;
			}
			break;
		case 2:
			if(1==released)
			{
				degree=(degree*10)+2;
				LCD_voidWriteStringCurrentPosition((u8 *)"2");
				released=0;
			}
			break;
		case 4:
			if(1==released)
			{
				degree=(degree*10)+3;
				LCD_voidWriteStringCurrentPosition((u8 *)"3");
				released=0;
			}
			break;
		case 8:
			break;
		case 16:
			if(1==released)
			{
				degree=(degree*10)+4;
				LCD_voidWriteStringCurrentPosition((u8 *)"4");
				released=0;
			}
			break;
		case 32:
			if(1==released)
			{
				degree=(degree*10)+5;
				LCD_voidWriteStringCurrentPosition((u8 *)"5");
				released=0;
			}
			break;
		case 64:
			if(1==released)
			{
				degree=(degree*10)+6;
				LCD_voidWriteStringCurrentPosition((u8 *)"6");
				released=0;
			}
			break;
		case 128:
			break;
		case 256:
			if(1==released)
			{
				degree=(degree*10)+7;
				LCD_voidWriteStringCurrentPosition((u8 *)"7");
				released=0;
			}
			break;
		case 512:
			if(1==released)
			{
				degree=(degree*10)+8;
				LCD_voidWriteStringCurrentPosition((u8 *)"8");
				released=0;
			}
			break;
		case 1024:
			if(1==released)
			{
				degree=(degree*10)+9;
			LCD_voidWriteStringCurrentPosition((u8 *)"9");
			released=0;
			}
			break;
		case 2048:
			break;
		case 4096:
			break;
		case 8192:
			if(1==released)
			{
				degree=(degree*10)+0;
				LCD_voidWriteStringCurrentPosition((u8 *)"0");
				released=0;
			}
			break;
		case 16384:
			if(1==released)
			{
				LCD_voidClearDisplay();
				degree/=10;
				SetDegree(degree);
				degree=0;
				released=0;
			}
			break;
		case 32768:
			break;
		}
	}
}

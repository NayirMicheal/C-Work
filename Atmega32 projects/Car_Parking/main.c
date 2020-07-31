/*
 * main.c
 *
 *  Created on: 21 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DELAY.h"
#include "GIE_int.h"
#include "DIO_int.h"
#include "EXTI_int.h"
#include "TIM_int.h"
#include "LCD_int.h"
static u8 Exti_flag=2;
static u8 Exti_flag_back=0;
static u8  cars=5;
static u8 digitOne,digitTwo;
u8* arr [10]={(u8 *)"0",(u8 *)"1",(u8 *)"2",(u8 *)"3",(u8 *)"4",(u8 *)"5",(u8 *)"6",(u8 *)"7",(u8 *)"8",(u8 *)"9"};
void Motor(void);

void parKCar(void)
{
	static u8 firsttime=0;
	if(1==firsttime && cars !=0)
	{
		Exti_flag=TOG_BIT(Exti_flag_back,0);
		TOG_BIT(PORTB,0);
	}
	firsttime=1;
}
void main(void)
{
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_26,DIO_u8_HIGH); // for IR Reciever pull up
	LCD_voidInitialize();
	TIM_voidInitialize();
	EXTI_voidInit();
	EXTI_voidSetCallback(parKCar);
	EXTI_voidEnable(); // on pin 26 pin D2
	GIE_EnableGlobalInterrupt();
	LCD_voidWriteStringCurrentPosition((u8 *)"cars:");
	digitOne=cars % 10;
	digitTwo=cars / 10;
	LCD_voidWriteStringXY(arr[digitOne],7,0);
	LCD_voidWriteStringXY(arr[digitTwo],6,0);
	while(1)
	{
		if(0==Exti_flag || 1==Exti_flag)
		{
			Motor();
		}
	}
}
void Motor(void)
{
	if((cars !=0 )&&(1==Exti_flag))
	{
		if(cars >=0)
		{
			for(u8 i=0;i<128;i++)
			{
				DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
				DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
				Delay_ms(2);
				DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_HIGH);
				DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
				Delay_ms(2);
				DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_HIGH);
				DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
				Delay_ms(2);
				DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
				DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_HIGH);
				Delay_ms(2);
			}

		}
	}
	else if((0==Exti_flag))
	{
		cars--;
		digitOne=cars % 10;
		digitTwo=cars / 10;
		LCD_voidWriteStringXY(arr[digitOne],7,0);
		LCD_voidWriteStringXY(arr[digitTwo],6,0);
		for(u8 i=0;i<128;i++)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_HIGH);
			Delay_ms(2);
			DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
			Delay_ms(2);
			DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
			Delay_ms(2);
			DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
			DIO_voidSetPinValue(DIO_u8_PIN_1,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_2,DIO_u8_LOW);
			DIO_voidSetPinValue(DIO_u8_PIN_3,DIO_u8_LOW);
			Delay_ms(2);
		}
	}
	Exti_flag=2;
}

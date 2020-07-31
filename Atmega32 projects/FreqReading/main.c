/*
 * main.c
 *
 *  Created on: 27 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "GIE_int.h"
#include "EXTI_int.h"
#include "TIM1_int.h"
#include "TIM_int.h"
#include "LCD_int.h"
static u8 flag=0;
static u16 Ton=0;
static u16 Toff=0;
static u8 firstTime=0;
static u8 End=0;
static u8 Write=0;
static u8 Xpos=8;
static const u8* Numbers[10]  ={(u8 *)"0",(u8 *)"1",(u8 *)"2",(u8 *)"3",(u8 *)"4",(u8 *)"5",(u8 *)"6",(u8 *)"7",(u8 *)"8",(u8 *)"9"};
void getFreqancyData(void)
{
	if(End==0)
	{

		if(flag==0)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
			voidTIM1_StartCount();
			EXTI_voidChangeMode(EXTI_u8_FALLING_EDGE);
			if(firstTime==1)
			{
				Toff=VoidTIM1_GetCounter();
				End=1;
			}
			flag=1;
		}
		else if(flag==1)
		{
			Ton=VoidTIM1_GetCounter();
			voidTIM1_ClearCounter();
			EXTI_voidChangeMode(EXTI_u8_RAISING_EDGE);
			firstTime=1;
			flag=0;
		}
	}

}
void main(void)
{
	u32 Duty;
	u32 Freq;
	u8 digit;
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_26,DIO_u8_HIGH);//Pull up resistor
	LCD_voidInitialize();
	LCD_voidWriteStringXY((u8 *)"DUTY",0,0);
	LCD_voidWriteStringXY((u8 *)"FREQ",0,1);
	TIM1_voidNormalInitialize();
	TIM_voidInitialize();
	EXTI_voidInit();
	EXTI_voidSetCallback(getFreqancyData);
	EXTI_voidEnable();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		if(Write==0)
		{
			if(End==1)
			{

				Ton+=8;
				Toff-=16;
				Duty=(u32)((u32)(((u32)Ton)*100)/(u32)(Ton+Toff));
				Freq=(u32)8000000/(u16)(Ton+Toff);
				while(Duty)
				{
					digit=Duty%10;
					Duty/=10;
					LCD_voidWriteStringXY((u8 *)Numbers[digit],Xpos,0);
					Xpos--;
				}
				Xpos=8;
				while(Freq)
				{
					digit=Freq%10;
					Freq/=10;
					LCD_voidWriteStringXY((u8 *)Numbers[digit],Xpos,1);
					Xpos--;
				}
				Write=1;
			}
		}
	}
}

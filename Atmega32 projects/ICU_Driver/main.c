/*
 * main.c
 *
 *  Created on: 5 Apr 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_int.h"
#include "TIM_int.h"
#include "TIM1_int.h"
#include "GIE_int.h"
#include "LCD_int.h"
static u8 flag=1;
static u16 Ton=0;
static u16 Temp1=0;
static u16 Temp2=0;
static u16 T_off=0;
static u8 Xpos=8;
static const u8* Numbers[10]  ={(u8 *)"0",(u8 *)"1",(u8 *)"2",(u8 *)"3",(u8 *)"4",(u8 *)"5",(u8 *)"6",(u8 *)"7",(u8 *)"8",(u8 *)"9"};
void ICU_FreqReading(void)
{
	switch(flag)
	{
	case 1:
		DIO_voidSetPinValue(DIO_u8_PIN_0,DIO_u8_HIGH);
		Temp1=ICU_voidGetICR1();
		ICU_voidChooseEdge(ICU_FALLING_EDGE);
		break;
	case 2:
		Temp2=ICU_voidGetICR1();
		Ton=Temp2-Temp1;
		ICU_voidChooseEdge(ICU_RAISING_EDGE);
		break;
	case 3:
		T_off=ICU_voidGetICR1()-Temp2;
		break;
	}
	flag++;
	if(4 == flag)
	{
		ICU_voidDisableInterrupt();
	}
}
void TimerCallBack(void)
{
	TIM_voidInitCountingRegister(155);
	TOG_BIT(PORTB,3);
}
void main (void)
{
	u32 Duty;
	u32 Freq;
	u8 digit;
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_30,DIO_u8_HIGH);
	LCD_voidInitialize();
	LCD_voidWriteStringXY((u8 *)"DUTY",0,0);
	LCD_voidWriteStringXY((u8 *)"FREQ",0,1);
	TIM_voidInitialize();
	TIM1_voidNormalInitialize();
	TIM1_voidStartCount();
	ICU_voidSetCallBack(ICU_FreqReading);
	ICU_voidChooseEdge(ICU_RAISING_EDGE);
	ICU_voidEnableInterrupt();
	TIM_voidSetCallBack(TimerCallBack);
	TIM_voidEnableInt();
	GIE_EnableGlobalInterrupt();
	while(1)
	{

		if(4 == flag)
		{
			Duty=(u32)((u32)(((u32)Ton)*100)/(u32)(Ton+T_off));
			Freq=(u32)8000000/(u16)(Ton+T_off);
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
			flag=5;
		}
	}
}

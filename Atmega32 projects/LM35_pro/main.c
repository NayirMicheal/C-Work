/*
 * main.c
 *
 *  Created on: 18 Apr 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DELAY.h"
#include "DIO_int.h"
#include "ADC_int.h"
#include "LCD_int.h"
#include "SWD_int.h"
u8 * numbers[10]={(u8 *)"0",(u8 *)"1",(u8 *)"2",(u8 *)"3",(u8 *)"4",
		(u8 *)"5",(u8 *)"6",(u8 *)"7",(u8 *)"8",(u8 *)"9"};
void main (void)
{
	u16 Data;
	u32 DataBig;
	u8 Xpos=14;
	u8 digit;
	u8 setpoint=23;
	u8 tempSetpoint;
	u32 tempTemp;
	u32 Temperature;
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_30,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_31,DIO_u8_HIGH);
	ADC_voidInit();
	LCD_voidInitialize();
	LCD_voidWriteStringCurrentPosition((u8 *)"Actual");
	LCD_voidWriteStringXY((u8 *)"SetPoint",0,1);
	while(1)
	{
		ADC_voidStartConversion(ADC0,&Data);
		DataBig=(u32)Data;
		Temperature =(u32)((u32)((u32)DataBig * (u16)(500))/ (u16)1024);
		if(SWD_u8GetSwitchState(SWD_u8_SW1)==SWD_u8RELEASED)
		{
			setpoint++;
		}
		if(SWD_u8GetSwitchState(SWD_u8_SW2)==SWD_u8RELEASED)
		{
			setpoint--;
		}
		tempTemp=Temperature;
		while (tempTemp)
		{
			digit= tempTemp % 10;
			LCD_voidWriteStringXY(numbers[digit],Xpos,0);
			tempTemp/=10;
			Xpos--;
		}
		Xpos=14;
		tempSetpoint = setpoint;
		while(tempSetpoint)
		{
			digit= tempSetpoint % 10;
			LCD_voidWriteStringXY(numbers[digit],Xpos,1);
			tempSetpoint/=10;
			Xpos--;
		}
		Xpos=14;
		if(Temperature > (u32)setpoint)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_29,DIO_u8_HIGH); //DC Motor
			DIO_voidSetPinValue(DIO_u8_PIN_28,DIO_u8_LOW); // Buzzer
		}
		else if( Temperature <= (u32)setpoint)
		{
			DIO_voidSetPinValue(DIO_u8_PIN_29,DIO_u8_LOW); //DC Motor
			DIO_voidSetPinValue(DIO_u8_PIN_28,DIO_u8_HIGH); // Buzzer
		}
		Delay_ms(200);
	}
}


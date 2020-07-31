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
u8 * numbers[10]={(u8 *)"0",(u8 *)"1",(u8 *)"2",(u8 *)"3",(u8 *)"4",
		(u8 *)"5",(u8 *)"6",(u8 *)"7",(u8 *)"8",(u8 *)"9"};
void main (void)
{
	u16 Data;
	u32 DataBig;
	u32 regulatedVolt;
	u32 LDRValue;
	u8 Xpos=8;
	u8 digit;
	DIO_voidInitialize();
	ADC_voidInit();
	LCD_voidInitialize();
	while(1)
	{
		ADC_voidStartConversion(ADC1,&Data);
		DataBig=(u32)Data;
		regulatedVolt =(u32)((u32)((u32)DataBig * (u16)(5000))/ (u16)1024);
		LDRValue=(u32)((u32)((u16) 1000 * (5000 - regulatedVolt)) / regulatedVolt);
		while (LDRValue)
		{
			digit= LDRValue % 10;
			LCD_voidWriteStringXY(numbers[digit],Xpos,0);
			LDRValue/=10;
			Xpos--;
		}
		Xpos=8;
		//Delay_ms(200);

	}
}


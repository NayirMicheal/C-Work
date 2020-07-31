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
#include "GIE_int.h"
#include "LCD_int.h"
#define R_KNOWN   (u32)100000
static const u8* Numbers[10]  ={(u8 *)"0",(u8 *)"1",(u8 *)"2",(u8 *)"3",(u8 *)"4",(u8 *)"5",(u8 *)"6",(u8 *)"7",(u8 *)"8",(u8 *)"9"};
void main (void)
{
	u16 Data;
	u8 xpos=8;
	u8 digit;
	u32 regulatedVolt;
	u32 DataBig;
	u32 Rvalue;
	DIO_voidInitialize();
	LCD_voidInitialize();
	LCD_voidClearDisplay();
	ADC_voidInit();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		ADC_voidStartConversion(ADC0,&Data);
		DataBig=(u32)Data;
		regulatedVolt =(u32)((u32)((u32)DataBig * (u16)(5))/ (u16)1024);
		Rvalue= (u32)((5-regulatedVolt)*R_KNOWN);
		Rvalue= Rvalue/(u32)(100*regulatedVolt);
		while (Rvalue)
		{
			digit=Rvalue%10;
			LCD_voidWriteStringXY((u8 *)Numbers[digit],xpos,0);
			Rvalue/=10;
			xpos--;
		}
		xpos=8;
		Delay_ms(50);
	}
}


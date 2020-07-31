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
static const u8* Numbers[10]  ={(u8 *)"0",(u8 *)"1",(u8 *)"2",(u8 *)"3",(u8 *)"4",(u8 *)"5",(u8 *)"6",(u8 *)"7",(u8 *)"8",(u8 *)"9"};
void main (void)
{
	u16 Data;
	u32 DataBig;
	u32 regulatedVolt;

	DIO_voidInitialize();
	LCD_voidInitialize();
	LCD_voidClearDisplay();
	ADC_voidInit();
	//GIE_EnableGlobalInterrupt();
	while(1)
	{
		LCD_voidClearDisplay();
		 ADC_voidStartConversion(ADC0,&Data);
		 DataBig=(u32)Data;


		regulatedVolt =(u32)((u32)((u32)DataBig * (u16)(500))/ (u16)1024);

		LCD_voidWriteStringCurrentPosition((u8 *)Numbers[(regulatedVolt/100)]);
		LCD_voidWriteStringCurrentPosition((u8 *)".");
		regulatedVolt %= 100;
		LCD_voidWriteStringCurrentPosition((u8 *)Numbers[(regulatedVolt/10)]);
		regulatedVolt %= 10;
		LCD_voidWriteStringCurrentPosition((u8 *)Numbers[regulatedVolt]);
		LCD_voidWriteStringCurrentPosition((u8 *)" v");
		Delay_ms(100);

	}
}


/*
 * main.c
 *
 *  Created on: 21 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY.h"
#include "DIO_int.h"
#include "TIM_int.h"
#include "SWD_int.h"
#include "LCD_int.h"
#define U8_SMALLEST_PERIOD 14
#define U8_BIGEST_PERIOD   254



u8 u8PwmWidth=254;
void callback(void)
{

}
void main(void)
{
	u8  block[2]={255,0};
	u8  space[2]={254,0};
	u8 index=7;
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_24,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PIN_25,DIO_u8_HIGH);
	LCD_voidInitialize();
	TIM_voidInitialize();
	LCD_voidWriteStringCurrentPosition((u8 *)"INTENSITY");
	for(u8 i=0;i<8;i++)
		LCD_voidWriteStringXY((u8 *)block,i,1);
	while(1)
	{

		if(SWD_u8GetSwitchState(SWD_u8_SW1)==SWD_u8PUSHED)
		{
			if(u8PwmWidth>U8_SMALLEST_PERIOD)
			{
				u8PwmWidth-=30;
				LCD_voidWriteStringXY((u8 *) space,index,1);
				index--;
			}
			TIM_voidInitCTCRegister(u8PwmWidth);
		}
		if(SWD_u8GetSwitchState(SWD_u8_SW2)==SWD_u8PUSHED)
		{
			if(u8PwmWidth<U8_BIGEST_PERIOD)
			{
				index++;
				u8PwmWidth+=30;
				LCD_voidWriteStringXY((u8 *)block,index,1);

			}
			TIM_voidInitCTCRegister(u8PwmWidth);
		}
		Delay_ms(200);
	}
}

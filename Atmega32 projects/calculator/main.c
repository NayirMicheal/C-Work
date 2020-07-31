/*
 * main.c
 *
 *  Created on: 31 Jan 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DELAY.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "KEYPAD_int.h"
void main (void)
{
	u16 StatusKeys;
	u8 numbers[][1]={"1","\0","2","\0","3","\0","4","\0","5","\0","6","\0","7","\0","8","\0","9","\0","0","\0"};
	s8 num1=-1,num2=-1;
	u8 operation,firstNum=0;
	u8 result;
	u8 digit;
	DIO_voidInitialize();
	LCD_voidInitialize();
	while(1)
	{
		StatusKeys=KEYPAD_u16GetStatus();

		for(u8 i=0;i<10;i++)
		{
			if(GET_BIT(StatusKeys,i))
			{
				if(firstNum==0)
				{
					num1=(i+1)%10;
					LCD_voidWriteStringCurrentPosition(numbers[(i*2)]);
					Delay_ms(200);
					firstNum=1;
				}
				else if(firstNum==1)
				{
					num2=(i+1)%10;
					LCD_voidWriteStringCurrentPosition(numbers[(i*2)]);
					Delay_ms(200);
				}
				break;
			}
		}
		if(GET_BIT(StatusKeys,10))
		{
			u8 TempResult;
			u8 numOfDigits=0;
			if(num1>=0 && num2>=0 && operation>0)
			{

				switch(operation)
				{
				case 1:
					result=num1+num2;
					break;
				case 2:
					result=num1-num2;
					break;
				case 3:
					result=num1*num2;
					break;
				case 4:
					result=num1/num2;
					break;
				}
				TempResult=result;
				LCD_voidClearDisplay();
				if(result==0)
				{
					LCD_voidWriteStringXY(numbers[18],0,0);
				}
				while(TempResult!=0)
				{
					TempResult/=10;
					numOfDigits++;
				}
				while(numOfDigits!=0)
				{
					digit=result%10;
					result/=10;
					numOfDigits--;
					LCD_voidWriteStringXY(numbers[((digit-1)*2)],numOfDigits,0);
					firstNum=0;
				}
			}
			Delay_ms(200);
		}
		if(GET_BIT(StatusKeys,11))
		{
			num1=-1;
			num2=-1;
			operation=0;
			firstNum=0;
			LCD_voidClearDisplay();
			Delay_ms(200);
		}
		if(GET_BIT(StatusKeys,12))
		{
			operation=1;
			LCD_voidWriteStringCurrentPosition("+");
			Delay_ms(200);
		}
		if(GET_BIT(StatusKeys,13))
		{
			operation=2;
			LCD_voidWriteStringCurrentPosition("-");
			Delay_ms(200);
		}
		if(GET_BIT(StatusKeys,14))
		{
			operation=3;
			LCD_voidWriteStringCurrentPosition("*");
			Delay_ms(200);
		}
		if(GET_BIT(StatusKeys,15))
		{
			operation=4;
			LCD_voidWriteStringCurrentPosition("/");
			Delay_ms(200);
		}
	}
}

/*
 * main.c
 *
 *  Created on: 19 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "DELAY.h"
#include "DIO_register.h"
#include "DIO_int.h"
#include "LCD_int.h"

void main (void)
{
	u8 cols [8] ={0b11111110,0b11111101,0b11111011,0b11110111,0b11101111,0b11011111,0b10111111,0b01111111};
	u8 Gaffar [8]={0, 0, 139, 125, 139, 0, 0, 0};
	u8 GaffarPlayFootball_1[8]={0, 0, 139, 125, 139, 96, 96, 0};
	u8 GaffarPlayFootball_2[8]={0, 0, 139, 125, 75, 48, 48, 0};
	u8 GaffarDance_1[8]={0, 0, 11, 157, 107, 128, 0, 0};
	u8 GaffarDance_2[8]={0, 128, 107, 157, 11, 0, 0, 0};
	u8 Smsma[8]={0, 48, 104, 40, 104, 56, 16, 16};
	u8 FunnySmsma[8]={0, 48, 104, 40, 104, 56, 0, 0};
	u8 SmsmaStrong_1[8]={0, 16, 40, 40, 16, 0, 254, 0};
	u8 SmsmaStrong_2[8]={0, 0, 0, 0, 16, 40, 238, 16};
	u8 Heart_big[8]={28, 34, 68, 136, 68, 34, 28, 0};
	u8 Heart_small[8]={8, 20, 36, 72, 36, 20, 8, 0};
	u8 LCD_HeartTop[8]={0, 0, 0, 0, 0, 0, 14, 17};
	u8 LCD_HeartStick1[8]={1, 2, 4, 12, 19, 2, 0, 0};
	u8 LCD_HeartStick2[8]={16, 8, 4, 2, 1, 0, 0, 0};
	u8 LCD_HeartUpArrow[8]={0, 0, 0, 14, 12, 10, 1, 0};

	/*Led Matrix Cols on PORTA and Row on PORTD */
	/*LCD Data is on PORTD*/
	DIO_voidInitialize();
	LCD_voidInitialize();

	while(1)
	{
		/*first scene*/
		PORTA=0xff;
		LCD_voidClearDisplay();
		LCD_voidWriteStringCurrentPosition("This is Gaffar");
		Delay_ms(1);
		for(u8 j=0;j<125;j++)
		{
			for(u8 i=0;i<8;i++)
			{
				PORTA=cols[i];
				PORTD=Gaffar[i];
				Delay_ms(2);
			}

		}
		/*Second scene*/
		PORTA=0xff;
		LCD_voidClearDisplay();
		LCD_voidWriteStringCurrentPosition("Playing football");
		for(u8 k=0;k<5;k++){
			for(u8 j=0;j<20;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=GaffarPlayFootball_1[i];
					Delay_ms(2);
				}

			}
			for(u8 j=0;j<20;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=GaffarPlayFootball_2[i];
					Delay_ms(2);
				}

			}
		}
		/*Third scene*/
		PORTA=0xff;
		LCD_voidClearDisplay();
		LCD_voidWriteStringCurrentPosition("he Can dance");
		for(u8 k=0;k<5;k++){
			for(u8 j=0;j<20;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=GaffarDance_1[i];
					Delay_ms(2);
				}

			}
			for(u8 j=0;j<20;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=Gaffar[i];
					Delay_ms(2);
				}

			}
			for(u8 j=0;j<20;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=GaffarDance_2[i];
					Delay_ms(2);
				}

			}
		}
		/*Forth scene*/
		PORTA=0xff;
		LCD_voidClearDisplay();
		LCD_voidWriteStringCurrentPosition("This is smsma");
		for(u8 j=0;j<125;j++)
		{
			for(u8 i=0;i<8;i++)
			{
				PORTA=cols[i];
				PORTD=Smsma[i];
				Delay_ms(2);
			}

		}
		/*Fifth scene*/
		PORTA=0xff;
		LCD_voidClearDisplay();
		LCD_voidWriteStringCurrentPosition("it is funny");
		for(u8 k=0;k<5;k++)
		{
			for(u8 j=0;j<20;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=Smsma[i];
					Delay_ms(2);
				}

			}
			for(u8 j=0;j<20;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=FunnySmsma[i];
					Delay_ms(2);
				}

			}
		}
		/*Sixth scene*/
		PORTA=0xff;
		LCD_voidClearDisplay();
		LCD_voidWriteStringCurrentPosition("It is strong");
		for(u8 k=0;k<3;k++)
		{
			for(u8 j=0;j<20;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=SmsmaStrong_1[i];
					Delay_ms(2);
				}

			}
			for(u8 j=0;j<20;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=SmsmaStrong_2[i];
					Delay_ms(2);
				}

			}
		}
		PORTA=0xff;
		LCD_voidClearDisplay();
		LCD_voidDrawCustomChar(LCD_HeartTop,0);
		LCD_voidDrawCustomChar(LCD_HeartStick1,1);
		LCD_voidDrawCustomChar(LCD_HeartStick2,2);
		LCD_voidDrawCustomChar(LCD_HeartUpArrow,3);
		LCD_voidWriteStringXY("Gaffar",0,0);
		LCD_voidWriteCustomChar(0,7,0);
		LCD_voidWriteCustomChar(0,8,0);
		LCD_voidWriteCustomChar(2,7,1);
		LCD_voidWriteCustomChar(1,8,1);
		LCD_voidWriteCustomChar(3,6,0);
		LCD_voidWriteStringXY("Smsma",11,1);
		for(u8 k=0;k<3;k++)
		{
			for(u8 j=0;j<40;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=Heart_big[i];
					Delay_ms(2);
				}

			}
			for(u8 j=0;j<40;j++)
			{
				for(u8 i=0;i<8;i++)
				{
					PORTA=cols[i];
					PORTD=Heart_small[i];
					Delay_ms(2);
				}

			}
		}

	}
}

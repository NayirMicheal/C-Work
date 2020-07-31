/*
 * main.c
 *
 *  Created on: 16 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include"DIO_int.h"
#include "DELAY.h"
#include "DIO_register.h"
#include "SEVENSEG_int.h"
#include "LCD_int.h"
void main (void)
{
	u8 cols [8] ={0b11111110,0b11111101,0b11111011,0b11110111,0b11101111,0b11011111,0b10111111,0b01111111};
	//LED_MATRIX ROWS PORT D, COL PORT A
	u8 rows_Image1 [8]={248, 0, 0, 0, 0, 0, 0, 0};
	u8 chars[5]={'s','n','a','k','e'};
	u8 o=0;
	DIO_voidInitialize();
	LCD_voidInitialize();

	while (1)
	{
		rows_Image1[0]=rows_Image1[0]>>1;
		rows_Image1[1]=rows_Image1[1]<<1;
		rows_Image1[2]=rows_Image1[2]>>1;
		rows_Image1[3]=rows_Image1[3]<<1;
		rows_Image1[4]=rows_Image1[4]>>1;
		rows_Image1[5]=rows_Image1[5]<<1;
		rows_Image1[6]=rows_Image1[6]>>1;
		rows_Image1[7]=rows_Image1[7]<<1;
		if(GET_BIT(rows_Image1[0],0)==1)
		{
			SET_BIT(rows_Image1[1],0);
		}

		if(GET_BIT(rows_Image1[1],7)==1)
		{
			SET_BIT(rows_Image1[2],7);

		}
		if(GET_BIT(rows_Image1[2],0)==1)
		{
			SET_BIT(rows_Image1[3],0);

		}
		if(GET_BIT(rows_Image1[3],7)==1)
		{
			SET_BIT(rows_Image1[4],7);

		}
		//////////////
		if(GET_BIT(rows_Image1[4],0)==1)
		{
			SET_BIT(rows_Image1[5],0);

		}

		if(GET_BIT(rows_Image1[5],7)==1)
		{
			SET_BIT(rows_Image1[6],7);
		}
		if(GET_BIT(rows_Image1[6],0)==1)
		{
			SET_BIT(rows_Image1[7],0);
		}
		if(GET_BIT(rows_Image1[7],7)==1)
		{
			SET_BIT(rows_Image1[0],7);
		}
		//////////////

		for(u8 j=0;j<62;j++)
		{
			for(u8 i=0;i<8;i++)
			{
				PORTA=cols[i];
				PORTD=rows_Image1[i];
				Delay_ms(2);
			}
		PORTA=0xff;
		}
		if(o==5)
				{
					o=-1;
					LCD_voidWriteCmd(0b00000001);

				}
				LCD_voidWriteData(chars[o]);
				//Delay_ms(1);
				o++;

	}

}


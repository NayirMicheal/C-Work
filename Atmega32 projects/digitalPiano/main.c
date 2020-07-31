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
#include "LED_MATRIX_int.h"
#include "KEYPAD_int.h"
void main (void)
{
	u16 StatusKeys;
	u16 DelayValue[16]={55,150,250,450,550,650,700,775,875,950,1025,1100,1200,1300,1400,1500};
	u8 gaffar[8]={0, 144, 146, 125, 146, 144, 0, 0};
	u8 gaffarDance[8]={0, 8, 146, 189, 82, 136, 128, 0};
	u8 gaffarDance2[8]={128, 136, 82, 189, 146, 8, 0, 0};
	DIO_voidInitialize();
	while(1)
	{
		StatusKeys=KEYPAD_u16GetStatus();

		for(u8 i=0;i<16;i++)
		{
			if(GET_BIT(StatusKeys,i))
			{


				for(u8 j=0;j<6;j++)
				{
					LED_MATRIX_voidLedMatrixOutputImage(gaffar);

					DIO_voidSetPinValue(DIO_u8_PIN_16,DIO_u8_HIGH);
					Delay_us(DelayValue[i]);
					DIO_voidSetPinValue(DIO_u8_PIN_16,DIO_u8_LOW);
					Delay_us(DelayValue[i]);
				}
				for(u8 j=0;j<6;j++)
				{
					if(i<=7)
						LED_MATRIX_voidLedMatrixOutputImage(gaffarDance);
					else if(i>7)
						LED_MATRIX_voidLedMatrixOutputImage(gaffarDance2);

					DIO_voidSetPinValue(DIO_u8_PIN_16,DIO_u8_HIGH);
					Delay_us(DelayValue[i]);
					DIO_voidSetPinValue(DIO_u8_PIN_16,DIO_u8_LOW);
					Delay_us(DelayValue[i]);
				}
				break;
			}
			else
			{
				DIO_voidSetPinValue(DIO_u8_PIN_16,DIO_u8_LOW);
				LED_MATRIX_voidCloseLedMatrix();
			}

		}

	}
}

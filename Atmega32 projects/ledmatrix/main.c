/*
 * main.c
 *
 *  Created on: 6 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"DIO_int.h"
#include "DELAY.h"
#include "DIO_register.h"
#include "SEVENSEG_int.h"
int main (void)
{u8 cols [8] ={0b11111110,0b11111101,0b11111011,0b11110111,0b11101111,0b11011111,0b10111111,0b01111111};
u8 rows_image1[8]={0, 0, 0, 15, 0, 0, 0, 0};
u8 rows_image2[8]={0, 0, 0, 0, 8, 4, 2, 1};
u8 rows_image3[8]={0, 0, 0, 0, 16, 16, 16, 16};
u8 rows_image4[8]={0, 0, 0, 0, 16, 32, 64, 128};
u8 rows_image5[8]={0, 0, 0, 240, 0, 0, 0, 0};
u8 rows_image6[8]={128, 64, 32, 16, 0, 0, 0, 0};
u8 rows_image7[8]={16, 16, 16, 16, 0, 0, 0, 0};
u8 rows_image8[8]={1, 2, 4, 8, 0, 0, 0, 0};

u8 SevSegData[10]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};
DIO_voidInitialize();
while(1){
	for(u8 j=0;j<7;j++){
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
		for(u8 i=0;i<8;i++)
		{
			PORTA=cols[i];
			PORTD=rows_image1[i];
			Delay_ms(2);
		}
		PORTA=0xff;
		SevenSeg_voidDisplayOnSeg(~SevSegData[1]);
		Delay_ms(2);

		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);
		PORTD=1;
		Delay_ms(2);
	}

	for(u8 j=0;j<7;j++){
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
		for(u8 i=0;i<8;i++)
		{
			PORTA=cols[i];
			PORTD=rows_image2[i];
			Delay_ms(2);
		}
		PORTA=0xff;
		SevenSeg_voidDisplayOnSeg(~SevSegData[2]);
		Delay_ms(2);

		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);
		PORTD=2;
		Delay_ms(2);

	}

	for(u8 j=0;j<7;j++){
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
		for(u8 i=0;i<8;i++)
		{
			PORTA=cols[i];
			PORTD=rows_image3[i];
			Delay_ms(2);
		}
		PORTA=0xff;
		SevenSeg_voidDisplayOnSeg(~SevSegData[3]);
		Delay_ms(2);

		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);
		PORTD=4;
		Delay_ms(2);

	}

	for(u8 j=0;j<7;j++){
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
		for(u8 i=0;i<8;i++)
		{
			PORTA=cols[i];
			PORTD=rows_image4[i];
			Delay_ms(2);
		}
		PORTA=0xff;
		SevenSeg_voidDisplayOnSeg(~SevSegData[4]);
		Delay_ms(2);

		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);
		PORTD=8;
		Delay_ms(2);

	}

	for(u8 j=0;j<7;j++){
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
		for(u8 i=0;i<8;i++)
		{
			PORTA=cols[i];
			PORTD=rows_image5[i];
			Delay_ms(2);
		}
		PORTA=0xff;
		SevenSeg_voidDisplayOnSeg(~SevSegData[5]);
		Delay_ms(2);

		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);
		PORTD=16;
		Delay_ms(2);

	}

	for(u8 j=0;j<7;j++){
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
		for(u8 i=0;i<8;i++)
		{
			PORTA=cols[i];
			PORTD=rows_image6[i];
			Delay_ms(2);
		}
		PORTA=0xff;
		SevenSeg_voidDisplayOnSeg(~SevSegData[6]);
		Delay_ms(2);

		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);
		PORTD=32;
		Delay_ms(2);

	}

	for(u8 j=0;j<7;j++){
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
		for(u8 i=0;i<8;i++)
		{
			PORTA=cols[i];
			PORTD=rows_image7[i];
			Delay_ms(2);
		}
		PORTA=0xff;
		SevenSeg_voidDisplayOnSeg(~SevSegData[7]);
		Delay_ms(2);

		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);
		PORTD=64;
		Delay_ms(2);

	}

	for(u8 j=0;j<7;j++){
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_HIGH);
		for(u8 i=0;i<8;i++)
		{
			PORTA=cols[i];
			PORTD=rows_image8[i];
			Delay_ms(2);
		}
		PORTA=0xff;
		SevenSeg_voidDisplayOnSeg(~SevSegData[8]);
		Delay_ms(2);

		DIO_voidSetPinValue(DIO_u8_PIN_8,DIO_u8_LOW);
		DIO_voidSetPinValue(DIO_u8_PIN_9,DIO_u8_LOW);
		PORTD=128;
		Delay_ms(2);
	}
}
return 0;
}

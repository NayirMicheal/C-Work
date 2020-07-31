/*********************************************/
/* Author : Nayir Michel                     */
/*Date : 15 JAN 2018                         */
/*Release : V01                              */
/*********************************************/

#include"STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY.h"

#include "DIO_int.h"

#include "LCD_config.h"
#include "LCD_priv.h"
#include "LCD_int.h"
/**********************************************/
/*Description: This function is used to  */
/* Initialise LCD parameters             */
/*********************************************/
extern void LCD_voidInitialize(void)
{
	Delay_ms(50);
	/*Write Function Set command*/
	voidWriteCmd(0b00110000 | (LCD_u8_FONT<<2) | (LCD_u8_NUM_OF_LINES<<3));

	Delay_us(100);

	/*Write Display on command*/
	voidWriteCmd(0b00001000 | (LCD_u8_BLINK_ON_OFF<<0) | (LCD_u8_CURSOR_ON_OFF<<1) | (LCD_u8_DISPLAY_ON_OFF<<2));

	Delay_us(100);

	/*Write command clear display*/
	voidWriteCmd(0b00000001);

	Delay_ms(2);
}

/*********************************************/
/*Description: This function is used to  */
/* write data to LCD             */
/*********************************************/
static void voidWriteData(u8 u8DataCpy)
{
/*Set RS to high*/
	DIO_voidSetPinValue(LCD_u8_RS_PIN,DIO_u8_HIGH);
/*Execute Command */
	voidLcdExecute(u8DataCpy);
}
/*Description: This function is used to  */
/* Execute LCD commands            */
/*********************************************/
static void voidWriteCmd(u8 u8CommandCpy)
{
	/*Set RS to Low*/
	DIO_voidSetPinValue(LCD_u8_RS_PIN,DIO_u8_LOW);
	/*Execute Command */
	voidLcdExecute(u8CommandCpy);
}

/*********************************************/
/*Description: This function is used to  */
/* Execute data on LCD lines             */
/*********************************************/
static void voidLcdExecute(u8 u8ValueCpy)
{
	/*Set RW to LOW*/
	DIO_voidSetPinValue(LCD_u8_RW_PIN,DIO_u8_LOW);
    /*Set Received data to LCD Lines*/
	for(u8 u8PinsCounterLocal=0;u8PinsCounterLocal;u8PinsCounterLocal++)
	{
		if(GET_BIT(u8ValueCpy,u8PinsCounterLocal))
		{
				DIO_voidSetPinValue(u8LCDDataPins[u8PinsCounterLocal],DIO_u8_HIGH);
		}
			else
		{
				DIO_voidSetPinValue(u8LCDDataPins[u8PinsCounterLocal],DIO_u8_LOW);
		}
	}
		/*set Enable high*/
	DIO_voidSetPinValue(LCD_u8_E_PIN,DIO_u8_HIGH);
	/*Delay 1 Ms*/
	Delay_us(100);
	/*set Enable low*/
	DIO_voidSetPinValue(LCD_u8_E_PIN,DIO_u8_LOW);
}


extern void LCD_voidWriteStringXY(u8 * u8PtrCpy,u8 u8XposCpy,u8 u8YposCpy)
{
	voidWriteCmd((0x80 | (u8YposCpy<<6) | u8XposCpy));
	while(*u8PtrCpy)
	{
		voidWriteData(*u8PtrCpy);
		u8PtrCpy++;
	}
}
extern void LCD_voidWriteStringCurrentPosition(u8 * u8PtrCpy)
{
	while(*u8PtrCpy)
		{
			voidWriteData(*u8PtrCpy);
			u8PtrCpy++;
		}
}
extern void LCD_voidClearDisplay(void)
{
	voidWriteCmd(0b00000001);
	Delay_us(1500);
}

extern void voidDrawCustomChar(u8 * u8PtrCpy,u8 u8IndexCpy)
{
	voidWriteCmd(0b10000000 | (u8IndexCpy<<3));
	for(u8 u8BytesCounterLocal=0;u8BytesCounterLocal<8;u8BytesCounterLocal++)
	{
		voidWriteData(u8PtrCpy[u8BytesCounterLocal]);
	}
}

extern void voidWriteCustomChar(u8 u8IndexCpy ,u8 u8XPositionCpy,u8 u8YPositionCpy)
{
	voidWriteCmd((0x80 | (u8YPositionCpy<<6) | u8XPositionCpy));
	voidWriteData(u8IndexCpy);
}

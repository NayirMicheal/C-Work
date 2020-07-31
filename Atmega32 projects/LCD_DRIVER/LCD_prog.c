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
	LCD_voidWriteCmd(0b00111000);

	Delay_us(100);

	/*Write Display on command*/
	LCD_voidWriteCmd(0b00001100);

	Delay_us(100);

	/*Write command clear display*/
	LCD_voidWriteCmd(0b00000001);

	Delay_ms(2);
}

/*********************************************/
/*Description: This function is used to  */
/* write data to LCD             */
/*********************************************/
extern void LCD_voidWriteData(u8 u8DataCpy)
{
/*Set RS to high*/
	DIO_voidSetPinValue(LCD_u8_RS_PIN,DIO_u8_HIGH);
/*Execute Command */
	voidLcdExecute(u8DataCpy);
}

/*********************************************/
/*Description: This function is used to  */
/* Execute LCD commands            */
/*********************************************/
extern void LCD_voidWriteCmd(u8 u8CommandCpy)
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
	if(GET_BIT(u8ValueCpy,0))
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_0,DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_0,DIO_u8_LOW);
	}

	if(GET_BIT(u8ValueCpy,1))
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_1,DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_1,DIO_u8_LOW);
	}

	if(GET_BIT(u8ValueCpy,2))
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_2,DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_2,DIO_u8_LOW);
	}

	if(GET_BIT(u8ValueCpy,3))
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_3,DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_3,DIO_u8_LOW);
	}

	if(GET_BIT(u8ValueCpy,4))
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_4,DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_4,DIO_u8_LOW);
	}

	if(GET_BIT(u8ValueCpy,5))
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_5,DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_5,DIO_u8_LOW);
	}

	if(GET_BIT(u8ValueCpy,6))
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_6,DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_6,DIO_u8_LOW);
	}

	if(GET_BIT(u8ValueCpy,7))
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_7,DIO_u8_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(LCD_u8_DATA_PIN_7,DIO_u8_LOW);
	}
		/*set Enable high*/
	DIO_voidSetPinValue(LCD_u8_E_PIN,DIO_u8_HIGH);
	/*Delay 1 Ms*/
	Delay_us(100);
	/*set Enable low*/
	DIO_voidSetPinValue(LCD_u8_E_PIN,DIO_u8_LOW);
}


extern void LCD_voidWriteString(u8 * u8PtrCpy,u8 u8XposCpy,u8 u8YposCpy)
{
	LCD_voidWriteCmd((0x80 | (u8YposCpy<<6) | u8XposCpy));
	while(*u8PtrCpy)
	{
		LCD_voidWriteData(*u8PtrCpy);
		u8PtrCpy++;
	}
}

extern void LCD_voidClearDisplay(void)
{
	LCD_voidWriteCmd(0b00000001);
	Delay_us(1500);
}

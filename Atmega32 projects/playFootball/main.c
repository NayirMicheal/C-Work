/*
 * main.c
 *
 *  Created on: 7 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "DELAY.h"
#include "DIO_int.h"
#include"GIE_int.h"
#include "EXTI_int.h"
#include "LED_MATRIX_int.h"

u8 Gaffar[8]={0, 0, 146, 127, 138, 0, 0, 0};
u8 GaffarGetBall[8]={0, 0, 146, 127, 74, 48, 48, 0};
u8 GaffarBall[8]={0, 0, 146, 127, 138, 96, 96, 0};
volatile static u8 GetBall=1;
volatile static u8 kick=0;
//connected with magnet
void int0(void) // to kick
{
	if(kick==0 && GetBall ==1) // if have the ball and and not kicked yet
	{
	volatile static u8 pinstatus=0;
		// then kick and not have the ball
		kick=1;
		GetBall=0;
		if(pinstatus==0)
		{
			pinstatus=1;
			DIO_voidSetPinValue(DIO_u8_PIN_29,DIO_u8_HIGH);
		}
		else if(pinstatus==1)
		{
			pinstatus=0;
			DIO_voidSetPinValue(DIO_u8_PIN_29,DIO_u8_LOW);
		}
	}

}
//connected with controller
void int1(void) // to recieve the ball
{
	if(GetBall==0 && kick ==1)
	{
		GetBall=1;
		kick=0;
	}
}
void main(void)
{
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_26,DIO_u8_HIGH); //pull up resistor on Ext 0 pin
	DIO_voidSetPinValue(DIO_u8_PIN_27,DIO_u8_HIGH); //pull up resistor on Ext 0 pin
	DIO_voidSetPinValue(DIO_u8_PIN_29,DIO_u8_LOW);
	EXTI_voidInit();
	EXTI_voidSetCallback_EXT0(int0);
	EXTI_voidSetCallback_EXT1(int1);
	EXTI_voidEnable_EXT0();
	EXTI_voidEnable_EXT1();
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		if((!kick) && GetBall)
		{
			for(u8 i=0;i<7;i++)
				LED_MATRIX_voidLedMatrixOutputImage(GaffarBall);
			for(u8 i=0;i<7;i++)
				LED_MATRIX_voidLedMatrixOutputImage(GaffarGetBall);
		}
		else if(kick==1 && GetBall==0)
		{
			for(u8 i=0;i<7;i++)
				LED_MATRIX_voidLedMatrixOutputImage(Gaffar);
		}

	}
}




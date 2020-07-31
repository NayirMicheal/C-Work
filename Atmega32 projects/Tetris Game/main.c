/*
 * main.c
 *
 *  Created on: 28 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "DELAY.h"
#include "DIO_register.h"
#include"DIO_int.h"
#include"LED_MATRIX_int.h"
#include"SWD_int.h"
void voidShiftLeft(u8 * u8ImageCpy);
void voidShiftRight(u8 * u8ImageCpy);
void voidShiftDown(u8 * u8ImageCpy);
void main(void)
{
	u8 SquareShape[8]={0, 0, 0, 3, 3, 0, 0, 0};
	u8 StickShape[8]={0, 0, 0, 7, 0, 0, 0, 0};
	u8 Screen[8]={0,0,0,0,0,0,0,0};
	u8 TempArray[8]={0,0,0,0,0,0,0,0};
	u8 Shape=1;
	DIO_voidInitialize();
	while(1)
	{

		if(Shape==1)
		{
			for(u8 Counter=0;Counter<8;Counter++)
			{
				TempArray[Counter]=SquareShape[Counter];
				Shape=0;
			}
		}
		else if(Shape==2)
		{
			for(u8 Counter=0;Counter<8;Counter++)
			{
				TempArray[Counter]=StickShape[Counter];
			}
		}
		if(SWD_u8GetSwitchState(SWD_u8_SW1)==SWD_u8PUSHED)
		{
			voidShiftLeft(TempArray);
		}
		if(SWD_u8GetSwitchState(SWD_u8_SW2)==SWD_u8PUSHED)
		{
			voidShiftRight(TempArray);
		}
		for(u8 count=0;count<8;count++)
		{
		if(GET_BIT(TempArray[count],7)!=1)
		voidShiftDown(TempArray);
		}
		for(u8 Counter=0;Counter<8;Counter++)
		{
			Screen[Counter]+=TempArray[Counter];
		}
		for(u8 Counter=0;Counter<32;Counter++)
		{
			LED_MATRIX_voidLedMatrixOutputImage(Screen);
		}
	}
}
void voidShiftLeft(u8 * u8ImageCpy)
{
	u8 u8TempValueLoc=u8ImageCpy[7];
	u8ImageCpy[7]=u8ImageCpy[0];
	for(u8 u8CounterLoc=0;u8CounterLoc<6;u8CounterLoc++)
	{
		u8ImageCpy[u8CounterLoc]=u8ImageCpy[u8CounterLoc+1];
	}
	u8ImageCpy[6]=u8TempValueLoc;

}
void voidShiftRight(u8 * u8ImageCpy)
{
	u8 u8TempValueLoc=u8ImageCpy[0];
	u8ImageCpy[0]=u8ImageCpy[7];
	for(u8 u8CounterLoc=7;u8CounterLoc>=2;u8CounterLoc--)
	{
		u8ImageCpy[u8CounterLoc]=u8ImageCpy[u8CounterLoc-1];
	}
	u8ImageCpy[1]=u8TempValueLoc;

}
void voidShiftDown(u8 * u8ImageCpy)
{
	u8 u8ReachDown=0;
	if(u8ReachDown!=1)
	for(u8 u8CounterLoc=0;u8CounterLoc<8;u8CounterLoc++)
	{
		if(GET_BIT(u8ImageCpy[u8CounterLoc],7)==1)
		{
			u8ReachDown=1;
			u8ImageCpy[u8CounterLoc]-=128;

		}

		u8ImageCpy[u8CounterLoc]=u8ImageCpy[u8CounterLoc]*2;
		if(u8ReachDown==1)
		{
			u8ImageCpy[u8CounterLoc]+=1;
			u8ReachDown=0;
		}

	}


}

/*
 * main.c
 *
 *  Created on: 25 Jan 2018
 *      Author: Nayir
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "DIO_int.h"
#include"LED_MATRIX_int.h"
#include "SWD_int.h"
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
void voidShiftUp(u8 * u8ImageCpy)
{
	u8 u8ReachUp=0;
	for(u8 u8CounterLoc=0;u8CounterLoc<8;u8CounterLoc++)
	{
		if(GET_BIT(u8ImageCpy[u8CounterLoc],0)==1)
		{
			u8ReachUp=1;
		}
		u8ImageCpy[u8CounterLoc]=u8ImageCpy[u8CounterLoc]/2;
		if(u8ReachUp ==1)
		{
			u8ImageCpy[u8CounterLoc]+=128;
			u8ReachUp=0;
		}
	}

}
void voidShiftDown(u8 * u8ImageCpy)
{
	u8 u8ReachDown=0;
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
void voidJump(u8 * u8ImageCpy)
{
	voidShiftUp(u8ImageCpy);
	voidShiftUp(u8ImageCpy);
	for(u8 i=0;i<8;i++)
		LED_MATRIX_voidLedMatrixOutputImage(u8ImageCpy);
	voidShiftDown(u8ImageCpy);
	voidShiftDown(u8ImageCpy);
}
void main(void)
{
	u8 Smsma [8]={0, 0, 52, 72, 72, 52, 0, 0};
	DIO_voidInitialize();
	while(1)
	{
		for(u8 i=0;i<8;i++)
			LED_MATRIX_voidLedMatrixOutputImage(Smsma);
		LED_MATRIX_voidCloseLedMatrix();
		if(SWD_u8GetSwitchState(SWD_u8_SW1)==SWD_u8PUSHED)
		{
			voidShiftLeft(Smsma);
		}
		if(SWD_u8GetSwitchState(SWD_u8_SW2)==SWD_u8PUSHED)
		{
			voidShiftRight(Smsma);
		}
		if(SWD_u8GetSwitchState(SWD_u8_SW3)==SWD_u8PUSHED)
		{
			voidShiftUp(Smsma);
		}
		if(SWD_u8GetSwitchState(SWD_u8_SW4)==SWD_u8PUSHED)
		{
			voidShiftDown(Smsma);
		}
		if(SWD_u8GetSwitchState(SWD_u8_SW5)==SWD_u8PUSHED)
		{
			voidJump(Smsma);
		}

	}
}

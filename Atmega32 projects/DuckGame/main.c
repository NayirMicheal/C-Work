/*
 * main.c
 *
 *  Created on: 5 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "TIM_int.h"
#include "GIE_int.h"
#include "RTO2_init.h"
#include "DIO_register.h"
#include "SWD_int.h"
#include "LCD_int.h"
void draw(void);
void switches(void);
void updateGame(void);
void Reset(void);
void voidShiftRight(u8 * u8ImageCpy);
void voidShiftUp(u8 * u8ImageCpy);
void DisplayScore(void);
u8* arr [10]={"0","1","2","3","4","5","6","7","8","9"};
u8 Duckbackup[8]={128, 0, 0, 0, 0, 0, 0, 0};
u8 Duck[8]={128, 0, 0, 0, 0, 0, 0, 0};
u8 kalb[8]={60, 229, 142, 164, 164, 142, 229, 60};
u8 true[8]={32, 64, 128, 64, 32, 16, 8, 4};
u8 u8ColsActivationLoc [8] ={0b11111110,0b11111101,0b11111011,0b11110111,0b11101111,0b11011111,0b10111111,0b01111111};
Task drawOnScreen={1,0,RTO_u8_ACTIVE_STATE,&draw};
Task switchTask={67,0,RTO_u8_ACTIVE_STATE,&switches};
Task updateTheGame={81,1,RTO_u8_ACTIVE_STATE,&updateGame};
Task updateLcd={40,0,RTO_u8_ACTIVE_STATE,&DisplayScore};
static u8 counter=0;
static u8 counterMissed=0;
u8 win=0;
u8 lose=0;
u8 hitOrMiss=0;
void main (void)
{
	RTO_voidCreateTask(&drawOnScreen,0);
	RTO_voidCreateTask(&switchTask,2);
	RTO_voidCreateTask(&updateTheGame,1);
	RTO_voidCreateTask(&updateLcd,3);

	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_24,DIO_u8_HIGH); //pull up
	DIO_voidSetPinValue(DIO_u8_PIN_25,DIO_u8_HIGH); //pull up
	LCD_voidInitialize();
	LCD_voidWriteStringXY((u8 *)"HITS: 00",0,0);
	LCD_voidWriteStringXY((u8 *)"MISS: 00",0,1);
	TIM_voidInitialize();
	TIM_voidEnableInt();
	RTO_voidInitialize();
	GIE_EnableGlobalInterrupt();
	while(1)
	{

	}
}
void draw(void)
{
	static u8 i=0;
	if((counter<20) && (counterMissed<20))
	{
		PORTB=Duck[i];
		PORTA=u8ColsActivationLoc[i];
		i++;
		if(i>7)
		{
			i=0;
		}
	}
	else if(counterMissed==20)
	{
		lose=1;
		RTO_voidSetTaskState(1,RTO_u8_SUSPENDED_STATE);
		PORTB=kalb[i];
		PORTA=u8ColsActivationLoc[i];
		i++;
		if(i>7)
		{
			i=0;
		}
	}
	else if(counter==20)
	{
		win=1;
		RTO_voidSetTaskState(1,RTO_u8_SUSPENDED_STATE);
		PORTB=true[i];
		PORTA=u8ColsActivationLoc[i];
		i++;
		if(i>7)
		{
			i=0;
		}
	}
}
void updateGame(void)
{
	voidShiftUp(Duck);
	voidShiftRight(Duck);
	if(Duck[7]==1)
	{
		counterMissed++;
		hitOrMiss=1;
		updateTheGame.u8periodicity-=1;
	}
}
void switches(void)
{
	if(SWD_u8GetSwitchState(SWD_u8_SW1)==SWD_u8PUSHED)
	{
		if((lose == 0) && (win ==0) )
		{
			Reset();
			updateTheGame.u8periodicity-=1;
			hitOrMiss=2;
			counter++;
		}
	}
	if(SWD_u8GetSwitchState(SWD_u8_SW2)==SWD_u8PUSHED)
	{
		Reset();
		counter=0;
		counterMissed=0;
		win=0;
		lose=0;
		updateTheGame.u8periodicity=67;
		LCD_voidClearDisplay();
		LCD_voidWriteStringXY((u8 *)"HITS: 00",0,0);
		LCD_voidWriteStringXY((u8 *)"MISS: 00",0,1);
		RTO_voidSetTaskState(3,RTO_u8_ACTIVE_STATE);
		RTO_voidSetTaskState(1,RTO_u8_ACTIVE_STATE);
	}
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
void Reset (void)
{
	for(u8 i=0;i<8;i++)
	{
		Duck[i]=Duckbackup[i];
	}
}

void DisplayScore(void)
{
	u8 digitone,digittwo;
	if(!lose && !win)
	{
		if(hitOrMiss==2)
		{
			digitone=counter % 10;
			digittwo=counter / 10;
			LCD_voidWriteStringXY(arr[digitone],7,0);
			LCD_voidWriteStringXY(arr[digittwo],6,0);
		}
		else if(hitOrMiss==1)
		{
			digitone=counterMissed % 10;
			digittwo=counterMissed / 10;
			LCD_voidWriteStringXY(arr[digitone],7,1);
			LCD_voidWriteStringXY(arr[digittwo],6,1);
		}

	}
	else if(win ==1)
	{
		LCD_voidClearDisplay();
		LCD_voidWriteStringCurrentPosition((u8 *)"You win");
		RTO_voidSetTaskState(3,RTO_u8_SUSPENDED_STATE);
	}
	else if(lose ==1)
	{
		LCD_voidClearDisplay();
		LCD_voidWriteStringCurrentPosition((u8 *)"Game Over");
		RTO_voidSetTaskState(3,RTO_u8_SUSPENDED_STATE);
	}

}

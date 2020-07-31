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
void draw(void);
void switches(void);
void voidShiftLeft(u8 * u8ImageCpy);
void voidShiftRight(u8 * u8ImageCpy);
void voidShiftUp(u8 * u8ImageCpy);
void voidShiftDown(u8 * u8ImageCpy);
void voidShiftLeftLarge(u8 * u8ImageCpy);
void updateGame(void);
void Reset(void);
void GameOverTask(void);
u8 madrabbackup[8]={0, 0, 128, 128, 128, 0, 0, 0};
u8 korabackup [8]={0, 0, 0,64, 0, 0, 0, 0};
u8 bricksbackup[8]={7, 7, 7, 7, 7, 7, 7, 7};
u8 madrab[8]={0, 0, 128, 128, 128, 0, 0, 0};
u8 kora [8]={0, 0, 0,64, 0, 0, 0, 0};
u8 bricks[8]={7, 7, 7, 7, 7, 7, 7, 7};
u8 GameOver[40]={0, 0, 0, 62, 34, 50, 0, 60, 18, 18, 60, 0, 62, 4, 8, 4, 62, 0, 62, 42, 42, 0, 62, 34, 62, 0, 62, 64, 62, 0, 62, 42, 42, 0, 62, 26, 46, 0, 0, 0};
u8 GameOverBackup[40]={0, 0, 0, 62, 34, 50, 0, 60, 18, 18, 60, 0, 62, 4, 8, 4, 62, 0, 62, 42, 42, 0, 62, 34, 62, 0, 62, 64, 62, 0, 62, 42, 42, 0, 62, 26, 46, 0, 0, 0};
static u8 up=1;
static u8 lose=0;
u8 u8ColsActivationLoc [8] ={0b11111110,0b11111101,0b11111011,0b11110111,0b11101111,0b11011111,0b10111111,0b01111111};
void main (void)
{
	Task drawOnScreen={1,0,RTO_u8_ACTIVE_STATE,&draw};
	Task switchTask={67,0,RTO_u8_ACTIVE_STATE,&switches};
	Task updateTheGame={67,1,RTO_u8_ACTIVE_STATE,&updateGame};
	Task GameOver={67,0,RTO_u8_ACTIVE_STATE,&GameOverTask};
	RTO_voidCreateTask(&drawOnScreen,0);
	RTO_voidCreateTask(&switchTask,2);
	RTO_voidCreateTask(&updateTheGame,1);
	RTO_voidCreateTask(&GameOver,3);
	DIO_voidInitialize();
	DIO_voidSetPinValue(DIO_u8_PIN_24,DIO_u8_HIGH); //pull up
	DIO_voidSetPinValue(DIO_u8_PIN_25,DIO_u8_HIGH); //pull up
	DIO_voidSetPinValue(DIO_u8_PIN_26,DIO_u8_HIGH); //pull up
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
	static u8 j=0;
	if(lose ==0)
	{
		PORTA=u8ColsActivationLoc[i];
		PORTB=madrab[i]|kora[i]|bricks[i];
		i++;
		if(i>7)
		{
			i=0;
		}
	}

	else if(lose ==1)
	{
		PORTA=u8ColsActivationLoc[j];
		PORTB=GameOver[j];
		j++;
		if(j>7)
		{
			j=0;
		}
	}
}
void updateGame(void)
{
	u8 i;
	if(lose==0){
		for(i=0;i<8;i++)
		{
			if(kora[i]>0)
			{
				break;
			}
		}
		if(((kora[i]/2)|bricks[i])==bricks[i])
		{
			up=0;
			bricks[i]-=(kora[i]/2);

		}
		else if(((kora[i]*2)|madrab[i])==madrab[i])
		{
			up=1;
			if(madrab[i+1]==0)
			{
				voidShiftRight(kora);
				if(kora[0]>0)
				{
					for(u8 j=0;j<8;j++)
						kora[j]=korabackup[j];
				}
			}
			else if(madrab[i-1]==0 || i==0)
			{
				voidShiftLeft(kora);
				if(kora[7]>0)
				{
					for(u8 j=0;j<8;j++)
						kora[j]=korabackup[j];
				}
			}
		}

		if(up==1)
		{
			voidShiftUp(kora);
			if(kora[i]==1)
			{
				up=0;
			}
		}
		else if(up ==0)
		{
			voidShiftDown(kora);
			if(kora[i]==128)
			{
				lose=1;
				for(u8 i=0;i<40;i++)
					GameOver[i]=GameOverBackup[i];
			}
		}
	}
}
void switches(void)
{
	if(SWD_u8GetSwitchState(SWD_u8_SW1)==SWD_u8PUSHED)
	{
		voidShiftRight(madrab);
	}
	if(SWD_u8GetSwitchState(SWD_u8_SW2)==SWD_u8PUSHED)
	{
		voidShiftLeft(madrab);
	}
	if(SWD_u8GetSwitchState(SWD_u8_SW3)==SWD_u8PUSHED)
	{
		Reset();
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
void voidShiftLeftLarge(u8 * u8ImageCpy)
{
	u8 u8TempValueLoc=u8ImageCpy[39];
	u8ImageCpy[39]=u8ImageCpy[0];
	for(u8 u8CounterLoc=0;u8CounterLoc<38;u8CounterLoc++)
	{
		u8ImageCpy[u8CounterLoc]=u8ImageCpy[u8CounterLoc+1];
	}
	u8ImageCpy[38]=u8TempValueLoc;

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
		madrab[i]=madrabbackup[i];
		kora[i]=korabackup[i];
		bricks[i]=bricksbackup[i];
		up=1;
		lose=0;
	}
}
void GameOverTask(void)
{
	if(lose==1)
		voidShiftLeftLarge(GameOver);
}

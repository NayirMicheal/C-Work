/*
 * main.c
 *
 *  Created on: 5 Mar 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_register.h"
#include "DIO_int.h"
#include "TIM_int.h"
#include "GIE_int.h"
#include "RTO2_init.h"
void Task1(void)
{
	TOG_BIT(PORTA,0);
}

void main (void)
{
	Task ledTask= {1,0,RTO_u8_ACTIVE_STATE,Task1};
	for(u8 i=0;i<8;i++)
	{
		RTO_voidCreateTask(&ledTask[i],i);
	}
	DIO_voidInitialize();
	TIM_voidInitialize();
	TIM_voidEnableInt();
	RTO_voidInitialize();
	GIE_EnableGlobalInterrupt();
	while(1)
	{

	}
}

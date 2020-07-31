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
void led1(void)
{
	TOG_BIT(PORTA,0);
}
void led2(void)
{
	TOG_BIT(PORTA,1);
}
void led3(void)
{
	TOG_BIT(PORTA,2);
}
void led4(void)
{
	TOG_BIT(PORTA,3);
}
void led5(void)
{
	TOG_BIT(PORTA,4);
}
void led6(void)
{
	TOG_BIT(PORTA,5);
}
void led7(void)
{
	TOG_BIT(PORTA,6);
}
void led8(void)
{
	TOG_BIT(PORTA,7);
}
void main (void)
{
	Task ledTask[8]={
			{4,0,RTO_u8_ACTIVE_STATE,led1},{6,0,RTO_u8_ACTIVE_STATE,led2},
			{8,0,RTO_u8_ACTIVE_STATE,led3},{10,0,RTO_u8_ACTIVE_STATE,led4},
			{2,0,RTO_u8_ACTIVE_STATE,led5},{1,0,RTO_u8_ACTIVE_STATE,led6},
			{5,0,RTO_u8_ACTIVE_STATE,led7},{7,0,RTO_u8_ACTIVE_STATE,led7}
	};
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

/*
 * RTO2.c
 *
 *  Created on: 28 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "TIM_int.h"
#include "RTO2_priv.h"
#include "RTO2_config.h"
#include "RTO2_init.h"
/***************************************************/
#include "BIT_MATH.h"
#include "DIO_register.h"
/***************************************************/
u32 RTO_u32OvfCount=0;
u8  RTO_u8_INITValue=0;
u32 RTO_u32OvfIncreament=0;
Task* RTO_SYSTASKS[RTO_u8_NUM_OF_TASKS]={(Task *)0};
static void RTO_voidSchedular(void)
{

	RTO_u32OvfIncreament ++;
	if(RTO_u32OvfIncreament == RTO_u32OvfCount)
	{
		RTO_u32OvfIncreament=0;
		TIM_voidInitRegister(RTO_u8_INITValue);
		/*Schedular code*/
		/*Loop on all Tasks*/
		for(u8 RTO_u8LoopCounter=0;RTO_u8LoopCounter<RTO_u8_NUM_OF_TASKS;RTO_u8LoopCounter++)
		{
			/*check that a task is created at this location*/
			if(RTO_SYSTASKS[RTO_u8LoopCounter] !=(Task*) 0)
			{
				if(RTO_SYSTASKS[RTO_u8LoopCounter]->u8State == RTO_u8_ACTIVE_STATE)
				{

					if(RTO_SYSTASKS[RTO_u8LoopCounter]->u8FirstDelay ==0)
					{
						RTO_SYSTASKS[RTO_u8LoopCounter]->u8FirstDelay=RTO_SYSTASKS[RTO_u8LoopCounter]->u8periodicity;
						(RTO_SYSTASKS[RTO_u8LoopCounter]->TaskHandler) ();
					}
					else
					{
						RTO_SYSTASKS[RTO_u8LoopCounter]->u8FirstDelay--;
					}
				}
				else
				{
					/*Task is suspended, nothing to do*/
				}
			}
			else
			{
				/*No Task created at this location*/
			}
		}
	}
}

/*This function initialize the RTO driver*/
void RTO_voidInitialize(void)
{
	u32 Local_Tovf;
	u32 Local_OvfFrac;
	//	/*Set Call Back of timer to schedular function*/
	TIM_voidSetCallBack(RTO_voidSchedular);
	//	/*Calculate number of OVF for tick*/
	Local_Tovf=(u32)((u32)((u32)(1<<TIM_u8_TIM_RES) * (u16)(TIM_u16_PRESCALER)) /(u8) RTO_u8_SYS_FREQ_MHZ);
	RTO_u32OvfCount=(u32)((u32)((u8) RTO_u8_TICK_TIME_MS * (u32)RTO_u16_MS_TO_US) / (u32)Local_Tovf);
	Local_OvfFrac=(u32)((u32)((u8)RTO_u8_TICK_TIME_MS * (u32)RTO_u16_MS_TO_US) % (u32)Local_Tovf);
	if(Local_OvfFrac != 0)
	{
		RTO_u32OvfCount++;
		RTO_u8_INITValue=(u8)((u16)(1 <<TIM_u8_TIM_RES) - (u16)((u32)( (u16) (1 << TIM_u8_TIM_RES) * (u32)Local_OvfFrac) / (u32)Local_Tovf));
	}
	else
	{
		RTO_u8_INITValue=0;
	}
}
/*This function creates a new task*/
void RTO_voidCreateTask(Task * TaskCpy, u8 u8Priority)
{
	if(u8Priority< RTO_u8_NUM_OF_TASKS)
	{
		RTO_SYSTASKS[u8Priority]=TaskCpy;
	}
	else
	{
		/*Report Error*/
	}
}





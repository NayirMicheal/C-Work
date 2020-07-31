/*
 * RTO_prog.c
 *
 *  Created on: 21 Feb 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER0_register.h"
#define NUM_OF_TASKS 6
#define Timer_Threshold 1563
#define Initial_Value 127

volatile u8 u8Tick_counter=0;
volatile u32 Timer_counter=Initial_Value;
void Leds_Task(void);
void Motor_Task(void);
void SevenSeg_Task(void);
void Buzzer_Task(void);
void LCD_E_TASK(void);
void LCD_A_TASK(void);
typedef struct
{
	void(*ptr)(void);
	u8 periodicity;
}Task;

/*Array of System tasks*/
Task SysTasks[NUM_OF_TASKS]={
		{Leds_Task,10},
		{Motor_Task,11},
		{SevenSeg_Task,14},
		{Buzzer_Task,2},
		{LCD_E_TASK,6},
		{LCD_A_TASK,8}

};
/*
 * RTO Schedular
 */
void scheduler (void)
{
	u8 u8LoopCounterLoc;
	u8Tick_counter++;
	for(u8LoopCounterLoc=0;u8LoopCounterLoc<NUM_OF_TASKS;u8LoopCounterLoc++)
	{
		if((u8Tick_counter % SysTasks[u8LoopCounterLoc].periodicity)==0)
		{
			SysTasks[u8LoopCounterLoc].ptr();
		}
	}
}

/*
 * Timer Init
 * */
void Timer0_init(void)
{
	TCNT0=Initial_Value;
	SET_BIT(TIMSK,0);
	SET_BIT(TIFR,0);
	TCCR0=0b00000001;
}

/*
 * Tick Timer
 * */
void __vector_11(void) __attribute__((signal,used));
void __vector_11(void)
{
	Timer_counter++;
	if(Timer_counter== Timer_Threshold)
	{
		Timer_counter=0;
		TCNT0=Initial_Value;
		scheduler();
	}
}

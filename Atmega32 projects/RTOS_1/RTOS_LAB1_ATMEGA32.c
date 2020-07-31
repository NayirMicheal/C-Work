/*
 * RTOS_LAB1_ATMEGA32.c
 *
 * Created: 1/27/2014 12:22:11 AM
 *  Author: Islam
 */ 

#include <avr/io.h>
#include "FreeRTOS.h"
#include "task.h"
#include "lcd_4bit.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* Define Tasks Priorities */
#define  TASK1_PRIORITY 1
#define  TASK2_PRIORITY 2

/*tasks codes prototypes */
static void task1_code(void*pvParamter);
static void task2_code(void*pvParamter);

int main(void)
{

	/*initialize LCD*/
	lcd_init();	
	/*Creat tasks*/
	xTaskCreate(task1_code,(const signed char *)"task1",configMINIMAL_STACK_SIZE,NULL,TASK1_PRIORITY,NULL);
	xTaskCreate(task2_code,(const signed char *)"task2",configMINIMAL_STACK_SIZE,NULL,TASK2_PRIORITY,NULL);
	/*start Scheduler */
	vTaskStartScheduler();
	

	return 0;
    
}

/*Task1 Code */
static void task1_code(void*pvParamter)
{
    char counter=0;
	for (;;)
	{
		counter = (counter+1)%10;
		lcd_clrScreen();
		lcd_dispString("I am Task 1");
		
		lcd_displayChar((counter+'0'));
		_delay_ms(1000);
		vTaskDelay(500);
	}
		
}

///*Task 2 Code*/
static void task2_code(void*pvParamter)
{
	char x =3;
	
	lcd_dispString("I am Task 3");
	//vTaskDelay(2000);
	
	
		
		x++;
		//func();
		lcd_clrScreen();
		lcd_dispString("I am Task 2");
		_delay_ms(1000);
		vTaskDelay(2000);
	
}


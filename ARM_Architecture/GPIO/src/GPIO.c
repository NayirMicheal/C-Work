/*
 * GPIO.c
 *
 *  Created on: 27 Apr 2018
 *      Author: Nayir
 */
#include <stdio.h>
#include "BIT_MATH.h"
#include "GPIO.h"

#define GPIO_PORTA 0x40010800
#define GPIO_PORTB 0x40010C00
#define GPIO_PORTC 0x40011000

typedef struct
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCK;
} GPIO_t;

volatile GPIO_t * const PORT_A=(volatile GPIO_t * const) GPIO_PORTA;
volatile GPIO_t * const PORT_B=(volatile GPIO_t * const) GPIO_PORTB;
volatile GPIO_t * const PORT_C=(volatile GPIO_t * const) GPIO_PORTC;

void GPIO_initialize(void)
{
	/*make registers equal zero*/
	PORT_A->CRL &= (uint32_t) 0;
	PORT_A->CRH &= (uint32_t) 0;
	PORT_B->CRL &= (uint32_t) 0;
	PORT_B->CRH &= (uint32_t) 0;
	PORT_C->CRL &= (uint32_t) 0;
	PORT_C->CRH &= (uint32_t) 0;
	for(uint8_t i=0;i<16;i++)
	{
		/*first 8 pins*/
		if(i<=7)
		{
			/*for PORT A*/
			PORT_A->CRL |= (uint32_t)(portA_cfg[i].pinMode << (i*4));
			PORT_A->CRL |= (uint32_t)(portA_cfg[i].IoMode << ((i*4) +2));
			switch(portA_cfg[i].pulltype)
			{
			case PULL_UP:
				SET_BIT(PORT_A->ODR,i);
				break;
			case PULL_DOWN:
				CLR_BIT(PORT_A->ODR,i);
				break;
			case NON_PULL_UP_DOWN:
				break;
			}

			/*for PORT B*/
			PORT_B->CRL |= (uint32_t)(portB_cfg[i].pinMode << (i*4));
			PORT_B->CRL |= (uint32_t)(portB_cfg[i].IoMode << ((i*4) +2));
			switch(portB_cfg[i].pulltype)
			{
			case PULL_UP:
				SET_BIT(PORT_B->ODR,i);
				break;
			case PULL_DOWN:
				CLR_BIT(PORT_B->ODR,i);
				break;
			case NON_PULL_UP_DOWN:
				break;
			}

			/*for PORT C*/
			PORT_C->CRL |= (uint32_t)(portC_cfg[i].pinMode << (i*4));
			PORT_C->CRL |= (uint32_t)(portC_cfg[i].IoMode << ((i*4) +2));
			switch(portC_cfg[i].pulltype)
			{
			case PULL_UP:
				SET_BIT(PORT_C->ODR,i);
				break;
			case PULL_DOWN:
				CLR_BIT(PORT_C->ODR,i);
				break;
			case NON_PULL_UP_DOWN:
				break;
			}
		}
		/*second 8 pins*/
		else
		{
			/*for PORT A*/
			PORT_A->CRH |= (uint32_t)(portA_cfg[i].pinMode << ((i*4)-8));
			PORT_A->CRH |= (uint32_t)(portA_cfg[i].IoMode << (((i*4) +2)-8));
			switch(portA_cfg[i].pulltype)
			{
			case PULL_UP:
				SET_BIT(PORT_A->ODR,i);
				break;
			case PULL_DOWN:
				CLR_BIT(PORT_A->ODR,i);
				break;
			case NON_PULL_UP_DOWN:
				break;
			}

			/*for PORT B*/
			PORT_B->CRH |= (uint32_t)(portB_cfg[i].pinMode << (i*4));
			PORT_B->CRH |= (uint32_t)(portB_cfg[i].IoMode << ((i*4) +2));
			switch(portB_cfg[i].pulltype)
			{
			case PULL_UP:
				SET_BIT(PORT_B->ODR,i);
				break;
			case PULL_DOWN:
				CLR_BIT(PORT_B->ODR,i);
				break;
			case NON_PULL_UP_DOWN:
				break;
			}

			/*for PORT C*/
			PORT_C->CRH |= (uint32_t)(portC_cfg[i].pinMode << (i*4));
			PORT_C->CRH |= (uint32_t)(portC_cfg[i].IoMode << ((i*4) +2));
			switch(portC_cfg[i].pulltype)
			{
			case PULL_UP:
				SET_BIT(PORT_C->ODR,i);
				break;
			case PULL_DOWN:
				CLR_BIT(PORT_C->ODR,i);
				break;
			case NON_PULL_UP_DOWN:
				break;
			}
		}
	}
}

Level_t GPIO_readPin(ports_t port,uint8_t pinNumber)
{
	uint8_t value=0;
	Level_t level=LOW;
	switch(port)
	{
	case portA:
		value=GET_BIT(PORT_A->IDR,pinNumber);
		break;
	case portB:
		value=GET_BIT(PORT_B->IDR,pinNumber);
		break;
	case portC:
		value=GET_BIT(PORT_C->IDR,pinNumber);
		break;
	}
	switch(value)
	{
	case 1:
		level=HIGH;
		break;
	case 0:
		level=LOW;
		break;
	}
	return level;
}

void GPIO_writePin(ports_t port,uint8_t pinNumber,Level_t level)
{
	switch(port)
	{
	case portA:
		switch (level)
		{
		case HIGH:
			SET_BIT(PORT_A->BSRR,pinNumber);
			break;
		case LOW:
			SET_BIT(PORT_A->BRR,pinNumber);
			break;
		}
		break;
		case portB:
			switch (level)
			{
			case HIGH:
				SET_BIT(PORT_B->BSRR,pinNumber);
				break;
			case LOW:
				SET_BIT(PORT_B->BRR,pinNumber);
				break;
			}
			break;
			case portC:
				switch (level)
				{
				case HIGH:
					SET_BIT(PORT_C->BSRR,pinNumber);
					break;
				case LOW:
					SET_BIT(PORT_C->BRR,pinNumber);
					break;
				}
				break;
	}
}

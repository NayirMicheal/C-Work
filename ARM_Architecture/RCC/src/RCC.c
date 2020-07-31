/*
 * RCC.c
 *
 *  Created on: 20 Apr 2018
 *      Author: Nayir
 */
#include <stdio.h>
#include "BIT_MATH.h"
#include "RCC.h"
#define RCC_BASE 0x40021000

#define RCC_CR 	     *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x00)))
#define RCC_CFGR 	 *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x04)))
#define RCC_CIR 	 *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x08)))
#define RCC_APB2RSTR *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x0c)))
#define RCC_APB1RSTR *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x10)))
#define RCC_APB1RSTR *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x10)))
#define RCC_AHBENR   *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x14)))
#define RCC_APB2ENR  *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x18)))
#define RCC_APB1ENR  *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x1c)))
#define RCC_BDCR  	 *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x20)))
#define RCC_CSR	  	 *((volatile uint32_t*) (RCC_BASE+((uint32_t)0x24)))

#define MAX_TIME_OUT 0x500
return_status_t rcc_setClockStatus(_clock_t clock,status_t status)
{
	uint32_t timeout=0;
	if(clock == HSE)
	{
		switch(status)
		{
		case EN:
			SET_BIT(RCC_CR,16);
			/*Timeout concept*/
			while((!(GET_BIT(RCC_CR,17))) && timeout < MAX_TIME_OUT)
			{
				timeout++;
			}
			if((GET_BIT(RCC_CR,17)))
			{
				return OK;
			}
			else
			{
				return NOTOK;
			}
			break;
		case DIS:
			CLR_BIT(RCC_CR,16);
		}
	}
	else if(clock == HSI)
	{
		switch(status)
		{
		case EN:
			SET_BIT(RCC_CR,0);
			while((!(GET_BIT(RCC_CR,1))) && (timeout < MAX_TIME_OUT))
			{
				timeout++;
			}
			break;
			if((GET_BIT(RCC_CR,1)))
			{
				return OK;
			}
			else
			{
				return NOTOK;
			}
		case DIS:
			CLR_BIT(RCC_CR,0);
		}
	}
	else if(clock == LSI)
	{
		switch(status)
		{
		case EN:
			SET_BIT(RCC_CSR,0);
			while(((GET_BIT(RCC_CSR,1))) && (timeout < MAX_TIME_OUT))
			{
				timeout++;
			}
			if((GET_BIT(RCC_CSR,1)))
			{
				return OK;
			}
			else
			{
				return NOTOK;
			}
			break;
		case DIS:
			CLR_BIT(RCC_CSR,0);
		}
	}
	else if(clock == PLL)
	{
		switch(status)
		{
		case EN:
			SET_BIT(RCC_CR,24);
			while((!(GET_BIT(RCC_CR,25))) && (timeout < MAX_TIME_OUT))
			{
				timeout++;
			}
			if((GET_BIT(RCC_CR,25)))
			{
				return OK;
			}
			else
			{
				return NOTOK;
			}
			break;
		case DIS:
			CLR_BIT(RCC_CR,24);
		}
	}
	return OK;
}

return_status_t rcc_configurePLL(uint32_t PLL_SRC,PLL_MUL_t PLL_MUL)
{
	if(GET_BIT(RCC_CR,25) == 1)
	{
		return NOTOK;
	}
	else
	{
		switch(PLL_SRC)
		{
		/*HSI oscillator clock / 2 selected as PLL input clock*/
		case PLL_CONFIG_HSI_DIV_2 :
			CLR_BIT(RCC_CFGR,16);
			break;
			/*HSE oscillator clock selected as PLL input clock*/
		case PLL_CONFIG_HSE:
			SET_BIT(RCC_CFGR,16);
			break;
		}
		/*ensure clearing those bits from 18 : 21*/
		CLR_BIT(RCC_CFGR,18);
		CLR_BIT(RCC_CFGR,19);
		CLR_BIT(RCC_CFGR,20);
		CLR_BIT(RCC_CFGR,21);
		RCC_CFGR |=((uint32_t)(PLL_MUL<<18));
		return OK;
	}
}
return_status_t rcc_configureHSE(uint32_t PLLxTPre)
{
	if(GET_BIT(RCC_CR,25) == 1)
	{
		return NOTOK;
	}
	else
	{
		switch(PLLxTPre)
		{
		/*HSE clock not divided*/
		case PLL_CONFIG_HSE:
			CLR_BIT(RCC_CFGR,17);
			break;

			/*HSE clock divided by 2*/
		case PLL_CONFIG_HSE_DIV_2:
			SET_BIT(RCC_CFGR,17);
			break;
		}
		return OK;
	}

}
return_status_t rcc_configureSYSCLK(clock_sys SYSCLK_SRC)
{
	CLR_BIT(RCC_CFGR , 0);
	CLR_BIT(RCC_CFGR , 1);
	switch(SYSCLK_SRC)
	{
	case HSI_SYSCLK:
		if(GET_BIT(RCC_CR,1))
		{
			RCC_CFGR |=(uint32_t) SYSCLK_SRC;
		}
		else
		{
			return NOTOK;
		}
		break;
	case HSE_SYSCLK:
		if(GET_BIT(RCC_CR,17))
		{
			RCC_CFGR |=(uint32_t) SYSCLK_SRC;
		}
		else
		{
			return NOTOK;
		}
		break;
	case PLL_SYSCLK:
		if(GET_BIT(RCC_CR,25))
		{
			RCC_CFGR |=(uint32_t) SYSCLK_SRC;
		}
		else
		{
			return NOTOK;
		}
		break;
	}
	return OK;
}

void rcc_configureMCO(MCO_t MCO)
{
	CLR_BIT(RCC_CFGR , 24);
	CLR_BIT(RCC_CFGR , 25);
	CLR_BIT(RCC_CFGR , 26);
	CLR_BIT(RCC_CFGR , 27);
	switch (MCO)
	{
	case NO_CLK:
		CLR_BIT(RCC_CFGR , 26);
		CLR_BIT(RCC_CFGR , 27);
		break;
	case SYS_CLK:
	case HSI_CLK:
	case HSE_CLK:
	case PLL_CLK:
		RCC_CFGR |=(uint32_t)(MCO<<24);
		break;
	}
}

void rcc_setAPB1Prescaler(uint32_t APB1_PRE)
{
	CLR_BIT(RCC_CFGR,8);
	CLR_BIT(RCC_CFGR,9);
	CLR_BIT(RCC_CFGR,10);
	switch(APB1_PRE)
	{
	/*no division*/
	case APB1_PRESCALER_NO_DIVISION:
		RCC_CFGR |=(uint32_t)(APB1_PRE<<10);
		break;

		/*divide by 2*/
	case APB1_PRESCALER_DIV_2:
		/*divide by 4*/
	case APB1_PRESCALER_DIV_4:
		/*divide by 8*/
	case APB1_PRESCALER_DIV_8:
		/*divide by 16*/
	case APB1_PRESCALER_DIV_16:
		RCC_CFGR |=(uint32_t)(APB1_PRE<<8);
		break;
	}
}
void rcc_setAPB2Prescaler(uint32_t APB2_PRE)
{
	CLR_BIT(RCC_CFGR,11);
	CLR_BIT(RCC_CFGR,12);
	CLR_BIT(RCC_CFGR,13);
	switch(APB2_PRE)
	{
	/*no division*/
	case APB2_PRESCALER_NO_DIVISION:
		RCC_CFGR |=(uint32_t)(APB2_PRE<<13);
		break;
		/*divide by 2*/
	case APB2_PRESCALER_DIV_2:
		/*divide by 4*/
	case APB2_PRESCALER_DIV_4:
		/*divide by 8*/
	case APB2_PRESCALER_DIV_8:
		/*divide by 16*/
	case APB2_PRESCALER_DIV_16:
		RCC_CFGR |=(uint32_t)(APB2_PRE<<11);
		break;
	}
}
void rcc_setAHBPrescaler(uint32_t AHB_PRE)
{
	CLR_BIT(RCC_CFGR,4);
	CLR_BIT(RCC_CFGR,5);
	CLR_BIT(RCC_CFGR,6);
	CLR_BIT(RCC_CFGR,7);
	switch(AHB_PRE)
	{
	/*no division*/
	case AHB_PRESCALER_NO_DIVISION:
		RCC_CFGR |=(uint32_t)(AHB_PRE<<7);
		break;
		/*divide by 2*/
	case AHB_PRESCALER_DIV_2:
		/*divide by 4*/
	case AHB_PRESCALER_DIV_4:
		/*divide by 8*/
	case AHB_PRESCALER_DIV_8:
		/*divide by 16*/
	case AHB_PRESCALER_DIV_16:
		/*divide by 64*/
	case AHB_PRESCALER_DIV_64:
		/*divide by 128*/
	case AHB_PRESCALER_DIV_128:
		/*divide by 256*/
	case AHB_PRESCALER_DIV_256:
		/*divide by 512*/
	case AHB_PRESCALER_DIV_512:
		RCC_CFGR |=(uint32_t)(AHB_PRE<<4);
		break;
	}
}
void rcc_setADCPrescaler(uint32_t ADC_PRE)
{
	CLR_BIT(RCC_CFGR,14);
	CLR_BIT(RCC_CFGR,15);
	RCC_CFGR |=(uint32_t)(ADC_PRE<<14);
}

void rcc_APB1periCmd(APB1_Peri_t APB1_PERI,status_t status)
{
	switch(status)
	{
	case EN:
		SET_BIT(RCC_APB1ENR,APB1_PERI);
		break;
	case DIS:
		CLR_BIT(RCC_APB1ENR,APB1_PERI);
		break;
	}
}
void rcc_APB2periCmd(APB2_Peri_t APB2_PERI,status_t status)
{
	switch(status)
	{
	case EN:
		SET_BIT(RCC_APB2ENR,APB2_PERI);
		break;
	case DIS:
		CLR_BIT(RCC_APB2ENR,APB2_PERI);
		break;
	}
}
void rcc_AHBperiCmd(AHB_Peri_t AHB_PERI,status_t status)
{
	switch(status)
	{
	case EN:
		SET_BIT(RCC_AHBENR,AHB_PERI);
		break;
	case DIS:
		CLR_BIT(RCC_AHBENR,AHB_PERI);
		break;
	}
}

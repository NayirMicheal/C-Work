/*
 * RCC_Manager.c
 *
 *  Created on: 23 Apr 2018
 *      Author: Nayir
 */
#include <stdio.h>
#include "RCC.h"
#include "RCC_Manager.h"

return_status_t RCC_Manager_clockInit(void)
{
	return_status_t clockStatus;
#if RCC_MANAGER_SYSCLOCK == MHZ_8_CLOCK
	clockStatus=rcc_setClockStatus(HSE,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(HSE_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;

#elif RCC_MANAGER_SYSCLOCK == MHZ_12_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL3);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_16_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL2);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_20_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL5);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_24_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL3);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_28_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL7);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_32_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL4);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_36_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL9);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_40_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL5);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_44_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL11);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_48_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL6);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_52_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL13);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_56_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL7);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_60_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL15);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_64_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL8);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#elif RCC_MANAGER_SYSCLOCK == MHZ_72_CLOCK
	clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL9);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus =rcc_setClockStatus(PLL,EN);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	clockStatus=rcc_configureSYSCLK(PLL_SYSCLK);
	if(clockStatus == NOTOK)
	{
		return NOTOK;
	}
	return OK;
#endif
}
return_status_t RCC_Manager_switchToClock(uint32_t MHZ)
{
	return_status_t clockStatus;
	switch(MHZ)
	{
	case MHZ_8_CLOCK:
		clockStatus=rcc_setClockStatus(HSE,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(HSE_SYSCLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_12_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL3);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL3);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_16_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL2);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL2);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_20_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL5);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL5);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_24_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL3);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL3);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_28_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL7);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL7);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_32_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL4);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL4);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_36_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL9);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL9);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_40_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL5);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL5);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_44_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL11);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL11);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_48_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL6);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL6);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_52_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL13);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL13);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_56_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL7);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL7);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_60_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE_DIV_2);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL15);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE_DIV_2,MUL15);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_64_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL8);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL8);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	case MHZ_72_CLOCK:
		clockStatus=rcc_configureHSE(PLL_CONFIG_HSE);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL9);
		if(clockStatus == NOTOK)
		{
			clockStatus=rcc_setClockStatus(HSI,EN);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_configureSYSCLK(HSI_SYSCLK);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus=rcc_setClockStatus(PLL,DIS);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
			clockStatus =rcc_configurePLL(PLL_CONFIG_HSE,MUL9);
			if(clockStatus == NOTOK)
			{
				return NOTOK;
			}
		}
		clockStatus =rcc_setClockStatus(PLL_CLK,EN);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		clockStatus=rcc_configureSYSCLK(PLL_CLK);
		if(clockStatus == NOTOK)
		{
			return NOTOK;
		}
		break;
	}
	return OK;
}



/*
 * SPI_prog.c
 *
 *  Created on: 1 May 2018
 *      Author: Nayir
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_reg.h"
#include "SPI_priv.h"
#include "SPI_config.h"
#include "SPI_int.h"
#include "DIO_register.h"

static volatile u8 recievedData;
static volatile u8 flag=0;
void SPI_init(void)
{
#if SPI_DORD == DORD_LSB_FIRST
	SET_BIT(SPCR,5);
#elif SPI_DORD == DORD_MSB_FIRST
	CLR_BIT(SPCR,5);
#endif

#if SPI_TYPE == SPI_MASTER
	SET_BIT(SPCR,4);
#elif SPI_TYPE == SPI_SLAVE
	CLR_BIT(SPCR,4);
#endif

#if SPI_CLK_POL == SPI_CLK_POL_RAISING
	CLR_BIT(SPCR,3);
#elif SPI_CLK_POL == SPI_CLK_POL_FALLING
	SET_BIT(SPCR,3);
#endif

#if SPI_CLK_PHASE == SPI_CLK_PHASE_SAMPLE
	CLR_BIT(SPCR,2);
#elif SPI_CLK_PHASE == SPI_CLK_PHASE_SETUP
	SET_BIT(SPCR,2);
#endif

#if SPI_PRESCALER == SPI_PRESCALER_2
	CLR_BIT(SPCR,1);
	CLR_BIT(SPCR,0);
	SET_BIT(SPSR,0);
#elif SPI_PRESCALER == SPI_PRESCALER_4
	CLR_BIT(SPCR,1);
	CLR_BIT(SPCR,0);
	CLR_BIT(SPSR,0);
#elif SPI_PRESCALER == SPI_PRESCALER_8
	CLR_BIT(SPCR,1);
	SET_BIT(SPCR,0);
	SET_BIT(SPSR,0);
#elif SPI_PRESCALER == SPI_PRESCALER_16
	CLR_BIT(SPCR,1);
	SET_BIT(SPCR,0);
	CLR_BIT(SPSR,0);
#elif SPI_PRESCALER == SPI_PRESCALER_32
	SET_BIT(SPCR,1);
	CLR_BIT(SPCR,0);
	SET_BIT(SPSR,0);
#elif SPI_PRESCALER == SPI_PRESCALER_64
	SET_BIT(SPCR,1);
	CLR_BIT(SPCR,0);
	CLR_BIT(SPSR,0);
#elif SPI_PRESCALER == SPI_PRESCALER_128
	SET_BIT(SPCR,1);
	SET_BIT(SPCR,0);
	CLR_BIT(SPSR,0);
#endif
	SET_BIT(SPCR,6);
}
void SPI_interruptEnable(void)
{
	SET_BIT(SPCR,7);
}
void SPI_disableEnable(void)
{
	CLR_BIT(SPCR,7);
}

void SPI_transmit(u8 data)
{
	SPDR=data;
}
void SPI_waitForTransferCompleteFlag(void)
{
	while(GET_BIT(SPSR,7) == 0);
}
u8 SPI_receive(void)
{
	if(flag==1)
	{
		flag=0;
		return recievedData;
	}
	else
	{
		return 0;
	}

}
void __vector_12 (void)__attribute__((signal,used));
void __vector_12 (void)
{
	recievedData=SPDR;
}

/*
 * RCC.h
 *
 *  Created on: 20 Apr 2018
 *      Author: Nayir
 */

#ifndef RCC_H_
#define RCC_H_

typedef enum
{
	HSE=0,
	HSI,
	PLL,
	LSI,
	NUM_OF_GENERAL_CLOCK
}_clock_t;

typedef enum
{
	DIS=0,
	EN
}status_t;

typedef enum
{
	NOTOK,
	OK
}return_status_t;

typedef enum
{
	MUL2=0,
	MUL3,
	MUL4,
	MUL5,
	MUL6,
	MUL7,
	MUL8,
	MUL9,
	MUL10,
	MUL11,
	MUL12,
	MUL13,
	MUL14,
	MUL15,
	MUL16
}PLL_MUL_t;
typedef enum
{
	HSI_SYSCLK=0,
	HSE_SYSCLK,
	PLL_SYSCLK
}clock_sys;
typedef enum {
	NO_CLK=0,
	SYS_CLK=4,
	HSI_CLK=5,
	HSE_CLK=6,
	PLL_CLK=7
}MCO_t;

typedef enum{
	AFIO=0,
	IOPA=2,
	IOPB=3,
	IOPC=4,
	IOPD=5,
	IOPE=6,
	IOPF=7,
	IOPG=8,
	ADC1=9,
	ADC2=10,
	TIM1=11,
	SPI1=12,
	TIM8=13,
	USART1=14,
	ADC3=15,
	TIM9=19,
	TIM10=20,
	TIM11=21
}APB2_Peri_t;
typedef enum{
	TIM2=0,
	TIM3=1,
	TIM4=2,
	TIM5=3,
	TIM6=4,
	TIM7=5,
	TIM12=6,
	TIM13=7,
	TIM14=8,
	WWDG=11,
	SPI2=14,
	SPI3=15,
	USART2=17,
	USART3=18,
	UART4E=19,
	UART5E=20,
	I2C1=21,
	I2C2=22,
	USB=23,
	CAN=25,
	BKP=27,
	PWR=28,
	DAC=29
}APB1_Peri_t;
typedef enum{
	DMA1=0,
	DMA2=1,
	SRAM=2,
	FLITF=4,
	CRCE=6,
	FSMC=8,
	SDIO=10
}AHB_Peri_t;

#define PLL_CONFIG_HSI_DIV_2 0
#define PLL_CONFIG_HSE       1
#define PLL_CONFIG_HSE_DIV_2 2

#define APB1_PRESCALER_NO_DIVISION 0
#define APB1_PRESCALER_DIV_2 4
#define APB1_PRESCALER_DIV_4 5
#define APB1_PRESCALER_DIV_8 6
#define APB1_PRESCALER_DIV_16 7


#define APB2_PRESCALER_NO_DIVISION 0
#define APB2_PRESCALER_DIV_2 4
#define APB2_PRESCALER_DIV_4 5
#define APB2_PRESCALER_DIV_8 6
#define APB2_PRESCALER_DIV_16 7

#define AHB_PRESCALER_NO_DIVISION 0
#define AHB_PRESCALER_DIV_2 	  8
#define AHB_PRESCALER_DIV_4 	  9
#define AHB_PRESCALER_DIV_8 	  10
#define AHB_PRESCALER_DIV_16 	  11
#define AHB_PRESCALER_DIV_64 	  12
#define AHB_PRESCALER_DIV_128 	  13
#define AHB_PRESCALER_DIV_256 	  14
#define AHB_PRESCALER_DIV_512 	  15

extern return_status_t rcc_setClockStatus(_clock_t clock,status_t status);
extern return_status_t rcc_configurePLL(uint32_t PLL_SRC,PLL_MUL_t PLL_MUL);
extern return_status_t rcc_configureHSE(uint32_t PLLxTPre);
extern return_status_t rcc_configureSYSCLK(clock_sys SYSCLK_SRC);
extern void rcc_configureMCO(MCO_t MCO);

extern void rcc_setAPB1Prescaler(uint32_t APB1_PRE);
extern void rcc_setAPB2Prescaler(uint32_t APB2_PRE);
extern void rcc_setAHBPrescaler(uint32_t AHB_PRE);
extern void rcc_setADCPrescaler(uint32_t ADC_PRE);

extern void rcc_APB1periCmd(APB1_Peri_t APB1_PERI,status_t status);
extern void rcc_APB2periCmd(APB2_Peri_t APB2_PERI,status_t status);
extern void rcc_AHBperiCmd(AHB_Peri_t AHB_PERI,status_t status);

#endif /* RCC_H_ */

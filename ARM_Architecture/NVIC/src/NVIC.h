/*
 * NVIC.h
 *
 *  Created on: 4 May 2018
 *      Author: Nayir
 */

#ifndef NVIC_H_
#define NVIC_H_
typedef enum
{
	WWDG=0,
	PVD,
	TAMPER,
	RTC,
	FLASH,
	RCC,
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	DMA1_Channel1,
	DMA1_Channel2,
	DMA1_Channel3,
	DMA1_Channel4,
	DMA1_Channel5,
	DMA1_Channel6,
	DMA1_Channel7,
	ADC1_2,
	USB_HP_CAN_TX,
	USB_LP_CAN_RX0,
	CAN_RX1,
	CAN_SCE,
	EXTI9_5,
	TIM8_BRK_TIM12,
	TIM8_UP_TIM13,
	TIM1_TRG_COM_TIM14,
	TIM1_CC,
	TIM2,
	TIM3,
	TIM4,
	I2C1_EV,
	I2C1_ER,
	I2C2_EV,
	I2C2_ER,
	SPI1,
	SPI2,
	USART1,
	USART2,
	USART3,
	EXTI15_10,
	RTCAlarm,
	USBWakeup,
	TIM8_BRK,
	TIM8_UP,
	TIM8_TRG_COM,
	TIM8_CC,
	ADC3,
	FSMC,
	SDIO,
	TIM5,
	SPI3,
	UART4,
	UART5,
	TIM6,
	TIM7,
	DMA2_Channel1,
	DMA2_Channel2,
	DMA2_Channel3,
	DMA2_Channel4_5
}interrupt_t;
void NVIC_enableInterrupt(interrupt_t index);
void NVIC_disableInterrupt(interrupt_t index);
void NVIC_generateSwInterrupt(interrupt_t index);
void NVIC_disableAllInterruptrequest(void);
void NVIC_enableAllInterruptrequest(void);


#endif /* NVIC_H_ */

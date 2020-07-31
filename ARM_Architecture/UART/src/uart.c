/*
 * uart.c
 *
 *  Created on: 4 May 2018
 *      Author: Nayir
 */
#include <stdio.h>
#include "BIT_MATH.h"
#include "uart.h"

#define Usart1_Base 0x40013800
#define Usart2_Base 0x40004400
#define Usart3_Base 0x40004800

/* UART masks */
#define UART_TXE_BIT_MASK 		(uint32_t)0x00000080
#define UART_TC_BIT_MASK 		(uint32_t)0x00000040
#define UART_RXNE_BIT_MASK 		(uint32_t)0x00000020

#define UART_UE_BIT_MASK 		(uint32_t)0x00002000
#define UART_M_BIT_MASK 		(uint32_t)0x00001000
#define UART_PCE_BIT_MASK 		(uint32_t)0x00000400
#define UART_PS_BIT_MASK 		(uint32_t)0x00000200
#define UART_TXEIE_BIT_MASK 	(uint32_t)0x00000080
#define UART_TCIE_BIT_MASK 		(uint32_t)0x00000040
#define UART_RXNEIE_BIT_MASK 	(uint32_t)0x00000020
#define UART_TE_BIT_MASK 		(uint32_t)0x00000008
#define UART_RE_BIT_MASK 		(uint32_t)0x00000004

#define UART_STOP_BITS_MASK 			(uint32_t)0x00000300
#define UART_STOP_BITS_1_MODE_MASK 		(uint32_t)0x00000000
#define UART_STOP_BITS_2_MODE_MASK 		(uint32_t)0x00002000

typedef struct
{
	uint32_t USART_SR;
	uint32_t USART_DR;
	uint32_t USART_BRR;
	uint32_t USART_CR1;
	uint32_t USART_CR2;
	uint32_t USART_CR3;
	uint32_t USART_GTPR;

}usart_t;

volatile usart_t * const Usart1=(volatile usart_t * const) Usart1_Base;
volatile usart_t * const Usart2=(volatile usart_t * const) Usart2_Base;
volatile usart_t * const Usart3=(volatile usart_t * const) Usart3_Base;

typedef enum{
	idle,
	initialized,
	sending
}uart_sending_status;

typedef enum
{
	Opened,
	Closed,
}RX_Buffer_State;

static struct
{
	const uint8_t *tx_data_buffer;
	uint16_t tx_buffer_size;
	uint16_t tx_buffer_pos;
}TX_Buffer;

static struct
{
	uint8_t *rx_data_buffer;
	uint16_t rx_buffer_size;
	uint16_t rx_buffer_pos;
}RX_Buffer;


CallBack tx_notify,rx_notify;
static RX_Buffer_State rx_buffer_state = Closed;
uart_sending_status send_status=idle;

static void stub_H(void);

void Usart_init(void)
{
	/* Initialize callbacks */
	rx_notify = stub_H;
	tx_notify = stub_H;
	/* Define word length */
	Usart1->USART_CR1 |= UART_M_BIT_MASK;
	Usart2->USART_CR1 |= UART_M_BIT_MASK;
	Usart3->USART_CR1 |= UART_M_BIT_MASK;

	/* Configure the stop bits */
	Usart1->USART_CR2 |=UART_STOP_BITS_1_MODE_MASK;
	Usart2->USART_CR2 |=UART_STOP_BITS_1_MODE_MASK;
	Usart3->USART_CR2 |=UART_STOP_BITS_1_MODE_MASK;

	/* No parity */
	Usart1->USART_CR1 &=~(UART_PCE_BIT_MASK);
	Usart2->USART_CR1 &=~(UART_PCE_BIT_MASK);
	Usart3->USART_CR1 &=~(UART_PCE_BIT_MASK);

	/* Config baud rate*/
	/* As 9600 , F_PCLK = 36 MHZ */
	Usart1->USART_BRR |= (uint32_t)0x00000EA6;
	Usart2->USART_BRR |= (uint32_t)0x00000EA6;
	Usart3->USART_BRR |= (uint32_t)0x00000EA6;

	/* Enable RX and TX*/
	Usart1->USART_CR1 |= UART_TE_BIT_MASK | UART_RE_BIT_MASK;
	Usart2->USART_CR1 |= UART_TE_BIT_MASK | UART_RE_BIT_MASK;
	Usart3->USART_CR1 |= UART_TE_BIT_MASK | UART_RE_BIT_MASK;

	/* Enable TXE and RX interrupts */
	Usart1->USART_CR1 |= UART_TCIE_BIT_MASK | UART_RXNEIE_BIT_MASK;
	Usart2->USART_CR1 |= UART_TCIE_BIT_MASK | UART_RXNEIE_BIT_MASK;
	Usart3->USART_CR1 |= UART_TCIE_BIT_MASK | UART_RXNEIE_BIT_MASK;

	/* Enable UART */
	Usart1->USART_CR1 |= UART_UE_BIT_MASK;
	Usart2->USART_CR1 |= UART_UE_BIT_MASK;
	Usart3->USART_CR1 |= UART_UE_BIT_MASK;
}
uart_return_status Usart_send(uart_t uart,const uint8_t * Data,uint8_t size)
{
	if((Data == NULL) || 0==size)
	{
		return fault_parameter;
	}
	if(send_status == sending)
	{
		return Busy;
	}
	TX_Buffer.tx_data_buffer=Data;
	TX_Buffer.tx_buffer_pos=0;
	TX_Buffer.tx_buffer_size=size;
	switch(uart)
	{
	case uart1:
		Usart1->USART_DR=(uint32_t) TX_Buffer.tx_data_buffer[TX_Buffer.tx_buffer_pos];
		break;
	case uart2:
		Usart2->USART_DR=(uint32_t) TX_Buffer.tx_data_buffer[TX_Buffer.tx_buffer_pos];
		break;
	case uart3:
		Usart3->USART_DR=(uint32_t) TX_Buffer.tx_data_buffer[TX_Buffer.tx_buffer_pos];
		break;
	}
	TX_Buffer.tx_buffer_pos++;
	send_status = sending;
	return Ok;
}
void Usart_recieve(uint8_t *data,uint16_t size)
{
	RX_Buffer.rx_data_buffer = data;
	RX_Buffer.rx_buffer_pos = 0;
	RX_Buffer.rx_buffer_size = size;
	rx_buffer_state = Opened;
}

void Usart_setTxCallBack(CallBack ptr)
{
	tx_notify = ptr;
}

void Usart_setRxCallBack(CallBack ptr)
{
	rx_notify = ptr;
}

static void stub_H(void)
{
	return;
}
void USART1_IRQHandler(void)
{
	if(Usart1->USART_SR & UART_TC_BIT_MASK)
	{
		/*clear flag*/
		Usart1->USART_SR &= ~ (UART_TC_BIT_MASK);
		/*complete send*/
		if(TX_Buffer.tx_buffer_pos == TX_Buffer.tx_buffer_size)
		{
			send_status = idle;
			TX_Buffer.tx_data_buffer = NULL;
			TX_Buffer.tx_buffer_pos = 0;
			TX_Buffer.tx_buffer_size = 0;
			tx_notify();
			return;
		}
		Usart1->USART_DR=TX_Buffer.tx_data_buffer[TX_Buffer.tx_buffer_pos];
		TX_Buffer.tx_buffer_pos++;
	}
	if(Usart1->USART_SR & UART_RXNE_BIT_MASK)
	{
		/*clear flag*/
		Usart1->USART_SR &= ~ (UART_RXNE_BIT_MASK);
		if(rx_buffer_state == Opened)
		{
			RX_Buffer.rx_data_buffer[RX_Buffer.rx_buffer_pos] = (uint8_t)Usart1->USART_DR;
			RX_Buffer.rx_buffer_pos++;
			if(RX_Buffer.rx_buffer_pos == RX_Buffer.rx_buffer_size)
			{
				rx_buffer_state = Closed;
				RX_Buffer.rx_data_buffer = NULL;
				RX_Buffer.rx_buffer_pos = 0;
				RX_Buffer.rx_buffer_size = 0;
				rx_notify();
				return;
			}
		}

	}
}
void USART2_IRQHandler(void)
{
	if(Usart2->USART_SR & UART_TC_BIT_MASK)
	{
		/*clear flag*/
		Usart2->USART_SR &= ~ (UART_TC_BIT_MASK);
		/*complete send*/
		if(TX_Buffer.tx_buffer_pos == TX_Buffer.tx_buffer_size)
		{
			send_status = idle;
			TX_Buffer.tx_data_buffer = 0;
			TX_Buffer.tx_buffer_pos = 0;
			TX_Buffer.tx_buffer_size = 0;
			tx_notify();
			return;
		}
		Usart2->USART_DR=TX_Buffer.tx_data_buffer[TX_Buffer.tx_buffer_pos];
		TX_Buffer.tx_buffer_pos++;
	}
	if(Usart1->USART_SR & UART_RXNE_BIT_MASK)
	{
		/*clear flag*/
		Usart2->USART_SR &= ~ (UART_RXNE_BIT_MASK);
		if(rx_buffer_state == Opened)
		{
			RX_Buffer.rx_data_buffer[RX_Buffer.rx_buffer_pos] = (uint8_t)Usart2->USART_DR;
			RX_Buffer.rx_buffer_pos++;
			if(RX_Buffer.rx_buffer_pos == RX_Buffer.rx_buffer_size)
			{
				rx_buffer_state = Closed;
				RX_Buffer.rx_data_buffer = 0;
				RX_Buffer.rx_buffer_pos = 0;
				RX_Buffer.rx_buffer_size = 0;
				rx_notify();
				return;
			}
		}

	}
}
void USART3_IRQHandler(void)
{
	if(Usart3->USART_SR & UART_TC_BIT_MASK)
	{
		/*clear flag*/
		Usart3->USART_SR &= ~ (UART_TC_BIT_MASK);
		/*complete send*/
		if(TX_Buffer.tx_buffer_pos == TX_Buffer.tx_buffer_size)
		{
			send_status = idle;
			TX_Buffer.tx_data_buffer = 0;
			TX_Buffer.tx_buffer_pos = 0;
			TX_Buffer.tx_buffer_size = 0;
			tx_notify();
			return;
		}
		Usart3->USART_DR=TX_Buffer.tx_data_buffer[TX_Buffer.tx_buffer_pos];
		TX_Buffer.tx_buffer_pos++;
	}
	if(Usart3->USART_SR & UART_RXNE_BIT_MASK)
	{
		/*clear flag*/
		Usart3->USART_SR &= ~ (UART_RXNE_BIT_MASK);
		if(rx_buffer_state == Opened)
		{
			RX_Buffer.rx_data_buffer[RX_Buffer.rx_buffer_pos] = (uint8_t)Usart3->USART_DR;
			RX_Buffer.rx_buffer_pos++;
			if(RX_Buffer.rx_buffer_pos == RX_Buffer.rx_buffer_size)
			{
				rx_buffer_state = Closed;
				RX_Buffer.rx_data_buffer = 0;
				RX_Buffer.rx_buffer_pos = 0;
				RX_Buffer.rx_buffer_size = 0;
				rx_notify();
				return;
			}
		}

	}
}

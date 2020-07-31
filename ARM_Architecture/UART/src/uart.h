/*
 * uart.h
 *
 *  Created on: 4 May 2018
 *      Author: Nayir
 */

#ifndef UART_H_
#define UART_H_
#include "uart_cfg.h"

typedef enum{
	uart1,
	uart2,
	uart3
}uart_t;

typedef enum{
	fault_parameter,
	Ok,
	Busy
}uart_return_status;

typedef void (* CallBack) (void);

void Uart_init(void);
uart_return_status Usart_send(uart_t uart,const uint8_t * Data,uint8_t size);
void Usart_recieve(uint8_t *data,uint16_t size);
void Usart_setTxCallBack(CallBack ptr);
void Usart_setRxCallBack(CallBack ptr);

#endif /* UART_H_ */

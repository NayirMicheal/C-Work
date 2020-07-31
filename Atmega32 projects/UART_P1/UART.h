/*
 * UART.h
 *
 *  Created on: 23 Apr 2018
 *      Author: Nayir
 */

#ifndef UART_H_
#define UART_H_

void UART_voidInit(void);
void UART_voidSend(u8 Data);
u8 UART_u8ReceivePolling(void);
void UART_EnableRecieveInterrupt(void);
void UART_DisableRecieveInterrupt(void);
void Uart_Receive(u8 * data, u16 * len);
#endif /* UART_H_ */

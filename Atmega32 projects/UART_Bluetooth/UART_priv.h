/*
 * UART_priv.h
 *
 *  Created on: 24 Apr 2018
 *      Author: Nayir
 */

#ifndef UART_PRIV_H_
#define UART_PRIV_H_

/*data size for the uart*/
#define UART_DATA_SIZE_5        0
#define UART_DATA_SIZE_6        1
#define UART_DATA_SIZE_7        2
#define UART_DATA_SIZE_8        3
#define UART_DATA_SIZE_9        4

#define UART_ASYNCH        		0
#define UART_SYNCH         		1

#define UART_PARITY_DISABLE     0
#define UART_PARITY_EVEN        2
#define UART_PARITY_ODD         3

#define UART_ONE_STOP           0
#define UART_TWO_STOP           1
#endif /* UART_PRIV_H_ */

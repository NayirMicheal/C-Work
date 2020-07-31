/*
 * SPI_int.h
 *
 *  Created on: 1 May 2018
 *      Author: Nayir
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_
void SPI_init(void);
void SPI_interruptEnable(void);
void SPI_disableEnable(void);
void SPI_transmit(u8 data);
u8 SPI_receive(void);

#endif /* SPI_INT_H_ */

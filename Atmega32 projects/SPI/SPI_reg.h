/*
 * SPI_reg.h
 *
 *  Created on: 1 May 2018
 *      Author: Nayir
 */

#ifndef SPI_REG_H_
#define SPI_REG_H_
#define SPDR *((volatile u8 *) 0x2F)
#define SPSR *((volatile u8 *) 0x2E)
#define SPCR *((volatile u8 *) 0x2D)

#endif /* SPI_REG_H_ */

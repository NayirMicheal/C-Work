/*
 * GLCD.h
 *
 *  Created on: 2 May 2018
 *      Author: Nayir
 */

#ifndef GLCD_H_
#define GLCD_H_

#define DC_PIN		DIO_u8_PIN_24
#define CE_PIN		DIO_u8_PIN_25
#define RST_PIN		DIO_u8_PIN_26

void GLCD_updateGlcd(u8 * ptr);
void GLCD_init(void);
#endif /* GLCD_H_ */

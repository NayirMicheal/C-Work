/*
 * LED_MATRIX_int.h
 *
 *  Created on: 16 Jan 2018
 *      Author: Nayir
 */

#ifndef LED_MATRIX_INT_H_
#define LED_MATRIX_INT_H_

#define u8_LED_MATRIX_PORTA 0
#define u8_LED_MATRIX_PORTB 1
#define u8_LED_MATRIX_PORTC 2
#define u8_LED_MATRIX_PORTD 3

void LED_MATRIX_voidLedMatrixOutputImage(u8* u8ImageCopy);
void LED_MATRIX_voidCloseLedMatrix(void);

#endif /* LED_MATRIX_INT_H_ */

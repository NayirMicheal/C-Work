/*
 * SevenSeg_config.h
 *
 *  Created on: 6 Jan 2018
 *      Author: Nayir
 */

#ifndef SEVENSEG_CONFIG_H_
#define SEVENSEG_CONFIG_H_

/*Choose the mode for the Seven Segment between Common Anode or Common Cathode */
#define u8_SEVENSEG_TYPE u8_SEVENSEG_ANODE

/*Choose pin for segment A*/
#define u8_SEVENSEG_SEG_A    DIO_u8_PIN_8
/*Choose pin for segment B*/
#define u8_SEVENSEG_SEG_B    DIO_u8_PIN_9
/*Choose pin for segment C*/
#define u8_SEVENSEG_SEG_C    DIO_u8_PIN_10
/*Choose pin for segment D*/
#define u8_SEVENSEG_SEG_D    DIO_u8_PIN_11
/*Choose pin for segment E*/
#define u8_SEVENSEG_SEG_E    DIO_u8_PIN_12
/*Choose pin for segment F*/
#define u8_SEVENSEG_SEG_F    DIO_u8_PIN_13
/*Choose pin for segment G*/
#define u8_SEVENSEG_SEG_G    DIO_u8_PIN_14
/*Choose pin for segment Dot*/
#define u8_SEVENSEG_SEG_DOT  DIO_u8_PIN_15
/*Choose pin for the Common */
#define u8_SEVENSEG_SEG_COMMON DIO_u8_PIN_24

#endif /* SEVENSEG_CONFIG_H_ */

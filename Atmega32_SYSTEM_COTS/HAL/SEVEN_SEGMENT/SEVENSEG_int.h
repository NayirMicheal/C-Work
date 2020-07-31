/*
 * SevenSeg_int.h
 *
 *  Created on: 6 Jan 2018
 *      Author: Nayir
 */

#ifndef SEVENSEG_INT_H_
#define SEVENSEG_INT_H_

/*Choose between Common Anode or Common Cathode for your Seven Segment*/
#define u8_SEVENSEG_ANODE 0
#define u8_SEVENSEG_CATHODE 1

/*Display on Seven segment take a u8 variable a display it on the seven segment */
void SevenSeg_voidDisplayOnSeg(u8 u8PaternCpy);

#endif /* SEVENSEG_INT_H_ */

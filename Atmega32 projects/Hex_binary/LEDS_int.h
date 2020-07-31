#ifndef _LED_INT_H
#define _LED_INT_H

#define LEDS_u8_LED0 0
#define LEDS_u8_LED1 1
#define LEDS_u8_LED2 2
#define LEDS_u8_LED3 3
#define LEDS_u8_LED4 4
#define LEDS_u8_LED5 5
#define LEDS_u8_LED6 6
#define LEDS_u8_LED7 7
#define LEDS_u8_NUMBEROFLEDS 6

void LEDS_voidSetLedOn(u8 u8LedPinCPY);
void LEDS_voidSetLedOff(u8 u8LedPinCPY);
#endif

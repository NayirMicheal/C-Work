#ifndef LEDS_CONFIG_H
#define LEDS_CONFIG_H

#ifdef LEDS_INT_H_
/*Please Add your Leds index*/
/******************************************/
/* Public Configuration*/
typedef enum{
	LEDS_u8_LED1,
	LEDS_u8_LED2,
	/*
	 * Please Insert your Leds here
	 * */
	LEDS_u8_LEDS_NB
}LEDS_LedIndex;
/******************************************/
/*Please write Pin Index for each Led
 *  with the same order define in LEDS_LedIndex*/
#endif
#ifdef LEDS_PRIV_H_
/*Please write Dio Pins dedicated to your Leds*/
u8 LEDS_u8LedToDioLink[LEDS_u8_LEDS_NB]={
		DIO_u8_PIN_25,
		DIO_u8_PIN_25
};

/*please write your open state for your Leds*/
u8 LEDS_u8LedMode[LEDS_u8_LEDS_NB]={
		LEDS_u8_MODE_NORMAL,
		LEDS_u8_MODE_REVERSE
};
#endif /* LEDS_CONFIG_H_ */

#endif

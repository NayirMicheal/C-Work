/*
 * SWD_config.h
 *
 *  Created on: 24 Jan 2018
 *      Author: Nayir
 */

#ifndef SWD_CONFIG_H_
#define SWD_CONFIG_H_

#ifdef SWD_INT_H_
/*Please Add your switches index*/
/******************************************/
/* Public Configuration*/
typedef enum{
	SWD_u8_SW1,
	SWD_u8_SW2,
	SWD_u8_SW3,
	SWD_u8_SW4,
	SWD_u8_SW5,
	SWD_u8_SW6,
	SWD_u8_SW7,
	SWD_u8_SW8,
	/*
	 * Please Insert your switches here
	 * */
	SWD_u8_SW_NB
}SWD_SwIndex;
/******************************************/
/*Please write Pin Index for each switch
 *  with the same order define in SWD_SwIndex*/
#endif
#ifdef SWD_PRIV_H_
/*Please write Dio Pins dedicated to your switches*/
u8 SWD_u8SwToDioLink[SWD_u8_SW_NB]={
		DIO_u8_PIN_0,
		DIO_u8_PIN_1,
		DIO_u8_PIN_2,
		DIO_u8_PIN_3,
		DIO_u8_PIN_4,
		DIO_u8_PIN_5,
		DIO_u8_PIN_6,
		DIO_u8_PIN_24,
};

/*please write your open state for your switches*/
u8 SWD_u8SwOpenState[SWD_u8_SW_NB]={
		DIO_u8_HIGH,
		DIO_u8_HIGH,
		DIO_u8_HIGH,
		DIO_u8_HIGH,
		DIO_u8_HIGH,
		DIO_u8_HIGH,
		DIO_u8_HIGH,
		DIO_u8_HIGH,
};
#endif /* SWD_CONFIG_H_ */
#endif

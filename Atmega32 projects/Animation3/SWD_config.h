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
		DIO_u8_PIN_8, //left
		DIO_u8_PIN_9, //right
		DIO_u8_PIN_10, //up
		DIO_u8_PIN_11, //down
		DIO_u8_PIN_12, //jump
};

/*please write your open state for your switches*/
u8 SWD_u8SwOpenState[SWD_u8_SW_NB]={
		DIO_u8_HIGH,
		DIO_u8_HIGH,
		DIO_u8_HIGH,
		DIO_u8_HIGH,
		DIO_u8_HIGH,
};
#endif /* SWD_CONFIG_H_ */
#endif

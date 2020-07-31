

#ifndef SWD_CONFIG_H_
#define SWD_CONFIG_H_

#ifdef SWD_INT_H_
/*Please Add your switches index*/
/******************************************/
/* Public Configuration*/
typedef enum{
	SWD_u8_SW1,
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
		DIO_u8_PIN_24,
};

/*please write your open state for your switches*/
u8 SWD_u8SwOpenState[SWD_u8_SW_NB]={
		DIO_u8_HIGH,
};
#endif /* SWD_CONFIG_H_ */
#endif

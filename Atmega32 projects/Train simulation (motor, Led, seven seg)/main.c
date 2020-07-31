/*
 * main.c
 *
 *  Created on: 15 Feb 2018
 *      Author: Nayir
 */
/*
 * This project describes security system for train.
 * includes
 * 1- LCD on PORT B for Data and
 * 2- LED Matrix PORT A for Cols and PORT B for Data
 * 3- 2 Seven Segment (Data on Port D and Common on pin 29 and pin 30)
 * 4- Buzzer on Port D pin 24
 * 5- Motor on Port D pin 27 , 28
 * 6- Switch (Externel intrrupt) Port D pin 26
 * 7- 2 Leds (Normal and Reverse) on Port D pin 25
 * */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DELAY.h"
#include "DIO_int.h"
#include "EXTI_int.h"
#include "GIE_int.h"
#include "LCD_int.h"
#include "LED_MATRIX_int.h"
#include "LEDS_int.h"
#include "SEVENSEG_int.h"

#define MOTOR_RIGHT DIO_u8_PIN_27
#define MOTOR_LEFT DIO_u8_PIN_28
#define SEVEN_SEG_ONE_EN DIO_u8_PIN_29
#define SEVEN_SEG_TWO_EN DIO_u8_PIN_30
#define SWITCH DIO_u8_PIN_26
#define LEDS DIO_u8_PIN_25
#define BUZZER DIO_u8_PIN_24

/*counter for train to pass*/
volatile static u8 counter=0;

/*this function set the counter to 99 when
 * the switch is pressed on interrupt*/
void int0_function(void)
{
	counter=99;
}
void main (void)
{
	u8 Motoropen=0;
	u8 words[][9]={"Welcome","Pepsi","Cocacola","Mac"};
	u8 whichword=0;
	u8 attention[8]={112, 76, 66, 93, 93, 66, 76, 112};
	/*Numbers for Seven Segment*/
	u8 segtable[10]={0b11000000,0b11111001,0b10100100,0b10110000,0b10011001,0b10010010,0b10000010,0b11111000,0b10000000,0b10010000};
	/*initialie the DIO pins*/
	DIO_voidInitialize();
	/*initialize the LCD pins*/
	LCD_voidInitialize();
	/*initialize the externel interrupt*/
	EXTI_voidInit();
	/*make pull up resistor on pin 26 (Ext interrupt)*/
	DIO_voidSetPinValue(SWITCH,DIO_u8_HIGH);
	/*set Callback function for the externel int0*/
	EXTI_voidSetCallback_EXT0(int0_function);
	/*Enable the externel int 0*/
	EXTI_voidEnable_EXT0();
	/*enable the global interrupt*/
	GIE_EnableGlobalInterrupt();
	while(1)
	{
		/*check if the train is passing*/
		if(counter>1)
		{
			/*switch on the red led*/
			LEDS_voidSetLedOn(LEDS_u8_LED1);
			/*to display the counter on seven segment (POV)*/
			for(u8 i=0;i<30;i++){

				DIO_voidSetPinValue(SEVEN_SEG_ONE_EN,DIO_u8_LOW);
				/*disable segment two for second digit*/
				DIO_voidSetPinValue(SEVEN_SEG_TWO_EN,DIO_u8_LOW);
				/*out the image on led matrix*/
				LED_MATRIX_voidLedMatrixOutputImage(attention);
				/*close the led matrix before out on seven seg*/
				LED_MATRIX_voidCloseLedMatrix();
				/*Enable Segment one for first digit*/
				DIO_voidSetPinValue(SEVEN_SEG_ONE_EN,DIO_u8_HIGH);
				/*disable segment two for second digit*/
				DIO_voidSetPinValue(SEVEN_SEG_TWO_EN,DIO_u8_LOW);
				/*out the first digit data on the seven segment*/

				SevenSeg_voidDisplayOnSeg(~segtable[(counter%10)]);
				/*move the motor and enable the buzzer for only 2 counts from the beginning*/
				if(counter>98)
				{
					/*Enable the moving of motor to the right*/
					DIO_voidSetPinValue(MOTOR_RIGHT,DIO_u8_HIGH);
					/*Disable the moving of motor to the left*/
					DIO_voidSetPinValue(MOTOR_LEFT,DIO_u8_LOW);
					/*Buzzer for*/
					for(u8 i=0;i<5;i++)
					{
						/*Enable the buzzer*/
						DIO_voidSetPinValue(BUZZER,DIO_u8_HIGH);
						/*delay for the buzzer*/
						Delay_us(80);
						/*disable the buzzer*/
						DIO_voidSetPinValue(BUZZER,DIO_u8_LOW);
						/*delay for the buzzer*/
						Delay_us(80);
					}
					Motoropen=1;
				}
				/*if the counter is less than 97*/
				else
				{
					/*switch off the motor*/
					DIO_voidSetPinValue(MOTOR_RIGHT,DIO_u8_LOW);
					DIO_voidSetPinValue(MOTOR_LEFT,DIO_u8_LOW);
					/*switch off the buzzer*/
					DIO_voidSetPinValue(BUZZER,DIO_u8_LOW);
					/*delay for seven segment*/
					Delay_us(800);
				}
				DIO_voidSetPinValue(SEVEN_SEG_ONE_EN,DIO_u8_LOW);
				/*disable segment two for second digit*/
				DIO_voidSetPinValue(SEVEN_SEG_TWO_EN,DIO_u8_LOW);
				/*out the image on led matrix*/
				LED_MATRIX_voidLedMatrixOutputImage(attention);
				/*close the led matrix before out on seven seg*/
				LED_MATRIX_voidCloseLedMatrix();
				/*disable the first seven segment*/
				DIO_voidSetPinValue(SEVEN_SEG_ONE_EN,DIO_u8_LOW);
				/*enable the second seven segment*/
				DIO_voidSetPinValue(SEVEN_SEG_TWO_EN,DIO_u8_HIGH);
				/*out the second digit on the second seven segment*/

				SevenSeg_voidDisplayOnSeg(~segtable[(counter/10)]);
				/*ensure that the buzzer is disabled*/
				DIO_voidSetPinValue(BUZZER,DIO_u8_LOW);
				/*delay for the seven segment*/
				Delay_us(800);
			}
			/*decrease the counter*/
			counter--;
		}
		/*if the counter is less than 1*/
		else
		{
			if(Motoropen==1){
				/*Enable the moving of motor to the right*/
				DIO_voidSetPinValue(MOTOR_RIGHT,DIO_u8_LOW);
				/*Disable the moving of motor to the left*/
				DIO_voidSetPinValue(MOTOR_LEFT,DIO_u8_HIGH);
				Motoropen=0;
				LCD_voidClearDisplay();
			}
			else
			{
				/*disable the motor*/
				DIO_voidSetPinValue(MOTOR_RIGHT,DIO_u8_LOW);
				DIO_voidSetPinValue(MOTOR_LEFT,DIO_u8_LOW);
			}
			/*enable the green led*/
			LEDS_voidSetLedOn(LEDS_u8_LED2);

			/*disable the seven segment*/
			DIO_voidSetPinValue(SEVEN_SEG_ONE_EN,DIO_u8_LOW);
			DIO_voidSetPinValue(SEVEN_SEG_TWO_EN,DIO_u8_LOW);
			/*disable the buzzer*/
			DIO_voidSetPinValue(BUZZER,DIO_u8_LOW);
			/*out the image on led matrix*/
			for(u8 i=0;i<50;i++)
				LED_MATRIX_voidLedMatrixOutputImage(attention);
		}
		LED_MATRIX_voidCloseLedMatrix();
		DIO_voidSetPinValue(SEVEN_SEG_ONE_EN,DIO_u8_LOW);
		DIO_voidSetPinValue(SEVEN_SEG_TWO_EN,DIO_u8_LOW);
		LCD_voidClearDisplay();
		LCD_voidWriteStringCurrentPosition(words[whichword]);
		whichword++;
		if(whichword==4)
		{
			whichword=0;
		}


	}
}

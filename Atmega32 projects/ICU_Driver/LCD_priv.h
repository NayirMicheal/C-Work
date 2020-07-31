/*********************************************/
/* Author : Nayir Michel                     */
/*Date : 15 JAN 2018                         */
/*Release : V01                              */
/*********************************************/
#ifndef _LCD_PRIV_H
#define _LCD_PRIV_H

u8 u8LCDDataPins [8]={LCD_u8_DATA_PIN_0,LCD_u8_DATA_PIN_1,LCD_u8_DATA_PIN_2,LCD_u8_DATA_PIN_3,LCD_u8_DATA_PIN_4,LCD_u8_DATA_PIN_5,LCD_u8_DATA_PIN_6,LCD_u8_DATA_PIN_7};
/*********************************************/
/*Description: This function is used to  */
/* Execute data on LCD lines             */
/*********************************************/
static void voidLcdExecute(u8 u8ValueCpy);

/*Description: This function is used to  */
/* Execute LCD commands            */
/*********************************************/
static void voidWriteCmd(u8 u8CommandCpy);

/*Description: This function is used to  */
/* write data to LCD             */
/*********************************************/

static void voidWriteData(u8 u8DataCpy);
#endif

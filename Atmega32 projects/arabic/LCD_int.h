/*********************************************/
/* Author : Nayir Michel                     */
/*Date : 15 JAN 2018                         */
/*Release : V01                              */
/*********************************************/

#ifndef _LCD_INT_H
#define _LCD_INT_H
/**********************************************/
/*Description: This function is used to  */
/* Initialise LCD parameters             */
/*********************************************/
extern void LCD_voidInitialize(void);


/*Description: This function is used to  */
/* write data to LCD             */
/*********************************************/
extern void LCD_voidWriteData(u8 u8DataCpy);


/*Description: This function is used to  */
/* Execute LCD commands            */
/*********************************************/
extern void LCD_voidWriteCmd(u8 u8CommandCpy);


extern void LCD_voidWriteString(u8 * u8PtrCpy,u8 u8XposCpy,u8 u8YposCpy);

extern void LCD_voidClearDisplay(void);
#endif

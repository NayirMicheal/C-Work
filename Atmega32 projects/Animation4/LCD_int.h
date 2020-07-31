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

extern void LCD_voidWriteStringXY(u8 * u8PtrCpy,u8 u8XposCpy,u8 u8YposCpy);

extern void LCD_voidWriteStringCurrentPosition(u8 * u8PtrCpy);

extern void LCD_voidClearDisplay(void);

extern void voidDrawCustomChar(u8 * u8PtrCpy,u8 u8IndexCpy);

extern void voidWriteCustomChar(u8 u8IndexCpy ,u8 u8XPositionCpy,u8 u8YPositionCpy);
#define LCD_u8_FONT_FIVE_EIGHT 0
#define LCD_u8_FONT_FIVE_ELEVEN 1

#define LCD_u8_DISPLAY_ON 1
#define LCD_u8_DISPLAY_OFF 0

#define LCD_u8_BLINK_ON 1
#define LCD_u8_BLINK_OFF 0

#define LCD_u8_CURSOR_ON 1
#define LCD_u8_CURSOR_OFF 0

#define LCD_u8_ONE_LINE 0
#define LCD_u8_TWO_LINE 1
#endif

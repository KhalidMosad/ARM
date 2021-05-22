/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 24/1/2021                                                                                      */
/*******************************************************************************************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include"STD_TYPES.h"
void LCD_VidInit(void);
void LCD_VidSendData(u8 copy_u8data);
void LCD_VidSendCommand(u32 copy_u8command);
void LCD_VidSendString(u8 *copy_u8string);
 void LCD_VidSendNumber( u16 copy_u16number);
void LCD_SetPosition(u8 raw, u8 column);
void LCD_VidClear(void);
void LCD_VidShiftRight(void);
void LCD_VidShiftLeft(void);
void LCD_voidReturnHome(void);
#define	GPIOA	0
#define	GPIOB	1

#define Lcopy_u8Mode	0b0010
#define LDcopy_u8Mode	0x22222222

#endif
/* LCD_INTERFACE_H_ */

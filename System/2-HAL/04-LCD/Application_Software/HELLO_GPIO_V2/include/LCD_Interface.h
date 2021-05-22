/*
 * LCD_Interface.h

 *
 *  Created on: Nov 30, 2020
 *      Author: Khaled
 */

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_
#include"STD_TYPES.h"
void LCD_VidInit(void);
void LCD_VidSendData(u32 copy_u8data);
void LCD_VidSendCommand(u32 copy_u8command);
void LCD_VidSendString(u8 *copy_u8string);
void LCD_VidSendNumber( u8 *copy_u8number);
void LCD_SetPosition(u8 raw, u8 column);
void LCD_VidClear(void);

#define	GPIOA	0
#define	GPIOB	1

#endif
/* LCD_INTERFACE_H_ */

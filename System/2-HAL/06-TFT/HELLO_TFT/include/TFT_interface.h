/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 29/1/2021                                                                                      */
/*******************************************************************************************************/
#ifndef 	TFT_INTERFACE_H
#define		TFT_INTERFACE_H

void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16* Copy_Image);
void HTFT_voidFillColor( u16 *Copy_u16Color);
void HTFT_voidDrawRectangular(u8 x1, u8 x2, u8 y1, u8 y2,u16 *Copy_u16Color );





#endif

/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 30/1/2021                                                                                      */
/*******************************************************************************************************/
#ifndef 	TFT_INTERFACE_H
#define		TFT_INTERFACE_H

void HESP_voidInit(void);
u8 HESP_u8ValidateCommand(void);
void HESP_voidWifiUserAndPass(u8 *username, u8 *password);
void HESP_voidServerData(u8 *IP, u8 *PORT);
void HESP_voidCharNumber(u8 *Number);
void HESP_voidGetFile(u8 *ID);

//

#endif

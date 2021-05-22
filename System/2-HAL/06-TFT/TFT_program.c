/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 29/1/2021                                                                                      */
/*******************************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPIO_interface.h"
#include"SPI_interface.h"
#include"STK_interface.h"
#include"TFT_interface.h"
#include"TFT_config.h"
#include"TFT_private.h"
void HTFT_voidInit(void)
{
	//Reset Pulse
	GPIO_voidSetPinValue(TFT_RESET_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RESET_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(3);
	GPIO_voidSetPinValue(TFT_RESET_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RESET_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(100);
	GPIO_voidSetPinValue(TFT_RESET_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(120000);
	//Sleep Out Command
	voidWriteCommand(0x11);
	MSTK_voidSetBusyWait(150000);
	//RGB565
	voidWriteCommand(0x3A);
	// Color Mode RGB565
	voidWriteData(0x05);
	//Display On Command 
	voidWriteCommand(0x29);
	
}
void HTFT_voidDisplayImage(const u16* Copy_Image)
{
	u16 counter;
	// Set X Address
	voidWriteCommand(0x2A);
	// 2 Byts Start point
	voidWriteData(0);
	voidWriteData(0);
	// 2 Byts End point
	voidWriteData(0);
	voidWriteData(127);
	
	// Set Y Address
	voidWriteCommand(0x2B);
	// 2 Byts Start point
	voidWriteData(0);
	voidWriteData(0);
	// 2 Byts End point
	voidWriteData(0);
	voidWriteData(159);
	
	/*   RAM Write Command*/
	voidWriteCommand(0x2C);
	for(counter=0; counter<20480;counter++)
	{
	voidWriteData(Copy_Image[counter]>>8);
	voidWriteData(Copy_Image[counter]&0x00ff);
		
	}
	
	
}

static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	//Clear TFT_A0_PIN
	GPIO_voidSetPinValue(TFT_A0_PIN,GPIO_LOW);
	// Send Command
	MSPI1_u8SendReceiveSynch(Copy_u8Command,&Local_u8Temp);
	
}
static void voidWriteData(u8 Data)
{
	u8 Local_u8Temp;
	//Set TFT_A0_PIN
	GPIO_voidSetPinValue(TFT_A0_PIN,GPIO_HIGH);
	// Send Data
	MSPI1_u8SendReceiveSynch(Data,&Local_u8Temp);
	
}


void HTFT_voidFillColor( u16 *Copy_u16Color)
{
	u16 counter;
	// Set X Address
	voidWriteCommand(0x2A);
	// 2 Byts Start point
	voidWriteData(0);
	voidWriteData(0);
	// 2 Byts End point
	voidWriteData(0);
	voidWriteData(127);
	
	// Set Y Address
	voidWriteCommand(0x2B);
	// 2 Byts Start point
	voidWriteData(0);
	voidWriteData(0);
	// 2 Byts End point
	voidWriteData(0);
	voidWriteData(159);
	
	/*   RAM Write Command*/
	voidWriteCommand(0x2C);
	for(counter=0; counter<20480;counter++)
	{
	voidWriteData(Copy_u16Color[counter]>>8);
	voidWriteData(Copy_u16Color[counter]&0x00ff);
		
	}
	
	
}
void HTFT_voidDrawRectangular(u8 x1, u8 x2, u8 y1, u8 y2, u16 *Copy_u16Color )
{
	u16 size= (x2-x1)*(y2-y1);
	u16 counter;
	
	// Set X Address
	voidWriteCommand(0x2A);
	// 2 Byts Start point
	voidWriteData(0);
	voidWriteData(x1);
	// 2 Byts End point
	voidWriteData(0);
	voidWriteData(x2);
	
	// Set Y Address
	voidWriteCommand(0x2B);
	// 2 Byts Start point
	voidWriteData(0);
	voidWriteData(y1);
	// 2 Byts End point
	voidWriteData(0);
	voidWriteData(y2);
	
	/*   RAM Write Command*/
	voidWriteCommand(0x2C);
	for(counter=0; counter<size;counter++)
	{
	voidWriteData(Copy_u16Color[counter]>>8);
	voidWriteData(Copy_u16Color[counter] & 0x00ff);
		
	}
	
	
	
	
}

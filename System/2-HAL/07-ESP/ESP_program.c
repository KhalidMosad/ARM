/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 30/1/2021                                                                                      */
/*******************************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPIO_interface.h"
#include"SPI_interface.h"
#include"STK_interface.h"
#include"ESP_interface.h"
#include"ESP_config.h"
#include"ESP_private.h"
void HESP_voidInit(void)
{
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
	/*Stop Echo */
	MUSART1_voidTransmit("ATE0\r\n");
	Local_u8Result= HESP_u8ValidateCommand();
	}
	
	u8 Local_u8Result=0;
	while(Local_u8Result==0)
	{
	/* Set Station Mode          */
	MUSART1_voidTransmit("AT+CWMODE=1\r\n");
	Local_u8Result= HESP_u8ValidateCommand();
	}

	
}

u8 HESP_u8ValidateCommand(void)
{
	u8 Local_u8Response[100]={0};
	u8 i=0;
	u8 Dummy=0;
	u8 Result =0;
	while(Local_u8Response[i-1] !=255)
	{
		Dummy=MUSART1_u8Receive();
		Local_u8Response[i]=Dummy;
		i++;
	}
	if (Local_u8Response[0] == 'O' && Local_u8Response[1]== 'K')
	{
		Result== 1;
	}
	return Result;
}




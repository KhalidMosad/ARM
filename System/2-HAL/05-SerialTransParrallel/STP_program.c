/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 23/1/2021                                                                                      */
/*******************************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPIO_interface.h"
#include"STK_interface.h"
#include"STP_interface.h"
#include"STP_config.h"
#include"STP_private.h"

void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Locak_u8Counter;
	u8 Locak_u8Bit;
	for ( Locak_u8Counter=7;Locak_u8Counter>=0;Locak_u8Counter--  )
	{
		/* Send Bit By Bit Starting From Most Significant Bit*/
		Locak_u8Bit=GET_BIT(Copy_u8DataToSend,Locak_u8Counter);
		
		MGPIO_voidSetPinValue(STP_SERIAL_DATA, Locak_u8Bit);
		
		/*Send Pulse To Shift Clock*/
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK, GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(STP_SHIFT_CLOCK, GPIO_LOW);
		MSTK_voidSetBusyWait(1);
		
	}
		/*Send Pulse To Store Clock*/
		MGPIO_voidSetPinValue(STP_STORE_CLOCK, GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(STP_STORE_CLOCK, GPIO_LOW);
		MSTK_voidSetBusyWait(1);
	
	
}
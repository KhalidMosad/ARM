/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 28/1/2021                                                                                      */
/*******************************************************************************************************/

#include "STD_Types.h"
#include "BIT_Math.h"
#include "USART_private.h"
#include "USART_interface.h"
#include "USART_config.h"


void MUSART1_voidInit(void)
{
	
	
	/* Clear Status Register */
	MUART->SR=0;
	
	//9600 BaudRate 
	MUART->BRR=0x341;
	
	/*
	115200    BRR =1C200
	
	*/
	#if Ch_Size==EIGHT_BITS
	//frame size   // 8bit
	CLR_BIT(MUART->CR1,M);

	#elif Ch_Size==NINE_BITS
	SET_BIT(MUART->CR1,M);

	#else 
		#error("Wrong choice")
		
	#endif


	#if Mode==ASYNCHRONOUS_OP
	CLR_BIT(MUART->CR2,11);
	#elif Mode==SYNCHRONOUS_OP
	SET_BIT(MUART->CR2,11);
	#else 
		#error("Wrong choice")
	#endif
	
	// Clock Phase 
	SET_BIT(MUART->CR2,9);
	
	
	/*
	// Disabled Parity Mode
	#if Parity_Mode==DISABLED
	CLR_BIT(UCSRC_HELP,UPM1);
	CLR_BIT(UCSRC_HELP,UPM0);
	#elif Parity_Mode==ENABLED_EVEN
	SET_BIT(UCSRC_HELP,UPM1);
	CLR_BIT(UCSRC_HELP,UPM0);
	#elif Parity_Mode==ENABLED_ODD
	SET_BIT(UCSRC_HELP,UPM1);
	SET_BIT(UCSRC_HELP,UPM0);
	
	#else
		#error("Wrong choice")
	#endif
	*/
	
	#if STOP_SELECT==ONE_BIT
	CLR_BIT(MUART->CR2,13);
	CLR_BIT(MUART->CR2,12);
	#elif STOP_SELECT==TWO_BIT
	SET_BIT(MUART->CR2,13);
	CLR_BIT(MUART->CR2,12);
	#endif
	
	
	
	//Clock Polarity
	#if CL_POL==TR_RISING
	CLR_BIT(MUART->CR2,10);
	#elif CL_POL==TR_FALING
	SET_BIT(MUART->CR2,10);
	#endif
	
					
	// USART Enable 
	SET_BIT(MUART->CR1,UE);
	//Transmitter Enable
	SET_BIT(MUART->CR1,TE);

	//Receiver Enable
	SET_BIT(MUART->CR1,RE);

}



u8 MUSART1_u8Receive(void)
{
	u8 x;
	
	while(0==GET_BIT(MUART->SR,5));
	x=((MUART->DR)&0xFF);
	return x;
}

void MUSART1_voidtransmit(char arr[])
{
	u8 i=0;
	while(arr[i]!= '\0')
	{
	MUART->DR=arr[i];
	while(0==GET_BIT(MUART->SR,6));
	i++;
	}

}









/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 27/1/2021                                                                                      */
/*******************************************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"SPI_interface.h"
#include"SPI_config.h"
#include"SPI_private.h"
#include "GPIO_interface.h"

void MSPI1_VoidInit(void)
{


	u32 Local_u32=0;

	MSPI1->CR1=0x0000;
	#if MODE==MASTER	
		SET_BIT(Local_u32,MSTR);
	#elif MODE==SLAVE	
		CLR_BIT(Local_u32,MSTR);
	#endif	
	
	#if CLOCK_RATE== F_2	
		CLR_BIT(Local_u32,SPR2);
		CLR_BIT(Local_u32,SPR0);
		CLR_BIT(Local_u32,SPR1);
	
	#elif CLOCK_RATE== F_4	
		CLR_BIT(Local_u32,SPR2);
		SET_BIT(Local_u32,SPR0);
		CLR_BIT(Local_u32,SPR1);
	#elif	CLOCK_RATE == F_8	
		CLR_BIT(Local_u32,SPR2);
		CLR_BIT(Local_u32,SPR0);
		SET_BIT(Local_u32,SPR1);
	#elif	CLOCK_RATE == F_16
		SET_BIT(Local_u32,SPR0);
		SET_BIT(Local_u32,SPR1);
		CLR_BIT(Local_u32,SPR2);
	#elif CLOCK_RATE== F_32
		SET_BIT(Local_u32,SPR2);
		CLR_BIT(Local_u32,SPR1);
		CLR_BIT(Local_u32,SPR0);
	#elif CLOCK_RATE== F_64
		SET_BIT(Local_u32,SPR2);
		CLR_BIT(Local_u32,SPR1);
		SET_BIT(Local_u32,SPR0);
	#elif CLOCK_RATE== F_128
		SET_BIT(Local_u32,SPR2);
		SET_BIT(Local_u32,SPR1);
		CLR_BIT(Local_u32,SPR0);
	#elif CLOCK_RATE== F_256
		SET_BIT(Local_u32,SPR2);
		SET_BIT(Local_u32,SPR0);
		SET_BIT(Local_u32,SPR1);
	#endif
	//SPI operations enable
	SET_BIT(Local_u32,SPE);
	
	#if CLOCK_POLARITY==LEADING_RISING
		CLR_BIT(Local_u32,CPOL);
	#elif CLOCK_POLARITY==LEADING_FALLING
		SET_BIT(Local_u32,CPOL);
	#endif

	#if CLOCK_PHASE==LEADING_SAMPLE
		CLR_BIT(Local_u32,CPHA);
	#elif CLOCK_PHASE==LEADING_SETUP
		SET_BIT(Local_u32,CPHA);
	#endif
	
	#if DATA== LSB_FIRST
		SET_BIT(Local_u32,LSB);
	#elif DATA==MSB_FIRST
		CLR_BIT(Local_u32,LSB);
	#endif
	
	
	#if DATA_FRAME== EIGHT_BIT
		CLR_BIT(Local_u32,DDF);
	#elif DATA_FRAME== SIXTEEN_BIT
		SET_BIT(Local_u32,DDF);
	#endif
	
	// Software Slave Management
	SET_BIT(Local_u32,SSM);
	// If Master SSI must be enabled 
	// Internal slave select
	SET_BIT(Local_u32,SSI);
	
	// if slave SSI = 0 
	//CLR_BIT(MSPI1->CR1,SSI);	
	MSPI1->CR1=Local_u32;
}


/* This Function Support Only One Slave */
MSPI1_u8SendReceiveSynch(u8 Copy_U8DataToTransmit,u8 *Copy_U8DataToReceive)
{
	/*Clear For SS Pin*/ 
	GPIO_voidSetPinValue(MSPI1_SLAVE_PIN, GPIO_LOW);
	MSPI1->DR =Copy_U8DataToTransmit;
	
	/* WAIT FOR BUSY FLAG TO FINISH */
	while(GET_BIT(MSPI1->SR,BSY)==1);
	/* Return To The receIved Data */
	*Copy_U8DataToReceive= MSPI1->DR;
	
	/* Set Slave Select Pin */
	GPIO_voidSetPinValue(MSPI1_SLAVE_PIN, GPIO_HIGH);
	
}


/*

void MSPI1_u8SendReceiveAsynch(u8 Copy_U8DataToTransmit,void (*CallBack)(u8))
{
	
	SET_BIT(MSPI1->CR2,5);	
			
	//Clear For SS Pin 
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN, GPIO_LOW);
	MSPI1->DR =Copy_U8DataToTransmit;
	
	// WAIT FOR BUSY FLAG TO FINISH 
	while(GET_BIT(MSPI1->SR,7)==1);
	// Return To The receIved Data 
	
	CallBack(MSPI1->DR);
	
	// Set Slave Select Pin 
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN, GPIO_HIGH);
	
}

*/



/*
void SPI1_IRQHandler(void)
{
	CallBack(MSPI1->DR);
	
}	
		
	
	*/










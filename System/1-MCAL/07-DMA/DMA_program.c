/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 26/1/2021                                                                                      */
/*******************************************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"DMA_interface.h"
#include"DMA_config.h"
#include"DMA_private.h"


void MDMA_voidChannelInit(void)
{
	/*        
	1-Memory To Memory
	2-Priority Very High
	3- Source and Destination Size =32 bit
	4- MINC, PINC
	5-No Circular
	6-Direction 
	7-Transfer Interrupt Enable

	*/
	
	/*
	#if CHANNEL_ID == 1
	DMA->Channel[0].CCR=
	DMA->Channel[0].CNDTR= 
	DMA->Channel[0].CPAR =
	DMA->Channel[0].CMAR =	
	DMA->Channel[0].Reserved=
	  */
DMA->Channel[0].CCR=0x00007AC2;	  
	
}
void MDMA_voidChannelStart(u32 *Copy_u32SourceAddress,u32 *Copy_u32DestinationAddress, u16 Copy_u16LocalLength)
{
	/* Make sure Thatt Channels is Disable              */
	CLR_BIT(DMA->Channel[0].CCR,0);
	/* Write The Address              */
	DMA->Channel[0].CPAR=Copy_u32SourceAddress;
	DMA->Channel[0].CMAR=Copy_u32DestinationAddress;
	/*Block Length  */
	DMA->Channel[0].CNDTR=Copy_u16LocalLength;
	/* Make sure Thatt Channels is Enabled              */
	SET_BIT(DMA->Channel[0].CCR,0);
	
	
	
}


	
		
	
	










/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 27/1/2021                                                                                      */
/*******************************************************************************************************/

#ifndef 	SPI_PRIVATE_H
#define		SPI_PRIVATE_H
#define 	CPHA	0
#define 	CPOL	1	
#define 	MSTR	2					
#define 	SPR0	3
#define 	SPR1	4
#define 	SPR2	5			
#define 	SPE		6
#define 	LSB		7

#define 	SSI		8			
#define 	SSM		9			
#define 	RXONLY	10
			
#define 	DDF			11	
#define 	CRCNEXT		12			
#define 	CRCEN		13			
#define 	BIDIOE		14			
#define 	BIDIMODE	15	



#define 	BSY			7







typedef struct
{
	volatile u32 CR1; 
	volatile u32 CR2;
	volatile u32 SR ;
	volatile u32 DR ;	
	volatile u32 CRCPR ;
	volatile u32 RXCRCR; 
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR ;
	volatile u32 I2SPR ;	

	
}SPI_t;

#define MSPI1	((SPI_t*)0x40013000)




#endif
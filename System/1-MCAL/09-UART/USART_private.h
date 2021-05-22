/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 28/1/2021                                                                                      */
/*******************************************************************************************************/

#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_


#define	RE	2
#define	TE	3
#define M	12
#define UE	13

typedef struct
{
	volatile u32 SR; 
	volatile u32 DR;
	volatile u32 BRR ;
	volatile u32 CR1 ;	
	volatile u32 CR2 ;
	volatile u32 CR3; 
	volatile u32 GTPR;


	
}UART_t;

#define MUART	((UART_t*)0x40013800)




#endif 
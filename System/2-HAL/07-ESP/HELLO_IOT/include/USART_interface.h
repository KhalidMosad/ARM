/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 28/1/2021                                                                                      */
/*******************************************************************************************************/

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define	ASYNCHRONOUS_OP	0
#define	SYNCHRONOUS_OP	1

#define	DISABLED		0
#define	ENABLED_EVEN	1
#define	ENABLED_ODD		2

#define	ONE_BIT			0
#define	TWO_BIT			1


#define EIGHT_BITS		0
#define NINE_BITS		1

#define TR_RISING		0
#define TR_FALING		1

void MUSART1_voidInit(void);
u8 MUSART1_u8Receive(void);
void MUSART1_voidtransmit(char arr[]);







#endif 

/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 1/2/2021                                                                                      */
/*******************************************************************************************************/
#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidInit(void);
void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority2 (s8 Copy_s8Priority, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u8Group);
void MNVIC_vidSetPriority1(u8 Copy_u8IntNumber ,  u8 Copy_u8Group  ,  u8 Copy_u8Priority );

#define GROUP3 0x05FA0300    	 // 4 bits for group (IPR) => group
#define GROUP4 0x05FA0400		//3 bits for group and 1 bit for sub
#define GROUP5 0x05FA0500		//2 bits for group and 2 bit for sub
#define GROUP6 0x05FA0600		//1 bits for group and 3 bit for sub
#define GROUP7 0x05FA0700		//0 bits for group and 4 bit for sub


#endif


/* Driver by struct */




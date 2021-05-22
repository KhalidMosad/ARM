/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 19/1/2021                                                                                      */
/*******************************************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"NVIC_interface.h"
#include"NVIC_private.h"
#include"NVIC_config.h"

void MNVIC_voidInit(void)
{
	#ifndef	 SCB_AIRCR
	#define	 SCB_AIRCR		*((u32*)0xE000ED0C)
	#endif
	SCB_AIRCR= MNVIC_GROUPS_SUBS;
}
void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	
	if ( Copy_u8IntNumber <=31)
	{
		NVIC_ISER0= (1<<Copy_u8IntNumber);
		//SET_BIT(NVIC_ISER0,Copy_u8IntNumber);	
	}
	else if ( Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ISER1=(1<<Copy_u8IntNumber);
		//SET_BIT(NVIC_ISER1,Copy_u8IntNumber);	
	}
	else 
	{
		/* Return Error */
	}
	
	
}
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	
	if ( Copy_u8IntNumber <=31)
	{
		NVIC_ICER0 = (1<<Copy_u8IntNumber);
		//SET_BIT(NVIC_ICER0,Copy_u8IntNumber);	
	}
	else if ( Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ICER1=(1<<Copy_u8IntNumber);
		//SET_BIT(NVIC_ICER1,Copy_u8IntNumber);	
	}
	else 
	{
		/* Return Error */
	}
	
	
}
void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber)
{
	
	if ( Copy_u8IntNumber <=31)
	{
		NVIC_ISPR0= (1<<Copy_u8IntNumber);
		//SET_BIT(NVIC_ISPR0,Copy_u8IntNumber);	
	}
	else if ( Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ISPR1=(1<<Copy_u8IntNumber);
		//SET_BIT(NVIC_ISPR1,Copy_u8IntNumber);	
	}
	else 
	{
		/* Return Error */
	}
	
	
}

void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
	
	if ( Copy_u8IntNumber <=31)
	{
		NVIC_ICPR0= (1<<Copy_u8IntNumber);
		//SET_BIT(NVIC_ICPR0,Copy_u8IntNumber);	
	}
	else if ( Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ICPR1=(1<<Copy_u8IntNumber);
		//SET_BIT(NVIC_ICPR1,Copy_u8IntNumber);	
	}
	else 
	{
		/* Return Error */
	}
	
	
}
u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber)
{
	u8 Local_u8Result=0;
	if ( Copy_u8IntNumber <=31)
	{
		Local_u8Result= GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
		
	}
	else if ( Copy_u8IntNumber <=59)
	{
		Copy_u8IntNumber -=32;
		Local_u8Result= GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
		
	}
	else 
	{
		/* Return Error */
	}
	
	return Local_u8Result;
}
/*
void MNVIC_voidSetPriority (s8 Copy_s8Priority, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority, u32 Copy_u8Group)
{
	u8 Local_u8Priority =Copy_u8SubPriority|(Copy_u8GroupPriority<<((Copy_u8Group-0x05FA0300)/256));
	//  Core Peripheral

	//  External Peripheral
	if(Copy_s8Priority>=0)
	{
		NVIC_IPR[Copy_s8Priority]=	Local_u8Priority<<4;
	}
	SCB_AIRCR= Copy_u8Group;
	
}

*/




/*
void MNVIC_voidSetPriority()




*/

void MNVIC_vidSetPriority(u8 Copy_u8IntNumber ,  u8 Copy_u8Group  ,  u8 Copy_u8Priority )
{

	/* Range Check                       */
	if( Copy_u8IntNumber < 60)
	{
		#if MNVIC_GROUPS_SUBS == MNVIC_GROUP4_SUB_0
		NVIC_IPR[Copy_u8IntNumber] = Copy_u8Group << 4;

		#elif MNVIC_GROUPS_SUBS == MNVIC_GROUP3_SUB_1
			NVIC_IPR[Copy_u8IntNumber] = (Copy_u8Priority | (Copy_u8Group << 1)) << 4 ;

		#elif MNVIC_GROUPS_SUBS == MNVIC_GROUP2_SUB_2
			NVIC_IPR[Copy_u8IntNumber] = (Copy_u8Priority | (Copy_u8Group << 2)) << 4 ;

		#elif MNVIC_GROUPS_SUBS == MNVIC_GROUP1_SUB_3
			NVIC_IPR[Copy_u8IntNumber] = (Copy_u8Priority | (Copy_u8Group << 3)) << 4 ;

		#elif MNVIC_GROUPS_SUBS == MNVIC_GROUP0_SUB_4
			NVIC_IPR[Copy_u8IntNumber] = (Copy_u8Priority << 4 );

		#endif

	}
	else
	{
		/* ERROR STATE */
	}

}


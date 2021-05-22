/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 1/2/2021                                                                                      */
/*******************************************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI_interface.h"
#include"EXTI_config.h"
#include"EXTI_private.h"
#include "GPIO_interface.h"

#ifndef	NULL
#define	NULL 	(void*)0
#endif
static void (*EXTI0_CallBack)(void)=NULL;

void MEXTI_voidInit (void)
{
	/* Disable interrupts*/
	EXTI->IMR = 0;
	/* Clear All Flags */
	EXTI->PR = 0xffffffff;

	
	
	#if EXTI_MODE == RISING
	SET_BIT(EXTI -> RTSR,EXTI_LINE );
	#elif EXTI_MODE == FALLING
	SET_BIT(EXTI->FTSR , EXTI_LINE );
	#elif EXTI_MODE == ON_CHANGE
	SET_BIT(EXTI -> RTSR,EXTI_LINE );
	SET_BIT(EXTI -> FTSR,EXTI_LINE );
	#elif	
		#error 	"Wrong Mode "
	#endif

	
}

void MEXTI_voidEnableEXTI(u8 Copy_u8Line)			/*, u8 Copy_u8SenseMode*/
{
	/* Range Check */
	if (Copy_u8Line<16)
	{	
	SET_BIT(EXTI->IMR ,	Copy_u8Line );
	}
	else
	{
		/*	Return ERROR		*/
	}
//	SET_BIT(EXTI->RTSR,	Copy_u8SenseMode );

}

void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	/* Range Check */
	if (Copy_u8Line<16)
	{	
	CLR_BIT(EXTI->IMR,	Copy_u8Line );
	}
	else
	{
		/*	Return ERROR		*/
	}
	
}


void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI->SWIER,Copy_u8Line );
}

void MEXTI_voidSetSignalLatch (u8 Copy_u8Line,u8 Copy_u8Mode)
{
	MEXTI_voidDisableEXTI(Copy_u8Line);
	switch(Copy_u8Mode)
	{
		case RISING:
			SET_BIT(EXTI->RTSR,Copy_u8Mode );
			CLR_BIT(EXTI->FTSR,Copy_u8Mode );
			break;
			
		case FALLING:
			CLR_BIT(EXTI->RTSR,Copy_u8Mode );
			SET_BIT(EXTI->FTSR,Copy_u8Mode );
			break;
			
		case ON_CHANGE:
			SET_BIT(EXTI->RTSR,Copy_u8Mode );
			SET_BIT(EXTI->FTSR,Copy_u8Mode );
			break;
		//default:
		//	#error "Wrong"   /*error*/
	}
	
	SET_BIT(EXTI->IMR ,Copy_u8Line );
}
void MEXTI_voidSetCallBack(void(*ptr)(void))
{
	if(ptr !=NULL)
	{
	EXTI0_CallBack=ptr;
	}
	
}





/* if Core Peripheral

void SysTick_Handler(void)
if vendor As Below	
 */
void EXTI0_IRQHandler(void)
{

	EXTI0_CallBack();
	/*	Clear pending bit*/
	SET_BIT(EXTI->PR , 0);
	
}

















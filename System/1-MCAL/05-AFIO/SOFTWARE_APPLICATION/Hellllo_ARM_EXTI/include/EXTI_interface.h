/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 19/1/2021                                                                                      */
/*******************************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
void MEXTI_voidInit (void);
void MEXTI_voidEnableEXTI(u8 Copy_u8Line);
void MEXTI_voidDisableEXTI(u8 Copy_u8Line);
void MEXTI_voidSwTrigger(u8 Copy_u8Line);
void MEXTI_voidSetSignalLatch (u8 Copy_u8Line,u8 Copy_u8Mode);
void MEXTI_voidSetCallBack(void(*ptr)(void));

#define 	RISING		0
#define 	FALLING		1
#define 	ON_CHANGE	2

#define 	EXTI_LINE0			0
#define 	EXTI_LINE1			1
#define 	EXTI_LINE2			2

#endif


/* Driver by struct */




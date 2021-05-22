/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 19/1/2021                                                                                      */
/*******************************************************************************************************/

#ifndef 	EXTI_PRIVATE_H
#define		EXTI_PRIVATE_H

typedef struct {
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
	
	
	
}EXIT_t;

#define EXTI  (( EXIT_t *)0x40010400)


#define 	EXTI_LINE0			0
#define 	EXTI_LINE1			1
#define 	EXTI_LINE2			2


#define 	RISING		0
#define 	FALLING		1
#define 	ON_CHANGE	2


#endif

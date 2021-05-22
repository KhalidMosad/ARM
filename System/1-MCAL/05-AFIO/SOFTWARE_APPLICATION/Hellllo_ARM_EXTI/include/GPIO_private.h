/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 24/1/2021                                                                                      */
/*******************************************************************************************************/





#ifndef 	GPIO_PRIVATE_H
#define		GPIO_PRIVATE_H


typedef struct
{
	volatile u32 CRL ; 
	volatile u32 CRH ; 
	volatile u32 IDR ; 
	volatile u32 ODR ; 
	volatile u32 BSRR ;
    volatile u32 BRR  ;
    volatile u32 LCKR ;
}GPIO_st;

#define GPIOAP	((volatile GPIO_st*)0x40010800)
#define	GPIOBP	((volatile GPIO_st*)0x40010C00)
#define	GPIOCP	((volatile GPIO_st*)0x40011000)


#endif

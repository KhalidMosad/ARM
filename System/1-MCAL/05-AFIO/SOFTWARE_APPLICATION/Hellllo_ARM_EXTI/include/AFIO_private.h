/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 19/1/2021                                                                                      */
/*******************************************************************************************************/

#ifndef 	AFIO_PRIVATE_H
#define		AFIO_PRIVATE_H

typedef struct {
	volatile u32 EVCR;
	volatile u32 MSPR;
	volatile u32 EXTICR[4];
	volatile u32 MAPR2;
	
	
	
}AFIO_t;

#define AFIO  ((volatile AFIO_t *)0x40010000)



#endif
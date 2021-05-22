/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 27/1/2021                                                                                      */
/*******************************************************************************************************/
#ifndef	SPI_INTERFACE_H
#define	SPI_INTERFACE_H

#define EIGHT_BIT		0
#define SIXTEEN_BIT		1


#define	F_4				0
#define	F_16			1
#define	F_64			2
#define	F_128			3
#define	F_2				4
#define	F_8				5
#define	F_32			6
#define	F_256  			8

#define	LEADING_RISING	0
#define	LEADING_FALLING	1

#define	LEADING_SAMPLE	0
#define	LEADING_SETUP	1

#define	MASTER			0
#define	SLAVE			1

#define	LSB_FIRST		0
#define	MSB_FIRST		1

#define	INT_ENABLE		0
#define	INT_DISABLE		1

void MSPI1_VoidInit(void);
void MSPI1_u8SendReceiveSynch(u8 Copy_U8DataToTransmit,u8 *Copy_U8DataToReceive);

//void MSPI1_u8SendReceiveAsynch(u8 Copy_U8DataToTransmit,void (*CallBack)(u8));



#endif


/* Driver by struct */




/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 24/1/2021                                                                                      */
/*******************************************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#define 	GPIO_HIGH     1
#define 	GPIO_LOW      0

#define		GPIOA 	0
#define		GPIOB	1
#define		GPIOC 	2


        
#define		PIN0 	0
#define		PIN1 	1
#define		PIN2 	2
#define		PIN3 	3
#define		PIN4 	4
#define		PIN5 	5
#define		PIN6 	6
#define		PIN7 	7
#define		PIN8 	8
#define		PIN9 	9
#define		PIN10 	10
#define		PIN11 	11
#define		PIN12 	12
#define		PIN13 	13
#define		PIN14 	14
#define		PIN15 	15


#define 	OUTPUT_SPEED_10MHZ_PUSHPULL   	 	0b0001
#define 	OUTPUT_SPEED_10MHZ_OpDrain			0b0101	
#define 	OUTPUT_SPEED_10MHZ_AFPP   	 		0b1001
#define 	OUTPUT_SPEED_10MHZ_AFOD				0b1101

#define 	OUTPUT_SPEED_50MHZ_PUSHPULL   	 	0b0011
#define 	OUTPUT_SPEED_50MHZ_OpDrain			0b0111	
#define 	OUTPUT_SPEED_50MHZ_AFPP   	 		0b1011
#define 	OUTPUT_SPEED_50MHZ_AFOD				0b1111			

#define 	OUTPUT_SPEED_2MHZ_PUSHPULL   	 	0b0010
#define 	OUTPUT_SPEED_2MHZ_OpDrain			0b0110	
#define 	OUTPUT_SPEED_2MHZ_AFPP   	 		0b1010
#define 	OUTPUT_SPEED_2MHZ_AFOD				0b1110

#define 	ANALOG_INPUT_INPUT  				0b0000
#define 	FLOATING_INPUT_INPUT				0b0100	
#define 	PULL_UP_INPUT_INPUT 				0b1000

#define 	POUTPUT_SPEED_10MHZ_PUSHPULL   	 	0x11111111
#define 	POUTPUT_SPEED_10MHZ_OpDrain			0x55555555
#define 	POUTPUT_SPEED_10MHZ_AFPP   	 		0x99999999
#define 	POUTPUT_SPEED_10MHZ_AFOD			0xDDDDDDDD

#define 	POUTPUT_SPEED_50MHZ_PUSHPULL   	 	0x33333333
#define 	POUTPUT_SPEED_50MHZ_OpDrain			0x77777777
#define 	POUTPUT_SPEED_50MHZ_AFPP   	 		0xBBBBBBBB
#define 	POUTPUT_SPEED_50MHZ_AFOD			0xFFFFFFFF

#define 	POUTPUT_SPEED_2MHZ_PUSHPULL   	 	0x22222222
#define 	POUTPUT_SPEED_2MHZ_OpDrain			0x66666666
#define 	POUTPUT_SPEED_2MHZ_AFPP   	 		0xAAAAAAAA
#define 	POUTPUT_SPEED_2MHZ_AFOD				0xEEEEEEEE


void GPIO_voidSetPinDirection(u8 copy_u8PORT, u8 copy_u8Pin, u8 copy_u8Mode);
void GPIO_voidSetPinValue(u8 copy_u8PORT, u8 copy_u8Pin, u8 copy_u8Value);
u8 GPIO_u8GetPinValue(u8 copy_u8PORT, u8 copy_u8Pin);
void GPIO_voidSetPortDirection(u8 copy_u8PORT, u32 copy_u8Mode);
void GPIO_voidSetPortValue(u8 copy_u8PORT, u32 copy_u8Value);

#endif

/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 27/1/2021                                                                                      */
/*******************************************************************************************************/

#ifndef 	SPI_CONFIG_H
#define		SPI_CONFIG_H
/* CLOCK RATE SELECT OPTIONS
F_2
F_4
F_8
F_16
F_32
F_64
F_128
F_256

*/
#define CLOCK_RATE	F_2

/* CLOCK POLARITY OPTIONS

LEADING_RISING
LEADING_FALLING

*/

#define CLOCK_POLARITY	LEADING_FALLING
 
 
/* CLOCK PHASE OPTIONS

LEADING_SAMPLE
LEADING_SETUP

*/ 
#define CLOCK_PHASE	LEADING_SETUP

/* Mode Options 
MASTER
SLAVE
*/
#define MODE	MASTER

/* DATA TRANSFER OPTIONS:

LSB_FIRST
MSB_FIRST
*/
#define	DATA	MSB_FIRST

/* OPERATIONS MODE OPTIONS:

INT_ENABLE
INT_DISABLE


#define OP_MODE	INT_DISABLE
*/


/*Data Frame Options: 
EIGHT_BIT	
SIXTEEN_BIT	
*/
#define DATA_FRAME	EIGHT_BIT


#define MSPI1_SLAVE_PIN	GPIOA,0


#endif
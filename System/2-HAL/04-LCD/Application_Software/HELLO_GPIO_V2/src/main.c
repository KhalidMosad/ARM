
/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 24/1/2021                                                                                      */
/*******************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SEVENSEG_interface.h"
#include "LCD_Interface.h"
void main(void)
{
	RCC_voidInitSysClock();
	/* Enable RCC for GPIOA*/
	RCC_voidEnableClock(RCC_APB2,2);
	/*Enable RCC for GPIOB*/
	RCC_voidEnableClock(RCC_APB2,3);
	LCD_VidInit();
	LCD_VidSendData('A');
	LCD_VidSendData('B');
	LCD_VidSendData('D');
	LCD_VidSendData('E');
	LCD_VidSendData('F');
	while(1);
	/*Enable RCC for GPIOC*/
	//RCC_VidEnableClock(RCC_APB2,4);

	//***HSEVENSEG_voidDisplayPort(GPIOA,POUTPUT_SPEED_2MHZ_PUSHPULL);

	//*GPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PUSHPULL);
	//*GPIO_voidSetPinDirection(GPIOB,PIN1,OUTPUT_SPEED_2MHZ_PUSHPULL);
	//GPIO_VidSetPinDirection(GPIOB,PIN2,OUTPUT_SPEED_2MHZ_PP);
	//GPIO_VidSetPinDirection(GPIOB,PIN3,OUTPUT_SPEED_2MHZ_PP);
	//GPIO_VidSetPinDirection(GPIOB,PIN4,OUTPUT_SPEED_2MHZ_PP);
	//*GPIO_voidSetPinDirection(GPIOB,PIN5,OUTPUT_SPEED_2MHZ_PUSHPULL);
//*	GPIO_voidSetPinDirection(GPIOB,PIN6,OUTPUT_SPEED_2MHZ_PUSHPULL);
	//*GPIO_voidSetPinDirection(GPIOB,PIN7,OUTPUT_SPEED_2MHZ_PUSHPULL);
	/**GPIO_voidSetPortDirection(GPIOA,POUTPUT_SPEED_2MHZ_PUSHPULL);
	//u16 w=500;
	while(1)
	{
		//*GPIO_voidSetPinValue(GPIOA,PIN1,GPIO_HIGH);
	//*	GPIO_voidSetPinValue(GPIOB,PIN1,GPIO_HIGH);
		//GPIO_VidSetPinValue(GPIOB,PIN2,HIGH);
		//GPIO_VidSetPinValue(GPIOB,PIN3,HIGH);
		//GPIO_VidSetPinValue(GPIOB,PIN4,HIGH);
	//*	GPIO_voidSetPinValue(GPIOB,PIN5,GPIO_HIGH);
	//*	GPIO_voidSetPinValue(GPIOB,PIN6,GPIO_HIGH);
	//*	GPIO_voidSetPinValue(GPIOB,PIN7,GPIO_HIGH);
GPIO_voidSetPortValue(GPIOA,0x05);

/*
		for (u8 i=0; i<=9;i++)
		{
			HSEVENSEG_voidDisplay(GPIOA,i);
			delay_1s();
		}
	}*/

	}


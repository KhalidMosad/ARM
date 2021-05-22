/*

 * main.c
 *
 *  Created on: Jan 26, 2021
 *      Author: Khaled
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"


void	delay(void);



void Toggle_LED(void);



void main()
{

	RCC_voidInitSysClock();
	/* Enable RCC for GPIOA*/
	/* Enable EXTI0 USING AF at bit 0*/
	RCC_voidEnableClock(RCC_APB2,0);
	/* Enable GPIOA*/
	RCC_voidEnableClock(RCC_APB2,2);

	/* Enable GPIOA Peripheral Clock          */

	GPIO_voidSetPinDirection(GPIOA,PIN0, PULL_UP_INPUT_INPUT);
	GPIO_voidSetPinValue(GPIOA,PIN0, 1);

	/*PIN6 OUTPUT*/
	GPIO_voidSetPinDirection(GPIOA,PIN5, OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(GPIOA,PIN7, OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinValue(GPIOA,PIN7, 1);
	//GPIO_voidTogglePin(GPIOA,PIN7);


	MEXTI_voidSetCallBack(Toggle_LED);

	MNVIC_voidInit();
	MEXTI_voidInit();

	/*EXTI0 Enable*/
	MEXTI_voidEnableEXTI(0);


	MNVIC_vidSetPriority(6,1,1);
	/* MNVIC EXTI0 ENable*/

	MNVIC_voidEnableInterrupt(6);
	//MNVIC_voidClearPendingFlag(6);

	//

while(1);



}


void Toggle_LED(void)
{

	GPIO_voidTogglePin(GPIOA,PIN5);
	GPIO_voidTogglePin(GPIOA,PIN7);
}


void	delay(void)
{
	for(u16 i=0;i<660;i++ )
		for(u16 j=0;j<660;j++)
			asm("NOP");
}


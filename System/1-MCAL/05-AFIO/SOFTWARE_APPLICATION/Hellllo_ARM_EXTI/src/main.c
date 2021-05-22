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
#include"AFIO_interface.h"


void	delay(void);



void Toggle_LED(void);
void Toggle_LED2(void);


void main()
{

	RCC_voidInitSysClock();
	/* Enable RCC for GPIOA*/
	/* Enable EXTI0 USING AF at bit 0*/
	RCC_voidEnableClock(RCC_APB2,0);
	/* Enable GPIOA*/
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,3);
	/* Enable GPIOA Peripheral Clock          */

	GPIO_voidSetPinDirection(GPIOA,PIN0, PULL_UP_INPUT_INPUT);
	GPIO_voidSetPinValue(GPIOA,PIN0, 1);
	GPIO_voidSetPinDirection(GPIOB,PIN1, PULL_UP_INPUT_INPUT);
	GPIO_voidSetPinValue(GPIOB,PIN1, 1);
	/*PIN6 OUTPUT*/
	GPIO_voidSetPinDirection(GPIOA,PIN5, OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(GPIOA,PIN7, OUTPUT_SPEED_2MHZ_PUSHPULL);
	//GPIO_voidSetPinValue(GPIOA,PIN7, 1);
	//GPIO_voidTogglePin(GPIOA,PIN7);


	MEXTI_voidSetCallBack(Toggle_LED);
	MEXTI1_voidSetCallBack(Toggle_LED2);
	MNVIC_voidInit();
	MEXTI_voidInit();
	MAFIO_voidSetEXITCnonfiguration(1,1);
	/*EXTI0 Enable*/
	MEXTI_voidEnableEXTI(0);
	MEXTI_voidSetSignalLatch(1,FALLING);
	MNVIC_vidSetPriority(7,0,1);
	MNVIC_vidSetPriority(6,1,1);
	/* MNVIC EXTI0 ENable*/

	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);
	//MNVIC_voidClearPendingFlag(6);

	//

while(1);



}


void Toggle_LED(void)
{

	GPIO_voidTogglePin(GPIOA,PIN5);


}
void Toggle_LED2(void)
{

	GPIO_voidTogglePin(GPIOA,PIN7);
}

void	delay(void)
{
	for(u16 i=0;i<660;i++ )
		for(u16 j=0;j<660;j++)
			asm("NOP");
}


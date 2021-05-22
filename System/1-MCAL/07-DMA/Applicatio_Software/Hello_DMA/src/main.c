
/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 2/2/2021                                                                                      */
/*******************************************************************************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "DMA_interface.h"
#include "DMA_private.h"

u16 i=0;

void main(void)
{
	RCC_voidInitSysClock();

	RCC_voidEnableClock(RCC_APB2,2);
	GPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinValue(GPIOA,PIN1,GPIO_HIGH);
	u32 Arr1[1000]={0};
	u32 Arr2[1000];

	u32 Arr3[1000]={0};
	u32 Arr4[1000];



	RCC_voidEnableClock(RCC_AHB,0);

	MDMA_voidChannelInit();
	MNVIC_voidEnableInterrupt(11);

	MDMA_voidChannelStart(Arr1, Arr2, 1000);

	for(  i=0; i<1000; i++)
	{
		Arr4[i]=Arr3[i];


	}



	while(1)
	{


	}


}


void DMA1_Channel1_IRQHandler(void)
{
	GPIO_voidSetPinValue(GPIOA,PIN0,GPIO_HIGH);
	/* Clear GIF Flags            */
	DMA->IFCR=1<<0;

	/* Clear TC Flags            */
	DMA->IFCR=1<<1;


}



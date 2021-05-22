/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 3/2/2021                                                                                     */
/*******************************************************************************************************/
#include "STD_Types.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"

volatile u8 StartFlag=0;
volatile u32 FrameData[50]={0};
volatile u8 EdgeCounter=0;
u8 Data=0;

void voidPlay(void)
{
	switch (Data)
	{
		case 70: 
			GPIO_voidSetPinValue(GPIOA,PIN1,GPIO_HIGH);
		break;
		
		case 69:
		GPIO_voidSetPinValue(GPIOA,PIN1,GPIO_LOW);
		break;
		
		case 59:
		GPIO_voidSetPinValue(GPIOA,PIN1,GPIO_HIGH);
		
		break;
			
	}
	
}




/*
void voidTakeAction(void)
{

	asm("NOP");
	/*
	 * Open a debug session here to test that the STK is working well
	 * Click any button on the transmitter to change the state of the signal
	 * If the debugger gone to the asembely line this means that it is working well
	 *After Testing the First asm Code*/

/* AFter testing the previous ASM do the following*/
/*
u8 i;
u8 Data=0;
if(FrameData[0] >=10000 && FrameData[0] <=14000 )
{
for (i=0;i<=8;i++)
{
	if(FrameData[17+i] >=2000 && FrameData[17+i] <=2300 )
	{
		SET_BIT(Data,i);
	}
	else
	{
		CLR_BIT(Data,i);
	}
}
voidPlay();
}
else
{

// Return Invalid Number
}
StartFlag=0;
FrameData[0]=0;
EdgeCounter=0;
}

*/


void voidGetFrame(void)
{
	asm("NOP");
/*
 * Open a debug session here to test that the seneor is working well
 * Click any button on the transmitter to change the state of the signal
 * If the debugger gone to the asembely line this means that it is working well
 *
 */

	/* After Checking use the Following Code   */
/*
if (StartFlag==0)
{
	MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
	StartFlag=1;
}
else
{
	FrameData[EdgeCounter]=MSTK_u32GetElapsedTime();
	MSTK_voidSetIntervalSingle(1000000,voidTakeAction);
	EdgeCounter++;
}

*/
}


void main(void)
{
	RCC_voidInitSysClock();
	/* Enable EXTI0 USING AF at bit 0*/
	RCC_voidEnableClock(RCC_APB2,0);
	/* Enable GPIOA*/
	RCC_voidEnableClock(RCC_APB2,2);
	/* A0 Is floating to be sensitive to high and low */
	GPIO_voidSetPinDirection(GPIOA,PIN0, FLOATING_INPUT_INPUT);


	/* Initialize A1, A2, A3 to RGB Color LED */
	GPIO_voidSetPinDirection(GPIOA,PIN1, OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(GPIOA,PIN2, OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(GPIOA,PIN3, OUTPUT_SPEED_2MHZ_PUSHPULL);
	/* Call Back Must be initialized before EXTI_Init */
	MEXTI_voidSetCallBack(voidGetFrame);

	MNVIC_voidInit();
	MEXTI_voidInit();

	/*EXTI0 Enable*/
	MEXTI_voidEnableEXTI(0);
	/* MNVIC EXTI0 ENable*/
	MNVIC_voidEnableInterrupt(6);
	MNVIC_vidSetPriority(6,1,1);

	/* Initialize STK */
	MSTK_voidInit();

	while(1)
	{



	}



}

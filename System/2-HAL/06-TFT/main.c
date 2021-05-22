#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"STK_interface.h"
#include "TFT_interface.h"
#include "SPI_interface.h"
#include "image.h"
#include "image2.h"
int main(void)
{
	/*8MHZ*/ 
	RCC_voidInitSysClock();
	//	GPIO ENABLE
	RCC_voidEnableClock(RCC_APB2,2);
	//SPI
	RCC_voidEnableClock(RCC_APB2,12);

	GPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_10MHZ_AFPP);
	GPIO_voidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_10MHZ_AFPP);
	MSTK_voidInit();
	MSPI1_VoidInit();
	HTFT_voidInit();


	HTFT_voidDisplayImage(image2);
	while(1)
	{

		
	}
	
	
}

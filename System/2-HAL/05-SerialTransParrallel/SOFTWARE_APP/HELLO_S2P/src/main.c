#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"STK_interface.h"
#include "STP_interface.h"

int main(void)
{
	/*8MHZ*/ 
	RCC_voidInitSysClock();
	//	GPIO ENABLE
	RCC_voidEnableClock(RCC_APB2,3);
	GPIO_voidSetPinDirection(GPIOB,PIN0,POUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(GPIOB,PIN6,POUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(GPIOB,PIN7,POUTPUT_SPEED_2MHZ_PUSHPULL);


	MSTK_voidInit();

	HSTP_voidSendSynchronus(0XAE);
	while(1)
	{

		
	}
	
	
}

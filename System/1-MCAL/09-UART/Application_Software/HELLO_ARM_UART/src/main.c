#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"USART_interface.h"

int main(void)
{
	/*8MHZ*/ 
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_APB2,2);

	RCC_voidEnableClock(RCC_APB2,14);
	
	GPIO_voidSetPinDirection(GPIOA,PIN9, OUTPUT_SPEED_2MHZ_AFPP);
	GPIO_voidSetPinDirection(GPIOA,PIN10, FLOATING_INPUT_INPUT);
	
	MUSART1_voidInit();
	u8 x;
	
	GPIO_voidSetPinDirection(GPIOA,PIN0, OUTPUT_SPEED_50MHZ_PUSHPULL);
	while(1)
	{
	MUSART1_voidtransmit("97");
		
		x=MUSART1_u8Receive();
		if (x=='5')
		{
			
			GPIO_voidSetPinValue(GPIOA,PIN0, GPIO_HIGH);
		}
		else if(x=='R')
		{
			GPIO_voidSetPinValue(GPIOA,PIN0, GPIO_LOW);
			
		}
		
	}
	
	
}

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"UART_interface.h"

int main(void)
{
	/*8MHZ*/ 
	RCC_voidInitSysClock();
	RCC_voidEnableClock(RCC_ABP2,2);
	
	RCC_voidEnableClock(RCC_ABP2,14);
	
	GPIO_voidSetPinDirection(GPIOA,PIN9, OUTPUT_50Mhz_PP);
	GPIO_voidSetPinDirection(GPIOA,PIN10, INPUT_FLOATING);
	
	MUSART1_voidInit();
	u8 x;
	
	GPIO_voidSetPinDirection(GPIOA,PIN0, OUTPUT_50Mhz_PP);
	while(1)
	{
		MUSART1_voidtransmit("97");
		
		x=MUSART1_u8Receive();
		if (x=='5')
		{
			
			GPIO_voidSetPinValue(GPIOA,PIN0, GPIO_HIGH);
		}
		elif(x=='R')
		{
			GPIO_voidSetPinValue(GPIOA,PIN0, GPIO_LOW);
			
		}
		
	}
	
	
}
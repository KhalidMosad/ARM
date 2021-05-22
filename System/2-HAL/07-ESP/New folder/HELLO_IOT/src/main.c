#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"ESP_interface.h"
#include"USART_interface.h"

int main(void)
{

	/*8MHZ*/ 
	RCC_voidInitSysClock();
	//	GPIO ENABLE
	RCC_voidEnableClock(RCC_APB2,2);
	RCC_voidEnableClock(RCC_APB2,3);
	// UART CLOCK ENABLE
	RCC_voidEnableClock(RCC_APB2,14);
	
	//TX
	GPIO_voidSetPinDirection(GPIOA,PIN9, OUTPUT_SPEED_2MHZ_AFPP);
	//RX
	GPIO_voidSetPinDirection(GPIOA,PIN10, FLOATING_INPUT_INPUT);
	MUSART1_voidInit();
	HESP_voidInit();

	HESP_voidWifiUserAndPass("Zakariya","mariamzakariya");



	while(1)
	{
	HESP_voidServerData("162.253.155.227", "80");
	HESP_voidCharNumber("48");
	HESP_voidGetFile("khalimozaarm.freevar.com");
		
	}
	
	
}

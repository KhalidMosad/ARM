#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"LEDMTX_interface.h"
#include "STK_interface.h"

int main(void)
{
	u8 myname[8]={132, 68, 36, 28, 36, 68, 132, 4};
	/*8MHZ*/ 
	RCC_voidInitSysClock();
	//	GPIOA ENABLE
	RCC_voidEnableClock(RCC_APB2,2);
	// GPIOB ENABLE
	RCC_voidEnableClock(RCC_APB2,3);

	MSTK_voidInit();

	HLEDMTX_voidInit();

	HLEDMTX_voidDisplay(myname);
	while(1)
	{

		
	}
	
	
}

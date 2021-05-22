/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 23/1/2021                                                                                      */
/*******************************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPIO_interface.h"
#include"SEVENSEG_interface.h"
#include"SEVENSEG_private.h"
#include"SEVENSEG_config.h"


static u8 ssnum[]={ZERO,ONE ,TWO ,THREE ,FOUR ,FIVE ,SIX ,SEVEN ,EIGHT ,NINE};

void HSEVENSEG_voidDisplayPort(u8 copy_u8PORT, u32 copy_u8Mode)
{
	GPIO_voidSetPortDirection(copy_u8PORT,copy_u8Mode);


}


void HSEVENSEG_voidDisplay(u8 copy_u8PORT,u8 number)
{
#if SEV_SEG_TYPE==1

	GPIO_voidSetPortValue(copy_u8PORT,ssnum[number]);

#elif SEV_SEG_TYPE ==2

		GPIO_voidSetPortValue(copy_u8PORT,~ssnum[number]);
	
#endif
}

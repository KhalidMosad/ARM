/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 23/1/2021                                                                                      */
/*******************************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPIO_interface.h"
#include"STK_interface.h"
#include"LEDMTX_interface.h"
#include"LEDMTX_config.h"
#include"LEDMTX_private.h"

void HLEDMTX_voidInit(void)
{
	GPIO_voidSetPinDirection(LEDMTX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	
	GPIO_voidSetPinDirection(LEDMTX_COL0_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL1_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL2_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL3_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL4_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL5_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL6_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	GPIO_voidSetPinDirection(LEDMTX_COL7_PIN,OUTPUT_SPEED_2MHZ_PUSHPULL);
	
}


static void HLEDMTX_voidDisableAllCols(void)
{
	
		/* Disable All columns */
	
	GPIO_voidSetPinValue(LEDMTX_COL0_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL1_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL2_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL3_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL4_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL5_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL6_PIN,GPIO_HIGH);
	GPIO_voidSetPinValue(LEDMTX_COL7_PIN,GPIO_HIGH);
	
	
	
}

static void HLEDMTX_voidSetRowValue(u8 Copy_u8Value)
	{
		u8 Local_u8Bit;
		Local_u8Bit=GET_BIT(Copy_u8Value,0);
		GPIO_voidSetPinValue(LEDMTX_ROW0_PIN,Local_u8Bit);

		Local_u8Bit=GET_BIT(Copy_u8Value,1);
		GPIO_voidSetPinValue(LEDMTX_ROW1_PIN,Local_u8Bit);

		Local_u8Bit=GET_BIT(Copy_u8Value,2);
		GPIO_voidSetPinValue(LEDMTX_ROW2_PIN,Local_u8Bit);

		Local_u8Bit=GET_BIT(Copy_u8Value,3);
		GPIO_voidSetPinValue(LEDMTX_ROW3_PIN,Local_u8Bit);

		Local_u8Bit=GET_BIT(Copy_u8Value,4);
		GPIO_voidSetPinValue(LEDMTX_ROW4_PIN,Local_u8Bit);

		Local_u8Bit=GET_BIT(Copy_u8Value,5);
		GPIO_voidSetPinValue(LEDMTX_ROW5_PIN,Local_u8Bit);

		Local_u8Bit=GET_BIT(Copy_u8Value,6);
		GPIO_voidSetPinValue(LEDMTX_ROW6_PIN,Local_u8Bit);

		Local_u8Bit=GET_BIT(Copy_u8Value,7);
		GPIO_voidSetPinValue(LEDMTX_ROW7_PIN,Local_u8Bit);



	}

void HLEDMTX_voidDisplay(u8 *Copy_u8Data)
{
	
	while(1)
	{
	HLEDMTX_voidDisableAllCols();
	/* Enable Column 0*/
	HLEDMTX_voidSetRowValue(Copy_u8Data[0]);
	GPIO_voidSetPinValue(LEDMTX_COL0_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
	HLEDMTX_voidDisableAllCols();
	/* Enable Column 1*/
	HLEDMTX_voidSetRowValue(Copy_u8Data[1]);
	GPIO_voidSetPinValue(LEDMTX_COL1_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
	HLEDMTX_voidDisableAllCols();
	/* Enable Column 2*/
	HLEDMTX_voidSetRowValue(Copy_u8Data[2]);
	GPIO_voidSetPinValue(LEDMTX_COL2_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
	
	HLEDMTX_voidDisableAllCols();
	/* Enable Column 3*/
	HLEDMTX_voidSetRowValue(Copy_u8Data[3]);
	GPIO_voidSetPinValue(LEDMTX_COL3_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
		HLEDMTX_voidDisableAllCols();
	/* Enable Column 4*/
	HLEDMTX_voidSetRowValue(Copy_u8Data[4]);
	GPIO_voidSetPinValue(LEDMTX_COL4_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
		HLEDMTX_voidDisableAllCols();
	/* Enable Column 5*/
	HLEDMTX_voidSetRowValue(Copy_u8Data[5]);
	GPIO_voidSetPinValue(LEDMTX_COL5_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
		HLEDMTX_voidDisableAllCols();
	/* Enable Column 6*/
	HLEDMTX_voidSetRowValue(Copy_u8Data[6]);
	GPIO_voidSetPinValue(LEDMTX_COL6_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	
		HLEDMTX_voidDisableAllCols();
	/* Enable Column 7*/
	HLEDMTX_voidSetRowValue(Copy_u8Data[7]);
	GPIO_voidSetPinValue(LEDMTX_COL7_PIN,GPIO_LOW);
	MSTK_voidSetBusyWait(2500);
	}
}

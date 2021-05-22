/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V01                                                                                         */
/* Date: 30/1/2021                                                                                      */
/*******************************************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"GPIO_interface.h"
#include"USART_interface.h"
#include "STK_interface.h"
#include"ESP_interface.h"
#include"ESP_config.h"
#include"ESP_private.h"


void HESP_voidInit(void)
{
	GPIO_voidSetPinDirection(GPIOB,PIN0, OUTPUT_SPEED_2MHZ_PUSHPULL);

	u8 Local_u8Result=0;

	//while(Local_u8Result==0)
	//{
	/*Stop Echo */
	MUSART1_voidtransmit("ATE1\r\n");
	//Local_u8Result= HESP_u8ValidateCommand();
	MSTK_voidSetBusyWait(3000000);
	//}

	//Local_u8Result=0;
	//while(Local_u8Result==0)
	//{
	/* Set Station Mode          */
	MUSART1_voidtransmit("AT+CWMODE=1\r\n");
	//Local_u8Result= HESP_u8ValidateCommand();
	//MSTK_voidSetBusyWait(3000000);
	//}
	

}

void HESP_voidWifiUserAndPass(u8 *username, u8 *password)
{
	//u8 Local_u8Result=0;
	//while(Local_u8Result==0)
	//{
	MUSART1_voidtransmit("AT+CWJAP_CUR=\"");
	MUSART1_voidtransmit(username);
	MUSART1_voidtransmit(  "\",\"" );
	MUSART1_voidtransmit(password);
	MUSART1_voidtransmit(  "\"r\n" );
	//MSTK_voidSetBusyWait(5000000);
	//MSTK_voidSetBusyWait(5000000);
	//Local_u8Result= HESP_u8ValidateCommand();
//}

}

void HESP_voidServerData(u8 *IP, u8 *PORT)
{
	u8 Local_u8Result=0;
	//while(Local_u8Result==0)
	//{

	MUSART1_voidtransmit("AT+CIPSTART=\"TCP\",\"");
	MUSART1_voidtransmit(IP);
	MUSART1_voidtransmit("\",");
	MUSART1_voidtransmit(PORT);
	MUSART1_voidtransmit(  "\r\n" );
	//Local_u8Result= HESP_u8ValidateCommand();
	MSTK_voidSetBusyWait(1000);

	//}

}

void HESP_voidCharNumber(u8 *Number)
{
	//u8 Local_u8Result=0;
	//while(Local_u8Result==0)
	//{

	MUSART1_voidtransmit("AT+CIPSEND=");
	MUSART1_voidtransmit(Number);
	MUSART1_voidtransmit(  "\r\n" );
	MSTK_voidSetBusyWait(1000);

	//Local_u8Result= HESP_u8ValidateCommand();

//}

}

void HESP_voidGetFile(u8 *ID)
{
u8 data=0;


	MUSART1_voidtransmit("GET http://");
	MUSART1_voidtransmit( ID );
	MUSART1_voidtransmit( "/status.txt\r\n" );


do{
data=(u8)MUSART1_u8Receive();


}while(data!=':');
data=(u8)MUSART1_u8Receive();
GPIO_voidSetPinValue(GPIOB,PIN0,1);
if (data=='1')
{

	GPIO_voidSetPinDirection(GPIOA,PIN0, OUTPUT_SPEED_50MHZ_PUSHPULL);
	GPIO_voidSetPinValue(GPIOA,PIN0, GPIO_HIGH);
	GPIO_voidSetPinDirection(GPIOA,PIN1, OUTPUT_SPEED_50MHZ_PUSHPULL);
	GPIO_voidSetPinValue(GPIOA,PIN1, GPIO_LOW);
}
else if(data=='0')
{
	GPIO_voidSetPinDirection(GPIOA,PIN0, OUTPUT_SPEED_50MHZ_PUSHPULL);
	GPIO_voidSetPinValue(GPIOA,PIN0, GPIO_LOW);
	GPIO_voidSetPinDirection(GPIOA,PIN1, OUTPUT_SPEED_50MHZ_PUSHPULL);
	GPIO_voidSetPinValue(GPIOA,PIN1, GPIO_HIGH);
}

}


u8 HESP_u8ValidateCommand(void)
{
	u8 Local_u8Response[100]={0};
	u8 i=0;
	u8 Dummy=0;
	u8 Result =0;
	while(Dummy !=255)
	{
		Dummy=MUSART1_u8Receive();
		Local_u8Response[i]=Dummy;
		i++;
	}
	if (Local_u8Response[0] == 'O' && Local_u8Response[1]== 'K')
	{
		Result= 1;
	}
	return Result;
}






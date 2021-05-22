/*******************************************************************************************************/
/* Author: Khalid                                                                                      */
/* Version :V02                                                                                         */
/* Date: 24/1/2021                                                                                      */
/*******************************************************************************************************/
#include "STD_TYPES.h"
#include"GPIO_interface.h"
#include "LCD_Interface.h"
#include "LCD_configure.h"
#include "LCD_private.h"
//#include "STK_interface.h"
void delay_1s(void);

void LCD_VidInit(void)
{

	#if LCD_Mode==EIGHT_BIT
//	MSTK_voidInit();
	GPIO_voidSetPinDirection	( Lcopy_u8PORT,RS_copy_u8Pin,Lcopy_u8Mode);
	GPIO_voidSetPinDirection	( Lcopy_u8PORT,R_w_copy_u8Pin,Lcopy_u8Mode);
	GPIO_voidSetPinDirection	( Lcopy_u8PORT,E_copy_u8Pin, Lcopy_u8Mode);
	GPIO_voidSetPortDirection	( LDcopy_u8PORT,LDcopy_u8Mode);

	LCD_VidSendCommand(0b00111000);
	//MSTK_voidSetBusyWait(12);
//	delay_1s();
	LCD_VidSendCommand(0b00001111);
	//MSTK_voidSetBusyWait(5);
	//delay_1s();
	LCD_VidSendCommand(0b00000001);
	//MSTK_voidSetBusyWait(10);
//	delay_1s();
	LCD_VidSendCommand(0b00000110);
//	MSTK_voidSetBusyWait(2);
	delay_1s();

	#elif LCD_Mode==FOUR_BIT

	GPIO_voidSetPinDirection	( Lcopy_u8PORT,RS_copy_u8Pin,Lcopy_u8Mode);
	GPIO_voidSetPinDirection	( Lcopy_u8PORT,R_w_copy_u8Pin,Lcopy_u8Mode);
	GPIO_voidSetPinDirection	( Lcopy_u8PORT,E_copy_u8Pin, Lcopy_u8Mode);
	GPIO_voidSetPortDirection	( LDcopy_u8PORT,LDcopy_u8Mode);
	LCD_VidClear();
	LCD_VidSendCommand(0x33);
	LCD_VidSendCommand(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_VidSendCommand(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_VidSendCommand(0x0c);	/* Display on cursor off */
	LCD_VidSendCommand(0x06);	/* Increment cursor (shift cursor to right) */
	LCD_VidSendCommand(0x01);	/* Clear display screen */
	delay_1s();
	#endif
}

void LCD_VidSendData(u8 copy_u8data)
{
	#if LCD_Mode==EIGHT_BIT
		GPIO_voidSetPinValue(Lcopy_u8PORT,  RS_copy_u8Pin,1);
		GPIO_voidSetPinValue(Lcopy_u8PORT,  R_w_copy_u8Pin,0);
		GPIO_voidSetPortValue(LDcopy_u8PORT,copy_u8data);
		GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);  // E=1; Upload Command
		//MSTK_voidSetBusyWait(5);
		delay_1s();
		GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);   // E=0 Display Command
	//	MSTK_voidSetBusyWait(3);
		delay_1s();
	#elif LCD_Mode==FOUR_BIT
		GPIO_voidSetPortValue(LDcopy_u8PORT,(LDcopy_u8PORT& 0x0F)|(copy_u8data&0xF0));
		GPIO_voidSetPinValue(Lcopy_u8PORT,  RS_copy_u8Pin,1);
		GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);  // E=1; Upload Command
		//MSTK_voidSetBusyWait(5);
		delay_1s();
		GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);   // E=0 Display Command
	//	MSTK_voidSetBusyWait(3);
		delay_1s();

		GPIO_voidSetPortValue(LDcopy_u8PORT,(LDcopy_u8PORT& 0x0F)|(copy_u8data<<4));
		GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);  // E=1; Upload Command
		//MSTK_voidSetBusyWait(5);
		delay_1s();
		GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);   // E=0 Display Command
	//	MSTK_voidSetBusyWait(3);
		delay_1s();

	#endif
}

void LCD_VidSendCommand(u32 copy_u8command)
{
	#if LCD_Mode==EIGHT_BIT
	GPIO_voidSetPinValue(Lcopy_u8PORT,  RS_copy_u8Pin,0);
	GPIO_voidSetPinValue(Lcopy_u8PORT,  R_w_copy_u8Pin,0);
	GPIO_voidSetPortValue(LDcopy_u8PORT,copy_u8command);
	GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);  // E=1; Upload Command
	delay_1s();
	GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);   // E=0 Display Command
	if (copy_u8command==1)
		delay_1s();
	//	MSTK_voidSetBusyWait(2);
	#elif LCD_Mode==FOUR_BIT
	GPIO_voidSetPortValue(LDcopy_u8PORT,(LDcopy_u8PORT& 0x0F)|(copy_u8command&0xF0));
	GPIO_voidSetPinValue(Lcopy_u8PORT,  RS_copy_u8Pin,0);
	GPIO_voidSetPinValue(Lcopy_u8PORT,  R_w_copy_u8Pin,0);
	GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);
	delay_1s();
	GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);
	delay_1s();
	GPIO_voidSetPortValue(LDcopy_u8PORT,(LDcopy_u8PORT& 0x0F)|(copy_u8command<<4)); /* Sending lower cmnds */
	GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);
	delay_1s();
	GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);
	delay_1s();
	#endif
}

void LCD_VidSendString( u8 *copy_u8string)
{


	int i=0;

	while(copy_u8string[i] != '\0')
	{

		LCD_VidSendData(copy_u8string[i]);
		delay_1s();
		i++;
	}






}

 void LCD_VidSendNumber( u16 copy_u16number)
{

	if (copy_u16number==0)
	{
		LCD_VidSendData('0');
	}
	s8 i=0;
	u8 str_num[5];
	while(copy_u16number>0)
	{
		str_num[i]=copy_u16number%10;
		copy_u16number/=10;
		i++;
	}
	i--;
	while(i>=0)
	{
		switch(str_num[i])
		{
		case 0 : LCD_VidSendData('0');break;
		case 1 : LCD_VidSendData('1');break;
		case 2 : LCD_VidSendData('2');break;
		case 3 : LCD_VidSendData('3');break;
		case 4 : LCD_VidSendData('4');break;
		case 5 : LCD_VidSendData('5');break;
		case 6 : LCD_VidSendData('6');break;
		case 7 : LCD_VidSendData('7');break;
		case 8 : LCD_VidSendData('8');break;
		case 9 : LCD_VidSendData('9');break;
		}

		i--;
	}


}


void LCD_VidSetPosition(u8 raw, u8 column)
{
	if(0==raw)       // raw= 0
	{
	LCD_VidSendCommand(128+column);    // 0b10000000=128 +column
	}
	if(1==raw)
	{
	LCD_VidSendCommand(128+64+column);  //  // 0b10000000=128 +column+64
	                                    // 64 is the start address of row 2
	}

}

void LCD_VidClear(void)
{
	LCD_VidSendCommand(1);
//	MSTK_voidSetBusyWait(2);
	delay_1s();
}

void LCD_VidShiftRight(void)
{
	LCD_VidSendCommand(0b00011100);
//	MSTK_voidSetBusyWait(2);
	//delay_1s();
}

void LCD_VidShiftLeft(void)
{
	LCD_VidSendCommand(0x18);
//	MSTK_voidSetBusyWait(2);
	//delay_1s();
}
void LCD_voidReturnHome(void)
{
	LCD_VidSendCommand(0x02);

}

void delay_1s(void)
{

	for(u16 i=0;i<660;i++ )
		for(u16 j=0;j<660;j++)
			asm("NOP");

}






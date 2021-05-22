/*
 * LCD_program.c

 *
 *  Created on: Nov 30, 2020
 *      Author: Khaled
 */
#include "STD_TYPES.h"
#include"GPIO_interface.h"
#include "LCD_Interface.h"
#include "LCD_configure.h"
#include "STK_interface.h"
void delay_1s(void);

void LCD_VidInit(void)
{
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
}

void LCD_VidSendData(u32 copy_u8data)
{
		GPIO_voidSetPinValue(Lcopy_u8PORT,  RS_copy_u8Pin,1);   // portA Pin0, Rs=1 // data
		GPIO_voidSetPinValue(Lcopy_u8PORT,  R_w_copy_u8Pin,0);    // portA Pin1, R/w=0 // r/w=0.... write
		GPIO_voidSetPortValue(LDcopy_u8PORT,copy_u8data);    // port C
		GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);  // E=1; Upload Command
		//MSTK_voidSetBusyWait(5);
		delay_1s();
		GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);   // E=0 Display Command
	//	MSTK_voidSetBusyWait(3);
		delay_1s();
}
void LCD_VidSendCommand(u32 copy_u8command)
{
	GPIO_voidSetPinValue(Lcopy_u8PORT,  RS_copy_u8Pin,0);   // portA Pin0, Rs=0 // command
	GPIO_voidSetPinValue(Lcopy_u8PORT,  R_w_copy_u8Pin,0);    // portA Pin1, R/w=0 // r/w=0.... write
	GPIO_voidSetPortValue(LDcopy_u8PORT,copy_u8command);    // port C
	GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,1);  // E=1; Upload Command
	delay_1s();
	GPIO_voidSetPinValue(Lcopy_u8PORT,  E_copy_u8Pin,0);   // E=0 Display Command
	if (copy_u8command==1)
		MSTK_voidSetBusyWait(2);
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
/*
 void LCD_VidSendNumber( u16 copy_u8number)
{

u16 rev=0,r,c=0;
if(copy_u8number== '0' )
	{
		LCD_VidSendData('0');
	}

	//int x= copy_u8number;
	int i=0;
	while (copy_u8number!=0)
	{

		r=copy_u8number%10;
		rev=rev*10+r;

		 copy_u8number=copy_u8number/10;
		 //int y=copy_u8number*10;

	//	if ((copy_u8number%10==0) /*&& (x==y) )
			c++;

	 }


	while (rev!=0)
	{

		LCD_VidSendData(48+rev%10);
		rev/=10;
	}
for(i=1;i<=c;i++)
	{
		LCD_VidSendData('0');
	}

}
*/

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
	MSTK_voidSetBusyWait(2);
}


void delay_1s(void)
{

	for(u16 i=0;i<660;i++ )
		for(u16 j=0;j<660;j++)
			asm("NOP");

}









/* Case of Synch*/
void main(void)
{
u8 Receive;

MSPI1_u8SendReceiveSynch(0x55,&Receive);

}

/* Case of Asynch*/
void func(u8 Data)
{
	// Code 
	
}

void main(void)
{


MSPI1_u8SendReceiveAsynch(0x55,func);

}
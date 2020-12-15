/*
 * EEPROM.c
 *
 * Created: 10/27/2020 12:33:27 AM
 *  Author: AbdEl-Rahman
 */ 
#include "EEPROM.h"
void EEPROM_SEQUINTEIAL_SEND_INIT( u8 address)
{
	MasterT_start();
	MasterT_send(0b10101000);
	MasterT_send(address);	
}
void EEPROM_send(u8 data)
{   //u8 deviceAdress=(0xA0|(u8)((address|0x700)>>7));
	//u8 byteAdress=(u8)(address);
	/*MasterT_start();
	MasterT_send(0b10101000);
	MasterT_send(address);*/
	MasterT_send(data);
	
	_delay_ms(10);
}
void EEPROM_SEQUINTEIAL_RECIEVE_INIT(u8 address)
{
	MasterT_start();
	MasterT_send(0b10101000);
	MasterT_send(address);
	MasterT_start();
	MasterT_send(0b10101001);
}
void EEPROM_recieve(u8 n, u8 * arr)									//N is size of array
{   //u8 deviceAdress=(0xA0|(u8)((address|0x700)>>7));
	//deviceAdress = (deviceAdress|0b00000001);
	//u8 byteAdress=(u8)(address);
	//_delay_ms(100);
	//u8 temp = 0;
	
	for(u8 i=0; i<(n-1) ; i++)
	{
		
		*arr = MasterR_recieve_ACK();
		*arr ++;
	//return temp;
	}	
		*arr = MasterR_recieve_NACK();
	//return temp;
}
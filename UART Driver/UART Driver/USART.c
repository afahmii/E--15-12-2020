/*
 * USART.c
 *
 * Created: 9/29/2020 1:29:04 PM
 *  Author: AbdEl-Rahman
 */ 
#include "USART.h"

void config1( usart_SYNC_MODE sync,usart_SPEED speed)
{    uint32 myUBRR;
	if(sync== ASYNC && speed ==USART_SPEED_NORMAL)
	{   myUCSRC |= (1 << URSEL);
		myUCSRC |= (1 << UMSEL);
		myUBRR = (uint32)(FOSC/(BAUD*16))-1;
	}
	else if(sync== ASYNC && speed ==USART_SPEED_DOUBLE)
	{   myUCSRC |= (1 << URSEL);
		myUCSRA |= (1<<U2X); 
		myUCSRC |= (1 << UMSEL);
		myUBRR = (uint32)(FOSC/(BAUD*8))-1;
	}
	else if(sync== SYNC)
	{   myUCSRC |= (1 << URSEL);
		myUCSRC &= ~(1 << UMSEL);
		myUBRR = (uint32)(FOSC/(BAUD*2))-1;
	}
	myUCSRC &= ~(1 << URSEL);
	myUBRRH = (myUBRR<<8);
	myUBRRL = myUBRR;
	
}

void config2(partity_MODE parity,stop_BIT stopbit,character_SIZE character)
{   
	if(parity == NO_PARITY)
	{
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (0b00<< UPM0);
	}
	
	else if(parity == ODD_PARITY)
	{
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (0b11<< UPM0);
	}
	
	else if(parity == EVEN_PARITY)
	{
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (0b10<< UPM0);
	}
	
	myUCSRC |= (1 << URSEL);
	myUCSRC |= (stopbit<<USBS);
	
/*	if(stop_BIT == oneSTOP_BIT)
	{
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (0<<USBS);
	}
	
	else if(stop_BIT == twoSTOP_BIT)
	{
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (1<<USBS);
	}
	*/
	
	if(character != SIZE_9)
	{
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (character << 1);
	}
	else if (character == SIZE_9)
	{
		myUCSRB |= (1<<UCSZ2);
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (SIZE_8 << 1);
	}
	
/*	if(character_SIZE == SIZE_5)
	{
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (SIZE_5 << 1);
	}
	else if(character_SIZE == SIZE_6)
	{
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (SIZE_6 << 1);
	}
	else if(character_SIZE == SIZE_7)
	{
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (SIZE_7 << 1);
	}
	else if(character_SIZE == SIZE_8)
	{
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (SIZE_8 << 1);
	}
	else if(character_SIZE == SIZE_9)
	{   myUCSRB |= (1<<UCSZ2);
		myUCSRC |= (1 << URSEL);
		myUCSRC |= (SIZE_6 << 1);
	}
	*/
}

void config3(usart_TRANSMITTER_STATUS transmitter,usart_RECIEVER_STATUS reciever)
{  if(transmitter == USART_TRANSMITTER_ENABLED)
	myUCSRB |= (1<<TXEN);
	else if(transmitter == USART_TRANSMITTER_DISABLED)
	myUCSRB &= ~(1<<TXEN);
	if(reciever == USART_RECIEVER_DISABLED)
	myUCSRB &= ~(1<<RXEN);
	if(reciever == USART_RECIEVER_ENABLED)
	myUCSRB |= (1<<RXEN);
}

void transmit(uint8 data, character_SIZE character)
{
	while(!(myUCSRA & (1<<UDRE)));
	if(character == SIZE_9)
	{
		myUCSRB |=((data <<8)&1);
	}
	myUDR = data;
}

uint8 recieve(uint8 *ptr_to_data, character_SIZE character)
{
	while(!(myUCSRA & (1 << RXC)) );
	uint8 parity_error =0; 
	if(((myUCSRA>>PE)&1 )!= 1 )
	{
		if(character == SIZE_9)
		{
			*ptr_to_data = (((myUCSRB >> 1)& 1) << 8) ;
		}
		*ptr_to_data = myUDR;
		parity_error =1 ;
	}
	return parity_error;
}
void transmit_int( transmitter_INT_STATUS status)
{
	if(status == TRANSMITTER_ENABLED )
	{
		myUCSRB |= (1<<TXCIE);
	}
	else if(status == TRANSMITTER_DISABLED )
	{
		myUCSRB &= ~(1<<TXCIE);
	}
}
void recieve_int( reciever_INT_STATUS status)
{
	if(status == RECIEVER_ENABLED )
	{
		myUCSRB |= (1<<RXCIE);
	}
	else if(status == RECIEVER_DISABLED )
	{
		myUCSRB &= ~(1<<RXCIE);
	}
}
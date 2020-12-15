/*
 * SPI.c
 *
 * Created: 10/4/2020 2:31:58 PM
 *  Author: AbdEl-Rahman
 */ 
#include "SPI.h"
void spi_init(master_slave_select select )
{
	if(select == MASTER )
	{
		myDDRB |=  (1 << MOSI) | (1<<SCK) | (1<<SS);
		myDDRB &= ~(1<<MISO) ;
	//	myPINB |= (1<<SS);
		mySPCR |= (1<<MSTR) | (1<<SPE); 
	}
	else if(select == SLAVE )
	{
		myDDRB |= (1<<MISO);
		myDDRB &= ~(1<<SS) & ~(1 << MOSI) & ~(1<<SCK);
		mySPCR |= (1<<SPE);
	}
}

void int_init(enable_disable_spi_int interrupt1)
{
	if(interrupt1 == 1 )
	{   
		mySPCR |= (1<<SPIE);
	}
	else if(interrupt1 == 0 )
	{
		mySPCR &= ~(1<<SPIE);
	}
}
uint8 master_transmit(uint8 data)
{
	mySPDR = data; 
	while (!(mySPSR &(1<<SPIF)));
	return mySPDR;
}

uint8 slave_recieve(uint8 data)
{
	mySPDR = data;
	while (!(mySPSR &(1<<SPIF)));
	return mySPDR;
}

void Clock_rate(clock_rate rate)
{
	if(rate == F_64)
	{
		mySPSR |= (1<<SPI2X);
		mySPCR |= (1<<SPR0) | (1<<SPR1);
	}
	if(rate == F_128)
	{
		mySPSR &= ~(1<<SPI2X);
		mySPCR |= (1<<SPR0) | (1<<SPR1);
	}
}

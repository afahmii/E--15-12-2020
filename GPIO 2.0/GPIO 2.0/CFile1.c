/*
 * CFile1.c
 *
 * Created: 8/31/2020 4:37:17 PM
 *  Author: AbdEl-Rahman
 */ 
/*
 * CFile1.c
 *
 * Created: 8/31/2020 2:36:14 PM
 *  Author: AbdEl-Rahman
 */ 
#include "IncFile1.h"

void direction_pin (uint8_t port,uint8_t state, uint8_t pin )
{
	if(state==output)
	(*(volatile uint8_t*)(port+1)) |= (1<<pin);
	else
	(*(volatile uint8_t*)(port+1)) &= ~(1<<pin);
}

void port_direction (uint8_t port , uint8_t state)  //set first 4 pins in port to zeros or ones
{
	if (state == input)
	(*(volatile uint8_t*)(port+1)) = 0xF0;     //set first 4 pins in port X to input
	if (state == output)
	(*(volatile uint8_t*)(port+1)) = 0x0F;     //set first 4 pins in port X to output
	
}






void pin_write (uint8_t port,uint8_t value, uint8_t pin )
{
	if(value==0)
	(*(volatile uint8_t*)(port+2)) &= ~(1<<pin);
	else
	(*(volatile uint8_t*)(port+2)) |= (1<<pin);
}

void port_write (uint8_t port,uint8_t state)
{    if(state==high)
	(*(volatile uint8_t*)(port+2)) = 0xff;  //set first 4 pins in port X to high
	else
	(*(volatile uint8_t*)(port+2)) = 0x00;  //set first 4 pins in port X to low
}

uint8_t pin_read (uint8_t port, uint8_t pin)
{
	uint8_t value;
	value = (*((volatile uint8_t*)(port))>>pin )&1;
	if (value ==0)
	return 0;
	else return 1;
}

uint8_t port_read (uint8_t port )
{
	uint8_t value;
	value = (*(volatile uint8_t	*)(port));
	return value;
}

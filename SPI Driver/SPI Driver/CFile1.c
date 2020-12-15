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
    (*(volatile uint8_t*)(port+1)) |= ~(1<<pin);	
}

void port_direction (uint8_t port , uint8_t state)  //set first 4 pins in port to zeros or ones 
{
	if (state == input)
	(*(volatile uint8_t*)(port+1)) = 0x00;     //set 8 pins in port X to input
	if (state == output)
	(*(volatile uint8_t*)(port+1)) = 0x0F;     //set 8 pins in port X to output
	
}




void pin_write (uint8_t port,uint8_t value, uint8_t pin )
{
	if(value==0)
	(*(volatile uint8_t*)(port+2)) &= ~(1<<pin);
	else
	(*(volatile uint8_t*)(port+2)) |= (1<<pin);
}

void port_write (uint8_t port,uint8_t state)
{    if(state==low)  
	(*(volatile uint8_t*)(port+2)) = 0x00;  //set first 4 pins in port X to low and last 4 pins in port x to high
	else 
	(*(volatile uint8_t*)(port+2)) = 0xff;  //set first 4 pins in port X to high and last 4 pins in port x to low
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

uint8_t check(void)
{
	for(int i=0;i<4;i++)
	{   port_write(A,high);
		pin_write(A,low,i);
		for(int j=4;j<8;j++)
		{   
				
			if(pin_read(A,j)==0)
			{
				while(pin_read(A,j)==0);
				   switch(i)
				   {
					  case (0):
					  {
						  if (j == 4) 
						  return '7';
						  else if (j == 5)
						  return '4';
						  else if (j == 6)
						  return '1';
						  else if (j== 7)
						  return 'A';
						  break;
					  } 
					  case (1):
					  {
						  if (j == 4)
						  return '8';
						  else if (j == 5)
						  return '5';
						  else if (j == 6)
						  return '2';
						  else if (j == 7)
						  return '0';
						  break;
					  }
					  case (2):
					  {
						  if (j == 4)
						  return '9';
						  else if (j == 5)
						  return '6';
						  else if (j == 6)
						  return '3';
						  else if (j == 7)
						  return '=';
						  break;
					  }
					  case (3):
					  {
						  if (j == 4)
						  return '/';
						  else if (j == 5)
						  return '*';
						  else if (j == 6)
						  return '-';
						  else if (j == 7)
						  return '+';
						  break;
					  }
					  
				   }                                                                               
			                                                                                       
			    }                                                                                  
		                                                                                       
			
	  }
	}
	return 0;
}
 
 
void lcd_init()
{
	(*(volatile uint8_t*)(lcd_data+1))=0xff;   // set data port to output
//	(*(volatile uint8_t*)(lcd_data+2))=0x00;    // set initial value to 0
	(*(volatile uint8_t*)(lcd_comms+1))=0xff;   // set commands ports to output
//	(*(volatile uint8_t*)(lcd_comms+2))=0x00;   // set initial value to 0
	pin_write(lcd_comms,low,E);
	_delay_us(2000);
	pin_write(lcd_comms,low,RS);
	pin_write(lcd_comms,low,RW);
	lcd_commands(0x38);
	lcd_commands(0x0E);
	lcd_commands(0x01);
	_delay_us(2000);
	lcd_commands(0x01);      // shift cursor right
	
}
void lcd_commands(uint8_t command)
{
	(*(volatile uint8_t*)(lcd_data+2))=command; 
	pin_write(lcd_comms,low,RS);
	pin_write(lcd_comms,low,RW);
	pin_write(lcd_comms,high,E);
	_delay_us(1);
	pin_write(lcd_comms,low,E);
	_delay_us(100);
	
}
void lcd_dataout(uint8_t data)
{
	(*(volatile uint8_t*)(lcd_data+2))=data;
	pin_write(lcd_comms,high,RS);
	pin_write(lcd_comms,low,RW);
	pin_write(lcd_comms,high,E);
	_delay_us(1);
	pin_write(lcd_comms,low,E);
	_delay_us(100);
}

void interrupt_init (void)
{
	mySREG |= (1<<7);
}

void timer_init(void)
{
	myTCCR1B = 0x02 ;
	myTIMSK |= (1<<2);
}
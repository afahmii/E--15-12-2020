/*
 * SPI Driver.c
 *
 * Created: 10/4/2020 1:19:11 PM
 * Author : AbdEl-Rahman
 */ 

#include <avr/io.h>
#include "SPI.h"
#include <avr/interrupt.h>
#include <util/delay.h>	
#include "IncFile1.h" 
#define F_CPU 1000000UL
int main(void)
{
    /* Replace with your application code */
//	Clock_rate(F_128);
	spi_init(MASTER);
	
		lcd_init();
		_delay_ms(10);
//	uint8 data=0;
    while (1) 
    {  for(uint8 i ='A';i<=255;i++)
		{  _delay_ms(1000);
		   master_transmit(i);
	   lcd_dataout(i);
		}
    }
	
}


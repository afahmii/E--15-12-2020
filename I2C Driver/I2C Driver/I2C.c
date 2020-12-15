/*
 * I2C.c
 *
 * Created: 10/11/2020 3:37:52 AM
 *  Author: AbdEl-Rahman
 */ 
#include "I2C.h"

void I2C_init(choose_prescaler pre)
{
	uint8 preS = pre;
	myTWSR = preS;
	myTWBR = ((CPU_F/SCL_F)-16)/(2*preS);  // generate TWBR value for desired SCL_F vlaue
	
}

void MasterT_start(void)
{
	myTWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN); // Send Start Bit and enable Twin-Wire
	while(!(myTWCR&(1<<TWINT)));              // wait till process is finished
	while ((myTWSR & 0xF8) != start) ;          // Check value of TWI Status Register if a start condition has been sent . Mask pre-scaler bits.
	myTWDR = SLA_W;                           // load slave address + R/W bit into TWDR Reg
	myTWCR = (1<<TWINT) | (1<<TWEN);          // Clear TWINT bit, data is sent immediately after TWINT is cleared 
	while (!(myTWCR & (1<<TWINT)));           // wait till process is finished 
}

void MasterT_send(uint8 data)
{
	myTWDR = data;                            // load data into TWDR , TWINT is 1 
	myTWCR = (1<<TWINT) | (1<<TWEN);          // Clear TWINT bit
	while (!(myTWCR & (1<<TWINT)));           // wait till precess is finished
}

void MasterT_stop(void)
{
	myTWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);  // Cleat TWINT bit, Send stop bit
	
}

uint8 SlaveR_init_recieve(uint8 address)
{
	myTWAR = address;                                // set slave address and deny general call, LSB =0
	myTWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);         // enable sending ACK and TWI 
	while (!(myTWCR & (1<<TWINT)));                  // wait till process is finished 
	while(myTWAR!= 0x60);                            // Own SLA+W has been received ACK has been returned
	myTWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);         // enable sending ACK and TWI 
	while (!(myTWCR & (1<<TWINT)));                  // wait till process is finished 
	while(myTWAR!= 0x80);                            //Previously addressed with own SLA+W, data has been received, ACK has been returned
	return myTWDR;                                   // return recieved data
}

/*
 * UART.h
 *
 * Created: 9/28/2020 4:13:44 PM
 *  Author: AbdEl-Rahman
 */ 


#ifndef USART_H_
#define USART_H_
#include "AtmegaRegs.h"
#include "DataTypes.h"
#define BAUD 9600
#define FOSC 1000000

typedef enum USART_SYNC_MODE
{
	ASYNC = 0<<6,
	SYNC = 1<<6 
}usart_SYNC_MODE;

typedef enum USART_SPEED
{
	USART_SPEED_NORMAL,
	USART_SPEED_DOUBLE
}usart_SPEED;
typedef enum USART_TRANSMITTER_STATUS
{
	USART_TRANSMITTER_ENABLED ,
	USART_TRANSMITTER_DISABLED
}usart_TRANSMITTER_STATUS;

typedef enum USART_RECIEVER_STATUS
{
	USART_RECIEVER_ENABLED,
	USART_RECIEVER_DISABLED
}usart_RECIEVER_STATUS;

typedef enum DATA_REG_STATUS_FLAG_INT
{
	STATUS_FLAG_ENABLED = 1<<5,
	STATUS_FLAG_DISABLED = 0<<5 
}data_REG_STATUS_FLAG_INT;

typedef enum TRANSMITTER_INT_STATUS
{
	TRANSMITTER_ENABLED = 1<<6,
	TRANSMITTER_DISABLED = 0<<6
}transmitter_INT_STATUS;

typedef enum RECIEVER_INT_STATUS
{
	RECIEVER_ENABLED = 1<<7,
	RECIEVER_DISABLED = 0<<7
}reciever_INT_STATUS;

typedef enum PARITY_MODE
{
	NO_PARITY		=(0<<4),
	EVEN_PARITY		=(2<<4),
	ODD_PARITY 	   = (3<<4)
}partity_MODE;

typedef enum STOP_BIT
{
	oneSTOP_BIT =0,
	twoSTOP_BIT =1
}stop_BIT;

typedef enum EDGE_MODE
{
	TANSMITTER_RISING_EDGE = 0<<0,
	TANSMITTER_FALLING_EDGE = 1<<0
}edge_MODE;

typedef enum CHARACTER_SIZE 
{
	SIZE_5 = 0,
	SIZE_6 = 1,
	SIZE_7 = 2,
	SIZE_8 = 3,
	SIZE_9 = 7
}character_SIZE;

void config1( usart_SYNC_MODE sync,usart_SPEED speed);
void config2(partity_MODE parity,stop_BIT stopbit,character_SIZE character);
void config3(usart_TRANSMITTER_STATUS transmitter,usart_RECIEVER_STATUS reciever);
void transmit(uint8 data ,character_SIZE character);
uint8 recieve(uint8 *ptr_to_data, character_SIZE character);
void transmit_int( transmitter_INT_STATUS status);
void recieve_int( reciever_INT_STATUS status);

/**********************UCSRA************************/
#define RXC 	7
#define TXC 	6
#define UDRE 	5
#define FE 		4
#define DOR		3
#define PE 		2
#define U2X		1
#define MPCM	0

/**********************UCSRB************************/
#define RXCIE 	7
#define TXCIE	6
#define UDRIE	5
#define RXEN 	4
#define TXEN	3
#define UCSZ2	2
#define RXB8	1
#define TXB8	0

/**********************UCSRC************************/
#define URSEL	7
#define UMSEL	6
#define UPM1	5
#define UPM0	4
#define USBS	3
#define UCSZ1	2
#define UCSZ0	1
#define UCPOL	0

#endif /* USART_H_ */
/*
 * SPI.h
 *
 * Created: 10/4/2020 1:21:52 PM
 *  Author: AbdEl-Rahman
 */ 


#ifndef SPI_H_
#define SPI_H_
#include "AtmegaRegs.h"
#include "DataTypes.h"
typedef enum MASTER_SLAVE_SELECT
{
	MASTER = 1,
	SLAVE = 0
	}master_slave_select;
	
typedef enum DATA_ORDER_SELECT
{
	MSB = 0,
	LSB = 1
	}data_order_select;
	
typedef enum ENABLE_DISABLE_SPI
{
	ENABLE_SPI = 1, 
	DIABLE_SPI =0
	}enable_disable_spi;

typedef enum ENABLE_DISABLE_SPI_INT
{
	ENABLE_INT = 1, 
	DIABLE_INT =0
	}enable_disable_spi_int;

typedef enum CHOOSE_PHASE
{
	LEADING_SAMPLE= 0,
	LEADING_SETUP =1
	}choose_phase;

typedef enum CHOOSE_CLOCK_POLARITY
{
	LEADING_RISING = 0, 
	LEADING_FALLING =1 
	}choose_clock;
	
typedef enum CLOCK_RATE
{
	F_64,
	F_128
	}clock_rate;


/*****************SPCR*************/
#define SPIE 	7
#define SPE 	6
#define DORD 	5
#define MSTR 	4
#define CPOL 	3
#define CPHA 	2
#define SPR1	1
#define SPR0	0
/*****************SPSR*************/
#define SPIF	7
#define WCOL	6
#define SPI2X	0
/*************************************/
#define MISO 6
#define MOSI 5
#define SCK 7
#define SS 4
void spi_init(master_slave_select select );
void int_init(enable_disable_spi_int interrupt1);
uint8 master_transmit(uint8 data);
uint8 slave_recieve(uint8 data);
void Clock_rate(clock_rate rate);



#endif /* SPI_H_ */
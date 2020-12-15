/*
 * I2C.h
 *
 * Created: 10/11/2020 1:34:45 AM
 *  Author: AbdEl-Rahman
 */ 


#ifndef I2C_H_
#define I2C_H_
#include "AtmegaRegs.h"
#include "DataTypes.h"
#define CPU_F 8000000ul
#define SCL_F 1000000ul
#define SLA_W 0b10010000
#define SLA_R 0b10010001
/**************ERRORS CODES***********/
#define start 0x08 //start condition has been transmitted
#define Restart 0x10  // A repeated START condition has been transmitted

typedef enum CHOOSE_PRESCALER{
	pre_1 = 0,
	pre_4 = 1, 
	pre_16 = 2, 
	pre_64 = 3
	
	}choose_prescaler;
void I2C_init(choose_prescaler pre);
void MasterT_start(void);
void MasterT_send(uint8 data);
void MasterT_stop(void); 
uint8 SlaveR_init_recieve(uint8 address); 
//uint8 SlaveR_recieve(void);

/***************TWI Bit Rate Register**************/
#define TWBR7 7
#define TWBR6 6
#define TWBR5 5
#define TWBR4 4
#define TWBR3 3
#define TWBR2 2
#define TWBR1 1
#define TWBR0 0

/***************TWI Control Register**************/
#define TWINT 7 
#define TWEA 6 
#define TWSTA 5 
#define TWSTO 4
#define TWWC 3
#define TWEN 2
#define TWIE 0

/***************TWI Status Register**************/
#define TWS7 7
#define TWS6 6
#define TWS5 5
#define TWS4 4
#define TWS3 3
#define TWPS1 1
#define TWPS0 0


#endif /* I2C_H_ */
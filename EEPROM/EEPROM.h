/*
 * EEPROM.h
 *
 * Created: 10/27/2020 12:33:40 AM
 *  Author: AbdEl-Rahman
 */ 

#ifndef EEPROM_H_
#define EEPROM_H_
#include "I2C.h"
void EEPROM_SEQUINTEIAL_SEND_INIT(u8 address);
void EEPROM_send(u8 data);
void EEPROM_SEQUINTEIAL_RECIEVE_INIT(u8 address);
void EEPROM_recieve(u8 n, u8 * arr);


#endif /* EEPROM_H_ */
/*
 * IncFile1.h
 *
 * Created: 8/31/2020 4:38:31 PM
 *  Author: AbdEl-Rahman
 */ 



#ifndef INCFILE1_H_
#define INCFILE1_H_
#include <avr/io.h>
#include <util/delay.h>
//#define F_CPU 4000000 (ul)
#define A 0x39
#define B 0x36
#define C 0x33
#define D 0x30
#define lcd_data C
#define lcd_comms B
#define RS 1
#define RW 2 
#define E 3 

#define output 1
#define input 0
#define high 1 
#define low 0 
#define mySREG    *((volatile uint8_t* const)0X5F)
#define myGIFR    *((volatile uint8_t* const)0X5A)
#define myMCUCR   *((volatile uint8_t* const)0X55)
#define myTCCR1B  *((volatile uint8_t* const)0X4E)
#define myTCNT1L  *((volatile uint8_t* const)0X4C)
#define myTCNT1H  *((volatile uint8_t* const)0X4D)
#define myTIMSK   *((volatile uint8_t* const)0X59)
#define ISR(vector, ...) \
void vector(void)__attribute__((signal,used,externally_visible)) __VA_ARGS__;\
void vector(void)

typedef unsigned char uint8_t;


void direction_pin (uint8_t port,uint8_t state, uint8_t pin );
void port_direction (uint8_t port , uint8_t state);
void pin_write (uint8_t port,uint8_t state, uint8_t pin );
void port_write (uint8_t port,uint8_t state);
uint8_t pin_read (uint8_t port, uint8_t pin);
uint8_t port_read (uint8_t port );
uint8_t check(void);


void lcd_init(void);
void lcd_commands(uint8_t command);
void lcd_dataout(uint8_t data);






#endif /* INCFILE1_H_ */
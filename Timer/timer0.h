/*
 * timer.h
 *
 * Created: 22-Sep-20 1:59:29 AM
 *  Author: khaled
 */ 

#ifndef TIMER_H_
#define TIMER_H_
#include "reg.h"
#include "timer0conf.h"
/*Timer0 operating modes*/
#define NORMAL (u8)0x00
#define PHASE_CORRECT_PWM (u8)0x40
#define CTC (u8)0x08
#define FAST_PWM (u8)0x48

/*Compare Output Mode, PWM Modes*/
#define NON_INVERTING (u8)0x20
#define INVERTING (u8)0x30

/*Compare Output Mode, CTC Mode*/
#define TOGGLE (u8)0x10 //Toggle OC0 on compare match
#define CLEAR (u8)0x20 //Clear OC0 on compare match
#define SET (u8)0x30 //Set OC0 on compare match

/*clock sources*/
#define PRESCALAR_OFF (u8)0x01
#define PRESCALAR_8 (u8)0x02
#define PRESCALAR_64 (u8)(0x03)
#define PRESCALAR_256 (u8)(0x04)
#define PRESCALAR_1024 (u8)(0x05)
#define EXTERNAL_CLK_FALLING_EDGE (u8)(0x06)
#define EXTERNAL_CLK_RISING_EDGE (u8)(0x07)

#define ON (u8)1
#define OFF (u8)0

#define OC0 (u8)3
#define TOIE0 (u8)0
#define OCIE0 (u8)1


/*Functions prototypes*/
void TMR0Init();
void TMR0SetDutyCycle(u8 dutyCycle);
void TMR0SetCompareValue(u8 val);
void TMR0SetInitialValue(u8 val);
u8 TMR0ReadCounterValue();
void TMR0Stop();



#endif /* TIMER_H_ */
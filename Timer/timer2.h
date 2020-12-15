/*
 * timer.h
 *
 * Created: 22-Sep-20 1:59:29 AM
 *  Author: khaled
 */ 

#ifndef TIMER_H_
#define TIMER_H_
#include "reg.h"
#include "timer2conf.h"
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
#define PRESCALAR_32 (u8)(0x03)
#define PRESCALAR_64 (u8)(0x04)
#define PRESCALAR_128 (u8)(0x05)
#define PRESCALAR_256 (u8)(0x06)
#define PRESCALAR_1024 (u8)(0x07)

#define ON (u8)1
#define OFF (u8)0

#define OC2 (u8)7
#define TOIE2 (u8)6
#define OCIE2 (u8)7


/*Functions prototypes*/
void TMR2Init();
void TMR2SetDutyCycle(u8 dutyCycle);
void TMR2SetCompareValue(u8 val);
void TMR2SetInitialValue(u8 val);
u8 TMR2ReadCounterValue();
void TMR2Stop();



#endif /* TIMER_H_ */
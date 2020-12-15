/*
 * Timer.c
 *
 * Created: 22-Sep-20 1:51:03 AM
 *  Author: khaled
 */ 

//#define F_CPU 8000000UL
#include "timer0.h"


void TMR0Init()
{
	*TCCR0 |= MODE|CLOCK|OC_MODE;
	if(OVERFLOW_INTERRUPT)
		*TIMSK |= 1<<TOIE0;
	if(COMPARE_MATCH_INTERRUPT)
		*TIMSK |= 1<<OCIE0;
	*TCNT0 = (u8)INIT_VAL;
}

void TMR0SetDutyCycle(u8 dutyCycle)
{
	*DDRB |= 1<<OC0;
	*OCR0=dutyCycle*2+dutyCycle/20+dutyCycle/2;
}

void TMR0SetCompareValue(u8 val)
{
	*OCR0=val;
}

void TMR0Stop()
{
	*TCCR0=0x00;
}

void TMR0SetInitialValue(u8 val)
{
	*TCNT0=val;
}

u8 TMR0ReadCounterValue()
{
	return *TCNT0;
}
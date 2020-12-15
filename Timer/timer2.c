/*
 * Timer.c
 *
 * Created: 22-Sep-20 1:51:03 AM
 *  Author: khaled
 */ 

//#define F_CPU 8000000UL
#include "timer2.h"


void TMR2Init()
{
	*TCCR2 |= MODE|CLOCK|OC_MODE;
	if(OVERFLOW_INTERRUPT)
		*TIMSK |= 1<<TOIE2;
	if(COMPARE_MATCH_INTERRUPT)
		*TIMSK |= 1<<OCIE2;
	*TCNT0 = (u8)INIT_VAL;
}

void TMR2SetDutyCycle(u8 dutyCycle)
{
	*DDRD |= 1<<OC2;
	*OCR2=dutyCycle*2+dutyCycle/20+dutyCycle/2;
}

void TMR2SetCompareValue(u8 val)
{
	*OCR2=val;
}

void TMR2Stop()
{
	*TCCR2=0x00;
}

void TMR2SetInitialValue(u8 val)
{
	*TCNT2=val;
}

u8 TMR2ReadCounterValue()
{
	return *TCNT2;
}
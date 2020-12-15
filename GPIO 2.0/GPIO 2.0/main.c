/*
 * GPIO 2.0.c
 *
 * Created: 8/31/2020 4:36:54 PM
 * Author : AbdEl-Rahman
 */ 


#include "IncFile1.h"

int main(void)
{

	mySREG|=1<<7;
	myGICR|=1<<6;
	myMCUCR = 0X01;
	direction_pin(A,output,1);
	direction_pin(D,input,2);
	//pin_write(A,high,1);
	while (1){
		pin_write(A,high,1);
	}
}
ISR(__vector_1){
    pin_write(A,low,1);
	_delay_ms(2000);
	myGIFR|=1<<6;
}





/*	Author: Daniel Cook
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: [Parking sensor pt.2]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs
    /* Insert your solution below */
    unsigned char tmpA = 0x00;
    unsigned char cntavail = 0x00;
    while (1) {
        cntavail = 0x00;
        tmpA = PINA;
        cntavail = ((tmpA&0x01)+((tmpA&0x02)>>1)+((tmpA&0x04)>>2)+((tmpA&0x08)>>3));
        if(cntavail == 4){
	cntavail = 0x80 + cntavail;
	}
	PORTC = 0x04 - cntavail;
 

    }
    return 1;
}

/*	Author: Daniel Cook
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #3
 *	Exercise Description: [Parking garage pt2]
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
        DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize
        unsigned char count = 0x00; // Temporary variable to hold the value of A
        unsigned char tmpA = 0x00;

    while (1) {
	count = 0x00;
        tmpA = PINA;
        count = ((tmpA&0x01)+((tmpA&0x02)>>1)+((tmpA&0x04)>>2)+((tmpA&0x08)>>3));
	if(count == 4){
	PORTC = (0x04 - count)|0x80;
	}
	else {
	PORTC = 0x04 -count;
	}
    }
    return 1;
}

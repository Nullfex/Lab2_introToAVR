/*	Author: Daniel Cook
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #4
 *	Exercise Description: [Amusment park]
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
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0x00; PORTC = 0xFF; // Configure port B's 8 pins as inputs
	DDRD = 0xFF; PORTD = 0x00; // Configure port C's 8 pins as outputs
    /* Insert your solution below */
    unsigned char tmpA = 0x00;
    unsigned char tmpB = 0x00;
    unsigned char tmpC = 0x00;
    unsigned char tmpD = 0x00;
    while (1) {
        tmpA = PINA;
	tmpB = PINB;
	tmpC = PINC;
	tmpD = 0x00;
 	tmpD = (((tmpA+tmpB+tmpC)>>4)<<2);

	if ((tmpA+tmpB+tmpC)>0x8C){
	tmpD = tmpD|0x01;
	}
	if(tmpA>tmpC){
	if((tmpA-tmpC)>80) {tmpD = tmpD|0x02;}
	}
	else {
	if((tmpC-tmpA)>80) {tmpD = tmpD|0x02;}
	}
	PORTD = tmpD;
    }
    return 1;
}

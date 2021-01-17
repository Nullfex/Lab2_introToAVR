/*	Author: Daniel Cook
 *  Partner(s) Name: 
 *	Lab Section: 021
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: [garage door]
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
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs
    /* Insert your solution below */
    unsigned char temp_input = 0x00;
    unsigned char temp_output = 0x00;
    while (1) {
	temp_input = PINA;
	if(temp_input == 0x01) {
		temp_output = 1;
	}
	else {temp_output = 0;};	
	PORTB = temp_output;
    }
    return 1;
}

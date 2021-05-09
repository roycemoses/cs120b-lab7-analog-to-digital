/*	Author: Royce Moses
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 * 
 *  VIDEO: https://youtu.be/PBOo6fxwn70
 * 
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char tmpB = 0x00;
unsigned char tmpD = 0x00;

// ADC = (V_in * 1024) / V_ref
void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
    //   ADEN:  setting this bit enables analog-to-digital conversion
    //   ADSC:  setting this bit starts the first conversion
    //   ADATE: setting this bit enables auto triggering. Since we are
    //          in Free Running Mode, a new conversion will trigger whenever
    //          the previous conversion completes.
}

int main(void) {
    /* Insert DDR and PORT initializations */
        // DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs, initalize to 1s.
        DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initalize to 0s.
        DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initalize to 0s.

    /* Insert your solution below */
    ADC_init();
    while (1) {
        unsigned short x = ADC;
        x = x & 0x00FF; // maintain lower 8 bits
        tmpB = (char)x; // x = ADC = 0xABCD --> 0xCD
        PORTB = tmpB;

        unsigned short y = ADC;
        y = (y & 0x0300) >> 8; // maintain bit 10 and 9, then shift it to [1:0]
        tmpD = (char)y; // y = ADC = 0xABCD --> lower 2 bits of 'b'
        PORTD = tmpD;
    }
    return 1;
}
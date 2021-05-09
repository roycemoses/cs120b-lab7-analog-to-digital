/*	Author: Royce Moses
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #7  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 * 
 *  VIDEO: https://youtu.be/27XvVM_oFZM
 *  
 *  MAX: b11 1000 0000 // #896 // x0380
 *  MIN: b00 0010 0111 // #39  // x0023
 * 
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char tmpB = 0x00;
// unsigned char tmpD = 0x00;

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
        // DDRD = 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initalize to 0s.

    /* Insert your solution below */
    ADC_init();
    unsigned short MAX = 0x0380;
    unsigned short thresh = MAX / 8; // #112
    while (1) {
        unsigned short x = ADC;
        if (x > 0 && x <= thresh)
            PORTB = 0x01;
        else if (x > thresh && x <= thresh*2)
            PORTB = 0x03;
        else if (x > thresh*2 && x <= thresh*3)
            PORTB = 0x07;
        else if (x > thresh*3 && x <= thresh*4)
            PORTB = 0x0F;
        else if (x > thresh*4 && x <= thresh*5)
            PORTB = 0x1F;
        else if (x > thresh*5 && x <= thresh*6)
            PORTB = 0x3F;
        else if (x > thresh*6 && x <= thresh*7)
            PORTB = 0x7F;
        else if (x > thresh*7 && x <= thresh*8)
            PORTB = 0xFF;
    }

    return 1;
}
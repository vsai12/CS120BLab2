/*      Author: vhuan025
 *       *  Partner(s) Name: 
 *        *      Lab Section: 023
 *         *      Assignment: Lab #2  Exercise #1
 *          *      Exercise Description: [optional - include for your own benefit]
 *           *
 *            *      I acknowledge all content contained herein, excluding template or example
 *             *      code, is my own original work.
 *              */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
        DDRA = 0x00; PORTA = 0xFF; //configure portA as inputs
        DDRB = 0xFF; PORTB = 0x00; //configure portB as outputs

        unsigned char tmpA = 0x00; //temp var to hold value of A
        while (1) {
                tmpA = PINA & 0x03; //mask to get PA0, PA1
                if(tmpA == 0x01) //if garage door is open and no light is sensed
                        PORTB = 0x01; //sets PB0 to 1
                else
                        PORTB = 0x00; //otherwise LED goes off
        }
        return 1;
}


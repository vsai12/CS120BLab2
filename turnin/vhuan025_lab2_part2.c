/*      Author: vhuan025
 *       *  Partner(s) Name: 
 *        *      Lab Section: 023
 *         *      Assignment: Lab #2  Exercise #2
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
        DDRC = 0xFF; PORTC = 0x00; //configure portC as outputs

        unsigned char tmpA = 0x00; //temp var to hold value of A
	unsigned char cntavail = 0x00; //count of available spots
        while (1) {
		cntavail = 0; //reset count
		tmpA = PINA & 0x0F; //mask to get PA0, PA1, PA2, PA3
		if((tmpA & 0x01) == 0x00) //checks if PA0 is 0
			cntavail++;
		if((tmpA & 0x02) == 0x00) //checks if PA1 is 0
                        cntavail++;
		if((tmpA & 0x04) == 0x00) //checks if PA2 is 0
                        cntavail++;
		if((tmpA & 0x08) == 0x00) //checks if PA3 is 0
                        cntavail++;
		PORTC = cntavail;
        }
        return 1;
}


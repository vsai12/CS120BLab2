/*      Author: vhuan025
 *       *  Partner(s) Name: 
 *        *      Lab Section: 023
 *         *      Assignment: Lab #2  Exercise #4
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
	DDRB = 0x00; PORTB = 0xFF; //configure portB as inputs
	DDRC = 0x00; PORTC = 0xFF; //configure portC as inputs
        DDRD = 0xFF; PORTD = 0x00; //configure portD as outputs

        while (1) {
		unsigned char sum = 0x00; //varaible to hold sum weight of carts
		unsigned char tmpD = 0x00; //temp var to hold value of D
		if(PINA > 0x8C) //checks if cartA > 140
			tmpD = tmpD | 0x01; //sets PD0 to 1;
		else if(PINB > 0x8C) //checks if cartB > 140
                        tmpD = tmpD | 0x01; //sets PD0 to 1;
		else if(PINC > 0x8C) //checks if cartC > 140
                        tmpD = tmpD | 0x01; //sets PD0 to 1;

		if(PINA > PINC) {
			if(PINA - PINC > 0x50)
				tmpD = tmpD | 0x02; //sets PD1 to 1
			
		}
		else if(PINC - PINA > 0x50)
			tmpD = tmpD | 0x02; //sets PD1 to 1
		
		sum = PINA + PINB + PINC;
		sum = sum & 0xFC; //sets last 2 bits of sum to 0
		tmpD = sum | tmpD; //copies the first 6 bits of sum into tmpD
		PORTD = tmpD;
		
        }
        return 1;
}


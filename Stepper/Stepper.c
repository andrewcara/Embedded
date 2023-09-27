#include <avr/io.h>
#include <util/delay.h>

int step(int stepper);

int main(void) {
    // Set the LED pin as an output
    DDRB |= 0b00011110;
    int stepper = 0;


    while (1) {
        // Turn the LED on

        step(stepper);
        _delay_ms(1); // Wait for 1 second

        stepper++;

        if(stepper > 7){
            stepper=0;
        }
    }

    return 0;
}

int step(int stepper){
    switch(stepper)
    {
        case 0:
        PORTB = 0b00010000;
        break;
        case 1:
        PORTB = 0b00011000;
        break;

        case 2:
        PORTB = 0b00001000;
        break;

        case 3:
        PORTB = 0b00001100;
        break;

        case 4: 
        PORTB = 0b00000100;
        break;

        case 5:
        PORTB = 0b00000110;
        break;

        case 6:
        PORTB = 0b00000010;
        break;

        case 7:
        PORTB = 0b00000000;
        break;

    }
}
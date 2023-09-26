#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN 0 // Define the digital pin for the LED
#define LED_PIN2 4
int main(void) {
    // Set the LED pin as an output
    DDRD |= (1 << LED_PIN);
    
    DDRB |= (1 << LED_PIN);

    while (1) {
        // Turn the LED on
        PORTD |= (1 << LED_PIN);
        PORTB |= (1 << LED_PIN2);
        _delay_ms(1000); // Wait for 1 second (1000 milliseconds)

        // Turn the LED off
        PORTD &= ~(1 << LED_PIN);
        _delay_ms(1000); // Wait for 1 second
        // Turn the LED off
        PORTB &= ~(1 << LED_PIN2);
        _delay_ms(2000); // Wait for 1 second
    }

    return 0;
}


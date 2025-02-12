#include <Arduino.h>
#include <avr_debugger.h>

#define LED1_PIN 0
#define LED2_PIN 1
#define LED3_PIN 2

void delay_ms(unsigned int ms)
{
    while (ms--)
    {
        _delay_ms(1);
    }
}

int main()
{
    #ifdef __DEBUG__
        dbg_start();
    #endif

    // Set LED pins to output
    DDRB |= (1 << LED1_PIN) | (1 << LED2_PIN) | (1 << LED3_PIN);  // Configuring PB0, PB1, PB2 as outputs

    while (1)
    {
        // Turn on LED1, delay, then turn it off
        PORTB |= (1 << LED1_PIN);   // Turn on LED1
        delay_ms(1000);             // 1 second delay

        // Turn on LED2, delay, then turn it off
        PORTB |= (1 << LED2_PIN);   // Turn on LED2
        delay_ms(1000);             // 1 second delay
        
        // Turn on LED3, delay, then turn it off
        PORTB |= (1 << LED3_PIN);   // Turn on LED3
        delay_ms(1000);             // 1 second delay
        
        PORTB &= ~(1 << LED1_PIN);  // Turn off LED1
        delay_ms(1000);             // 1 second delay
        PORTB &= ~(1 << LED2_PIN);  // Turn off LED2
        delay_ms(1000);             // 1 second delay
        PORTB &= ~(1 << LED3_PIN);  // Turn off LED3
        delay_ms(1000);             // 1 second delay
    }

    return 0;
}

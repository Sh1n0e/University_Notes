#include <Arduino.h>
#include <avr_debugger.h>

#define LED_PIN DDB0

int main()
{
  #ifdef __DEBUG__
    dbg_start();
  #endif

  DDRB |= (1 << LED_PIN);

  while(1)
  {
    PORTB ^= (1<< LED_PIN);
    _delay_ms(1000);
  }
}
#include <Arduino.h>
#include <avr_debugger.h>

#define BUZZER_PIN 5
#define BUTTON_PIN 1 //Defining buttons based on their pins

int main()
{
  #ifdef __DEBUG__
    dbg_start();
  #endif

  DDRD |= (1<< BUZZER_PIN); // Set PD5 to be the output
  DDRB &= ~(1<<BUTTON_PIN); // Set Button to input 
  PORTB |= (1<<BUTTON_PIN); 

  while(1)
  {
    if(!(PINB & (1<<BUTTON_PIN))) // If button is pressed
    {
      PORTD |= (1<<BUZZER_PIN); // Turn on buzzer
    }
    else // If button is not pressed
    {
      PORTD &= ~(1<<BUZZER_PIN); //turn off the buzzer 
    }
  }
}
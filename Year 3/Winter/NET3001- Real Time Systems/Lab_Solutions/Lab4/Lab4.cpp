#include <Arduino.h>
#include <avr_debugger.h>
#define ARRAY_SIZE 16
#define ARRAY_SIZE_DECIMAL 10
//did not use these but could be used if we want to use bit masking
#define PUSH_BUTTON 0 
#define SWITCH0 0
#define SWITCH1 1

int main()
{
  #ifdef __DEBUG__
    dbg_start();
  #endif
  //Hexadecimal digits value for 7-segment
  byte digits[ARRAY_SIZE] = {0xEE, 0x82, 0xDC, 0xD6, 0xB2, 0x76, 0x7E, 0xC2, 0xFE, 0xF6, 
  0xFA , 0xFE, 0x6C, 0xEE, 0x7C, 0x78 }; 
  
  DDRD = 0xFF; // Port D set to ouput all pins

  DDRB = 0x00; // In port b PIN0, 1, and 2 are input
  PORTB = 0x03; // set pull up for PINB0 and 1

  DDRC = 0x00; // set port C pins to input
  PORTC = 0x01; // set pull up for PINC5
  
  byte task = 0; 
  while(1)
  {
      if((PINC & 0x01))
      {
        task= PINB & 0x03;
        if (task == 0) // count up from 0 to F
        {
          byte i;
          for(i = 0 ; i<ARRAY_SIZE;i++)
          {
            PORTD = digits[i];
            _delay_ms(1000);
          }
          //reset PORTD to turn off the 7-segment
          PORTD &= 0x00;
        }else if(task == 1) //count down from F to 0
        {
          byte i;
          for(i = 0 ; i<ARRAY_SIZE;i++)
          {
            PORTD = digits[ARRAY_SIZE-(i+1)];
            _delay_ms(1000);
          }
          //reset PORTD to turn off the 7-segment
          PORTD &= 0x00;

        }else if(task == 2) // count up decimal
        {
          byte i;
          for(i = 0 ; i<ARRAY_SIZE_DECIMAL;i++)
          {
            PORTD = digits[i];
            _delay_ms(1000);
          }
          //reset PORTD to turn off the 7-segment
          PORTD &= 0x00;

        }else if(task == 3){ // count down decimal
          byte i;
          for(i = 0 ; i<ARRAY_SIZE_DECIMAL;i++)
          {
            PORTD = digits[ARRAY_SIZE_DECIMAL-(i+1)];
            _delay_ms(1000);
          }
          //reset PORTD to turn off the 7-segment
          PORTD &= 0x00;
        }
  
      }
      _delay_ms(500);
  }
}





#include <Arduino.h>
#include <avr_debugger.h>

extern "C"
{
  uint8_t average2(uint8_t,uint8_t);
  uint8_t division();
}

int main()
{

  #ifdef __DEBUG__
    dbg_start();
  #endif

  uint8_t result = average2(20, 40);
  result = division();
  while(1)
  {
    
  }

}
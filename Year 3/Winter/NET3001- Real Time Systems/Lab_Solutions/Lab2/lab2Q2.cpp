#include <Arduino.h>
#include <avr_debugger.h>

extern "C"
{
    byte average2(byte,byte); //function to calculate the average of two numbers
    void division();  // function to divide one number by another number
    void sum(byte);
}

int main()
{

  #ifdef __DEBUG__
    dbg_start();
  #endif
  Serial.begin(9600);
  byte result= average2(20,40);
  
  Serial.println(result);
  
  division();
  sum(5);

  while(1)
  {
   
  }

}
/********************************************************************
 * The LCD controller is connected to the Arduino Uno board based on 
 * the following details:
 *
 * PD4-PD7 for LCD D4-D7
 * PB1 for LCD R/S
 * PB0 for LCD EN
 *******************************************************************/

 #include <Arduino.h>
 #include <avr_debugger.h>
 
 // Defines Variables
 #define RS PB1 // Register Select is connected to PB0
 #define EN PB0 // Enable pin is connected to PB1
 
 #define D4 PD4 // D4 is connected to PD4
 #define D5 PD5 // D5 is connected to PD5
 #define D6 PD6 // D6 is connected to PD6
 #define D7 PD7 // D7 is connected to PD7
 
 // Function prototypes
 void LCD_init(void);
 void LCD_command(uint8_t command);
 void LCD_data(uint8_t data);
 void LCD_string(char *str);
 void displayBirthYear(int birthYear);
 void scrollText(void);
 
 int main()
 {
	 // Add at the beginning of each project to enable debugging
	 #ifdef __DEBUG__
		 dbg_start();
	 #endif
 
	 // Initialize LCD controller
	 LCD_init();
 
	 // Calling Birth Year function to display on Board
	 displayBirthYear(2003);  
 
	 // Scroll the text repeatedly
	 while (1)
	 {
		 scrollText();
	 }
 }
 
 // initialize ports and LCD controller
 void LCD_init(void)
 {
   DDRB |= (1 << RS) | (1 << EN); // set RS and EN pin to output 
   PORTB &= ~( 1 << EN);           // turn off EN 
   PORTD = 0xF0;
   DDRD |= 0xF0; // set pins for Port D to output 
 
   _delay_ms(40);   
   LCD_command(0x28); /* Initialization of 16X2 LCD in 4bit mode */
   LCD_command(0x0E); /* Display ON Cursor OFF */
   LCD_command(0x06); /* Auto Increment cursor */
   LCD_command(0x01); /* Clear display */
   LCD_command(0x14); // Shift cursor right
   LCD_command(0x80); /* Cursor at home position */
   _delay_ms(300);
 }
 
 // Send Commands to LCD
 void LCD_command(uint8_t command)
 {
   PORTB &= ~(1 << RS); /* RS = 0 */
   PORTD = (PORTD & 0x0F) | (command & 0xF0); /* put upper nibble of the command to PortD */
 
   PORTB |= (1 << EN);  /* Enable pulse*/
   _delay_us(1);
   PORTB &= ~(1 << EN); /* clear E */
   _delay_ms(2);
 
   PORTD = (PORTD & 0x0F) | (command << 4); /* put lower nibble of the command to PortD */
 
   PORTB |= (1 << EN);  /* Enable pulse*/
   _delay_us(1);
   PORTB &= ~(1 << EN); /* clear E */
   _delay_ms(2);
 }
 
 // Send Data to LCD
 void LCD_data(uint8_t data)
 {
   PORTB |= (1 << RS);  /* RS = 1 */
   PORTD = (PORTD & 0x0F) | (data & 0xF0);  /* put upper nibble of the data to PortD */
  
   PORTB |= (1 << EN);  /* Enable pulse */
   _delay_us(1);
   PORTB &= ~(1 << EN); /* clear E */
   _delay_ms(1);
 
   PORTD = (PORTD & 0x0F) | (data << 4);  /* put lower nibble of the data to PortD */
  
   PORTB |= (1 << EN);  /* Enable pulse */
   _delay_us(1);
   PORTB &= ~(1 << EN); /* clear E */
   _delay_ms(1);
 }
 
 // Send string to LCD
 void LCD_string(char *str)
 {
   byte i;
   for(i=0; str[i] !='\0'; i++)
   {
	 LCD_data(str[i]);
   }
 }
 
 // Creating function for birth year 
 void displayBirthYear(int birthYear){
   char birthYearStr[16];
   sprintf(birthYearStr, "Birth Year: %d", birthYear);
   LCD_string(birthYearStr);
 }
 
 // Scroll text to the right and then back from the left
 void scrollText(void)
 {
   // Shift the text to the left, making it scroll
   LCD_command(0x06); // Shift left
   _delay_ms(500);
 
   // Repeat the process of shifting to the left to create a scrolling effect
   // We will add a small delay so the shift happens gradually
   for (int i = 0; i < 16; i++)  // Move it by the full length of the screen
   {
	 _delay_ms(300);  // Slow down the scrolling speed for visibility
	 LCD_command(0x06);  // Shift text left
   }
   
   // Pause before repeating the scroll
   _delay_ms(1000);
 }
 
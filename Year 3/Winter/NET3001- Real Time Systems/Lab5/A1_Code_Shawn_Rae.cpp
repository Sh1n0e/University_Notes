#include <Arduino.h>
#include <avr_debugger.h>

// Define constants/macros for pins
#define DOORPINR (1 << PC1)  // Door Red LED
#define DOORPING (1 << PC2)  // Door Green LED 

#define FLOOR1 (1 << PC5)    // Floor 1 LED
#define FLOOR2 (1 << PB4)    // Floor 2 LED 
#define FLOOR3 (1 << PB3)    // Floor 3 LED 

#define BUTTON1 (1 << PC0)   // Floor 1 Button
#define BUTTON2 (1 << PB0)   // Floor 2 Button
#define BUTTON3 (1 << PB1)   // Floor 3 Button

// Array for 7-segment display digits
#define ARRAY_SIZE 10
const int digits[ARRAY_SIZE] = {0xEE, 0x82, 0xDC, 0xD6, 0xB2, 0x76, 0x7E, 0xC2, 0xFE, 0xF6};

// Function prototypes
void close_door();
void open_door();
void moveflr(int current_flr, int go_flr, const int *digits);

int main() {
  #ifdef __DEBUG__
    dbg_start();
  #endif

  int current_flr = 1; // Default set up will have the 7 segment counter to floor 1

  // Initialize ports
  DDRD = 0xFF; // PORTD is the output for 7 segment counter 
  DDRC |= FLOOR1 | DOORPINR | DOORPING; // PORTC as outputs for floor 1 button and LEDS connected to analog ports
  DDRB |= FLOOR2 | FLOOR3; // Set PORTB for floor 2 and floor 3
  PORTC |= DOORPINR; // Door is open on initial startups 

  // Set button pins for input with pull-ups
  DDRC &= ~BUTTON1;
  PORTC |= BUTTON1;
  DDRB &= ~(BUTTON2 | BUTTON3);
  PORTB |= (BUTTON2 | BUTTON3);

  // Initial state: Elevator on floor 1, door open
  PORTC |= FLOOR1; // Turn on floor 1 LED (A5)
  PORTD = digits[1]; // Display floor 1 on 7-segment

  while (1) {
    // Check for button presses
    if (!(PINC & BUTTON1)) {
      _delay_ms(50); // Delay
      if (!(PINC & BUTTON1) && current_flr != 1) {
        close_door();
        moveflr(current_flr, 1, digits);
        current_flr = 1;
        open_door();
      }
    }
    if (!(PINB & BUTTON2)) {
      _delay_ms(50);
      if (!(PINB & BUTTON2) && current_flr != 2) {
        close_door();
        moveflr(current_flr, 2, digits);
        current_flr = 2;
        open_door();
      }
    }
    if (!(PINB & BUTTON3)) {
      _delay_ms(50);
      if (!(PINB & BUTTON3) && current_flr != 3) {
        close_door();
        moveflr(current_flr, 3, digits);
        current_flr = 3;
        open_door();
      }
    }
  }
}

void close_door() {
  PORTC &= ~DOORPINR; // Turn off door open LED
  PORTC |= DOORPING;  // Turn on door close LED
  _delay_ms(1000); // Delay for 1 second
}

void open_door() {
  PORTC &= ~DOORPING; // Turn off door close LED
  PORTC |= DOORPINR;  // Turn on door open LED
  _delay_ms(1000); // Delay for 1 second
}

void moveflr(int current_flr, int go_flr, const int *digits) {
  int flrmovement = abs(current_flr - go_flr);
  int i;

  // Turn off current floor LED
  if (current_flr == 1) {
    PORTC &= ~FLOOR1;
  } else if (current_flr == 2) {
    PORTC &= ~FLOOR2;
  } else if (current_flr == 3) {
    PORTC &= ~FLOOR3;
  }

  // Simulate floor movement
  for (i = 1; i < 6; i++) {
    PORTD = digits[i]; // Count seconds on 7-segment
    _delay_ms(1000);
  }

  // Special case for a double floor move
  if (flrmovement == 2) {
    PORTD = digits[2]; // Display mid-floor (floor 2)
    _delay_ms(1000);
    for (i = 1; i < 6; i++) { // Counts again after displaying middle floor
      PORTD = digits[i];
      _delay_ms(1000);
    }
  }

  // Ensure correct floor LED is turned on
  if (go_flr == 1) {
    PORTC |= FLOOR1;
  } else if (go_flr == 2) {
    PORTC |= FLOOR2;
  } else if (go_flr == 3) {
    PORTC |= FLOOR3;
  }
  PORTD = digits[go_flr];
}

# Basic I/O in AVR and Arduino

## Introduction
- Peripherals (sensors, actuators, etc.) can be connected to an Arduino for input/output (I/O) operations.
- Arduino has both digital and analog I/O pins.
- This document focuses on **digital I/O**.

## GPIO in Arduino
- All **GPIO pins** have Read/Write capabilities.
- Each pin's direction can be set independently.
- Ports are labeled as **PORTX**, where X represents B, C, or D.

## Arduino Port Registers
- **PORTx** (x = B, C, D): Controls pin values.
- **DDRx**: Controls the direction (Input/Output) of the pins.
- **PINx**: Reads pin values.

### **Port Pin Configurations**
| DDRxn | PORTxn | PUD | Mode | Pull-up |
|--------|--------|-----|------|---------|
| 0 | 0 | x | Input | No |
| 0 | 1 | 0 | Input | Yes |
| 1 | 0 | x | Output | No |
| 1 | 1 | x | Output | No |

## Writing to a Pin
1. Set the pin as **output** (if necessary).
2. Configure **DDRx** for output.
3. Write **high/low** value to the pin by setting or clearing **PORTx**.

## GPIO as Output
- Can supply **40mA max**.
- Overcurrent can damage the Arduino.
- External resistors can limit current flow.

## GPIO as Input
- Inputs can be **floating** (unpredictable values) if left unconnected.
- **Pull-up resistors** ensure a defined state when no signal is present.

## Pull-up & Pull-down Resistors
- **Pull-up resistor** connects pin to **Vcc** (default HIGH state).
- **Pull-down resistor** connects pin to **GND** (default LOW state).

## Direct Setting vs `pinMode()`
```c
pinMode(8, OUTPUT); // Using Arduino function
DDRB |= (1<<0); // Direct setting
```

## LED Basics
- **Anode (positive terminal)** → Vcc.
- **Cathode (negative terminal)** → GND.
- Use resistors to prevent LED burnout.

## 7-Segment Displays
- **Common Cathode:** All cathodes are connected to GND.
- **Common Anode:** All anodes are connected to Vcc.
- Each LED segment is controlled separately.

## LCD 16x2 Display
- Displays characters on **two lines (16 characters each)**.
- **Pin 3:** Adjusts contrast.
- **Pin 4-6:** Control Register Select, Read/Write, and Enable.
- **Pin 7-14:** Data pins.
- Can be used in **4-bit mode** (reducing required pins).

## Conclusion
- Understanding **basic I/O** is crucial for microcontroller programming.
- Proper handling of GPIO, pull-up/down resistors, and external components is essential for reliable operation.

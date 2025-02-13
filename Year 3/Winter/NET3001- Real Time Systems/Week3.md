# AVR Assembly Language Summary

## Introduction to Assembly
- Assembly is a low-level programming language that serves as a human-readable abstraction of binary machine code.
- Assemblers translate assembly code into binary code that the CPU understands.
- Example: `ADD R1, R2, R3` → `1101 0010 0100 0011` (binary).

## Why Use Assembly?
- Optimized for speed and memory efficiency.
- Provides insight into hardware operation.
- Allows full utilization of a microcontroller’s features.

## Applications of Assembly
- Device drivers
- Low-level embedded systems
- Real-time systems
- Memory/speed-critical applications

## Comparison with C
- Both Assembly and C allow full access to microcontroller functions and registers.
- They have smaller memory footprints compared to Arduino IDE-based programs.
- Assembly provides finer control over hardware but requires a deeper understanding of CPU architecture.

## Assembly Programming Essentials
- **Operands:** Data used in operations must be in specific registers.
- **Instruction Classes:** Includes arithmetic, logic, branching, bit operations, data transfer, and control instructions.
- **Directives:** Special instructions that control program memory placement, macros, and initialization.

## CPU Operations
- Fetches instructions from memory.
- Loads data into registers.
- Executes commands.

## Registers & Memory
- Registers (`R0-R31`) store values for operations.
- **Status Register (SREG):** Contains flags like Zero (Z), Carry (C), and Overflow (V).
- Special function registers control I/O and peripherals.

## Function Calls & Stack Management
- Function parameters and return values are stored in specific registers.
- The stack is used for temporary data storage and function return addresses.

## Arduino Assembly Setup
- In **VSCode**, `.S` files contain assembly code, integrated with C++ using `extern "C"`.
- Example: A blink program in AVR Assembly.

## Performance Comparison
| Programming Language | Binary Size (Bytes) | Speed (kHz) |
|----------------------|--------------------|------------|
| Arduino IDE         | 847                | 121        |
| C                  | 472                | 2667       |
| Assembly           | 472                | 4002       |

## Conclusion
- Assembly offers superior speed and efficiency at the cost of complexity.
- It is useful for real-time and embedded systems where performance is critical.
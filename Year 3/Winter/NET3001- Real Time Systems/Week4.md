### C vs Embedded C
- **Similar Constructs**: Both use similar constructs like conditionals and loops.
- **Main Differences**:
  - **Context and Applications**: Embedded C is used in environments with limited memory and time constraints.
  - **Libraries**: Embedded C uses specialized libraries for specific hardware.
  - **Compilers**: Embedded C compilers generate executables for microcontrollers, while C compilers generate executables for specific operating systems.

### Embedded Programming Languages
- **Requirements**: Must produce compact and efficient code, allow access to peripherals, and have close ties to hardware.
- **Languages**: Commonly used languages include Assembly, C, C++, C#, Ada, and Java.

### Inline Assembly in C
- **Usage**: Inline assembly can be used within C programs for low-level hardware manipulation.

### C Basics - Variables
- **Storage Duration**: Automatic (block scope) and Static (program duration).
- **Scope**: Block/local and File/global.
- **Linkages**: No linkage, Internal linkage, and External linkage.

### C Basics – Control Structures
- **Conditional Execution**: `if`, `if-else`, `switch-case`.
- **Iterative Execution**: `while`, `do-while`, `for`.

### C Basics – Functions/Subroutines
- **Advantages**: Modular design, code reuse.
- **Components**: Function declaration, definition, call, and parameter passing (by value, pointer, reference).

### Pointers
- **Definition**: Variables that store memory addresses.
- **Symbols**: `&` (address operator), `*` (pointer type-modifier and indirection operator).

### Bitwise Operators
- **Operators**: OR (`|`), AND (`&`), NOT (`~`), XOR (`^`), Shift left (`<<`), Shift right (`>>`).
- **Usage**: Creating masks to set, clear, or test bits.

### Examples
- **Setting Pins**: Methods to set pins as output or high/low using bit masks, binary values, and hex values.
- **Blink Example**: Basic Arduino program to blink an LED using bitwise operations.

### Extracting and Monitoring Bits
- **Extracting Bits**: Techniques to extract high and low 8-bits from a 16-bit value.
- **Monitoring Bits**: Checking if a specific bit is set.
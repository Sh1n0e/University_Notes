### Liquid Crystal Display (LCD)
- **Usage**: Common in embedded systems to display status and parameters.
- **LCD16x2**: 
  - 2 lines with 16 characters each.
  - Each character is a 5x8 pixel matrix.
- **Pin Description**:
  - **VEE**: Adjusts contrast.
  - **RS**: Register select (0 for command, 1 for data).
  - **RW**: Read/write (0 to write, 1 to read).
  - **E**: Enable (latches data).
  - **Data Pins (D0-D7)**: Send data/commands.
  - **LED Pins**: Backlight.

### Serial Communications
- **Definition**: Communication between devices one bit at a time.
- **Advantages**: Uses fewer pins compared to parallel communication.
- **Types**:
  - **RS232**: Peer-to-peer.
  - **RS485**: Multi-point.
  - **USB**: Universal Serial Bus.
  - **SPI**: Serial Peripheral Interface.
  - **I2C**: Inter-Integrated Circuit.

### Serial vs Parallel Communication
- **Serial**: One bit at a time, fewer wires, less data skew, better noise immunity.
- **Parallel**: One byte/word at a time, more wires, potential data skew, simpler design.

### USART (Universal Synchronous/Asynchronous Receiver/Transmitter)
- **Function**: Interface between microprocessor and serial port.
- **Operation**:
  - Breaks data into bits for transmission.
  - Converts received bits into bytes.
- **Requirements**:
  - Start/stop bits.
  - Parity bit.
  - Pre-defined timing.
  - Frame size.

### USART in Arduino Uno
- **Configuration Options**:
  - **Start Bits**: 1.
  - **Stop Bits**: 1 or 2.
  - **Parity**: Even, odd, or none.
  - **Character Sizes**: 5 to 9 bits.

### USART Frames
- **Components**:
  - **Start Bit**: Always low.
  - **Parity Bit**: Even, odd, or none.
  - **Stop Bit**: Always high.
  - **Idle**: No transfer, always high.

### Example Code
- **Initialization**:
  ```c
  #define BAUD_RATE 0x0067 // 9600 Baud rate
  void USART_init(void) {
      UBRR0 = BAUD_RATE; // Set baud rate
      UCSR0C = ((0<<USBS0) | (1<<UCSZ01) | (1<<UCSZ00)); // Frame format: 8 data, 1 stop bit
      UCSR0B = ((1<<RXEN0) | (1<<TXEN0)); // Enable receiver and transmitter
  }
  ```
- **Sending Data**:
  ```c
  void USART_send(unsigned char data) {
      while(!(UCSR0A & (1<<UDRE0))); // Wait for buffer to be empty
      UDR0 = data; // Transmit data
  }
  ```
- **Receiving Data**:
  ```c
  unsigned char USART_receive(void) {
      while(!(UCSR0A & (1<<RXC0))); // Wait for data
      return UDR0; // Return received data
  }
  ```
# Raspberry Pi GPIO LED Control Project

## Project Overview

This project involves controlling an LED connected to a Raspberry Pi 1 without an operating system (bare metal programming). The LED state (on/off) will be displayed through a simple HTTP web server running on the Raspberry Pi's Ethernet interface.

## Requirements

### Hardware Requirements

- Raspberry Pi 1 Model B
- LED
- Resistor (220-330 Ohm) for the LED
- Ethernet cable
- Power supply for Raspberry Pi
- Optional: UART to USB converter for debugging

### Software Requirements

- ARM cross-compiler toolchain (arm-none-eabi)
- Make build system
- Optional: TFTP server for network booting
- Optional: Serial console software (e.g., PuTTY, screen)

## Technical Specifications

### LED Control

- The LED will be connected to GPIO 0
- The LED will blink at regular intervals (configurable)
- The GPIO pin will be programmed using direct register manipulation without an OS

### Web Server

- Basic HTTP server implementation in C
- Ethernet communication using direct register access to the Raspberry Pi's Ethernet controller
- Simple HTTP response that shows the current LED state
- No complex HTTP features required (basic GET request handling is sufficient)

## Project Structure

```plaintext
Makefile            # Build configuration
README.md           # Project documentation (this file)
src/
  gpio.c            # GPIO manipulation functions
  gpio.h            # GPIO header definitions
  linker.ld         # Memory layout for the Raspberry Pi
  main.c            # Main program logic
  startup.s         # Initialization assembly code
  network.c         # Ethernet and networking code (to be implemented)
  network.h         # Network header definitions (to be implemented)
  webserver.c       # HTTP server implementation (to be implemented)
  webserver.h       # Web server header definitions (to be implemented)
```

## Development Environment Setup

### Cross-Compiler Setup

1. Install the ARM cross-compiler:
   - On Windows:
   
     ```bash
     # Download and install ARM GCC from https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
     # Add the bin directory to your PATH
     ```
   
   - On Linux:
   
     ```bash
     sudo apt-get install gcc-arm-none-eabi
     ```

2. Verify the installation:
   
   ```bash
   arm-none-eabi-gcc --version
   ```

### Build System Setup

1. Install Make:
   - On Windows: Install Make from GnuWin32 or use the one included with MinGW/MSYS2
   - On Linux: `sudo apt-get install make`

2. Verify the installation:
   ```
   make --version
   ```

### Serial Console (Optional for Debugging)

1. Connect a UART to USB converter:
   - GND to GND
   - RX to GPIO 14 (TXD)
   - TX to GPIO 15 (RXD)

2. Configure serial console software:
   - Baud rate: 115200
   - Data bits: 8
   - Stop bits: 1
   - Parity: None
   - Flow control: None

## Implementation Guidelines

### GPIO Implementation

1. Configure GPIO 0 as an output pin
2. Implement functions to toggle the LED on and off
3. Create a timing mechanism for blinking (could be a simple delay loop)

### Ethernet Controller

1. Initialize the Ethernet controller
2. Configure MAC and IP addresses
3. Implement basic Ethernet frame handling
4. Implement ARP to resolve MAC addresses

### Network Stack

1. Implement basic IPv4 packet handling
2. Implement simple UDP/IP stack
3. Implement minimal TCP/IP for HTTP connections

### HTTP Server

1. Listen for incoming TCP connections on port 80
2. Parse HTTP GET requests
3. Generate HTTP responses with the LED status
4. Format: Simple HTML page showing "LED ON" or "LED OFF"

## Building and Running

### Building the Project

```bash
make clean
make
```

This will generate a kernel.img file that can be loaded onto the Raspberry Pi.

### Loading onto the Raspberry Pi

Method 1: SD Card

1. Format an SD card as FAT32
2. Copy bootloader files (bootcode.bin, start.elf) from Raspberry Pi firmware repository
3. Copy the compiled kernel.img to the SD card
4. Insert the SD card into the Raspberry Pi and power it on

Method 2: Network Boot (if supported by your Pi model)

1. Set up a TFTP server
2. Configure the Raspberry Pi for network booting
3. Place kernel.img in the TFTP server directory

## Testing

1. Connect the Raspberry Pi to power and Ethernet
2. The LED should start blinking
3. Determine the IP address of the Raspberry Pi (through DHCP logs or static IP configuration)
4. Open a web browser and navigate to the Pi's IP address
5. Verify that the web page displays the current LED state

## Debugging

1. Use serial console output for debugging messages
2. Add status LEDs if additional GPIO pins are available
3. Use Ethernet packet sniffing tools like Wireshark to debug network communication

## Resources

- [Raspberry Pi Hardware Documentation](https://www.raspberrypi.org/documentation/hardware/raspberrypi/)
- [ARM Architecture Reference Manual](https://developer.arm.com/documentation/ddi0406/latest/)
- [BCM2835 Datasheet (Raspberry Pi 1 SoC)](https://www.raspberrypi.org/app/uploads/2012/02/BCM2835-ARM-Peripherals.pdf)
- [Bare Metal Raspberry Pi Programming Guide](https://github.com/dwelch67/raspberrypi)

## Next Steps

1. Implement the network.c and network.h files for Ethernet communication
2. Develop the webserver.c and webserver.h files for HTTP handling
3. Integrate the web server with the LED control logic
4. Test and debug the complete system
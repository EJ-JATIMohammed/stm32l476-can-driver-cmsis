# STM32L476RG CAN Driver using CMSIS

A bare-metal Controller Area Network (CAN) driver implementation for the STM32L476RG microcontroller using the Cortex Microcontroller Software Interface Standard (CMSIS). This project provides a complete CAN communication stack with a practical application example.

## Project Overview

This embedded systems project demonstrates a professional-grade CAN driver implementation tailored for the STM32L476RG. The driver provides:

- **Direct hardware control** via CMSIS without external dependencies
- **Configurable CAN communication** with support for standard and extended frames
- **Message filtering** for selective frame reception
- **Interrupt-driven receive handling** with dual FIFO support
- **Transmission and reception** of CAN messages
- **LED feedback** for application status indication

## STM32L476RG Microcontroller

The STM32L476RG is an ultra-low-power 32-bit ARM Cortex-M4 microcontroller with:

- **Processor**: ARM Cortex-M4 @ 80 MHz
- **Memory**: 128 KB RAM, 1 MB Flash
- **Peripherals**: 
  - CAN 2.0B interface (CAN1)
  - GPIO ports with flexible multiplexing
  - Interrupt controller (NVIC)
- **Package**: LQFP100

## CAN Driver Architecture

The CAN driver (`can_driver`) provides the following components:

### Header Files (`can_driver/Inc`)
- Function declarations and type definitions
- CAN configuration structures
- Hardware abstraction layer interfaces

### Source Files (`can_driver/Src`)
- CAN controller initialization and configuration
- GPIO pin multiplexing setup
- Filter configuration for selective message reception
- Transmit and receive message handling
- Interrupt service routine support

### Key Features

**CAN Initialization**: Configure bitrate timing parameters (prescaler, phase segments, SJW)

**GPIO Configuration**: Pin multiplexing for CAN TX/RX (e.g., PB8/PB9)

**Message Filtering**: 32-bit and 16-bit filter modes for frame ID filtering

**Transmission**: Queue and send CAN messages with standard or extended identifiers

**Reception**: Retrieve received messages from FIFO with full frame metadata

**Loopback & Silent Modes**: Support for testing configurations

## CMSIS Integration

This project uses CMSIS (Cortex Microcontroller Software Interface Standard) for:

- **Direct register access** via `stm32l4xx.h` header
- **CMSIS core functions** for interrupt management and system control
- **Hardware register definitions** for CAN, GPIO, and RCC (Reset and Clock Control)
- **Portability** across STM32L4 series microcontrollers

## Simple Application in main.c

The application layer (`application/main.c`) demonstrates:

**LED Initialization**: Configure GPIO for LED status output

**CAN Configuration**:
- Initialize CAN1 peripheral with specific timing parameters
- Configure GPIO pins PB8/PB9 for CAN TX/RX
- Set loopback mode for testing without external CAN bus

**Message Filtering**: Set up 32-bit ID filter to accept specific CAN message IDs

**CAN Transmission**: Send test messages containing ASCII data ('M','O','H','A','M','M','E','D')

**Reception Handling**: Process received messages via interrupt handlers (`CAN1_RX0_IRQHandler`, `CAN1_RX1_IRQHandler`)

**Application Modes**:
- **Version 1**: 32-bit filter with LOOPBACK enabled (included)
- **Version 2**: 16-bit filter configuration (commented reference example)

## Project Structure

```
stm32l476-can-driver-cmsis/
├── README.md                      # Project documentation
├── can_driver/                    # CAN driver module
│   ├── Inc/                       # Header files
│   └── Src/                       # Implementation files
└── application/                   # Application layer
    └── main.c                     # Main application with CAN usage example
```

## Development Environment

**Recommended Setup**:
- **Toolchain**: ARM GCC (arm-none-eabi-gcc)
- **IDE**: STM32CubeIDE or similar
- **Debugger**: ST-Link v2 or compatible
- **Build System**: Makefile or IDE project configuration

**Required Tools**:
- STM32L476RG development board
- USB ST-Link debugger
- CAN bus analyzer (optional, for non-loopback testing)

## Build and Usage Instructions

### Compilation

1. Set up the ARM GCC toolchain environment
2. Ensure CMSIS header files are accessible for STM32L476RG
3. Include the driver source files in your project:
   - `can_driver/Src/*.c`
   - `application/main.c`
4. Compile:
   ```bash
   arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -O2 \
     -Ican_driver/Inc \
     -o firmware.elf \
     can_driver/Src/*.c application/main.c
   ```

### Flashing

5. Connect ST-Link debugger to the development board
6. Flash using:
   ```bash
   st-flash write firmware.elf 0x08000000
   ```

### Testing

7. Power on the microcontroller
8. Observe LED feedback on message transmission/reception
9. Use a CAN analyzer to verify message traffic (when not in loopback mode)

## Features

- ✅ Bare-metal CAN driver without HAL dependency
- ✅ CMSIS-based hardware abstraction
- ✅ Dual FIFO receive with interrupt support
- ✅ Configurable message ID filtering
- ✅ Extended and standard frame support
- ✅ Loopback and silent operational modes
- ✅ GPIO pin multiplexing for CAN interface
- ✅ LED status feedback mechanism
- ✅ Complete application example
- ✅ STM32L476RG optimized implementation

## License

This project is provided as part of an embedded systems portfolio.

## Author

**EJ-JATIMohammed**  
Project: STM32L476RG CAN Driver using CMSIS

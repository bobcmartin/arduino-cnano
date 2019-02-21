/*
  pins_arduino.h - Pin definition functions 
 
*/
#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include <avr/pgmspace.h>
#include "timers.h"

#define NUM_DIGITAL_PINS            38
#define NUM_ANALOG_INPUTS           8
//#define NUM_RESERVED_PINS           2  // (TOSC1/2)
//#define NUM_INTERNALLY_USED_PINS    10 // (2 x Chip select + 2 x UART + 4 x IO + LED_BUILTIN + 1 BUTTON_BUILTIN)
//#define NUM_I2C_PINS                2  // (SDA / SCL)
//#define NUM_SPI_PINS                3  // (MISO / MOSI / SCK)
//#define NUM_TOTAL_FREE_PINS         (NUM_DIGITAL_PINS)
//#define NUM_TOTAL_PINS              (NUM_DIGITAL_PINS + NUM_RESERVED_PINS + NUM_INTERNALLY_USED_PINS + NUM_I2C_PINS + NUM_SPI_PINS)
//#define ANALOG_INPUT_OFFSET         14
//#define digitalPinToAnalogInput(p)  ((p < NUM_ANALOG_INPUTS) ? (p) : (p) - ANALOG_INPUT_OFFSET)

#define EXTERNAL_NUM_INTERRUPTS     48

#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 5 || (p) == 6 || (p) == 9 || (p) == 10)

#define SPI_MUX		  	(PORTMUX_SPI0_DEFAULT_gc)
#define PIN_SPI_MISO	(4)
#define PIN_SPI_SCK		(6)
#define PIN_SPI_MOSI	(5)
#define PIN_SPI_SS		(7)

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define PIN_WIRE_SDA        (2)
#define PIN_WIRE_SCL        (3)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

// This UART is connected to the on-board debugger for USB CDC serial port.
// The UART pins are also available on the board pins.
// USART3 on mega4809 (alternative pins)
// Mapped to HWSERIAL0 in Serial library
#define HWSERIAL0 (&USART3)
#define HWSERIAL0_DRE_VECTOR (USART3_DRE_vect)
#define HWSERIAL0_DRE_VECTOR_NUM (USART3_DRE_vect_num)
#define HWSERIAL0_RXC_VECTOR (USART3_RXC_vect)
#define HWSERIAL0_MUX (PORTMUX_USART3_DEFAULT_gc)
#define PIN_WIRE_HWSERIAL0_RX (9) // PB1
#define PIN_WIRE_HWSERIAL0_TX (8) // PB0

// Main USART available on board pins
// USART0 on mega4809 (alternative pins)
// Mapped to HWSERIAL1 in Serial library
#define HWSERIAL1 (&USART0)
#define HWSERIAL1_DRE_VECTOR (USART0_DRE_vect)
#define HWSERIAL1_DRE_VECTOR_NUM (USART0_DRE_vect_num)
#define HWSERIAL1_RXC_VECTOR (USART0_RXC_vect)
#define HWSERIAL1_MUX (PORTMUX_USART0_DEFAULT_gc)
#define PIN_WIRE_HWSERIAL1_RX (1) // PA1
#define PIN_WIRE_HWSERIAL1_TX (0) // PA0

#ifdef CNANO_UART_SPARE
// Spare USART available on header pins.
// USART1 on mega4809 (alternative pins)
// Mapped to HWSERIAL2 in Serial library
#define HWSERIAL2 (&USART1)
#define HWSERIAL2_DRE_VECTOR (USART1_DRE_vect)
#define HWSERIAL2_DRE_VECTOR_NUM (USART1_DRE_vect_num)
#define HWSERIAL2_RXC_VECTOR (USART1_RXC_vect)
#define HWSERIAL2_MUX		  (PORTMUX_USART1_DEFAULT_gc)
#define PIN_WIRE_HWSERIAL2_RX (15) // PC1
#define PIN_WIRE_HWSERIAL2_TX (14) // PC0
#endif


// Not used because the crystal is connecte to these pins
#define HWSERIAL3_MUX (PORTMUX_USART2_NONE_gc)

#define TWI_MUX		  (PORTMUX_TWI0_DEFAULT_gc)

#define MUX_SPI			(SPI_MUX)
#define SPI_INTERFACES_COUNT	1

#define LED_BUILTIN 37
#define BUTTON_BUILTIN 38

#define PIN_A0   (22)
#define PIN_A1   (23)
#define PIN_A2   (24)
#define PIN_A3   (25)
#define PIN_A4   (26)
#define PIN_A5   (27)
#define PIN_A6   (28)
#define PIN_A7   (29)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
static const uint8_t A6 = PIN_A6;
static const uint8_t A7 = PIN_A7;

#define PINS_COUNT		(40u)

#ifdef ARDUINO_MAIN

// On the Arduino board, digital pins are also used
// for the analog output (software PWM).  Analog input
// pins are a separate set.

// ATMEGA4809 / ARDUINO
//
//                     (SCL)(SDA) (7)  (2)                 (R)  (3~) (6~)
//                 PA4  PA3  PA2  PA1  PA0  GND  VDD  UPDI PF6  PF5  PF4  PF3
//
//                  48   47   46   45   44   43   42   41   40   39   38   37
//              + ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ +
//        PA5   1|                                                             |36  PF2
//        PA6   2|                                                             |35  PF1 (TOSC2)
//        PA7   3|                                                             |34  PF0 (TOSC1)
//   (9~) PB0   4|                                                             |33  PE3 (8)
//  (10~) PB1   5|                                                             |32  PE2 (13)
//   (5~) PB2   6|                                                             |31  PE1 (12)
//        PB3   7|                          48pin QFN                          |30  PE0 (11~)
//   (Tx) PB4   8|                                                             |29  GND
//   (Rx) PB5   9|                                                             |28  AVDD
//        PC0  10|                                                             |27  PD7 (VREF)
//        PC1  11|                                                             |26  PD6
//        PC2  12|                                                             |25  PD5 (A5)
//               + ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ +
//                  13   14   15   16   17   18   19   20   21   22   23   24
//
//                  PC3  VDD  GND  PC4  PC5  PC6  PC7  PD0  PD1  PD2  PD3  PD4
//                                 (1)  (0)  (4)       (A0) (A1) (A2) (A3) (A4)

//
const uint8_t PROGMEM digital_pin_to_port[] = {
	PA, // 0  PA0 / USART0 TX
	PA, // 1  PA1 / USART0 RX
	PA, // 2  PA2 / TWI_SDA
	PA, // 3  PA3 / TWI_SCL
	PA, // 4  PA4 / SPI0 MISO
	PA, // 5  PA5 / SPI0 MOSI
	PA,	// 6  PA6 / SPI0 SCK
	PA,	// 7  PA7 / SPI0 SS
	
	PB, // 8  PB0 / debugger USART TX
	PB, // 9  PB1 / debugger USART RX
	PB, // 10 PB2
	PB,	// 11 PB3
	PB, // 12 PB4
	PB, // 13 PB5

	PC,	// 14 PC0 / spare USART TX
	PC,	// 15 PC1 / spare USART RX
	PC,	// 16 PC2
	PC, // 17 PC3
	PC, // 18 PC4
	PC, // 19 PC5
	PC, // 20 PC6
	PC,	// 21 PC7

	PD, // 22 PD0 / AI0
	PD, // 23 PD1 / AI1
	PD, // 24 PD2 / AI2
	PD, // 25 PD3 / AI3
	PD, // 26 PD4 / AI4
	PD, // 27 PD5 / AI5
	PD, // 28 PD6 / AI6
	PD,	// 29 PD7 / AI7

	PE, // 30 PE0
	PE, // 31 PE1
	PE, // 32 PE2
	PE, // 33 PE3

	PF,	// 34 PF2
	PF,	// 35 PF3
	PF, // 36 PF4

	PF, // 37 PF5 / LED
	PF,	// 38 PF6 / BUTTON as GPIO or RESET
	PF,	// 39 PF0 / TOSC 1
	PF,	// 40 PF1 / TOSC 2
};

/* Use this for accessing PINnCTRL register */
const uint8_t PROGMEM digital_pin_to_bit_position[] = {
	PIN0_bp,	// 0  PA0 / USART0 TX
	PIN1_bp,	// 1  PA1 / USART0 RX
	PIN2_bp,	// 2  PA2 / TWI_SDA
	PIN3_bp,	// 3  PA3 / TWI_SCL
	PIN4_bp,	// 4  PA4 / SPI0 MISO
	PIN5_bp,	// 5  PA5 / SPI0 MOSI
	PIN6_bp,	// 6  PA6 / SPI0 SCK
	PIN7_bp,	// 7  PA7 / SPI0 SS
	PIN0_bp,	// 8  PB0 / debugger USART TX
	PIN1_bp,	// 9  PB1 / debugger USART RX
	PIN2_bp,	// 10 PB2
	PIN3_bp,	// 11 PB3
	PIN4_bp,	// 12 PB4
	PIN5_bp,	// 13 PB5
	PIN0_bp,	// 14 PC0 / spare USART TX
	PIN1_bp,	// 15 PC1 / spare USART RX
	PIN2_bp,	// 16 PC2
	PIN3_bp,	// 17 PC3
	PIN4_bp,	// 18 PC4
	PIN5_bp,	// 19 PC5
	PIN6_bp,	// 20 PC6
	PIN7_bp,	// 21 PC7
	PIN0_bp,	// 22 PD0 / AI0
	PIN1_bp,	// 23 PD1 / AI1
	PIN2_bp,	// 24 PD2 / AI2
	PIN3_bp,	// 25 PD3 / AI3
	PIN4_bp,	// 26 PD4 / AI4
	PIN5_bp,	// 27 PD5 / AI5
	PIN6_bp,	// 28 PD6 / AI6
	PIN7_bp,	// 29 PD7 / AI7
	PIN0_bp,	// 30 PE0
	PIN1_bp,	// 31 PE1
	PIN2_bp,	// 32 PE2
	PIN3_bp,	// 33 PE3
	PIN2_bp,	// 34 PF2
	PIN3_bp,	// 35 PF3
	PIN4_bp,	// 36 PF4
	PIN5_bp,	// 37 PF5 / LED
	PIN6_bp,	// 38 PF6 / BUTTON as GPIO or RESET
	PIN0_bp,	// 39 PF0 / TOSC 1
	PIN1_bp 	// 40 PF1 / TOSC 2
};

/* Use this for accessing PINnCTRL register */
const uint8_t PROGMEM digital_pin_to_bit_mask[] = {
	PIN0_bm,	// 0  PA0 / USART0 TX
	PIN1_bm,	// 1  PA1 / USART0 RX
	PIN2_bm,	// 2  PA2 / TWI_SDA
	PIN3_bm,	// 3  PA3 / TWI_SCL
	PIN4_bm,	// 4  PA4 / SPI0 MISO
	PIN5_bm,	// 5  PA5 / SPI0 MOSI
	PIN6_bm,	// 6  PA6 / SPI0 SCK
	PIN7_bm,	// 7  PA7 / SPI0 SS
	PIN0_bm,	// 8  PB0 / debugger USART TX
	PIN1_bm,	// 9  PB1 / debugger USART RX
	PIN2_bm,	// 10 PB2
	PIN3_bm,	// 11 PB3
	PIN4_bm,	// 12 PB4
	PIN5_bm,	// 13 PB5
	PIN0_bm,	// 14 PC0 / spare USART TX
	PIN1_bm,	// 15 PC1 / spare USART RX
	PIN2_bm,	// 16 PC2
	PIN3_bm,	// 17 PC3
	PIN4_bm,	// 18 PC4
	PIN5_bm,	// 19 PC5
	PIN6_bm,	// 20 PC6
	PIN7_bm,	// 21 PC7
	PIN0_bm,	// 22 PD0 / AI0
	PIN1_bm,	// 23 PD1 / AI1
	PIN2_bm,	// 24 PD2 / AI2
	PIN3_bm,	// 25 PD3 / AI3
	PIN4_bm,	// 26 PD4 / AI4
	PIN5_bm,	// 27 PD5 / AI5
	PIN6_bm,	// 28 PD6 / AI6
	PIN7_bm,	// 29 PD7 / AI7
	PIN0_bm,	// 30 PE0
	PIN1_bm,	// 31 PE1
	PIN2_bm,	// 32 PE2
	PIN3_bm,	// 33 PE3
	PIN2_bm,	// 34 PF2
	PIN3_bm,	// 35 PF3
	PIN4_bm,	// 36 PF4
	PIN5_bm,	// 37 PF5 / LED
	PIN6_bm,	// 38 PF6 / BUTTON as GPIO or RESET
	PIN0_bm,	// 39 PF0 / TOSC 1
	PIN1_bm 	// 40 PF1 / TOSC 2
};

const uint8_t PROGMEM digital_pin_to_timer[] = {
	NOT_ON_TIMER,	// 0  PA0 / USART0 TX
	NOT_ON_TIMER,	// 1  PA1 / USART0 RX
	NOT_ON_TIMER,	// 2  PA2 / TWI_SDA
	NOT_ON_TIMER,   // 3  PA3 / TWI_SCL
	NOT_ON_TIMER,	// 4  PA4 / SPI0 MISO
	NOT_ON_TIMER,   // 5  PA5 / SPI0 MOSI
	NOT_ON_TIMER,   // 6  PA6 / SPI0 SCK
	NOT_ON_TIMER,	// 7  PA7 / SPI0 SS
	TIMERA0,	    // 8  PB0 / debugger USART TX
	TIMERA0,		// 9  PB1 / debugger USART RX
	TIMERA0,		// 10 PB2
	NOT_ON_TIMER,	// 11 PB3
	NOT_ON_TIMER,	// 12 PB4
	NOT_ON_TIMER,	// 13 PB5
	NOT_ON_TIMER,	// 14 PC0 / spare USART TX
	NOT_ON_TIMER,	// 15 PC1 / spare USART RX
	NOT_ON_TIMER,	// 16 PC2
	NOT_ON_TIMER,	// 17 PC3
	NOT_ON_TIMER,	// 18 PC4
	NOT_ON_TIMER,	// 19 PC5
	NOT_ON_TIMER,	// 20 PC6
	NOT_ON_TIMER,	// 21 PC7
	NOT_ON_TIMER,	// 22 PD0 / AI0
	NOT_ON_TIMER,	// 23 PD1 / AI1
	NOT_ON_TIMER,	// 24 PD2 / AI2
	NOT_ON_TIMER,	// 25 PD3 / AI3
	NOT_ON_TIMER,	// 26 PD4 / AI4
	NOT_ON_TIMER,	// 27 PD5 / AI5
	NOT_ON_TIMER,	// 28 PD6 / AI6
	NOT_ON_TIMER,	// 29 PD7 / AI7
	TIMERB2,	    // 30 PE0
	NOT_ON_TIMER,	// 31 PE1
	NOT_ON_TIMER,	// 32 PE2
	NOT_ON_TIMER,	// 33 PE3
	NOT_ON_TIMER,	// 34 PF2
	NOT_ON_TIMER,	// 35 PF3
	TIMERB0,	    // 36 PF4
	TIMERB1,	    // 37 PF5 / LED
	NOT_ON_TIMER,	// 38 PF6 / BUTTON as GPIO or RESET
	NOT_ON_TIMER,	// 39 PF0 / TOSC 1
	NOT_ON_TIMER,	// 40 PF1 / TOSC 2
};


#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR			Serial
#define SERIAL_PORT_HARDWARE		Serial1
#define SERIAL_PORT_USBVIRTUAL		Serial
#define SERIAL_PORT_HARDWARE_OPEN	Serial2

#endif

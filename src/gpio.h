#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// BCM2835 GPIO base address for Raspberry Pi 1
#define GPIO_BASE       0x20200000

// GPIO function select registers
#define GPFSEL0         0x00
#define GPFSEL1         0x04

// GPIO pin output set registers
#define GPSET0          0x1C

// GPIO pin output clear registers
#define GPCLR0          0x28

// GPIO pin level registers
#define GPLEV0          0x34

// GPIO pin definitions
#define GPIO_PIN_0      0  // Pin for LED control

// Function prototypes
void gpio_init(void);
void gpio_set_output(unsigned int pin);
void gpio_set_pin(unsigned int pin);
void gpio_clear_pin(unsigned int pin);
void gpio_toggle_pin(unsigned int pin);
unsigned int gpio_read_pin(unsigned int pin);
void delay_ms(uint32_t milliseconds);

#endif /* GPIO_H */
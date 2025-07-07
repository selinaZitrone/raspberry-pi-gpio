#include "gpio.h"

// Volatile pointer to GPIO peripheral
volatile uint32_t* gpio = (uint32_t*)GPIO_BASE;

// Initialize GPIO
void gpio_init(void) {
    // No specific initialization needed for GPIO peripheral
    // Just ensure our LED pin is configured as output
    gpio_set_output(GPIO_PIN_0);
}

// Set a GPIO pin as output
void gpio_set_output(unsigned int pin) {
    // Calculate which GPFSEL register to use (0-5)
    int reg = pin / 10;
    
    // Calculate which bits in the register correspond to our pin
    int shift = (pin % 10) * 3;
    
    // Clear the three bits corresponding to our pin
    gpio[reg] &= ~(7 << shift);
    
    // Set the bits to 001 for output
    gpio[reg] |= (1 << shift);
}

// Set GPIO pin high
void gpio_set_pin(unsigned int pin) {
    // Using GPSET register to set the pin high
    // Each bit in GPSET corresponds to a pin
    gpio[GPSET0/4] = 1 << pin;
}

// Set GPIO pin low
void gpio_clear_pin(unsigned int pin) {
    // Using GPCLR register to set the pin low
    // Each bit in GPCLR corresponds to a pin
    gpio[GPCLR0/4] = 1 << pin;
}

// Toggle GPIO pin state
void gpio_toggle_pin(unsigned int pin) {
    if (gpio_read_pin(pin)) {
        gpio_clear_pin(pin);
    } else {
        gpio_set_pin(pin);
    }
}

// Read GPIO pin state
unsigned int gpio_read_pin(unsigned int pin) {
    // Return 1 if pin is high, 0 if low
    return (gpio[GPLEV0/4] & (1 << pin)) ? 1 : 0;
}

// Simple delay function using a counter loop
void delay_ms(uint32_t milliseconds) {
    // This is a crude delay and not accurate
    // For a more accurate delay, a timer peripheral should be used
    volatile uint32_t i, j;
    for (i = 0; i < milliseconds; i++) {
        for (j = 0; j < 5000; j++) {
            // This empty loop will create a delay
            // The exact timing depends on the CPU speed
            // You may need to adjust the 5000 value for your specific Pi
        }
    }
}
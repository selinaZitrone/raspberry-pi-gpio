raspberry-pi-gpio
├── src
│   ├── main.c          // Entry point of the application
│   ├── gpio.c          // Implementation of GPIO functions
│   ├── gpio.h          // Header file for GPIO functions
│   ├── startup.s       // Assembly startup routine
│   └── linker.ld       // Linker script for memory layout
├── Makefile            // Build instructions
└── README.md           // Documentation

#include "gpio.h"
#include "network.h"
#include "webserver.h"

// LED-Konfiguration
#define LED_BLINK_INTERVAL_MS 500  // Blink-Intervall in Millisekunden

// Globale Variable für den LED-Status (1 = an, 0 = aus)
volatile int led_state = 0;

/**
 * Hauptfunktion des Programms
 */
void main(void) {
    // GPIO initialisieren
    gpio_init();
    
    // Netzwerk initialisieren (wird später implementiert)
    network_init();
    
    // Webserver initialisieren
    webserver_init();
    
    // Hauptschleife - LED blinken lassen und Netzwerkanfragen bearbeiten
    while(1) {
        // LED umschalten
        gpio_toggle_pin(GPIO_PIN_0);
        
        // LED-Status aktualisieren
        led_state = !led_state;
        
        // Kurz warten
        delay_ms(LED_BLINK_INTERVAL_MS);
        
        // Netzwerkanfragen bearbeiten (wird später implementiert)
        network_process();
    }
}
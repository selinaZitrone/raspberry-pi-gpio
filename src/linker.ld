/* filepath: c:\Users\Selina_User\Files_Selina\Repos\999_private\raspberry-pi-gpio\src\linker.ld */
ENTRY(_start)

SECTIONS {
    /* Kernel-Image beginnt bei 0x8000 */
    . = 0x8000;
    
    /* .text-Sektion enthält Code */
    .text : {
        *(.init)
        *(.text)
    }
    
    /* .data-Sektion enthält initialisierte Daten */
    .data : {
        *(.data)
    }
    
    /* .bss-Sektion enthält nicht initialisierte Daten */
    .bss : {
        *(.bss)
    }
}
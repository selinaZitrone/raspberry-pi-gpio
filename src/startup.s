.section .init
.global _start

_start:
    // Setze Stack-Pointer
    ldr sp, =0x8000

    // Branch zum C-Code
    bl main

    // Sollte nie hierher kommen, aber für den Fall der Fälle eine Endlosschleife
hang:
    b hang
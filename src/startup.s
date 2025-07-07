@ filepath: c:\Users\Selina_User\Files_Selina\Repos\999_private\raspberry-pi-gpio\src\startup.s
.section .init
.global _start

_start:
    @ Setze Stack-Pointer
    ldr sp, =0x8000

    @ Branch zum C-Code
    bl main

    @ Sollte nie hierher kommen, aber für den Fall der Fälle eine Endlosschleife
hang:
    b hang
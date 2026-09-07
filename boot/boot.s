.syntax unified
.cpu cortex-m3
.thumb

.section .isr_vector, "a"
    .word _estack
    .word Reset_Handler

.section .text
.global Reset_Handler

.thumb_func
Reset_Handler:
    ldr r0, =0x08004000     /* program base address */
    
    /* load the program's sp into the bootloader sp */
    ldr r1, [r0, #0]
    mov sp, r1

    /* jump to the program's reset handler */
    ldr r2, [r0, #4]
    bx r2

dead_catch:
    b dead_catch

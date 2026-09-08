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
    /* .data copy */
    ldr r2, =_sidata
    ldr r3, =_sdata
    ldr r4, =_edata
    b data_check

data_copy_loop:
    ldr r0, [r2], #4
    str r0, [r3], #4

data_check:
    cmp r3, r4
    bcc data_copy_loop

    /* .bss zeroing */
    mov r0, #0
    ldr r2, =_sbss
    ldr r3, =_ebss
    b bss_check

bss_zero_loop:
    str r0, [r2], #4

bss_check:
    cmp r2, r3
    bcc bss_zero_loop

    bl boot /* boot.c main entry */

dead_catch:
    b dead_catch

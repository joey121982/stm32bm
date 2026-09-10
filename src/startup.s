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
    /* copy .data from flash */
    ldr r2, =_sidata
    ldr r3, =_sdata
    ldr r4, =_edata

    cmp r3, r4
    bcs 2f     
1:
    ldr r0, [r2], #4
    str r0, [r3], #4
    cmp r3, r4
    bcc 1b     
2:
    /* zero out .bss */
    mov r0, #0
    ldr r2, =_sbss
    ldr r3, =_ebss

    cmp r2, r3
    bcs 4f
3:
    str r0, [r2], #4
    cmp r2, r3
    bcc 3b
4:
    /* jump to main */
    bl main
    b .
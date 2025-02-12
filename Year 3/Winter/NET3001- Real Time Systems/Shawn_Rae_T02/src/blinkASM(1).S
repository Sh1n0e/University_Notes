#define __SFR_OFFSET 0

#include "avr/io.h"

.global start
.global led

start:
    sbi DDRB, 5     ; set B5 to be output
    ret             ; return to main program
led:
    cpi r24, 0x00   ; value in r24 passed by caller should be compared with 0
    breq ledOFF     ; jump to ledOFF if equal to 0
    sbi PINB, 0     ; set B5 to high
    rcall myDelay
    ret
ledOFF:
    cbi PINB, 0     ; set B5 to low
    rcall myDelay
    ret

.equ delayVal, 40000    ; initial count value for inner loop
myDelay:
    ldi r20, 50         ; initial count value for outter loop
outerLoop:
    ldi r30, lo8(delayVal) 
    ldi r31, hi8(delayVal)
innerLoop:
    sbiw r30, 1             ; subtract 1 from 16-bits value in R31, R30
    brne innerLoop          ; jump if count value not equal to 0

    subi r20, 1             ; subtract 1 from R20 counter for outer loop
    brne outerLoop          ; jump if r20 not equal to 0

    ret

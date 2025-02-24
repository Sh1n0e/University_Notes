#define __SFR_OFFSET 0

#include "avr/io.h"

.global average2
.global division

; data for average2
.set avg, 0 ; variable to store the result of average

; data for division
.equ div1, 30
.equ div2, 10
.set   result, 0



;subroutine to calculate the average of two numbers
average2:
    add r24, r22 ; add the first parameter to the second one
    ror r24      ; rotate to right to divide by 2
    sts avg, r24 ; save the result to sram
    lds r24, avg ; load from sram into r24 to return the result
    ret


; subroutine to calculate quotion for divding two integers
division:
    ldi r18, div1   ; bring the dividee to register
    ldi r19, div2   ; bring the divider to register
    ldi r20, 0      ; clear the register to hold the result
    jmp myloop      ; jump to the repeated subtraction to generate division
nomore:             ; label to come back when we can nolonger subtract
    sts result, r20 ; store the result 5o memory
    lds r24, result ; load from sram to register to confirm the result
    ret             ; return from subroutine

myloop:          ; label for the repetition
    sub r18, r19 ; subtract div2 from div1
    brmi nomore  ; jump if result is negative meaning we can no longer subtract
    inc r20      ; increment the quotion
    jmp myloop   ; jump to repeat subtraction

sumloop:
    

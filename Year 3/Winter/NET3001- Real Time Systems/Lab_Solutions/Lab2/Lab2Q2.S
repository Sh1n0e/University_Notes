#define __SFR_OFFSET 0

#include "avr/io.h"

.global average2
.global division
.global sum

; data for Average2
.equ num1, 10   ; data for average subroutine
.equ num2, 30
.equ avg, 0     ; for result of the average

; data for division
.equ div1, 30
.equ div2, 10
.equ   result, 0

; data for sum
.equ summation, 0

; subroutine to calculate average of 2 numbers
average2:
    ; simple version to calculate average of 2 numbers
    ;ldi r16, num1
    ;ldi r17, num2
    ;add r16, r17
    ;ror r16         ; rotate to right to divide by 2
    ;sts avg, r16
    ;lds r20, avg    ; load from sram to regixter to confirm the result
    ;ret
    ; version with parameters passed from C file
    nop             ; no operation to see the registers in debugging
    add r24, r22    ; the parameters are in r24 and r22
    ror r24         ; shift to right to divide by 2
    sts avg, r24    ; store the average into memory
    lds r24, avg    ; load from sram to register to confirm the result
    ret             ; return from subroutine

; subroutine to calculate quotion for divding two integers
division:
    ldi r16, div1   ; bring the dividee to register
    ldi r17, div2   ; bring the divider to register
    ldi r18, 0      ; clear the regster to hold the result
    jmp myloop      ; jump to the repeated subtraction to generate division
nomore:             ; label to come back when we can nolonger subtract
    sts result, r18 ; store the result 5o memory
    lds r20, result ; load from sram to register to confirm the result
    ret             ; return from subroutine

myloop:          ; label for the repetition
    sub r16, r17 ; subtract div2 from div1
    brmi nomore  ; jump if result is negative meaning we can no longer subtract
    inc r18      ; increment the quotion
    jmp myloop   ; jump to repeat subtraction

sum: 
    ldi r16, 0      ; clear r16 to hold the sum
    mov r17, r24    ; transfer the parameter to R17
repeat:
    add r16, r17    ; add the value of parameter with sum
    dec r17         ; decrement the parameter value
    brpl repeat     ; if value of counter is not negative repeat
    sts summation, r16 ; store the result to memory
    lds r20, summation ; load from sram to register to confirm the result
    ret
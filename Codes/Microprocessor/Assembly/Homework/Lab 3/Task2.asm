; Draw a 10*10 box of stars without using any string. Use only flow control instructions and loop to draw the box.

; Sample Execution

; **********
; **********
; **********
; **********
; **********
; **********
; **********
; **********
; **********
; **********

; Solution:

.MODEL SMALL
.STACK 100H
.CODE


MAIN PROC
    MOV AH, 2
    MOV CX, 10

label1:
    MOV BL, 10
    label2:
        MOV DL, "*"
        INT 21H
        SUB BL, 1
        jnz label2

        MOV DL, 0AH
        INT 21H
        MOV DL, 0DH
        INT 21H
    loop label1

    MOV AH, 4CH
    INT 21H
        
ENDP MAIN
END MAIN

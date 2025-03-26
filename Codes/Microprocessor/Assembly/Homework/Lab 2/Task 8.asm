; Take 2 input numbers from 0-4 and print the sum of the numbers in new line

.MODEL SMALL
.STACK 100H
.DATA
    NL DB 0DH, 0AH, '$'

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX


    MOV AH, 1
    INT 21H
    SUB AL, '0'
    MOV BL, AL


    MOV AH, 1
    INT 21H
    SUB AL, '0'

    ADD BL, AL

    ADD BL, '0'


    MOV AH, 9
    LEA DX, NL
    INT 21H


    MOV AH, 2
    MOV DL, BL
    INT 21H


    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
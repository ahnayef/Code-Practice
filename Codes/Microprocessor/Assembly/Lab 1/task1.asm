; Task 1: Basic Structure of 8086 Assembly Code and Printing a Characters

.MODEL small
.STACK 100H
.DATA
.CODE

MAIN PROC

    MOV AH, 2 ; Output mode
    MOV DL, 041H ;A
    INT 21H

    ;Printing a new line
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H

    MOV DL, 042H ;B
    INT 21H

    ;Printing a new line
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H

    MOV DL, 043H ;c
    INT 21H

    ;Printing a new line
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H

    MOV DL, 'a'
    INT 21H

    ; Terminate the program
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
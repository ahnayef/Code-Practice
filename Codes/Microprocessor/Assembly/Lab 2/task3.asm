; Printing the sring "Hello World" one character at a time

; Task 2: Input and output of characters

.MODEL small
.STACK 100H
.DATA
.CODE

MAIN PROC

    MOV AH, 2 ; Output mode


    ; Output 'Hello World' one character at a time
    MOV DL, 'H'
    INT 21H
    MOV DL, 'e'
    INT 21H
    MOV DL, 'l'
    INT 21H
    MOV DL, 'l'
    INT 21H
    MOV DL, 'o'
    INT 21H
    MOV DL, ' '
    INT 21H
    MOV DL, 'W'
    INT 21H
    MOV DL, 'o'
    INT 21H
    MOV DL, 'r'
    INT 21H
    MOV DL, 'l'
    INT 21H
    MOV DL, 'd'
    INT 21H
    

    ; Terminate the program
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
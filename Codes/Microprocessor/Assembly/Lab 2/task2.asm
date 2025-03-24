; Task 2: Input and output of characters

.MODEL small
.STACK 100H
.DATA
.CODE

MAIN PROC

    ; Read a character from the keyboard
    MOV AH, 1 ; Input mode
    INT 21H

    ; Store the character in BL
    MOV BL, AL

    ; New line
    MOV AH, 2 ; Output mode
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H

    ; Output the stored character
    MOV DL, BL
    INT 21H

    ; Terminate the program
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
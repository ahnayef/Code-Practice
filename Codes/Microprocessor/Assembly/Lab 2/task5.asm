; Uppercase to Lowercase

.MODEL small
.STACK 100H
.DATA
MSG1 DB "Enter a charecter in uppercase$"  ; Prompt message for user input
MSG2 DB "Charecter in lowercase:$"         ; Message to display the converted character
NL DB 0AH, 0DH, "$"                        ; New line characters
.CODE

MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    MOV AH, 9
    LEA DX , MSG1
    INT 21H                                ; Display MSG1

    MOV AH, 1
    INT 21H                                ; Read a character from user input
    MOV BL, AL                             ; Store the input character in BL

    MOV AH, 9
    LEA DX, NL
    INT 21H                                ; Print new line
    LEA DX, MSG2
    INT 21H                                ; Display MSG2

    MOV AH, 2
    ADD BL, 20H                            ; Convert uppercase to lowercase by adding 20H
    MOV DL, BL                             ; Move the converted character to DL
    INT 21H                                ; Display the lowercase character

    MOV AH, 4CH
    INT 21H                                ; Terminate the program

ENDP MAIN
END MAIN
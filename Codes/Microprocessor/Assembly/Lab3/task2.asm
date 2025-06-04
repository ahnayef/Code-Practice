; Take 6 characters as input and print them in new lines

; Solution:


.MODEL SMALL
.STACK 100H
.DATA
MSG DB "Enter six characters: $"           ; Prompt message for user input
NL DB 0AH, 0DH, "$"                        ; New line characters
a db ?, "$"                                ; Storage for first character
b db ?, "$"                                ; Storage for second character
c db ?, "$"                                ; Storage for third character
d db ?, "$"                                ; Storage for fourth character
e db ?, "$"                                ; Storage for fifth character
f db ?, "$"                                ; Storage for sixth character
.CODE


MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    MOV AH, 9
    LEA DX, MSG
    INT 21H                                ; Display MSG

    MOV AH, 1

    INT 21H
    MOV a, AL                              ; Store first character

    INT 21H
    MOV b, AL                              ; Store second character

    INT 21H
    MOV c, AL                              ; Store third character

    INT 21H
    MOV d, AL                              ; Store fourth character

    INT 21H
    MOV e, AL                              ; Store fifth character

    INT 21H
    MOV f, AL                              ; Store sixth character

    MOV AH, 9
    LEA DX, NL
    INT 21H                                ; Print new line

    MOV AH, 2
    MOV DL, a
    INT 21H                                ; Display first character

    MOV AH, 9
    LEA DX, NL
    INT 21H                                ; Print new line

    MOV AH, 2
    MOV DL, b
    INT 21H                                ; Display second character

    MOV AH, 9
    LEA DX, NL
    INT 21H                                ; Print new line

    MOV AH, 2
    MOV DL, c
    INT 21H                                ; Display third character

    MOV AH, 9
    LEA DX, NL
    INT 21H                                ; Print new line

    MOV AH, 2
    MOV DL, d
    INT 21H                                ; Display fourth character

    MOV AH, 9
    LEA DX, NL
    INT 21H                                ; Print new line

    MOV AH, 2
    MOV DL, e
    INT 21H                                ; Display fifth character

    MOV AH, 9
    LEA DX, NL
    INT 21H                                ; Print new line

    MOV AH, 2
    MOV DL, f
    INT 21H                                ; Display sixth character

    MOV AH, 4CH
    INT 21H                                ; Terminate the program

ENDP MAIN
END MAIN
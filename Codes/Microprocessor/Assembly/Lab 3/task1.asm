; Write a program to:
; a) Prompt the user
; b) Read first, middle and last initials for a person's name
; c) Display them down the left margin

; Sample Execution:
; ENTER THREE INITIALS: AHN
; A
; H
; N

.MODEL SMALL
.STACK 100H
.DATA
MSG DB "Enter three initials: $"           ; Prompt message for user input
NL DB 0AH, 0DH, "$"                        ; New line characters
.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV AH, 9
    LEA DX, MSG
    INT 21H                                ; Display MSG

    MOV AH, 1
    INT 21H                                ; Read first initial
    MOV BL, AL                             ; Store first initial in BL

    INT 21H                                ; Read middle initial
    MOV BH, AL                             ; Store middle initial in BH

    INT 21H                                ; Read last initial
    MOV CL, AL                             ; Store last initial in CL

    MOV AH, 9
    LEA DX, NL
    INT 21H                                ; Print new line

    MOV AH, 2
    MOV DL, BL
    INT 21H                                ; Display first initial

    MOV AH, 9
    LEA DX, NL
    INT 21H                                ; Print new line

    MOV AH, 2
    MOV DL, BH
    INT 21H                                ; Display middle initial

    MOV AH, 9
    LEA DX, NL
    INT 21H                                ; Print new line

    MOV AH, 2
    MOV DL, CL
    INT 21H                                ; Display last initial

    MOV AH, 4CH
    INT 21H                                ; Terminate the program

ENDP MAIN
END MAIN
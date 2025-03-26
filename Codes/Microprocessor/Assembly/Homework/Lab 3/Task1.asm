; Write a program to:
; a) Display "?", 
; b) Read three initials,
; c) Display them in the middle of an 11 x 11 box of asterisks.

; Sample Execution:

; ?AHN
; ***********
; ***********
; ***********
; ***********
; *****A*****
; *****H*****
; *****N*****
; ***********
; ***********
; ***********
; ***********


.MODEL SMALL
.STACK 100H
.DATA
STAR DB "***********", 0AH, 0DH, "$" 
STAR2 DB "*****"
NL DB 0AH, 0DH, "$"
a DB ?, "$"
b DB ?, "$"
c DB ?, "$"
.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    MOV AH, 2
    MOV DL, "?"
    INT 21H

    MOV AH, 1
    INT 21h
    MOV a, AL
    INT 21h
    MOV b, AL
    INT 21h
    MOV c, AL

    MOV CX, 4
    MOV AH, 9
    LEA DX, NL
    INT 21H
label1:
    LEA DX, STAR
    INT 21H
    loop label1

    MOV AH, 2
    MOV DL, "*"
    INT 21H
    INT 21H
    INT 21H
    INT 21H
    INT 21H
    MOV DL, a
    INT 21H
    MOV DL, "*"
    INT 21H
    INT 21H
    INT 21H
    INT 21H
    INT 21H

    MOV AH, 9
    LEA DX, NL
    INT 21H

    MOV AH, 2
    MOV DL, "*"
    INT 21H
    INT 21H
    INT 21H
    INT 21H
    INT 21H
    MOV DL, b
    INT 21H
    MOV DL, "*"
    INT 21H
    INT 21H
    INT 21H
    INT 21H
    INT 21H

    MOV AH, 9
    LEA DX, NL
    INT 21H

    MOV AH, 2
    MOV DL, "*"
    INT 21H
    INT 21H
    INT 21H
    INT 21H
    INT 21H
    MOV DL, c
    INT 21H
    MOV DL, "*"
    INT 21H
    INT 21H
    INT 21H
    INT 21H
    INT 21H

    MOV AH, 9
    LEA DX, NL
    INT 21H

    MOV CX, 4
    MOV AH, 9
label2:
    LEA DX, STAR
    INT 21H
    loop label2

    
    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
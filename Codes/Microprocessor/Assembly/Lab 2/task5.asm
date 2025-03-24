; Uppercase to Lowercase

.MODEL small
.STACK 100H
.DATA
MSG1 DB "Enter a charecter in uppercase$"
MSG2 DB "Charecter in lowercase:$"
NL DB 0AH, 0DH, "$"
.CODE

MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    MOV AH, 9
    LEA DX , MSG1
    INT 21H

    MOV AH, 1
    INT 21H
    MOV BL, AL

    MOV AH, 9
    LEA DX, NL
    INT 21H
    LEA DX, MSG2
    INT 21H

    MOV AH, 2
    ADD BL, 20H
    MOV DL, BL
    INT 21H


    MOV AH, 4CH
    INT 21H

ENDP MAIN
END MAIN
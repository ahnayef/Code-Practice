.MODEL small
.STACK 100H
.DATA
MSG DB 'Hello, World!', '$'
.CODE

MAIN PROC

    MOV AX, @DATA
    MOV DS, AX

    ; Write your code here


    MOV AH, 4CH
    INT 21H


ENDP MAIN
END MAIN
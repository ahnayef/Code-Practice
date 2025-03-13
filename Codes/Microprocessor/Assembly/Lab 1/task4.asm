; Printing the string "Hello World" using @data directive

.MODEL small
.STACK 100H
.DATA 
MSG db "Hello World$"
.CODE

MAIN PROC

    MOV AX , @DATA
    MOV DS, AX

    MOV AH, 9
    LEA DX, MSG
    INT 21H

    
    MOV AH, 4CH
    INT 21H

ENDP MAINE
END MAIN
; Printing the string "Hello World" using @data directive

.MODEL small
.STACK 100H
.DATA 
MSG db "Hello World", 0AH, 0DH, '$'
MSG2 db "NEUB", 0AH, 0DH, '$'

.CODE

MAIN PROC

    MOV AX , @DATA
    MOV DS, AX

    MOV AH, 9
    LEA DX, MSG
    INT 21H
    
    LEA DX, MSG2
    INT 21H

    
    MOV AH, 4CH
    INT 21H

ENDP MAINE
END MAIN
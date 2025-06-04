; Replace the number in BX by its absolute value.

.MODEL small
.STACK 100H
.DATA    
MSG db '**********', 0dh, 0ah,'$'
.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX  

    mov bx, -10
    cmp bx, 0
    jg l1     
    neg bx
l1:
    
    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN 
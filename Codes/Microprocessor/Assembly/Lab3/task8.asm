; Loop without use of loop instructions.

.MODEL small
.STACK 100H
.DATA    
MSG db '**********', 0dh, 0ah,'$'
.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX  

    mov bl, 5
    mov ah, 2
    mov dl, '*'   
 label1:   
    int 21h
    sub bl, 1
    jnz label1       

    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
; Suppose AX and BX contain signed numbers. Write some code to put the biggest one in cx.

.MODEL small
.STACK 100H
.DATA    
MSG db '**********', 0dh, 0ah,'$'
.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX  

    
    mov ax, 100h
    mov bx, 99h       
    
    cmp ax, bx
    jge l1
    jl l2

l1: 
    mov cx, ax
    jmp l3
l2:          
    mov cx, bx
l3:                    

    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
; Write a program to draw a 10*10 solid box of star using loop.

.MODEL small
.STACK 100H
.DATA    
MSG db '**********', 0dh, 0ah,'$'
.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX  
    
    mov cx, 10
    mov ah, 9
    lea dx, msg
label:
    int 21h
    loop label    
    

    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
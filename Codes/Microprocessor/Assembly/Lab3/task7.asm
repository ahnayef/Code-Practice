; A basic while (1) loop

.MODEL small
.STACK 100H
.DATA    
MSG db '**********', 0dh, 0ah,'$'
.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX  

label:    
    mov ah, 1
    int 21h
    mov dl, al 
    sub dl, 20h
    mov ah, 2
    int 21h
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h  
    
    jmp label
  
    

    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
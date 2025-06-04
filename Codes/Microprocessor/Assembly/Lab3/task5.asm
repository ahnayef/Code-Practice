; Write a count-controlled loop to display a row of 80 stars

.MODEL small
.STACK 100H
.DATA    
.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX  
    
    mov cx, 80  
    mov ah, 2
    mov dl, '*'

label1:  
    int 21h
    loop label1  
             
             
    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
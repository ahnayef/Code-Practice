; Write a program to draw a 10*10 box of star

; Sample Execution:

; **********
; **********
; **********
; **********
; **********
; **********
; **********
; **********
; **********
; **********
; **********

; Solution:

.MODEL small
.STACK 100H
.DATA    
MSG db '**********', 0dh, 0ah,'$'
.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX  
    
    mov ah, 9
    lea dx, msg
    int 21h     
    int 21h  
    int 21h  
    int 21h  
    int 21h  
    int 21h  
    int 21h   
    int 21h  
    int 21h      
    int 21h    
    

    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
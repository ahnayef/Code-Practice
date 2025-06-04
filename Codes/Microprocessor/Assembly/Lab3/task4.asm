; Write a program to draw a 10*10 hollow box of stars

; Sample Execution

; **********
; *        *
; *        *
; *        *
; *        *
; *        *
; *        *
; *        *
; *        *
; **********

; Solution

.MODEL small
.STACK 100H
.DATA    
MSG db '**********', 0dh, 0ah,'$'   
MSG2 db '*        *', 0dh, 0ah,'$'
.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX  
    
    mov ah,9
    lea dx, msg  
    int 21h 
    lea dx, msg2 
    int 21h 
    int 21h 
    int 21h 
    int 21h 
    int 21h 
    int 21h 
    int 21h 
    int 21h 
    lea dx, msg 
    int 21h 
             
             
    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
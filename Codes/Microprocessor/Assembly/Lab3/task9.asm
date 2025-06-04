; Write a program to take a hexadecimal, A-F as input and print its equivalent decimal in the next line.

; Sample Execution

; A-10
; B-11
; C-12
; E-13
; F-14

;  Solution

.MODEL small
.STACK 100H
.DATA    
MSG db '**********', 0dh, 0ah,'$'
.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX  

label1:      
    mov ah, 1
    int 21h 
    mov bl, al
    
    mov ah, 2
    mov dl, '-'
    int 21h
    mov dl, '1'
    int 21h
    mov dl, bl 
    
    ;sub dl, 11h
    sub dl, 'A'
    add dl, '0' 
    
    int 21h
    
    mov dl, 0dh
    int 21h
    mov dl, 0ah
    int 21h

    jmp label1       

    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
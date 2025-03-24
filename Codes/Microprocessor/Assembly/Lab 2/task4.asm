; Printing the string "Hello World" using @data directive

.MODEL small
.STACK 100H
.DATA 
MSG db "Hello World", 0AH, 0DH, '$' ; Define the first message string
MSG2 db "NEUB", 0AH, 0DH, '$'      ; Define the second message string

.CODE

MAIN PROC

    MOV AX, @DATA    ; Initialize data segment
    MOV DS, AX       

    MOV AH, 9        ; Display first message
    LEA DX, MSG      
    INT 21H          
    
    LEA DX, MSG2     ; Display second message
    INT 21H          

    MOV AH, 4CH      ; Terminate program
    INT 21H          

ENDP MAIN
END MAIN
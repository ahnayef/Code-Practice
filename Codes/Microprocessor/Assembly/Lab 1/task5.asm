; Uppercase to Lowercase

.MODEL small
.STACK 100H
.DATA
MSG1 DB "Enter a charecter in uppercase$"
MSG2 DB "Enter a charecter in lowercase$"
.CODE

MAIN PROC

    MOV AX, @DATA
    MOV DS, AX



    MOV AH, 4CH
    ITN 21H

ENDP MAIN
END MAIN
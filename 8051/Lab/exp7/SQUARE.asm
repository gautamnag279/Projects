CLR P0.7
START:Mov A,#00h
Mov P1, A
CALL DLY
Mov A, #0ffh
Mov P1, A
CALL DLY
JMP START
DLY:Mov R0, #01Fh
loop1:DJNZ r0, loop1
RET 
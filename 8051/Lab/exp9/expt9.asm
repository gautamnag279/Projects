	START:	SETB P3.3		
		SETB P3.4		
		MOV P1, #11000000B	
		CALL delay		
		MOV P1,#11111001B		
		CALL delay		
		MOV P1,#10100100B		
		CALL delay		
		MOV P1,#10110000B		
		CALL delay		
		MOV P1,#10011001B		
		CALL delay		
		MOV P1,#10010010B		
		CALL delay		
		MOV P1,#10000010B		
		CALL delay		
		MOV P1,#11111000B		
		CALL delay		
		MOV P1,#10000000B		
		CALL delay		
		MOV P1,#10011000B		
		CALL delay		
		SETB P3.4		
		CLR P3.3		
		MOV P1,#11000000B		
		CALL delay		
		MOV P1,#11111001B		
		CALL delay		
		MOV P1,#10100100B		
		CALL delay		
		MOV P1,#10110000B		
		CALL delay		
		MOV P1,#10011001B		
		CALL delay		
		MOV P1,#10010010B		
		CALL delay		
		MOV P1,#10000010B		
		CALL delay		
		MOV P1,#11111000B		
		CALL delay		
		MOV P1,#10000000B		
		CALL delay		
		MOV P1,#10011000B		
		CALL delay		
		JMP start		
	DELAY:	MOV R0,#0FFH		
		HERE: DJNZ R0,HERE		
		RET		

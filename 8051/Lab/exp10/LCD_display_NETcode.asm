;put data in RAM
	MOV 30H, #'H'
	MOV 31H, #'E'
	MOV 32H, #'Y'
  MOV 33H, #'Y'
   MOV 34H, #'O'
	MOV 35H, #0	; end of data marker


; initialise the display
; see instruction set for details


	CLR P1.3		; clear RS - indicates that instructions are being sent to the module

; function set	
	CLR P1.7		; |
	CLR P1.6		; |
	SETB P1.5		; |
	CLR P1.4		; | high nibble set

	SETB P1.2		; |
	CLR P1.2		; | negative edge on E

	CALL delay		; wait for BF to clear	
				; function set sent for first time - tells module to go into 4-bit mode
; Why is function set high nibble sent twice? See 4-bit operation on pages 39 and 42 of HD44780.pdf.

	SETB P1.2		; |
	CLR P1.2		; | negative edge on E
				; same function set high nibble sent a second time

	SETB P1.7		; low nibble set (only P1.7 needed to be changed)

	SETB P1.2		; |
	CLR P1.2		; | negative edge on E
				; function set low nibble sent
	CALL delay		; wait for BF to clear


; entry mode set
; set to increment with no shift
	CLR P1.7		; |
	CLR P1.6		; |
	CLR P1.5		; |
	CLR P1.4		; | high nibble set

	SETB P1.2		; |
	CLR P1.2		; | negative edge on E

	SETB P1.6		; |
	SETB P1.5		; |low nibble set

	SETB P1.2		; |
	CLR P1.2		; | negative edge on E

	CALL delay		; wait for BF to clear


; display on/off control
; the display is turned on, the cursor is turned on and blinking is turned on
	CLR P1.7		; |
	CLR P1.6		; |
	CLR P1.5		; |
	CLR P1.4		; | high nibble set

	SETB P1.2		; |
	CLR P1.2		; | negative edge on E

	SETB P1.7		; |
	SETB P1.6		; |
	SETB P1.5		; |
	SETB P1.4		; | low nibble set

	SETB P1.2		; |
	CLR P1.2		; | negative edge on E

	CALL delay		; wait for BF to clear


; send data
	SETB P1.3		; clear RS - indicates that data is being sent to module
	MOV R1, #30H		; data to be sent to LCD is stored in 8051 RAM, starting at location 30H
loop:
	MOV A, @R1		; move data pointed to by R1 to A
	JZ finish		; if A is 0, then end of data has been reached - jump out of loop
	CALL sendCharacter	; send data in A to LCD module
	INC R1			; point to next piece of data
	JMP loop		; repeat

finish:
	JMP $


sendCharacter:
	MOV C, ACC.7		; |
	MOV P1.7, C		; |
	MOV C, ACC.6		; |
	MOV P1.6, C		; |
	MOV C, ACC.5		; |
	MOV P1.5, C		; |
	MOV C, ACC.4		; |
	MOV P1.4, C		; | high nibble set

	SETB P1.2		; |
	CLR P1.2		; | negative edge on E

	MOV C, ACC.3		; |
	MOV P1.7, C		; |
	MOV C, ACC.2		; |
	MOV P1.6, C		; |
	MOV C, ACC.1		; |
	MOV P1.5, C		; |
	MOV C, ACC.0		; |
	MOV P1.4, C		; | low nibble set

	SETB P1.2		; |
	CLR P1.2		; | negative edge on E

	CALL delay		; wait for BF to clear

delay:
	MOV R0, #50
	DJNZ R0, $
	RET
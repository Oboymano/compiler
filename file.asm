section	.text
	global	_start
_start:
	MOV	rax,3

	MOV	[value+120],rax
	MOV	rax,3

	MOV	[value+136],rax
	PUSH	r10
	MOV	r10,3
loop0:
	MOV	r8,[value+120]
	PUSH	r8
	MOV	r9,2
	POP	r8
	MOV	rax,r8
	IMUL	r9

	MOV	[value+120],rax
	DEC	r10
	CMP	r10,1
	JGE	loop0
	POP	r10
	MOV	rax,[value+120]
	PUSH	r10
	PUSH	r11
	PUSH	rdi
	PUSH	rdx
	PUSH	rax
	PUSH	rbx

	CALL	printDec

	POP	rbx
	POP	rax
	POP	rdx
	POP	rdi
	POP	r11
	POP	r10

	CALL	printLineOnly

	MOV	rax,60
	MOV	rdi,0
	syscall

printDec:
	MOV	r10,0
	MOV	r11,0
	LEA	rdi,[buffer+19]
	XOR	rdx,rdx
	CMP	rax,0
	JGE	not_zero
	NEG	rax
	MOV	r11,1
not_zero:
	MOV	rbx,10
	div	rbx
	add	rdx,'0'
	mov	byte[rdi],dl
	dec	rdi
	inc	r10
	xor	rdx,rdx
	cmp	rax,0
	jne	not_zero
	cmp	r11,1
	JNE	plus
	PUSH	rax
	PUSH	rdi
	PUSH	rdx
	MOV	rax,1
	MOV	rdi,1
	MOV	rsi,minus
	MOV	rdx,1
	syscall
	POP	rax
	POP	rdi
	POP	rdx
plus:
	INC	rdi
	MOV	rbx,rdi
	MOV	rax,1
	MOV	rdi,1
	MOV	rsi,rbx
	MOV	rdx,r10
	syscall
	ret

printHex:
	MOV	r10,0
	MOV	r11,0
	LEA	rdi,[buffer+19]
	XOR	rdx,rdx
	CMP	rax,0
	JGE	not_zeroHex
	NEG	rax
	MOV	r11,1
not_zeroHex:
	MOV	rbx,16
	div	rbx
	CALL	convert
	mov	byte[rdi],dl
	dec	rdi
	inc	r10
	xor	rdx,rdx
	cmp	rax,0
	jne	not_zeroHex
	cmp	r11,1
	JNE	plusHex
	PUSH	rax
	PUSH	rdi
	PUSH	rdx
	MOV	rax,1
	MOV	rdi,1
	MOV	rsi,minus
	MOV	rdx,1
	syscall
	POP	rax
	POP	rdi
	POP	rdx
plusHex:
	INC	rdi
	MOV	rbx,rdi
	MOV	rax,1
	MOV	rdi,1
	MOV	rsi,rbx
	MOV	rdx,r10
	syscall
	ret

convert:
	CMP	rdx,10
	JL	convert_done
	ADD	rdx,0x7
convert_done:
	ADD	rdx,0x30
	ret

printLineOnly:
	MOV	rax,1
	MOV	rdi,1
	MOV	rsi,line
	MOV	rdx,1
	syscall
	ret

section	.data
	line	db 0x0A
	value	TIMES 26 DQ 0
	buffer	resb	20
	minus	db	'-'

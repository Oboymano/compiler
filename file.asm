section	.text
	global	_start
_start:
	MOV	rax,1
	MOV	rdi,1
	MOV	rsi,text0
	MOV	rdx,3
	syscall

	MOV	rax,1
	MOV	rdi,1
	MOV	rsi,text1
	MOV	rdx,3
	syscall

	MOV	rax,1
	MOV	rdi,1
	MOV	rsi,text2
	MOV	rdx,2
	syscall

	MOV	rax,1
	MOV	rdi,1
	MOV	rsi,text3
	MOV	rdx,7
	syscall

	MOV	rax,60
	MOV	rdi,0
	syscall

section	.data
	text0	db	'azx',10
	text1	db	'zxc',10
	text2	db	'ne',10
	text3	db	'aassdd',10

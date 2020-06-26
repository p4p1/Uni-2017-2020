; strlen.asm
; unsigned int strlen(char *str)

bits 64
global strlen:function

section .text

strlen:
	mov	rax, 0
	cmp	byte [rdi + rax], 0
	jnz	while_loop
	ret
while_loop:
	inc	rax
	cmp	byte [rdi + rax], 0
	jnz	while_loop
	ret

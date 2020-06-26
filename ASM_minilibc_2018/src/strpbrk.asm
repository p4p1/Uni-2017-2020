; char *strpbrk(const char *s, const char *accept)
; rax ------------- rdi, ---- rsi

bits 64
global strpbrk:function

section .text

strpbrk:
	mov	r8, 0
	mov	r9, 0
	cmp	rdi, 0
	jz	null_ptr
	cmp	rsi, 0
	jz	null_ptr
	jmp	accept_loop

main_loop:
	mov	r9, 0
	inc	r8
	cmp	byte [rdi + r8], 0
	jz	null_ptr
	jmp	accept_loop

accept_loop:
	mov	r10b, byte [rsi + r9]
	cmp	byte [rdi + r8], r10b
	je	found
	cmp	byte [rsi + r9], 0
	jz	main_loop
	inc	r9
	jmp	accept_loop

found:
	mov	rax, rdi
	add	rax, r8
	ret

null_ptr:
	mov	rax, 0
	ret

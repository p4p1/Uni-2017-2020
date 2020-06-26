; char *rindex(const char *s, int c);
; rax------------rdi, -------- rsi

bits 64
global rindex:function

section .text

rindex:
	mov	rax, rdi
	mov	rbx, 0
	cmp	byte [rax + rbx], 0
	jnz	strlen_loop
	jmp	rindex_main
strlen_loop:
	inc	rbx
	cmp	byte [rax + rbx], 0
	jnz	strlen_loop
	jmp	rindex_main
rindex_main:
	cmp	byte [rax + rbx], sil
	jne	rindex_loop
	add	rax, rbx
	ret
rindex_loop:
	dec	rbx
	cmp	byte [rax + rbx], sil
	jne	rindex_loop
	add	rax, rbx
	ret

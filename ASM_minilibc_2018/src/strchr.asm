; char *strchr(const char *str, int c);
; rax  ---------- rdi ------,--- rsi
; int 8

bits 64
global strchr:function

section .text

strchr:
	mov	rax, rdi
	mov	rbx, 0
	cmp	byte [rax + rbx], 0
	jz	not_found
	cmp	byte [rax + rbx], sil
	jne	loop
	add	rax, rbx
	ret

loop:
	inc	rbx
	cmp	byte [rax + rbx], 0
	jz	not_found
	cmp	byte [rax + rbx], sil
	jne	loop
	add	rax, rbx
	ret

not_found:
	mov	rax, 0
	ret

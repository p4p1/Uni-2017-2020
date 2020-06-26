; void *memset(void *s, int c, size_t n);
; rax----------rdi ---,-rsi--,---rdx

bits 64
global memset:function

section .text

memset:
	mov	rbx, 0
	cmp	rdi, 0
	jz	is_null
	mov	[rdi + rbx], rsi
	cmp	rbx, rdx
	jl	loop
	mov	rax, rdi
	ret

loop:
	inc	rbx
	mov	[rdi + rbx], rsi
	cmp	rbx, rdx
	jl	loop
	mov	rax, rdi
	ret

is_null:
	mov	rax, 0
	ret

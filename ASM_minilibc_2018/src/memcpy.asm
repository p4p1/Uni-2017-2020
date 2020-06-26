; void *memcpy(void *dest, const void *src, size_t n)
; rax ------------- rdi, ---- rsi--  ----,  rdx

bits 64
global memcpy:function

section .text

memcpy:
	mov	r8, 0
	cmp	rdi, 0
	jz	null_ptr
	cmp	rsi, 0
	jz	null_ptr
	cmp	r8, rdx
	jl	loop
	mov	rax, rsi
	ret

loop:
	mov	r9, [rsi + r8]
	mov	[rdi + r8], r9
	inc	r8
	cmp	r8, rdx
	jl	loop
	mov	rax, rsi
	ret

null_ptr:
	mov	rax, 0
	ret

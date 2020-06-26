; int strncmp(const char *s1, const char *s2, size_t n);
; rax ------------- rdi, -----------rsi, ------- rdx

bits 64
global strncmp:function

section .text

strncmp:
	mov	r8, 0
	cmp	rdi, 0
	jz	null_ptr
	cmp	rsi, 0
	jz	null_ptr
	cmp	rdx, 0
	jz	null_ptr
	cmp	byte [rdi + r8], 0
	jz	ret_val
	cmp	byte [rsi + r8], 0
	jz	ret_val

loop:
	mov	r10b, byte [rsi + r8]
	mov	r9b, byte[rdi + r8]
	cmp	r10b, r9b
	jne	ret_val
	cmp	r8, rdx
	jae	ret_val
	cmp	byte [rdi + r8], 0
	jz	ret_val
	cmp	byte [rsi + r8], 0
	jz	ret_val
	inc	r8
	jmp loop


ret_val:
	mov	r9b, byte [rdi + r8]
	mov	r10b, byte [rsi + r8]
	sub	r9b, r10b
	mov	al, r9b
	ret

null_ptr:
	mov	rax, 0
	ret

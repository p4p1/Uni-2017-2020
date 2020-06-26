; int strcmp(const char *s1, const char *s2);
; rax ------------- rdi, -----------rsi

bits 64
global strcmp:function

section .text

strcmp:
	mov	r8, 0
	cmp	byte [rdi + r8], 0
	jz	ret_val
	cmp	byte [rsi + r8], 0
	jz	ret_val

loop:
	mov	r9, [rdi + r8]
	cmp	[rsi + r8], r9
	je	ret_val
	inc	r8
	jmp loop


ret_val:
	mov	r9, [rdi + r8]
	sub	r9, [rsi + r8]
	mov	rax, r9
	ret

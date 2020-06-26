; int read(int fd, void *buf, int count)
global my_read

section .text

my_read:
	mov	rax, 0
	; no need to set rdi because the fd is already inside of it
	; rsi is also already set by the function call
	; and rdx is also already set by the function call
	syscall
	mov	rax, 0
	ret


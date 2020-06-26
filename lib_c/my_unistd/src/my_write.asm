; int write(int fd,  char *buf, int nb)
global my_write
global not_writen
global null_pointer

section .text

my_write:
	mov	rax, 1
	; no need to set rdi because the fd is already inside of it
	; rsi is also already set by the function call
	; and rdx is also already set by the function call
	cmp	rsi, 0
	je	null_pointer
	syscall
	cmp	rax, rdx
	jne	not_write
	ret

null_pointer:
	mov	rax, -1
	ret

not_write:
	mov	rax, -2
	ret

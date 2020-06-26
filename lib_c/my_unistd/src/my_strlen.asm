; int my_strlen(void *buffer)
global my_strlen

section .text

my_strlen:
	; '\0' ca determine la fin
	inc	rax
	or	RDI, 0
	je	my_strlen
	ret

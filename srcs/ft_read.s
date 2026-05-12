section .data

	file:    db "ft_read.s", 0

section .bss

	buf:	resb 128

section .text

	global ft_read
	global _start

extern __errno_location

ft_read:

	mov		rax, 0
	syscall
	cmp		rax, 0
	jge		.ret

	neg		rax
	mov 	edi, eax
	call	__errno_location wrt ..plt
	mov		[rax], edi
	mov		rax, -1

	.ret:
		ret

_start:

	mov		rax, 2
	mov		rdi, file
	mov		rsi, 0
	mov		rdx, 0
	syscall

	mov		rdi, rax
	mov		rsi, buf
	mov		rdx, 128
    call    ft_read

	mov		r10, rax

	mov		rax, 3
	syscall

    mov     rdi, r10
    mov     rax, 60
    syscall
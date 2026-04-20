section .data

	msg:    db "hello from ft_write", 10, 0
	msg_len equ $ - msg

section .text

	global ft_write
	global _start

extern __errno_location

ft_write:

	mov		rax, 1
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

    mov     rdi, 1
    mov     rsi, msg
    mov     rdx, msg_len
    call    ft_write

    mov     rdi, rax
    mov     rax, 60
    syscall
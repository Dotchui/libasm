section .data

	msg:    db "hello from ft_strlen", 10, 0

section .text

	global ft_strlen
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

ft_strlen:

	xor rax, rax

	.loop:

		cmp byte [rdi+rax], 0
		je .done
		inc rax
		jmp .loop

	.done:
	
		ret

_start:

	mov		rdi, msg
	call	ft_strlen

	mov		rdi, rax
    mov     rax, 60
    syscall
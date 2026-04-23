section .text
	global ft_write
	global ft_strlen

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

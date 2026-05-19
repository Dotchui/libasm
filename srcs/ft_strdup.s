section .text

    global ft_strdup

	extern ft_strlen
	extern ft_strcpy
	extern malloc

ft_strdup:
	
	push	rbx
	push	rbp
	call	ft_strlen
	mov		rbx, rax
	mov		rbp, rdi

	mov		rdi, rax
	add		rdi, 1
	call	malloc wrt ..plt

	cmp		rax, 0
	je		.malloc_fail

	mov		rdi, rax
	mov		rsi, rbp
	call	ft_strcpy

	pop		rbp
	pop		rbx
	ret

	.malloc_fail:
	
		pop	rbp
		pop	rbx
		mov	rax, 0
		ret
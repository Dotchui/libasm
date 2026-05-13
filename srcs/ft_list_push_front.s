section .text

    global ft_list_push_front

extern malloc

ft_list_push_front:

	push	rdi
	push	rsi

	mov		rdi, 16
	call	malloc
	test	rax, rax
	je		.done

	pop		rsi
	pop		rdi

	mov 	[rax], rsi
	mov		rcx, [rdi]
	mov		[rax+8], rcx
	mov		[rdi], rax
	ret

	.done:

		pop	rsi
		pop	rdi
		ret
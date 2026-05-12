section .data

	msg:    db "hello from ft_strdup", 10, 0

section .text

	global ft_strlen
	global ft_strcpy
    global ft_strdup
	global _start

extern malloc

ft_strlen:

	xor rax, rax

	.loop:

		cmp byte [rdi+rax], 0
		je .done
		inc rax
		jmp .loop

	.done:

		ret

ft_strcpy:

	xor rcx, rcx

	.loop:

		mov		al, [rsi+rcx]
		mov		[rdi+rcx], al
		test	al, al
		je		.done
		inc		rcx
		jmp		.loop

	.done:

		mov		rax, rdi
		ret

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

_start:

    mov		rdi, msg
	sub		rsp, 8
	call	ft_strdup

	mov     rdi, rax
    mov     rax, 60
	add		rsp, 8
    syscall

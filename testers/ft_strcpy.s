section .data

	msg1:	db "agougo", 10, 0
	msg2:	db "coucou", 10, 0

section .text

	global ft_strcpy
	global ft_write
	global ft_strlen
	global _start

extern __errno_location

ft_strlen:

	xor rax, rax

	.loop:

		cmp byte [rdi+rax], 0
		je .done
		inc rax
		jmp .loop

	.done:

		ret

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

_start:

	mov		rdi, msg2
	mov		rsi, msg1
	call	ft_strcpy

	call	ft_strlen

	mov		rdx, rax
	mov		rsi, rdi
	mov		rdi, 1
	call	ft_write

    mov     rdi, rax
    mov     rax, 60
    syscall
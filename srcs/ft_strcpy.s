section .data

	msg1:	db "agougo", 10, 0
	msg2:	db "coucou", 10, 0

section .text

	global ft_strcpy
	global _start

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

    mov     rdi, rax
    mov     rax, 60
    syscall
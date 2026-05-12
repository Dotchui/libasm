section .data

	msg1:	db "aoucou", 0
	msg2:	db "coucou", 0

section .text

	global ft_strcmp
	global _start

ft_strcmp:

	xor rcx, rcx

	.loop:

		mov	al, [rdi+rcx]
		mov	dl, [rsi+rcx]
		cmp al, dl
		jne .diff
		test al, al
		je	.done
		inc	rcx
		jmp	.loop

	.diff:

		movzx	eax, al
		movzx	edx, dl
		sub		eax, edx
		ret

	.done:
	
		xor		eax, eax
		ret

_start:

	mov		rdi, msg1
	mov		rsi, msg2
	call	ft_strcmp

    mov     rdi, rax
    mov     rax, 60
    syscall
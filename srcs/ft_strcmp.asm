section .text
	global ft_strcmp

ft_strcmp:

	xor rax, rax

	.loop:
		mov	al, [rdi+rax]
		mov	dl, [rsi+rax]
		cmp al, dl
		jne .done
		test al, al
		je	.done
		inc	rax
		jmp	.loop

	.done:
		sub al, dl
		movsx eax, al
		ret
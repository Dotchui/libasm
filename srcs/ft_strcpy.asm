section .text
	global ft_strcpy

ft_strcpy:

	xor rax, rax

	.loop:
		mov		al, [rsi+rax]
		mov		[rdi+rax], al
		test	al, al
		je		.done
		inc		rax
		jmp		.loop

	.done:
		mov		rax, rdi
		ret
section .text

	global ft_list_size

ft_list_size:

	xor rax, rax

	.loop:

		test    rdi, rdi
		je      .done
		inc     rax
        mov     rdi, [rdi+8]
		jmp     .loop

	.done:
	
		ret
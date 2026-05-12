section .data

	msg:    db "hello from ft_strlen", 10, 0

section .text

	global ft_strlen
	global _start

ft_strlen:

	xor rax, rax

	.loop:

		cmp byte [rdi+rax], 0
		je .done
		inc rax
		jmp .loop

	.done:
	
		ret

_start:

	mov		rdi, msg
	call	ft_strlen

	mov		rdi, rax
    mov     rax, 60
    syscall
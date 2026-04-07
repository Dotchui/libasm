section .data
	string	db "hi", 0

section .text
	global _start

_start:

	mov rdi, string
	call ft_strlen
	mov rdi, rax
	mov rax, 60
	syscall

section .data

	msg:    db "hello from ft_strlen", 0
	base:	db "10", 0

section .text

    global ft_strlen
    global ft_atoi_base
    global _start

check_ws:

    xor rax, rax
    xor rcx, rcx
    
    .loop:

        mov     al, [rdi+rcx]
        test    al, al
        jz      .ok

		cmp		al, '+'
		je		.fail
		cmp		al, '-'
		je		.fail
        cmp     al, ' '
        je      .fail
        cmp     al, 9
        je      .fail
        cmp     al, 10
        je      .fail
        cmp     al, 11
        je      .fail
        cmp     al, 12
        je      .fail
        cmp     al, 13
        je      .fail
        inc     rcx
        jmp     .loop
    
    .ok:

        mov     rax, 1

    .fail:

        ret

check_dup:

	xor rax, rax

	.loop1:

		mov		r8b, [rdi+rax]
		test	r8b, r8b
		jz		.ok
		mov		rcx, rax
		inc		rcx

	.loop2:

		mov		r9b, [rdi + rcx]
		test	r9b, r9b
		jz		.next_char
		cmp		r8b, r9b
		jz		.fail
		inc		rcx
		jmp		.loop2

	.next_char:

		inc		rax
		jmp		.loop1

	.ok:

		mov		rax, 1
		ret

	.fail:

		xor		rax, rax
		ret

skip_ws:

	xor		rax, rax
	xor		rdx, rdx
	
	.loop:
		
		mov		r8b, [rdi+rdx]
		test	r8b, r8b
		jz		.fail
		cmp		r8b, ' '
		jz		.next_char
		cmp		r8b, 9
		jz		.next_char
		cmp		r8b, 10
		jz		.next_char
		cmp		r8b, 11
		jz		.next_char
		cmp		r8b, 12
		jz		.next_char
		cmp		r8b, 13
		jz		.next_char
		mov		rax, 1
		ret

	.next_char:

		inc	rdx
		jmp	.loop
	
	.fail:

		ret

sign_loop:

	xor		rax, rax
	mov		r10, 1

	.loop:
		
		mov		r8b, [rdi+rdx]
		test	r8b, r8b
		jz		.fail
		cmp		r8b, '+'
		jz		.plus_sign
		cmp		r8b, '-'
		jz		.minus_sign
		inc		rax
		ret

	.plus_sign:

		inc		rdx
		jmp		.loop

	.minus_sign:
		
		neg		r10
		inc		rdx
		jmp		.loop

	.fail:

		ret


ft_atoi_base:

	mov		rdx, rdi
	mov		rdi, rsi

	call	ft_strlen
	cmp		rax, 2
	jl		.fail

	call	check_ws
	cmp		rax, 0
	jz		.fail

	call	check_dup
	cmp		rax, 0
	jz		.fail

	mov		rsi, rdi
	mov		rdi, rdx
	call	skip_ws
	cmp		rax, 0
	jz		.fail

	call	sign_loop
	cmp		rax, 0
	jz		.fail

	xor		rax, rax

	.loop:

		mov		r8b, [rdi+rdx]
		test	r8b, r8b
		jz		.end
		cmp		r8b, '0'
		jl		.end
		cmp		r8b, '9'
		ja		.end
		imul	rax, rax, 10
		sub		r8b, '0'
		movzx	rcx, r8b
		add		rax, rcx
		inc		rdx
		jmp		.loop

	.end:

		imul	rax, r10
		ret

	.fail:

		xor rax, rax
		ret

_start:

    mov		rdi, msg
	mov		rsi, base
	call	ft_atoi_base
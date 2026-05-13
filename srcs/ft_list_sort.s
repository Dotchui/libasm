section .text

    global ft_list_sort

ft_list_sort:

    test    rdi, rdi
    je      .done

    mov     rbx, [rdi]
    test    rbx, rbx
    je      .done

    push    rbx
    push    r12
    push    r13

    mov     r12, rsi

    .outer:

        xor     r13b, r13b
        mov     rdx, rbx

    .inner:

        mov     rax, [rdx+8]
        test    rax, rax
        je      .outer_check

        mov     rdi, [rdx]
        mov     rsi, [rax]
        call    r12
        cmp     eax, 0
        jle     .no_swap

        mov     rcx, [rdx]
        mov     r8, [rax]
        mov     [rdx], r8
        mov     [rax], rcx
        mov     r13b, 1

    .no_swap:

        mov     rdx, rax
        jmp     .inner

    .outer_check:

        test    r13b, r13b
        jne     .outer

        pop     r13
        pop     r12
        pop     rbx

	.done:
	
		ret
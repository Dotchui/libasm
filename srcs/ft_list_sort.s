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
    push    r14
    push    r15

    mov     r12, rsi

    .outer:

        xor     r13b, r13b
        mov     rdx, rbx

    .inner:

        mov     rax, [rdx+8]
        test    rax, rax
        je      .outer_check

        mov     r15, rdx
        mov     r14, rax

        mov     rdi, [r15]
        mov     rsi, [r14]
        call    r12
        cmp     eax, 0
        jle     .no_swap

        mov     rcx, [r15]
        mov     r8, [r14]
        mov     [r15], r8
        mov     [r14], rcx
        mov     r13b, 1

    .no_swap:

        mov     rdx, r14
        jmp     .inner

    .outer_check:

        test    r13b, r13b
        jne     .outer

        pop     r15
        pop     r14
        pop     r13
        pop     r12
        pop     rbx

	.done:
	
		ret
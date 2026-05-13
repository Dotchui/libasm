section .text

    global ft_list_remove_if
    extern free

ft_list_remove_if:

    test    rdi, rdi
    je      .done

    push    rbx
    push    r12
    push    r13
    push    r14
    push    r15

    mov     rbx, rdi
    mov     r12, rsi
    mov     r13, rdx
    mov     r14, rcx

    mov     r15, [rbx]
    xor     r8, r8

    .loop:

        test    r15, r15
        je      .done_restore

        mov     rdi, [r15]
        mov     rsi, r12
        call    r13
        test    eax, eax
        jne     .keep

        mov     r9, [r15+8]
        test    r8, r8
        jne     .link_prev
        mov     [rbx], r9
        jmp     .free_node

    .link_prev:

        mov     [r8+8], r9

    .free_node:

        mov     rdi, [r15]
        call    r14
        mov     rdi, r15
        call    free
        mov     r15, r9
        jmp     .loop

    .keep:

        mov     r8, r15
        mov     r15, [r15+8]
        jmp     .loop

    .done_restore:

        pop     r15
        pop     r14
        pop     r13
        pop     r12
        pop     rbx

    .done:

        ret
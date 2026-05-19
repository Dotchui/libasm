section .text

    global  ft_list_sort

ft_list_sort:
    test    rdi, rdi
    je      .done
    mov     rax, [rdi]
    test    rax, rax
    je      .done
    
    push    rbx
    push    r12
    push    r13
    
    mov     rbx, rax
    mov     r12, rsi

.outer:
    xor     r13b, r13b
    mov     rdx, rbx

.inner:
    mov     rax, [rdx+8]
    test    rax, rax
    je      .outer_check

    push    rdx
    push    rax
    mov     rdi, [rdx]
    mov     rsi, [rax]
    call    r12
    pop     rax
    pop     rdx

    cmp     eax, 0
    jle     .no_swap

    mov     rcx, [rdx]
    mov     r8,  [rax]
    mov     [rdx], r8
    mov     [rax], rcx

    cmp     rdx, rbx
    jne     .skip_head_update
    mov     rbx, rax
.skip_head_update:
    mov     r13b, 1

.no_swap:
    mov     rdx, rax
    jmp     .inner

.outer_check:
    test    r13b, r13b
    jne     .outer


    mov     rax, [rdi]
    cmp     rax, rbx
    je      .no_head_change
    mov     [rdi], rbx
.no_head_change:

    pop     r13
    pop     r12
    pop     rbx
.done:
    ret
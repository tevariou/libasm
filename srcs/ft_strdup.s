    section .text
	global  ft_strdup
	extern  ft_strlen
	extern  ft_strcpy
	extern  malloc

ft_strdup:
    push    rdi                 ; save src
	call    ft_strlen
	inc     rax                 ; increment for null termination
	mov     rdi, rax            ; pass size to malloc
	call    malloc wrt ..plt
	test    rax, rax
	jz      .done
	pop     rsi
	mov     rdi, rax
	call    ft_strcpy

.done:
	ret

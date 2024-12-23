    section .text
	global  ft_write
	extern  __errno_location

ft_write:
	mov     rax, 1                      ; write
	syscall
	test    rax, rax
	jns     .done                       ; if no error (>=0), return

.error:
	neg     rax
    push    rax
    call    __errno_location wrt ..plt  ; with respect to procedure linkage table
    pop     qword[rax]
    mov     rax, -1

.done:
    ret

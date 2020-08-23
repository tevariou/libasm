	global _ft_write
	extern	___error
	section .text

_ft_write:
    enter 0, 0
	mov rax, 0x2000004 ; SYSCALL_CLASS_UNIX write
	syscall
	jnc done
	sub rsp, 8
    push rax
    call ___error
    pop qword[rax]

done:
	leave
	ret

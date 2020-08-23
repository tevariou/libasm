	global _ft_read
	extern ___error
	section .text

_ft_read:
    enter 0, 0
	mov rax, 0x2000003 ; SYSCALL_CLASS_UNIX read
	syscall
	jnc done
	sub rsp, 8
    push rax
    call ___error
    pop qword[rax]

done:
	leave
	ret

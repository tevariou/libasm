	global _ft_read
	section .text

_ft_read:
    enter 0, 0
	mov rax, 0x2000003 ; SYSCALL_CLASS_UNIX read
	syscall
	leave
	ret

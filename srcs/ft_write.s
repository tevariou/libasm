	global _ft_write
	section .text

_ft_write:
    enter 0, 0
	mov rax, 0x2000004 ; SYSCALL_CLASS_UNIX write
	syscall
	leave
	ret

	global _ft_write
	section .text

_ft_write:
	mov rax, 0x2000004 ; SYSCALL_CLASS_UNIX write
	syscall
	ret

	section .text
	global _ft_read

_ft_read:
	mov rax, 0x2000003 ; SYSCALL_CLASS_UNIX read
	syscall
	ret

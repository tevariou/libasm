	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc
	section .text

_ft_strdup:
	call _ft_strlen
	inc rax
	mov rsi, rdi
	mov rdi, rax
	call _malloc
	test rax, rax
	jz exit
	mov rdi, rax
	call _ft_strcpy

exit:
	ret


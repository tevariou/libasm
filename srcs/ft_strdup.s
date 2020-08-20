	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc
	section .text

_ft_strdup:
	enter 0, 0
	call _ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	sub rsp, 8
	call _malloc
	add rsp, 8
	pop rsi
	test rax, rax
	jz exit
	mov rdi, rax
	call _ft_strcpy

exit:
	leave
	ret


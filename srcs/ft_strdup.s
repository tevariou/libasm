	global _ft_strdup
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc
	section .text

_ft_strdup:
    push rdi ; save src
	call _ft_strlen
	inc rax ; increment for null termination
	mov rdi, rax
	call _malloc
	pop rsi ;
	test rax, rax ; check malloc return value
	jz exit
	mov rdi, rax
	call _ft_strcpy

exit:
	ret


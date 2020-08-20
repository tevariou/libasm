	global _ft_strcpy
	section .text

_ft_strcpy:
	cld
	push rdi ; save dst

copy:
	lodsb ; tmp = *src++
	stosb ; *dest++ = tmp
	test al, al ; if (tmp & tmp)
	jnz copy
	pop rax ; ret dst
	ret

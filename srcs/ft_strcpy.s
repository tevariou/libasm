	section .text
	global  ft_strcpy

ft_strcpy:
	cld                 ; clear direction flag (forward direction)
	xor     rax, rax    ; ret = 0
	push    rdi         ; save dst

.copy:
	lodsb               ; tmp = *src++ (load rsi into al and increment rsi according to direction flag)
	stosb               ; *dst++ = tmp (load al into rdi and increment rdi according to direction flag)
	test    al, al      ; tmp & tmp
	jnz     .copy       ; jump if not zero
	pop     rax         ; ret dst
	ret

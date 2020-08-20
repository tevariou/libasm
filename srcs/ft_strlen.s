	global  _ft_strlen
	section .text

_ft_strlen:
	xor rax, rax ; i = 0
	jmp compare

increment:
	inc rax ; i++
	jmp compare

compare:
	cmp byte[rdi+rax], 0 ; if (s[i] == 0)
	jne increment
	ret

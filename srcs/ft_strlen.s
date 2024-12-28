    section .text
    global  ft_strlen

ft_strlen:
	xor rax, rax            ; i = 0

.compare:
	cmp byte[rdi+rax], 0    ; if (s[i] == 0)
	jz  .done
	inc rax                 ; i++
	jmp .compare

.done:
    ret

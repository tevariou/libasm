	global _ft_strcmp
	section .text

_ft_strcmp:
	cld

compare:
	cmp byte[rdi], 0 ; if (*s1 == 0)
	je done
	cmp byte[rsi], 0 ; if (*s2 == 0)
	je done
	cmpsb ; if (*s1++ == *s2++)
	je compare
	dec di ; s1--
	dec si ; s2--

done:
    movsx  rax, byte[rdi] ; ret = *s1
	sub rax, [rsi] ; ret -= *s2
	ret

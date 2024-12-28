    section .text
	global  ft_strcmp

ft_strcmp:
	cld                     ; clear direction flag
	xor     rax, rax        ; ret = 0

.compare:
	cmp     byte[rdi], 0    ; if (*s1 == 0)
	jz      .stop
	cmp     byte[rsi], 0    ; if (*s2 == 0)
	jz      .stop
	cmpsb                   ; if (*s1++ == *s2++)
	jz      .compare
	dec     rdi             ; go back to the last matching character
	dec     rsi             ; go back to the last matching character

.stop:
    mov     al, byte[rdi]
    sub     al, byte[rsi]   ; *s1 - *s2
    jz      .done
    jns     .positive
    mov     rax, -1
    ret

.positive:
    mov     rax, 1

.done:
    ret

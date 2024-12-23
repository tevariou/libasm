    section .text
	global  ft_read
	extern  __errno_location

ft_read:
	xor     rax, rax                    ; (0) read
	syscall
	test    rax, rax
	jns     .done                       ; if no error, return

.error:
	neg     rax
    push    rax
    call    __errno_location wrt ..plt  ; with respect to procedure linkage table
    pop     qword[rax]
    mov     rax, -1

.done:
    ret

; The PLT is a table in the data section of an executable or shared library.
; It contains small code stubs (jumps) that are used to call external functions (functions defined in other shared libraries).
; In position-independent code, the address of a shared library and its functions is not known at compile time.
; The library can be loaded at different memory addresses each time the program is run.
; Therefore, you can't directly embed the absolute address of __errno_location in the call instruction.

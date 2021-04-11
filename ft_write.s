extern __errno_location
global ft_write

section .text
ft_write:
		mov		rax, 1
		syscall
		cmp		rax, 0
		jl		.err
		ret
.err:
		push	rdi
		mov		rdi, rax
		neg		rdi
		call	__errno_location wrt ..plt
		mov		[rax], rdi
		mov		rax, -1
		pop		rdi
		ret
global ft_strlen

section .text
ft_strlen:
		push	rdx
		xor		rdx, rdx
		xor		rax, rax

.loop:
		cmp		byte [rdi + rdx], 0
		je		.return
		inc		rax
		inc		rdx
		jmp		.loop

.return:
		pop		rdx
		ret
global ft_strcmp

section .text
ft_strcmp:
		push	rdx
		push	rcx
		xor		rdx, rdx
		xor		rcx, rcx
		xor		rax, rax

.loop:
		mov		dl, byte [rdi + rcx]
		cmp		dl, byte [rsi + rcx]
		jg		.great
		jl		.low
		cmp		dl, 0
		je		.equal
		inc		rcx
		jmp		.loop

.great:
		mov		rax, 1
		jmp		.return

.low:
		mov		rax, -1
		jmp		.return

.equal:
		mov		rax, 0

.return:
		pop		rcx
		pop		rdx
		ret
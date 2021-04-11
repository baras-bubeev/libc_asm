global ft_strcpy

section .text
ft_strcpy:		; rdi = dest, rsi = src
		push	rdx
		push	rcx
		xor		rdx, rdx
		xor		rcx, rcx

.loop:
		mov		dl, byte [rsi + rcx]
		mov		byte [rdi + rcx], dl
		cmp		dl, 0
		je		.return
		inc		rcx
		jmp		.loop

.return:
		mov		rax, rdi
		pop		rcx
		pop		rdx
		ret
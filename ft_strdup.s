global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

section .text
ft_strdup:
		push	rsi
		call	ft_strlen
		inc		rax
		push	rdi
		mov		rdi, rax
		call	malloc wrt ..plt
		pop		rdi
		cmp		rax, 0
		je		.return
		mov		rsi, rdi
		mov		rdi, rax
		call	ft_strcpy

.return:
		pop		rsi
		ret
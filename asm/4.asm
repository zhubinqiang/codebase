# Segmentation fault (core dumped)
# occurs when a program attempts to access a memory location that it is not allowed to access

global main

main:
	mov ebx, 1
	mov ecx, 2
	add ebx, ecx

	mov [0x233], ebx
	mov eax, [0x233]

	ret


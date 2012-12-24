[bits 32]

global main
extern kmain

section .text
align 4

stacksize equ 0x4096

main:
	mov esp,stack+stacksize
	push 0
	call kmain

	hlt

section .bss
align 4
stack:
	resb stacksize

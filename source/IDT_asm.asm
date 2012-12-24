[bits 32]

global FLUSH_IDT

FLUSH_IDT:
	mov eax,[esp+4]
	lidt [eax]
	ret



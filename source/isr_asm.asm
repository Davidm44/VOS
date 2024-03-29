[bits 32]

extern isr_handler

GLOBAL isr0
GLOBAL isr1
GLOBAL isr2
GLOBAL isr3
GLOBAL isr4
GLOBAL isr5
GLOBAL isr6
GLOBAL isr7
GLOBAL isr8
GLOBAL isr9
GLOBAL isr10
GLOBAL isr11
GLOBAL isr12
GLOBAL isr13
GLOBAL isr14
GLOBAL isr15
GLOBAL isr16
GLOBAL isr17
GLOBAL isr18
GLOBAL isr19
GLOBAL isr20
GLOBAL isr21
GLOBAL isr22
GLOBAL isr23
GLOBAL isr24
GLOBAL isr25
GLOBAL isr26
GLOBAL isr27
GLOBAL isr28
GLOBAL isr29
GLOBAL isr30
GLOBAL isr31

isr_common_stub:
   pusha                  

   mov ax, ds           
   push eax                

   mov ax, 0x10  
   mov ds, ax
   mov es, ax
   mov fs, ax
   mov gs, ax

   call isr_handler

   pop eax       
   mov ds, ax
   mov es, ax
   mov fs, ax
   mov gs, ax

   popa                 
   add esp, 8     
   sti
   iret   

isr0:
	cli
	push byte 0
	push byte 0
	jmp isr_common_stub

isr1:
	cli
	push byte 0
	push byte 1
	jmp isr_common_stub

isr2:
	cli
	push byte 0
	push byte 2
	jmp isr_common_stub

isr3:
	cli
	push byte 0
	push byte 3
	jmp isr_common_stub

isr4:
	cli
	push byte 0
	push byte 4
	jmp isr_common_stub

isr5:
	cli
	push byte 0
	push byte 5
	jmp isr_common_stub

isr6:
	cli
	push byte 0
	push byte 6
	jmp isr_common_stub

isr7:
	cli
	push byte 0
	push byte 7
	jmp isr_common_stub

isr8:
	cli
	push byte 0
	push byte 8
	jmp isr_common_stub

isr9:
	cli
	push byte 0
	push byte 9
	jmp isr_common_stub

isr10:
	cli
	push byte 0
	push byte 10
	jmp isr_common_stub

isr11:
	cli
	push byte 0
	push byte 11
	jmp isr_common_stub

isr12:
	cli
	push byte 0
	push byte 12
	jmp isr_common_stub

isr13:
	cli
	push byte 0
	push byte 13
	jmp isr_common_stub

isr14:
	cli
	push byte 0
	push byte 14
	jmp isr_common_stub

isr15:
	cli
	push byte 0
	push byte 15
	jmp isr_common_stub

isr16:
	cli
	push byte 0
	push byte 16
	jmp isr_common_stub

isr17:
	cli
	push byte 0
	push byte 17
	jmp isr_common_stub

isr18:
	cli
	push byte 0
	push byte 18
	jmp isr_common_stub

isr19:
	cli
	push byte 0
	push byte 19
	jmp isr_common_stub

isr20:
	cli
	push byte 0
	push byte 20
	jmp isr_common_stub

isr21:
	cli
	push byte 0
	push byte 21
	jmp isr_common_stub

isr22:
	cli
	push byte 0
	push byte 22
	jmp isr_common_stub

isr23:
	cli
	push byte 0
	push byte 23
	jmp isr_common_stub

isr24:
	cli
	push byte 0
	push byte 24
	jmp isr_common_stub

isr25:
	cli
	push byte 0
	push byte 25
	jmp isr_common_stub

isr26:
	cli
	push byte 0
	push byte 26
	jmp isr_common_stub

isr27:
	cli
	push byte 0
	push byte 27
	jmp isr_common_stub

isr28:
	cli
	push byte 0
	push byte 28
	jmp isr_common_stub

isr29:
	cli
	push byte 0
	push byte 29
	jmp isr_common_stub

isr30:
	cli
	push byte 0
	push byte 30
	jmp isr_common_stub

isr31:
	cli
	push byte 0
	push byte 31
	jmp isr_common_stub



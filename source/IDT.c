#include "IDT.h"
#include "common.h"

IDT_ENTRY idt_entries[256] = {0};
IDT_PTR idt_ptr;

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();
extern void isr16();
extern void isr17();
extern void isr18();
extern void isr19();
extern void isr20();
extern void isr21();
extern void isr22();
extern void isr23();
extern void isr24();
extern void isr25();
extern void isr26();
extern void isr27();
extern void isr28();
extern void isr29();
extern void isr30();
extern void isr31();

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();


void Initialize_IDT()
{
	idt_ptr.limit = ( sizeof(idt_entries)*256 -1 );
	idt_ptr.base = (unsigned int)&idt_entries;
	
	outb(0x20, 0x11);
  	outb(0xA0, 0x11);
 	outb(0x21, 0x20);
  	outb(0xA1, 0x28);
  	outb(0x21, 0x04);
  	outb(0xA1, 0x02);
  	outb(0x21, 0x01);
  	outb(0xA1, 0x01);
  	outb(0x21, 0x0);
  	outb(0xA1, 0x0);

	IDT_AddEntry(0,(unsigned int)isr0,0x08,0x8E);	
	IDT_AddEntry(1,(unsigned int)isr1,0x08,0x8E);
	IDT_AddEntry(2,(unsigned int)isr2,0x08,0x8E);
	IDT_AddEntry(3,(unsigned int)isr3,0x08,0x8E);
	IDT_AddEntry(4,(unsigned int)isr4,0x08,0x8E);	
	IDT_AddEntry(5,(unsigned int)isr5,0x08,0x8E);
	IDT_AddEntry(6,(unsigned int)isr6,0x08,0x8E);
	IDT_AddEntry(7,(unsigned int)isr7,0x08,0x8E);
	IDT_AddEntry(8,(unsigned int)isr8,0x08,0x8E);	
	IDT_AddEntry(9,(unsigned int)isr9,0x08,0x8E);
	IDT_AddEntry(10,(unsigned int)isr10,0x08,0x8E);
	IDT_AddEntry(11,(unsigned int)isr11,0x08,0x8E);
	IDT_AddEntry(12,(unsigned int)isr12,0x08,0x8E);
	IDT_AddEntry(13,(unsigned int)isr13,0x08,0x8E);
	IDT_AddEntry(14,(unsigned int)isr14,0x08,0x8E);
	IDT_AddEntry(15,(unsigned int)isr15,0x08,0x8E);
	IDT_AddEntry(16,(unsigned int)isr16,0x08,0x8E);
	IDT_AddEntry(17,(unsigned int)isr17,0x08,0x8E);
	IDT_AddEntry(18,(unsigned int)isr18,0x08,0x8E);
	IDT_AddEntry(19,(unsigned int)isr19,0x08,0x8E);
	IDT_AddEntry(20,(unsigned int)isr20,0x08,0x8E);
	IDT_AddEntry(21,(unsigned int)isr21,0x08,0x8E);
	IDT_AddEntry(22,(unsigned int)isr22,0x08,0x8E);
	IDT_AddEntry(23,(unsigned int)isr23,0x08,0x8E);
	IDT_AddEntry(24,(unsigned int)isr24,0x08,0x8E);
	IDT_AddEntry(25,(unsigned int)isr25,0x08,0x8E);
	IDT_AddEntry(26,(unsigned int)isr26,0x08,0x8E);
	IDT_AddEntry(27,(unsigned int)isr27,0x08,0x8E);
	IDT_AddEntry(28,(unsigned int)isr28,0x08,0x8E);
	IDT_AddEntry(29,(unsigned int)isr29,0x08,0x8E);
	IDT_AddEntry(30,(unsigned int)isr30,0x08,0x8E);
	IDT_AddEntry(31,(unsigned int)isr31,0x08,0x8E);

	IDT_AddEntry(32,(unsigned int)irq0,0x08,0x8E);	
	IDT_AddEntry(33,(unsigned int)irq1,0x08,0x8E);
	IDT_AddEntry(34,(unsigned int)irq2,0x08,0x8E);
	IDT_AddEntry(35,(unsigned int)irq3,0x08,0x8E);
	IDT_AddEntry(36,(unsigned int)irq4,0x08,0x8E);	
	IDT_AddEntry(37,(unsigned int)irq5,0x08,0x8E);
	IDT_AddEntry(38,(unsigned int)irq6,0x08,0x8E);
	IDT_AddEntry(39,(unsigned int)irq7,0x08,0x8E);
	IDT_AddEntry(40,(unsigned int)irq8,0x08,0x8E);	
	IDT_AddEntry(41,(unsigned int)irq9,0x08,0x8E);
	IDT_AddEntry(42,(unsigned int)irq10,0x08,0x8E);
	IDT_AddEntry(43,(unsigned int)irq11,0x08,0x8E);
	IDT_AddEntry(44,(unsigned int)irq12,0x08,0x8E);
	IDT_AddEntry(45,(unsigned int)irq13,0x08,0x8E);
	IDT_AddEntry(46,(unsigned int)irq14,0x08,0x8E);
	IDT_AddEntry(47,(unsigned int)irq15,0x08,0x8E);
	


	FLUSH_IDT((unsigned int)&idt_ptr);
}

void IDT_AddEntry(unsigned char index,unsigned int base,unsigned short selector,unsigned char flags)
{	
	idt_entries[index].lowbase = base & 0xFFFF;
	idt_entries[index].highbase = (base >> 16) & 0xFFFF;
	idt_entries[index].zero = 0;
	idt_entries[index].selector = selector;
	idt_entries[index].flags = flags;
}

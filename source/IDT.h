struct idt_entry
{
	unsigned short lowbase;
	unsigned short selector;
	unsigned char zero;
	unsigned char flags;
	unsigned short highbase;
}__attribute__((packed));
typedef struct idt_entry IDT_ENTRY, *PIDT_ENTRY;

struct idt_ptr
{
	unsigned short limit;
	unsigned int base;
}__attribute__((packed));
typedef struct idt_ptr IDT_PTR,*PDIT_PTR;

void Initialize_IDT();
extern void IDT_FLUSH(idt_ptr);

void IDT_AddEntry(unsigned char index,unsigned int base,unsigned short selector,unsigned char flags);

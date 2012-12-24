ENTRY (kmain)

SECTIONS{
    . = 0x00001000;

    .text ALIGN (0x4) :{
        *(.text)
    }

  
    .rodata ALIGN (0x4) : {
        *(.rodata)
    }
	
 
    .data ALIGN (0x4) : {
        *(.data)
	*(COMMON)
    }

    .bss : {
        sbss = .;
        *(COMMON)
        *(.bss)
        ebss = .;
    }
}


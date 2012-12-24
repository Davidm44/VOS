#Assemble bootloader
nasm -f bin ./source/Boot.asm -o ./bin/Boot.bin

#assemble & compile kernel
nasm -f elf ./source/bootmain.asm -o ./bin/bootmain.o

nasm -f elf ./source/IDT_asm.asm -o ./bin/IDT_asm.o
nasm -f elf ./source/isr_asm.asm -o ./bin/isr_asm.o
nasm -f elf ./source/IRQ_asm.asm -o ./bin/IRQ_asm.o

gcc -ffreestanding -m32 -c -o ./bin/main.o ./source/main.c 
gcc -ffreestanding -m32 -c -o ./bin/console.o ./source/console.c
gcc -ffreestanding -m32 -c -o ./bin/common.o ./source/common.c
gcc -ffreestanding -m32 -c -o ./bin/IDT.o ./source/IDT.c
gcc -ffreestanding -m32 -c -o ./bin/isr.o ./source/isr.c


ld -T linker.ld -melf_i386 --oformat elf32-i386 -o ./bin/kernel.o ./bin/bootmain.o ./bin/main.o ./bin/console.o ./bin/common.o ./bin/IDT.o ./bin/IDT_asm.o ./bin/isr_asm.o ./bin/isr.o ./bin/IRQ_asm.o

objcopy -R .note -R .comment -S -O binary ./bin/kernel.o ./bin/kernel.bin

#Create image file of OS
dd if=/dev/zero of=VOS.img bs=1MB count=1

dd if=./bin/Boot.bin of=VOS.img bs=512 count=1

dd if=./bin/kernel.bin of=VOS.img bs=512 seek=1 count=10

#write to loop device
#sudo dd if=VOS.img of=/dev/loop0 bs=512 count=2
 
#run bochs
sudo bochs -f /etc/bochs-init/bochsrc.txt

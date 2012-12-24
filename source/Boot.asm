[BITS 16]
[ORG 0x7C00]

main:
	jmp start

vos_signature 	db 'VOS',0

message 		db 'Entering protected mode...',0
sig_not_found 	db 'Unable to find VOS signature...',0
	
start:
	
	cli
	xor ax,ax
	mov ds,ax
	
	call ClearScreen
	
	push message
	call PrintString
	
reset:
	mov ah,0
	mov dl,0
	int 0x13
	jc reset
	
	
	mov bx,0x1000
	
read:
	mov ah,0x2
	mov al,20		;how many sectors to read
	mov ch,0		;track 
	mov cl,2		;sector 
	mov dh,0		;head
	mov dl,0		;drive number
	int 0x13
	jc read

	jmp signature_found ;TEMPORARY****
	
	mov di,5 		;skip jmp bytes
	mov si,0
	
check_signature:

	mov bh,byte [0x1000+di]
	
	mov dh,byte [vos_signature+si]
	cmp bh,dh
	jne signature_not_found
	
	cmp si,3
	je signature_found
	
	inc si
	inc di
	
	jmp check_signature
	
signature_not_found:
	call ClearScreen
	
	push sig_not_found
	call PrintString
	
	hlt

signature_found:
	
	cli
	lgdt [GDT]

	call ClearScreen
	
	mov eax,CR0
	or eax,1
	mov CR0,eax
	
	
	jmp 08h:enter_32
	hlt

[bits 32]

enter_32:

	mov ax,10h
	mov ds,ax
	mov ss,ax
	mov esp,090000h

	call 0x08:0x1000
	
hang:
	jmp hang
	
;**********************************
; 			Functions 			  *
;**********************************

[bits 16]
ClearScreen:

	mov al,02h
	mov ah,0
	int 10h
	ret
	
PrintChar:

	push bp
	mov bp,sp

	mov ax,word [bp+4]
	
	mov al,byte [bp+4]
	mov ah,0Eh
	int 10h
	
	mov sp,bp
	pop bp
	ret

PrintString:

	push bp
	mov bp,sp
	
	mov bx,0
	
	printLoop:
		push bp    
		mov bp,[bp+4]
		add bp,bx
		mov cl,byte [bp]
		pop bp
		cmp cl,0
		je print_done
		
		push cx
		call PrintChar
		inc bx
		jmp printLoop
print_done:
	
	mov sp,bp
	pop bp
	ret
	
gdt_data: 
	dd 0 				
	dd 0 

	
	dw 0FFFFh 			
	dw 0 				
	db 0 				
	db 10011010b 			
	db 11001111b 			
	db 0 				
 

	dw 0FFFFh 			
	dw 0 				
	db 0 				
	db 10010010b 			
	db 11001111b 			
	db 0				
 
end_of_gdt:
GDT: 
	dw end_of_gdt - gdt_data - 1 	
	dd gdt_data 			

	times 510 - ( $ - $$ ) db 0
	dw 0xAA55

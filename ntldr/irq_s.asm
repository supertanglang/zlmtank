

segment .text	; 代码段
bits 32	; 32 位保护模式

; 对齐指令
align 4
global irq0:
irq0:
	push byte 0
	jmp irq

align 4
global irq1:
irq1:
	push byte 1
	jmp irq

align 4
global irq2:
irq2:
	push byte 2
	jmp irq

align 4
global irq3:
irq3:
	push byte 3
	jmp irq

align 4
global irq4:
irq4:
	push byte 4
	jmp irq

align 4
global irq5:
irq5:
	push byte 5
	jmp irq

align 4
global irq6:
irq6:
	push byte 6
	jmp irq

align 4
global irq7:
irq7:
	push byte 7
	jmp irq

align 4
global irq8:
irq8:
	push byte 8
	jmp irq

align 4
global irq9:
irq9:
	push byte 9
	jmp irq

align 4
global irq10:
irq10:
	push byte 10
	jmp irq

align 4
global irq11:
irq11:
	push byte 11
	jmp irq

align 4
global irq12:
irq12:
	push byte 12
	jmp irq

align 4
global irq13:
irq13:
	push byte 13
	jmp irq

align 4
global irq14:
irq14:
	push byte 14
	jmp irq

align 4
global irq15:
irq15:
	push byte 15
	jmp irq

align 4
; exception: 异常处理程序
global irq
irq:
	cld
	; 压入 4 个段选择子寄存器
	push gs
	push fs
	push es
	push ds
	; 压入 8 个通用寄存器 EAX ECX EDX EBX ESP EBP ESI EDI
	pusha
	; 取得系统数据段选择子
SYS_DATASEL equ 0x10
	mov eax, SYS_DATASEL
	mov ds, eax
	mov es, eax
	mov fs, eax
	mov gs, eax
	; 调用 C 处理程序
extern doirq
	call doirq
	cli
	; 弹出 8 个通用寄存器
	popa
	; 弹出 4 个段寄存器
	pop ds
	pop es
	pop fs
	pop gs
	; 弹出中断码
	add esp, 4
	iret



;%include "def.inc"

[extern ntldr_main]

[global ntldr_entry]
;[global _idt_base]
;[global _os_entry]

[BITS 32]           

ntldr_entry:    
	;���üĴ���   
	;;��ʼ�����ݼĴ���
	mov               ax , 0x10
	mov               ds , ax
	mov               es , ax
	mov               fs , ax
	mov               gs , ax
	mov               ss , ax
	mov               esp , 0x400000
	mov               ebp, esp
  
	;����c�ں���ں���
	jmp ntldr_main

BOOTSEC_SEG		equ		0x0
BOOTSEC_OFFSET		equ		0x7c00

NTLDR16_SEG           equ                 0x9000
NTLDR16_OFFSET        equ                 0x0000
NTLDR16_SIZE          equ                 1024          ;setup�Ĵ�С1KB,������ 512 �ı���
NTLDR16_LINEADDR      equ                 0x90000




NTLDR32_SIZE          equ                 204800        ;SYSTEM�Ĵ�С100KB,��ֵ������ 512 �ı���
                                                      ;ʵ��ֵ���Բ���
NTLDR32_LINEADDR      equ                 0x100000
NTLDR32_FARMER_SIZE   equ                 0x80        ;128byte


;bootinfo�ŵ�0x600��λ��
BOOTINFO_SEG		equ		0x0
BOOTINFO_OFFSET		equ		0x600
BOOT_PARAM_LINEADDR	equ		0x600

;bootinfo����Ҫͬ���޸�syscfg.h�����Ӧ�Ľṹ
BOOTDRIVER              equ             BOOTINFO_OFFSET + 0
MEM_E801_MEM_LEN_DW	equ		BOOTINFO_OFFSET + 1
MEM_E820_ITEM_NUM_DW	equ		BOOTINFO_OFFSET + 5
MEM_E820_ITEM_OFFSET	equ		BOOTINFO_OFFSET + 9
MEM_E820_ITEM_SIZE	equ		20
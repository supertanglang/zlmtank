

NTLDR16_SEG           equ                 0x9000
NTLDR16_OFFSET        equ                 0x0000
NTLDR16_SIZE          equ                 1024          ;setup�Ĵ�С1KB,������ 512 �ı���
NTLDR16_LINEADDR      equ                 0x90000




NTLDR32_SIZE          equ                 204800        ;SYSTEM�Ĵ�С100KB,��ֵ������ 512 �ı���
                                                      ;ʵ��ֵ���Բ���
NTLDR32_LINEADDR      equ                 0x400000
NTLDR32_FARMER_SIZE   equ                 0x80


BOOT_PARAM            equ  512-2-4    ;ntldr�ĳ���
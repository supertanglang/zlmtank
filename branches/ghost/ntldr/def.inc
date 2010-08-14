

NTLDR16_SEG           equ                 0x9000
NTLDR16_OFFSET        equ                 0x0000
NTLDR16_SIZE          equ                 1024          ;setup的大小1KB,必须是 512 的倍数
NTLDR16_LINEADDR      equ                 0x90000




NTLDR32_SIZE          equ                 204800        ;SYSTEM的大小100KB,此值必须是 512 的倍数
                                                      ;实际值可以不符
NTLDR32_LINEADDR      equ                 0x400000
NTLDR32_FARMER_SIZE   equ                 0x80


BOOT_PARAM            equ  512-2-4    ;ntldr的长度

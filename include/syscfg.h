#ifndef SYSCFG_H
#define SYSCFG_H

//内存分布
#define	KERNEL_BASE_LA   0x80000000       //3G
#define KERNEL_BASE_PA   0x00000000       //0
#define KERNEL_BASE_SIZE 0x02000000       //32M


#define ESP_BASE_LA   0x90000
#define ESP_BASE_PA   0x90000
#define ESP_BASE_SIZE //....

#define BIOS_BASE_LA  0x000000
#define BIOS_BASE_PA  0x000000
#define BIOS_BASE_SIZE 0x100000

#define NTLDR_BASE_LA  BIOS_BASE_LA+BIOS_BASE_SIZE  //0x0010 0000
#define NTLDR_BASE_PA  BIOS_BASE_PA+BIOS_BASE_SIZE  //0x0010 0000
#define NTLDR_BASE_SIZE 0x100000


#define PTE_BASE_LA KERNEL_BASE_LA                   //0x8000 0000
#define PTE_BASE_PA NTLDR_BASE_PA + NTLDR_BASE_SIZE  //0x0020 0000
#define PTE_BASE_SIZE 0x100000

#define GDT_ITEM_NUM 256
#define GDT_BASE_LA PTE_BASE_LA + PTE_BASE_SIZE //0x8010 0000
#define GDT_BASE_PA PTE_BASE_PA + PTE_BASE_SIZE //0x0030 0000
#define GDT_BASE_SIZE 8*GDT_ITEM_NUM  //32个gdt slot,每个dword*2      2048

#define IDT_ITEM_NUM 256
#define IDT_BASE_LA GDT_BASE_LA + GDT_BASE_SIZE      //0x8010 0800
#define IDT_BASE_PA GDT_BASE_PA + GDT_BASE_SIZE      //0x0030 0800
#define IDT_BASE_SIZE 4*IDT_ITEM_NUM


//GDT system seletor
#define KERNEL_CODE_SEL 0x8
#define KERNEL_DATA_SEL 0x10

#define GDT_KERNEL_CODE_SEL KERNEL_CODE_SEL
#define GDT_KERNEL_DATA_SEL KERNEL_DATA_SEL
#define IDT_KERNEL_CODE_SEL KERNEL_CODE_SEL
#define IDT_KERNEL_DATA_SEL KERNEL_DATA_SEL








// StartMode
#define STARTMODE_NORMAL 0
#define STARTMODE_SAFE   1
#define STARTMODE_DEBUG  2

// StartModeExt
#define STARTMODEEXT_



// VedioMode
#define VIDEO_TEXT_MODE
#define VIDEO_VESA_MODE

typedef struct _syscfg
{
  BOOTINFO *Bootinfo;
  DWORD CpuType;
  DWORD CpuFreq;
  DWORD CpuNum;


  DWORD RunningMode;
  DWORD RunningExt;

  DWORD VideoMode;

}SYSTEMCONFIG;


#endif

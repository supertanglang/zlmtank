#include <types.h>
#include <vga.h>
#include <bootinfo.h>
#include <stdlib.h>
#include <dbg.h>

#include <gdt.h>
#include <idt.h>
#include <irq.h>
#include <traps.h>
#include <time.h>
#include <serial.h>
//�ոս���c���
//��ʱ������4M��һ����λ��
//�ոս��뱣��ģʽ
//GDTֻ��3�ű�
//code / data���ص�,����0-4G


//��Ҫ��������
//������ҳ,ϵͳʹ�ø�2G (0x80000000-0xffffffff)
//�û�����ʹ�õ�2G 0x00000000-0x7fffffff
//���µ���GDT,IDT,PTE

//�μ�syscfg.h




void PrintBootInfo();
void ntldr_initsyscfg();


void ntldr_main()
{
  InitSerialPort();


  //biosĬ�����ı�ģʽ,���ǳ�ʼ��һ��
  vga_init();
  // ����
  vga_clrscr();

  SetStd((stdputs)vga_puts);

  PrintBootInfo();

  // ��ʼ��GDT
  gdt_init();

  //��ʼ��IDT
  idt_init();

  //��ʼ��irq
  irq_init();

  //��ʼ��trap
  traps_init();

  //��ʼ����ʱ��
  timer_init();
  
  SerialTest();

  
  for(;;);
  
  return;
}


void PrintBootInfo()
{
  BYTE *ptr = (BYTE *)BOOTINFO_PTR;
  BOOTINFO *bootinfo = (BOOTINFO *)ptr;
  E820_MAP_ITEM *map_item_ptr = NULL;
  DWORD ii = 0;

  printf(" e801 : memsize = %x (%d kb)\n",
  	     bootinfo->e801_mem_len,
  	     bootinfo->e801_mem_len);

  map_item_ptr = bootinfo->e820_map_ptr;
  for (ii = 0; ii < bootinfo->e820_map_num; ii++)
  {
    printf(" e820: 0x%x%x, 0x%x%x, 0x%x\n",
		   map_item_ptr->mem_base_up32,
		   map_item_ptr->mem_base_low32,
		   map_item_ptr->mem_len_up32,
		   map_item_ptr->mem_len_low32,
		   map_item_ptr->mem_type);
  }
  
}



